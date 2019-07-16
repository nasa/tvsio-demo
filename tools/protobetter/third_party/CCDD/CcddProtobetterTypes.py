# a custom CcsdsCommandTablePrototype for SBN integration - TODO: this 
# is the same pattern that telemetry should follow too really
class CcsdsCommandTablePrototype:

    def __init__(self, commandTableName, headerFileName):
        self.StructureName = commandTableName
        self.HeaderFileName = headerFileName
        self.Size = -1
        self.Commands = {} # dictionary of "commandName":"commandCode"
        self.static_decl = False

    # this "CommandTableName" has the same meaning as a Protobetter "structure name"
    def CommandTableName(self):
        return self.StructureName

    # the following functions implement the Protobetter 'Prototype' interface

    def MemberCount(self):
        return len(self.Commands)

    def SetStaticDeclaration(self, statdeclIn):
        self.static_decl = statdeclIn

    def EmitTypeInclude(self):
        return "#include \"" + self.HeaderFileName + "\"\n"

    def EmitTypeDefinition(self):
        return ""

    def EmitPackDeclaration(self):

        magicCode = "uint32_t Pack" + self.CommandTableName() + "("
        magicCode += "void *buffer, "
        magicCode += "void *protobetter_type);\n"

        return magicCode

    def EmitUnpackDeclaration(self):

        magicCode = "uint32_t Unpack" + self.CommandTableName() + "("
        magicCode += "void *protobetter_type, "
        magicCode += "void *buffer);\n"

        return magicCode

    def EmitPackCode(self):

        magicCode = ""

        if self.static_decl:
           magicCode += "static "
        magicCode += "uint32_t Pack" + self.CommandTableName() + "("
        magicCode += "void *buffer, "
        magicCode += "void *protobetter_type)\n"
        magicCode += "{\n"

        magicCode += "\tCFE_SB_Msg_t *msg = (CFE_SB_Msg_t *) protobetter_type;\n\n"
        magicCode += "\tuint16_t cmdCode = CFE_SB_GetCmdCode(msg);\n\n"

        magicCode += "\tswitch (cmdCode)\n\t{\n"

        for commandName in self.Commands:

            magicCode += "\t\tcase " + str(self.Commands[commandName]) + ":\n\n"
            magicCode += "\t\t\treturn Pack" + commandName + "(buffer, protobetter_type);\n\n"

        magicCode += "\t\tdefault:\n\n\t\t\treturn 0;\n\t}\n}\n"

        return magicCode

    def EmitUnpackCode(self):

        magicCode = ""

        if self.static_decl:
           magicCode += "static "
        magicCode += "uint32_t Unpack" + self.CommandTableName() + "("
        magicCode += "void *protobetter_type, "
        magicCode += "void *buffer)\n"
        magicCode += "{\n"

        magicCode += "\tCFE_SB_Msg_t *msg = (CFE_SB_Msg_t *) buffer;\n\n"
        magicCode += "\tuint16_t cmdCode = CFE_SB_GetCmdCode(msg);\n\n"

        magicCode += "\tswitch (cmdCode)\n\t{\n"

        for commandName in self.Commands:

            magicCode += "\t\tcase " + str(self.Commands[commandName]) + ":\n\n"
            magicCode += "\t\t\treturn Unpack" + commandName + "(protobetter_type, buffer);\n\n"

        magicCode += "\t\tdefault:\n\n\t\t\treturn 0;\n\t}\n}\n"

        return magicCode
