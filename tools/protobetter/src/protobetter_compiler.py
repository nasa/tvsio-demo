#!/usr/bin/env python
import os
import json
import re
import glob
import shutil
from optparse import OptionParser

thisFile = os.path.realpath(__file__)
thisDir = os.path.dirname(thisFile)

############################################################################
####### Main classes for protobetter code-gen and user-defined types #######
############################################################################

class ProtobetterGenerator:

    AvailableStructTypes = {} # key: structTypeName, value: structSize

    def __init__(self, baseName):
        for key, item in ProtobetterGenerator.AvailableStructTypes.iteritems():
           del item
        ProtobetterGenerator.AvailableStructTypes = {}
        
        self.Prototypes = []
        self.DefineName = "__PROTOBETTER_"+baseName.upper()+"_H__"
        self.HeaderName = "protobetter_"+baseName+".h"
        self.SourceName = "protobetter_"+baseName+".c"
        self.ExternalIncludes = []

    def AddProtobetterType(self, proto_type):
        self.Prototypes.append(proto_type)

    def AddExternalInclude(self, headerFileName):
        self.ExternalIncludes.append("#include \"" + headerFileName + "\"\n")

    def GenerateHeaderFileData(self, withTypeDefinitions = True):

        generatedDeclarations  = "#ifndef "+self.DefineName+"\n#define "+self.DefineName+"\n\n"
        generatedDeclarations += "#ifdef __cplusplus\nextern \"C\"\n{\n#endif\n"
        generatedDeclarations += "#include <stdint.h>\n"
        generatedDeclarations += "#include \"protobetter_core.h\"\n"

        for headerFileName in self.ExternalIncludes:
            generatedDeclarations += headerFileName

        generatedDeclarations += "\n"

        for prototype in self.Prototypes:

            if prototype.MemberCount() > 0 and not prototype.static_decl:

                if withTypeDefinitions:

                    generatedDeclarations += prototype.EmitTypeDefinition() + "\n"

                else:

                    generatedDeclarations += prototype.EmitTypeInclude() + "\n\n"

                generatedDeclarations += "#define STRUCT_" + prototype.StructureName.upper() + "_PACKED_SIZE " + str(prototype.Size) + "\n\n"

                generatedDeclarations += prototype.EmitPackDeclaration() + "\n\n"
                generatedDeclarations += prototype.EmitUnpackDeclaration() + "\n\n"                

        generatedDeclarations += "#ifdef __cplusplus\n}\n#endif\n"
        generatedDeclarations += "#endif //"+self.DefineName+"\n\n"

        return generatedDeclarations

    def GenerateSourceFileData(self):

        generatedCode = "#include \"" + self.HeaderName + "\"\n\n"

        for prototype in self.Prototypes:

            generatedCode += prototype.EmitPackCode() + "\n\n"
            generatedCode += prototype.EmitUnpackCode() + "\n\n"

        return generatedCode

class ProtobetterType:

    def __init__(self, structureName, headerFileName):
        self.StructureName = structureName # TODO: change the to '.TypeName'
        self.HeaderFileName = headerFileName # TODO: maybe protobetter should generate struct defs too?
        self.MemberList = [] # TODO: change 'MemberList' to "__memberList'... it's not part of the interface
        self.Size = -1
        self.static_decl = False
        self.CustomDeclarations = set()

    def SetStaticDeclaration(self, statdeclIn):
        self.static_decl = statdeclIn

    # TODO: consider removing this - not sure if you really need it
    def AddBitFieldCollection(self, bitfieldCollection):

        bufferLengthInBits = str(bitfieldCollection.Length * 8)

        self.CustomDeclarations.add("\tuint" + bufferLengthInBits + "_t buffer" + bufferLengthInBits + " = 0;\n")
        self.MemberList.append(bitfieldCollection)

    def MemberCount(self):
        return len(self.MemberList)

    def EmitTypeInclude(self):
        magicCode = "#include \"" + self.HeaderFileName + "\"\n"
        return magicCode

    def EmitTypeDefinition(self):

        magicCode = "typedef struct\n{\n"

        for member in self.MemberList:

            magicCode += member.EmitMemberDeclaration()

        magicCode += "\n} " + self.StructureName + ";\n"

        return magicCode

    def EmitPackDeclaration(self):
        magicCode = "uint32_t Pack" + self.StructureName + "("
        magicCode += "void *buffer, "
        magicCode += "void *protobetter_type);\n"

        return magicCode

    def EmitUnpackDeclaration(self):

        magicCode = "uint32_t Unpack" + self.StructureName + "("
        magicCode += "void *protobetter_type, "
        magicCode += "void *buffer);\n"

        return magicCode

    def EmitPackCode(self):

        magicCode = ""
        if self.static_decl:
           magicCode += "static inline "
        magicCode += "uint32_t Pack" + self.StructureName + "("
        magicCode += "void *buffer, "
        magicCode += "void *protobetter_type)\n"
        magicCode += "{\n"

        for declaration in self.CustomDeclarations:
            magicCode += declaration

        magicCode += "\n"

        magicCode += "\t" + self.StructureName + " *mystruct = (" + self.StructureName + "*)protobetter_type;\n"
        magicCode += "\tunsigned char *bytes = (unsigned char*)buffer;\n\n"

        for member in self.MemberList:
            magicCode += member.EmitPackCode()

        magicCode += "\n\treturn " + str(self.Size) + ";\n"

        magicCode += "}\n"
        return magicCode

    def EmitUnpackCode(self):

        magicCode = ""
        if self.static_decl:
           magicCode += "static inline "
        magicCode += "uint32_t Unpack" + self.StructureName + "("
        magicCode += "void *protobetter_type, "
        magicCode += "void *buffer)\n"
        magicCode += "{\n"

        for declaration in self.CustomDeclarations:
            magicCode += declaration

        magicCode += "\n"

        magicCode += "\t" + self.StructureName + " *mystruct = (" + self.StructureName + "*)protobetter_type;\n"
        magicCode += "\tunsigned char *bytes = (unsigned char*)buffer;\n\n"

        for member in self.MemberList:
            magicCode += member.EmitUnpackCode()


        magicCode += "\n\treturn sizeof(" + self.StructureName + ");\n"

        magicCode += "}\n"
        return magicCode

############## Protobetter Supported Field Types ######################
#   Classes for that handle emitting their own code for each 
#   fundamental type supported by protobetter
#
#   Supported types are:
#       
#       TODO: update this comment
#
#       - Bit Field
#		- Uint8
#		- Uint8Array
#       - Uint16
# 		- Uint16Array
#       - Uint32
# 		- Uint32Array
#       - Uint64
#		- Uint64Array
#       - Float
#		- FloatArray
#       - Double
#		- DoubleArray
#
#######################################################################

class ProtobetterBitfieldCollection:

    # NOTE: length here is in *bytes*
    def __init__(self, byteIndex, length):

        if length not in [1, 2, 4, 8]:
            print("\nERROR: bitfield must live in a word of length 8, 16, 32, or 64 bytes!\n")
            exit()

        self.ByteIndex = byteIndex
        self.Length = length
        self.BitFields = []
        self.BufferName = "buffer" + str(self.Length * 8)
        self.BitsUsed = 0

    def EmitMemberDeclaration(self):

        magicCode = ""

        for bitfield in self.BitFields:

            magicCode += "\t" + bitfield["typeName"] + " "
            magicCode += bitfield["fieldName"] + " : "
            magicCode += str(bitfield["bitfieldLength"]) + ";\n"

        return magicCode

    def AddBitField(self, typeName, fieldName, bitfieldLength):

        if bitfieldLength > ((8 * self.Length) - self.BitsUsed):

            print("\nERROR: bitifeld length is greater than the bits available in this BitFieldCollection!\n")
            exit()

        packingMask = CalculatePackingMask(self.BitsUsed, bitfieldLength, self.Length)

        self.BitFields.append({"typeName":typeName, "fieldName":fieldName, "bitfieldLength":bitfieldLength, "bitOffset":str(self.BitsUsed), "packingMask":packingMask})

        self.BitsUsed += bitfieldLength

    def EmitPackCode(self):

        magicCode = "\n\t" + self.BufferName + " = 0;\n"

        for bitfield in self.BitFields:

            magicCode += "\tPACK_BIT_FIELD("
            magicCode += self.BufferName + ", "
            magicCode += "mystruct->" + bitfield["fieldName"] + ", "
            magicCode += bitfield["bitOffset"] + ", "
            magicCode += bitfield["packingMask"] + ");\n"

        magicCode += "\tPACK_UINT" + str(self.Length * 8) + "("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&" + self.BufferName + ");\n\n"

        return magicCode

    def EmitUnpackCode(self):

        magicCode = "\n\tUNPACK_UINT" + str(self.Length * 8) + "("
        magicCode += "&" + self.BufferName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "]);\n"

        for bitfield in self.BitFields:

            magicCode += "\tUNPACK_BIT_FIELD("
            magicCode += "mystruct->" + bitfield["fieldName"] + ", "
            magicCode += self.BufferName + ", "
            magicCode += bitfield["bitOffset"] + ", "
            magicCode += bitfield["packingMask"] + ");\n"

        magicCode += "\n"

        return magicCode

class ProtobetterChar:

    def __init__(self, fieldName, byteIndex, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "char"
        else:
            typeName = "unsigned char"

        return "\t" + typeName + " " + self.FieldName + ";\n"


    def EmitPackCode(self):
        magicCode = "\tmemcpy("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "1);\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tmemcpy("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "1);\n"
        return magicCode

class ProtobetterCharArray:

    def __init__(self, fieldName, byteIndex, length, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Length = length
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "char"
        else:
            typeName = "unsigned char"

        return "\t" + typeName + " " + self.FieldName + "[" + str(self.Length) + "];\n"


    def EmitPackCode(self):
        magicCode = "\tmemcpy("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += str(self.Length) + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tmemcpy("
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += str(self.Length) + ");\n"
        return magicCode

class ProtobetterInt8:

    def __init__(self, fieldName, byteIndex, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "int8_t"
        else:
            typeName = "uint8_t"

        return "\t" + typeName + " " + self.FieldName + ";\n"

    def EmitPackCode(self):
        magicCode = "\tPACK_UINT8("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tUNPACK_UINT8("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "]);\n"
        return magicCode

class ProtobetterInt8Array:

    def __init__(self, fieldName, byteIndex, length, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Length = length
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "int8_t"
        else:
            typeName = "uint8_t"

        return "\t" + typeName + " " + self.FieldName + "[" + str(self.Length) + "];\n"

    def EmitPackCode(self):
        magicCode = "\tPACK_UINT8_ARRAY("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += str(self.Length) + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tUNPACK_UINT8_ARRAY("
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += str(self.Length) + ");\n"
        return magicCode

class ProtobetterInt16:

    def __init__(self, fieldName, byteIndex, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "int16_t"
        else:
            typeName = "uint16_t"

        return "\t" + typeName + " " + self.FieldName + ";\n"

    def EmitPackCode(self):
        magicCode = "\tPACK_UINT16("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tUNPACK_UINT16("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "]);\n"
        return magicCode

class ProtobetterInt16Array:

    # TODO: length here is the number of elements - change the name so it's not ambiguous
    def __init__(self, fieldName, byteIndex, length, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Length = length
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "int16_t"
        else:
            typeName = "uint16_t"

        return "\t" + typeName + " " + self.FieldName + "[" + str(self.Length) + "];\n"

    def EmitPackCode(self):

        magicCode = "\tPACK_UINT16_ARRAY("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += str(self.Length) + ");\n"

        return magicCode

    def EmitUnpackCode(self):

        magicCode = "\tUNPACK_UINT16_ARRAY("
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += str(self.Length) + ");\n"

        return magicCode

class ProtobetterInt32:

    def __init__(self, fieldName, byteIndex, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "int32_t"
        else:
            typeName = "uint32_t"

        return "\t" + typeName + " " + self.FieldName + ";\n"
        
    def EmitPackCode(self):
        magicCode = "\tPACK_UINT32("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tUNPACK_UINT32("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "]);\n"
        return magicCode

class ProtobetterInt32Array:

    # TODO: length here is the number of elements - change the name so it's not ambiguous
    def __init__(self, fieldName, byteIndex, length, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Length = length
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "int32_t"
        else:
            typeName = "uint32_t"

        return "\t" + typeName + " " + self.FieldName + "[" + str(self.Length) + "];\n"

    def EmitPackCode(self):

        magicCode = "\tPACK_UINT32_ARRAY("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += str(self.Length) + ");\n"

        return magicCode

    def EmitUnpackCode(self):

        magicCode = "\tUNPACK_UINT32_ARRAY("
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += str(self.Length) + ");\n"

        return magicCode

class ProtobetterInt64:

    def __init__(self, fieldName, byteIndex, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "int64_t"
        else:
            typeName = "uint64_t"

        return "\t" + typeName + " " + self.FieldName + ";\n"
        
    def EmitPackCode(self):

        magicCode = "\tPACK_UINT64("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tUNPACK_UINT64("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "]);\n"
        return magicCode

class ProtobetterInt64Array:

    # TODO: length here is the number of elements - change the name so it's not ambiguous
    def __init__(self, fieldName, byteIndex, length, signed = False):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Length = length
        self.Signed = signed

    def EmitMemberDeclaration(self):

        if self.Signed:
            typeName = "int64_t"
        else:
            typeName = "uint64_t"

        return "\t" + typeName + " " + self.FieldName + "[" + str(self.Length) + "];\n"

    def EmitPackCode(self):

        magicCode = "\tPACK_UINT64_ARRAY("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += str(self.Length) + ");\n"

        return magicCode

    def EmitUnpackCode(self):

        magicCode = "\tUNPACK_UINT64_ARRAY("
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += str(self.Length) + ");\n"

        return magicCode

class ProtobetterFloat:

    def __init__(self, fieldName, byteIndex):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex

    def EmitMemberDeclaration(self):

        return "\tfloat " + self.FieldName + ";\n"

    def EmitPackCode(self):
        magicCode = "\tPACK_FLOAT("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tUNPACK_FLOAT("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "]);\n"
        return magicCode

class ProtobetterFloatArray:

    # TODO: length here is the number of elements - change the name so it's not ambiguous
    def __init__(self, fieldName, byteIndex, length):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Length = length

    def EmitMemberDeclaration(self):

        return "\tfloat " + self.FieldName + "[" + str(self.Length) + "];\n"

    def EmitPackCode(self):

        magicCode = "\tPACK_FLOAT_ARRAY("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += str(self.Length) + ");\n"

        return magicCode

    def EmitUnpackCode(self):

        magicCode = "\tUNPACK_FLOAT_ARRAY("
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += str(self.Length) + ");\n"


        return magicCode

class ProtobetterDouble:

    def __init__(self, fieldName, byteIndex):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex

    def EmitMemberDeclaration(self):

        return "\tdouble " + self.FieldName + ";\n"

    def EmitPackCode(self):
        magicCode = "\tPACK_DOUBLE("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tUNPACK_DOUBLE("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "]);\n"
        return magicCode

class ProtobetterDoubleArray:

    # TODO: length here is the number of elements - change the name so it's not ambiguous
    def __init__(self, fieldName, byteIndex, length):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Length = length

    def EmitMemberDeclaration(self):

        return "\tdouble " + self.FieldName + "[" + str(self.Length) + "];\n"

    def EmitPackCode(self):

        magicCode = "\tPACK_DOUBLE_ARRAY("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += str(self.Length) + ");\n"

        return magicCode

    def EmitUnpackCode(self):

        magicCode = "\tUNPACK_DOUBLE_ARRAY("
        magicCode += "mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += str(self.Length) + ");\n"

        return magicCode

class ProtobetterStruct:

    def __init__(self, typeName, fieldName, byteIndex):
        self.TypeName = typeName
        self.FieldName = fieldName
        self.ByteIndex = byteIndex

    def EmitMemberDeclaration(self):

        return "\t" + self.TypeName + " " + self.FieldName + ";\n"

    def EmitPackCode(self):
        magicCode = "\tPack" + self.TypeName + "("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tUnpack" + self.TypeName + "("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "]);\n"
        return magicCode

class ProtobetterStructArray:

    def __init__(self, typeName, fieldName, byteIndex, structSize, arrayLength):
        self.TypeName = typeName
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.StructSize = structSize
        self.ArrayLength = arrayLength

    def EmitMemberDeclaration(self):

        return "\t" + self.TypeName + " " + self.FieldName + "[" + str(self.ArrayLength) + "];\n"

    def EmitPackCode(self):

        magicCode = "\t{\n"
        magicCode += "\t\tint ii = 0;\n"
        magicCode += "\t\tfor(ii = 0; ii < " + str(self.ArrayLength) + "; ++ii) {\n"
        magicCode += "\t\t\tPack" + self.TypeName + "("
        magicCode += "&bytes[" + str(self.ByteIndex) + " + (ii*(" + str(self.StructSize) + "))], "
        magicCode += "&mystruct->" + self.FieldName + "[ii]);\n"
        magicCode += "\t\t}\n"
        magicCode += "\t}\n"

        return magicCode

    def EmitUnpackCode(self):

        magicCode = "\t{\n"
        magicCode += "\t\tint ii = 0;\n"
        magicCode += "\t\tfor(ii = 0; ii < " + str(self.ArrayLength) + "; ++ii) {\n"
        magicCode += "\t\t\tUnpack" + self.TypeName + "("
        magicCode += "&mystruct->" + self.FieldName + "[ii], "
        magicCode += "&bytes[" + str(self.ByteIndex) + " + (ii*(" + str(self.StructSize) + "))]);\n"
        magicCode += "\t\t}\n"
        magicCode += "\t}\n"

        return magicCode

# TODO: hrm... this is about the same as ProtobetterInt8Array... consider removing this...
class ProtobetterByteArray:

    def __init__(self, fieldName, byteIndex, length):
        self.FieldName = fieldName
        self.ByteIndex = byteIndex
        self.Length = length

    def EmitMemberDeclaration(self):

        return "\tchar " + self.FieldName + "[" + str(self.Length) + "];\n"

    def EmitPackCode(self):
        magicCode = "\tmemcpy("
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += str(self.Length) + ");\n"
        return magicCode

    def EmitUnpackCode(self):
        magicCode = "\tmemcpy("
        magicCode += "&mystruct->" + self.FieldName + ", "
        magicCode += "&bytes[" + str(self.ByteIndex) + "], "
        magicCode += str(self.Length) + ");\n"
        return magicCode


############################################################################
################# Protobetter Utility Functions ############################
############################################################################

def CalculatePackingMask(bitOffset, fieldWidth, fieldSize):

    bitString = ''

    for index in range(0, fieldSize*8):

        if index >= bitOffset and index < (bitOffset + fieldWidth):

            bitString = '0' + bitString

        else:
            
            bitString = '1' + bitString

    return hex(int(bitString, 2))

def BuildPrototypeFromJsonObject(typeName, headerFileName, members):

    if typeName in list(ProtobetterGenerator.AvailableStructTypes.keys()):

        print("\n\nERROR: multiple proto_types specified with the same type name!")
        exit()

    prototype = ProtobetterType(typeName, headerFileName)
    strOffset = ""
    intOffset = 0

    processingBitField = False
    currentBitfieldCollection = None

    for x in range(0, len(members)):

        try: # parse json data in ProtobetterType objects

            memberName = members[x]['name']
            memberType = members[x]['type']

            bits = 0
            arraylen = 0

            if 'bits' in members[x]:
                bits = members[x]['bits']
            elif 'arraylen' in members[x]:
                arraylen = members[x]['arraylen']

        except KeyError as err:
            print("\n\Protobetter Compiler Error: missing required parameter '{0}' in proto_type file: {1}\n\n".format(err.args[0], prototypeFilePath))
            continue                

        if bits != 0: # it's a bit field...

            if memberType == "int8_t" or memberType == "uint8_t":
                wordLength = 1

            elif memberType == "int16_t" or memberType == "uint16_t":
                wordLength = 2

            elif memberType == "int32_t" or memberType == "uint32_t":
                wordLength = 4

            elif memberType == "int64_t" or memberType == "uint64_t":
                wordLength = 8

            else:
                print("\nERROR: unrecognized type for bitfield!!!\n")
                exit()

            if currentBitfieldCollection is None:

                currentBitfieldCollection = ProtobetterBitfieldCollection(str(intOffset) + strOffset, wordLength)
                intOffset += wordLength

                prototype.AddBitFieldCollection(currentBitfieldCollection)

            else:

                # TODO: should we allow for padding inbetween bitfields in the same word or is that unecessary complexity?

                if (wordLength != currentBitfieldCollection.Length) or (currentBitfieldCollection.BitsUsed + bits > currentBitfieldCollection.Length * 8):

                    currentBitfieldCollection = ProtobetterBitfieldCollection(str(intOffset) + strOffset, wordLength)
                    intOffset += wordLength

                    prototype.AddBitFieldCollection(currentBitfieldCollection)

            currentBitfieldCollection.AddBitField(memberType, memberName, bits)

        else:

            # it's not a bit field...
            currentBitfieldCollection = None

            # TODO: same question as other comments here - should we really support the character type differently than int8/uint8?
            if memberType == "char" or memberType == "unsigned char" or memberType == "string":
                fieldSize = 1
                if not memberName.startswith("pad"):
                    if arraylen != 0:
                        prototype.MemberList.append(ProtobetterInt8Array(memberName, str(intOffset) + strOffset, arraylen))
                        if isinstance(arraylen, str):
                           strOffset += " + (" +str(fieldSize) + "*" + arraylen + ")"
                        else:
                           intOffset += fieldSize * arraylen
                    else:
                        prototype.MemberList.append(ProtobetterChar(memberName, str(intOffset) + strOffset, 1))
                        intOffset += fieldSize

            elif memberType == "int8_t" or memberType == "uint8_t":
                signed = False if memberType.startswith("uint") else True
                fieldSize = 1
                if not memberName.startswith("pad"):
                    if arraylen != 0:
                        prototype.MemberList.append(ProtobetterInt8Array(memberName, str(intOffset) + strOffset, arraylen, signed))
                        if isinstance(arraylen, str):
                           strOffset += " + (" +str(fieldSize) + "*" + arraylen + ")"
                        else:
                           intOffset += fieldSize * arraylen
                    else:
                        prototype.MemberList.append(ProtobetterInt8(memberName, str(intOffset) + strOffset, signed))
                        intOffset += fieldSize

            elif memberType == "int16_t" or memberType == "uint16_t":
                signed = False if memberType.startswith("uint") else True
                fieldSize = 2
                if not memberName.startswith("pad"):
                    if arraylen != 0:
                        prototype.MemberList.append(ProtobetterInt16Array(memberName, str(intOffset) + strOffset, arraylen, signed))
                        if isinstance(arraylen, str):
                           strOffset += " + (" +str(fieldSize) + "*" + arraylen + ")"
                        else:
                           intOffset += fieldSize * arraylen
                    else:
                        prototype.MemberList.append(ProtobetterInt16(memberName, str(intOffset) + strOffset, signed))
                        intOffset += fieldSize

            elif memberType == "int32_t" or memberType == "uint32_t":
                signed = False if memberType.startswith("uint") else True
                fieldSize = 4
                if not memberName.startswith("pad"):
                    if arraylen != 0:
                        prototype.MemberList.append(ProtobetterInt32Array(memberName, str(intOffset) + strOffset, arraylen, signed))
                        if isinstance(arraylen, str):
                           strOffset += " + (" +str(fieldSize) + "*" + arraylen + ")"
                        else:
                           intOffset += fieldSize * arraylen
                    else:
                        prototype.MemberList.append(ProtobetterInt32(memberName, str(intOffset) + strOffset, signed))
                        intOffset += fieldSize

            elif memberType == "int64_t" or memberType == "uint64_t":
                signed = False if memberType.startswith("uint") else True
                fieldSize = 8
                if not memberName.startswith("pad"):
                    if arraylen != 0:
                        prototype.MemberList.append(ProtobetterInt64Array(memberName, str(intOffset) + strOffset, arraylen, signed))
                        if isinstance(arraylen, str):
                           strOffset += " + (" +str(fieldSize) + "*" + arraylen + ")"
                        else:
                           intOffset += fieldSize * arraylen
                    else:
                        prototype.MemberList.append(ProtobetterInt64(memberName, str(intOffset) + strOffset, signed))
                        intOffset += fieldSize

            elif memberType == "float":
                fieldSize = 4
                if not memberName.startswith("pad"):
                    if arraylen != 0:
                        prototype.MemberList.append(ProtobetterFloatArray(memberName, str(intOffset) + strOffset, arraylen))
                        if isinstance(arraylen, str):
                           strOffset += " + (" +str(fieldSize) + "*" + arraylen + ")"
                        else:
                           intOffset += fieldSize * arraylen
                    else:
                        prototype.MemberList.append(ProtobetterFloat(memberName, str(intOffset) + strOffset))
                        intOffset += fieldSize

            elif memberType == "double":
                fieldSize = 8
                if not memberName.startswith("pad"):
                    if arraylen != 0:
                        prototype.MemberList.append(ProtobetterDoubleArray(memberName, str(intOffset) + strOffset, arraylen))
                        if isinstance(arraylen, str):
                           strOffset += " + (" +str(fieldSize) + "*" + arraylen + ")"
                        else:
                           intOffset += fieldSize * arraylen
                    else:
                        prototype.MemberList.append(ProtobetterDouble(memberName, str(intOffset) + strOffset))
                        intOffset += fieldSize

            elif memberType == "bytearray":
                fieldSize = arraylen
                if not memberName.startswith("pad"):
                    # TODO: i think we probably should get rid of this in favor of ProtobetterInt8Array... consider it
                    prototype.MemberList.append(ProtobetterByteArray(memberName, str(intOffset) + strOffset, arraylen))
                    if isinstance(arraylen, str):
                       strOffset += " + (" +str(fieldSize) + "*" + arraylen + ")"
                    else:
                       intOffset += fieldSize

            elif memberType in list(ProtobetterGenerator.AvailableStructTypes.keys()):

                if memberName.startswith("pad"):
                    print("\n\nERROR: Padding fields cannot have a structure type!\n\n")
                    exit()

                fieldSize = ProtobetterGenerator.AvailableStructTypes[memberType]
                if arraylen != 0:
                    prototype.MemberList.append(ProtobetterStructArray(memberType, memberName, str(intOffset) + strOffset, fieldSize, arraylen))
                    if isinstance(arraylen, str) or isinstance(fieldSize, str):
                       strOffset += " + ((" +str(fieldSize) + ")*" + str(arraylen) + ")"
                    else:
                       intOffset += fieldSize * arraylen
                else:
                    prototype.MemberList.append(ProtobetterStruct(memberType, memberName, str(intOffset) + strOffset))
                    if isinstance(fieldSize, str):
                       strOffset += " + " + fieldSize
                    else:
                       intOffset += fieldSize

            else:

                print("\n\nERROR: Encountered unknown member type '{0}' for member '{1}' in proto_type '{2}'!\n\n".format(memberType, memberName, typeName))
                exit()

    if strOffset:
       prototype.Size = str(intOffset) + strOffset
       ProtobetterGenerator.AvailableStructTypes[typeName] = str(intOffset) + strOffset
    else:
       prototype.Size = intOffset
       ProtobetterGenerator.AvailableStructTypes[typeName] = intOffset



    return prototype

############################################################################
############################ Begin App Code ################################
############################################################################

def json_load_byteified(file_handle):
    return _byteify(
        json.load(file_handle, object_hook=_byteify),
        ignore_dicts=True
    )

def json_loads_byteified(json_text):
    return _byteify(
        json.loads(json_text, object_hook=_byteify),
        ignore_dicts=True
    )

def _byteify(data, ignore_dicts = False):
    # if this is a unicode string, return its string representation
    if isinstance(data, unicode):
        return data.encode('utf-8')
    # if this is a list of values, return list of byteified values
    if isinstance(data, list):
        return [ _byteify(item, ignore_dicts=True) for item in data ]
    # if this is a dictionary, return dictionary of byteified keys and values
    # but only if we haven't already byteified it
    if isinstance(data, dict) and not ignore_dicts:
        return {
            _byteify(key, ignore_dicts=True): _byteify(value, ignore_dicts=True)
            for key, value in data.iteritems()
        }
    # if it's anything else, return it in its original form
    return data

def main():

    parser = OptionParser(description="Given a list of *.ptype filepaths, generates structure definitions and serialization code.", usage = "protobetter_compiler.py [OPTION] PROTOTYPE_FILE_PATHS")
    parser.add_option('-o', '--output', dest='output', help="Output directory for protobetter generated files.", default=".")

    (options, args) = parser.parse_args()

    outputDirectory = os.path.abspath(options.output)
    if not os.path.exists(outputDirectory):
        print("Output file path '" + outputDirectory + "' does not exist.")
        return 

    prototype_files = []

    # handle wild-card characters b.c. sometimes they come through w/o being globbed
    for filePath in args:

        files = glob.glob(filePath)

        if files is None or len(files) == 0:

            print("ERROR: unrecognized ProtoType file-path... " + filePath)
            exit()

        for f in files:

            if (filePath.endswith(".ptype")):
                prototype_files.append(os.path.abspath(f))

    if len(prototype_files) == 0:
        print("\n\n *** Protobetter Compiler ERROR: No proto-type file paths specified *** \n\n")

    generator = ProtobetterGenerator("generated")

    outputSourceFilePath = os.path.join(outputDirectory, generator.SourceName)
    outputHeaderFilePath = os.path.join(outputDirectory, generator.HeaderName)

    for prototypeFilePath in prototype_files:

        prototypeJsonString = ""

        with open(prototypeFilePath, 'r') as prototypeFile:
            prototypeJsonString = prototypeFile.read()

        try:
            prototypeArray = json_loads_byteified(prototypeJsonString)
        except ValueError as err:
            print("\n\nProtobetter Compiler ERROR when parsing file '{0}': {1}\n".format(prototypeFilePath, err))
            print("\n\nMay want to double check that the json data in proto-type file is valid... e.g. should be no commas after last member of a json array, etc...\n\n")
            continue

        for prototypeDefinition in prototypeArray:

            try: # parse json data in ProtobetterType objects

                typeName = prototypeDefinition['typeName']
                headerFileName = prototypeDefinition['headerFileName']
                members = prototypeDefinition['members']

            except KeyError as err:
                print("\n\Protobetter Compiler Error: missing required parameter '{0}' in proto_type file: {1}\n\n".format(err.args[0], prototypeFilePath))
                continue

            prototype = BuildPrototypeFromJsonObject(typeName, headerFileName, members)

            generator.AddProtobetterType(prototype)

    with open(outputHeaderFilePath, "w") as outputHeaderFile:
        outputHeaderFile.write(generator.GenerateHeaderFileData())

    with open(outputSourceFilePath, "w") as outputSourceFile:
        outputSourceFile.write(generator.GenerateSourceFileData())

    if thisDir != os.path.dirname(outputHeaderFilePath):
        shutil.copyfile(thisDir + "/protobetter_core.h", os.path.dirname(outputHeaderFilePath) + "/protobetter_core.h")

if __name__ == "__main__":
    main()

