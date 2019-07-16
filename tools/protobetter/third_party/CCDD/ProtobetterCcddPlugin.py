import sys, os, shutil

thisFile =  ccdd.getScriptName()
thisDir = os.path.dirname(thisFile)
topDir = os.path.abspath(thisDir + "/../../src")

sys.path.append(thisDir)
sys.path.append(topDir)

import json

from protobetter_compiler import ProtobetterGenerator
from protobetter_compiler import ProtobetterType
from protobetter_compiler import CalculatePackingMask
from protobetter_compiler import BuildPrototypeFromJsonObject

from CCDD import CcddScriptDataAccessHandler

from CcddProtobetterTypes import CcsdsCommandTablePrototype

groupNames = ccdd.getAssociatedGroupNames()

systemName = None

if len(groupNames) != 0:
        # Get the value of the first group's 'System' data field, if present
        systemName = ccdd.getGroupDataFieldValue(groupNames[0], "System")

    # Check if the system name wasn't found in the group data field
if systemName is None or not systemName:
        # Get the value of the first root structure's 'System' data field
        rootStructureTableNames = ccdd.getRootStructureTableNames()

        if rootStructureTableNames is not None and len(rootStructureTableNames) > 0:
            systemName = ccdd.getTableDataFieldValue(ccdd.getRootStructureTableNames()[0], "System")

    # Check if the data field doesn't exist in either a group or table
if systemName == None:
        systemName = "unknown"

baseName = systemName;
proto_headername="protobetter_"+baseName+".h";
proto_sourcename="protobetter_"+baseName+".c";
prototype_filename="protobetter_"+baseName+".ptype";
type_include=systemName+"_types.h"

generator = ProtobetterGenerator(baseName)

numberOfStructureRows = ccdd.getStructureTableNumRows()
structureNames = ccdd.getStructureTablesByReferenceOrder()

generatedPrototypeList = []

if (numberOfStructureRows == 0):

   ccdd.showInformationDialog("No structure data supplied to script..." + ccdd.getScriptName())

else:

    try:

        for structIndex in range(len(structureNames)):

            usedVariableNames = []

            currentStructName = structureNames[structIndex]

            # we will be building up a list of member objects which protobetter can consume
            structMembers = []

            for rowIndex in range(numberOfStructureRows):

                if currentStructName == ccdd.getStructureTableNameByRow(rowIndex):

                    variableName = ccdd.getStructureTableData("variable name", rowIndex)

                    if not variableName.endswith("]"): # tbh, it should never end w/ "]"

                        if variableName not in usedVariableNames:

                            usedVariableNames.append(variableName)

                            memberType = ccdd.getStructureTableData("data type", rowIndex)

                            arrayLength = ccdd.getStructureTableData("array size", rowIndex)

                            if arrayLength is not None and arrayLength:

                                # we're dealing w/ an array

                                arrayLength = int(arrayLength)
                                arrayText = ccdd.getStructureTableData("array text", rowIndex)
                                if arrayText is not None and arrayText:
                                   structMembers.append({"name":variableName, "type":memberType, "arraylen":str(arrayText)})
                                else:
                                   # TODO: process array
                                   structMembers.append({"name":variableName, "type":memberType, "arraylen":arrayLength})

                            else:

                                # we're dealing w/ a single type

                                # see if it's a bit field...
                                bitFieldLength = ccdd.getStructureTableData("bit length", rowIndex)

                                if bitFieldLength is not None and bitFieldLength:

                                    bitFieldLength = int(bitFieldLength)
                                    
                                    structMembers.append({"name":variableName, "type":memberType, "bits":bitFieldLength})

                                else:

                                    structMembers.append({"name":variableName, "type":memberType})
            

            generatedPrototypeList.append({"typeName":currentStructName,"headerFileName":type_include,"members":structMembers})

            prototype = BuildPrototypeFromJsonObject(currentStructName, type_include, structMembers)

            MsgId = ccdd.getTableDataFieldValue(structureNames[structIndex], "Message ID")
            if MsgId is None or not MsgId:
               prototype.SetStaticDeclaration(True)
            else:
               prototype.SetStaticDeclaration(False)

            generator.AddProtobetterType(prototype)
            
    except Exception as e:

        del generator
        ccdd.showErrorDialog(str(e))

# TODO: document this more explicitly (for structure tables too)
#       in essence, you can iterate through rows for all 
#       command / structure tables by using this value returned below
numberOfCommandRows = ccdd.getCommandTableNumRows()

commandTableNames = ccdd.getCommandTableNames()

if (numberOfCommandRows == 0):

   ccdd.showInformationDialog("No structure data supplied to script..." + ccdd.getScriptName())

else:

    try:

        usedVariableNames = []

        cmdPrimaryHeaderSize = ccdd.getDataTypeSizeInBytes("CCSDS_Primary")
        if (cmdPrimaryHeaderSize is not None and cmdPrimaryHeaderSize):
            cmdPrimaryHeaderSize = int(cmdPrimaryHeaderSize)
        else:
            ccdd.showErrorDialog("Could not determine CCSDS_Primary structure table size! Make sure the table is defined in CCDD!")

        for commandIndex in range(len(commandTableNames)):

            currentCommandTableName = commandTableNames[commandIndex]

            commandTablePrototype = CcsdsCommandTablePrototype(currentCommandTableName, type_include)

            for rowIndex in range(numberOfCommandRows):

                # this check guarantees that we're only looking at rows for the right table
                if currentCommandTableName == ccdd.getCommandTableNameByRow(rowIndex):

                    # process individual commands in *this* table

                    commandName = ccdd.getCommandTableData("command name", rowIndex)

                    # TODO: this check was in an older script - is it still needed?
                    #       maybe it was based on a deprecated version of the CCDD scripting API...
                    if not commandName.endswith("]"):

                        commandName = commandName + "_t"
                        commandCode = ccdd.getCommandCode(rowIndex)

                        if commandCode is not None:
                            commandTablePrototype.Commands[commandName] = commandCode

                        if commandName not in usedVariableNames:

                            usedVariableNames.append(commandName)

                            if commandCode is None or not commandCode:
                                ccdd.showErrorDialog("Command table " + currentCommandTableName + " does not have a command code for command named " + commandName + "!")

                            # convert to an int from (possibly hex) string
                            commandCode = int(commandCode, 0)

                            # we will be building up a list of member objects which protobetter can consume
                            commandArgs = []

                            commandArgs.append({"name":"CmdHeader", "type":"bytearray", "arraylen":cmdPrimaryHeaderSize})
                            commandArgs.append({"name":"CCSDS_CmdSecHdr", "type":"bytearray", "arraylen":2})

                            for commandArgIndex in range(ccdd.getNumCommandArguments(rowIndex)):

                                commandArgName = ccdd.getCommandArgName(commandArgIndex, rowIndex)
                                commandArgType = ccdd.getCommandArgDataType(commandArgIndex, rowIndex)

                                if commandArgName is not None and commandArgName and commandArgType is not None and commandArgType:

                                    commandArgs.append({"name":commandArgName, "type":commandArgType})

                            generatedPrototypeList.append({"typeName":commandName,"headerFileName":type_include,"members":commandArgs})

                            # this builds the serialization code for *this* command - but not the wrapper for the whole table of commands
                            prototype = BuildPrototypeFromJsonObject(commandName, type_include, commandArgs)

                            # we want the size we provide to user for the commandTablePrototype buffer to be 
                            # at least as big as the largest possible command that might be packed
                            if prototype.Size > commandTablePrototype.Size:
                                commandTablePrototype.Size = prototype.Size

                            generator.AddProtobetterType(prototype)

            generator.AddProtobetterType(commandTablePrototype)

    except Exception as e:

        ccdd.showErrorDialog(str(e))

generator.AddExternalInclude("cfe_sb.h")

file = ccdd.openOutputFile(proto_headername)
ccdd.writeToFile(file, generator.GenerateHeaderFileData(False))
ccdd.closeFile(file)

file = ccdd.openOutputFile(proto_sourcename)
ccdd.writeToFile(file, generator.GenerateSourceFileData())
ccdd.closeFile(file)

if generatedPrototypeList:
    file = ccdd.openOutputFile(prototype_filename)
    ccdd.writeToFile(file, json.dumps(generatedPrototypeList))
    ccdd.closeFile(file)

ccddFile = os.path.realpath("./" + proto_headername)
ccddDir = os.path.dirname(ccddFile)
shutil.copyfile(topDir + "/protobetter_core.h", ccddDir + "/protobetter_core.h")

#ccdd.showInformationDialog("Sucessfully generated protobetter code in " + proto_headername + " and " + proto_sourcename)

del generator
