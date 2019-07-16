import sys
import os
import shutil

dir_path = os.path.dirname(os.path.realpath(__file__))

print("dir_path = " + dir_path)

sys.path.append(dir_path + "/../..")
sys.path.append(dir_path + "/../../../../src")

shutil.copyfile(dir_path + "/../../../../src/protobetter_core.h", "protobetter_core.h")

from protobetter_compiler import ProtobetterGenerator
from protobetter_compiler import ProtobetterType
from protobetter_compiler import CalculatePackingMask
from protobetter_compiler import BuildPrototypeFromJsonObject

from CcddProtobetterTypes import CcsdsCommandTablePrototype

def main():

    # TODO: need to get this tested w/ some ptype files mimicking CCDD commands...
    #       unit-testify this w/ gtest for automated regression purposes

    generator = ProtobetterGenerator("generated")
    generator.AddExternalInclude("test_stubs.h")

    commandTablePrototype = CcsdsCommandTablePrototype("PDU1_CMD", "protobetter_generated.h")

    # process all the command args

    commandArgs = []

    commandArgs.append({"name":"CmdHeader", "type":"bytearray", "arraylen":10})
    commandArgs.append({"name":"CCSDS_CmdSecHdr", "type":"bytearray", "arraylen":2})
    commandArgs.append({"name":"INPUT_BUS", "type":"uint8_t"})

    commandPrototype = BuildPrototypeFromJsonObject("SET_PDU1_INPUT_BUS_SELECT_t", "protobetter_generated.h", commandArgs)

    if commandPrototype.Size > commandTablePrototype.Size:
        commandTablePrototype.Size = commandPrototype.Size

    generator.AddProtobetterType(commandPrototype)


    commandArgs = []

    commandArgs.append({"name":"CmdHeader", "type":"bytearray", "arraylen":10})
    commandArgs.append({"name":"CCSDS_CmdSecHdr", "type":"uint16_t"})
    commandArgs.append({"name":"RPCONOFFSTATE", "type":"uint8_t"})
    commandArgs.append({"name":"rpcCHANNEL", "type":"uint8_t"})

    commandPrototype = BuildPrototypeFromJsonObject("SET_PDU1_RPC_CHANNEL_STATE_t", "protobetter_generated.h", commandArgs)

    if commandPrototype.Size > commandTablePrototype.Size:
        commandTablePrototype.Size = commandPrototype.Size

    generator.AddProtobetterType(commandPrototype)


    commandArgs = []

    commandArgs.append({"name":"CmdHeader", "type":"bytearray", "arraylen":10})
    commandArgs.append({"name":"CCSDS_CmdSecHdr", "type":"uint16_t"})
    commandArgs.append({"name":"FORCERPCOFF", "type":"uint8_t"})
    commandArgs.append({"name":"rpcCHANNEL", "type":"uint8_t"})

    commandPrototype = BuildPrototypeFromJsonObject("SET_PDU1_RPC_CHANNEL_OPEN_t", "protobetter_generated.h", commandArgs)

    if commandPrototype.Size > commandTablePrototype.Size:
        commandTablePrototype.Size = commandPrototype.Size

    generator.AddProtobetterType(commandPrototype)


    # build up the command table

    commandTablePrototype.Commands["SET_PDU1_INPUT_BUS_SELECT_t"] = 4
    commandTablePrototype.Commands["SET_PDU1_RPC_CHANNEL_STATE_t"] = 5
    commandTablePrototype.Commands["SET_PDU1_RPC_CHANNEL_OPEN_t"] = 6

    generator.AddProtobetterType(commandTablePrototype)

    with open("protobetter_generated.h", "w") as outputHeaderFile:
        outputHeaderFile.write(generator.GenerateHeaderFileData())

    with open("protobetter_generated.c", "w") as outputSourceFile:
        outputSourceFile.write(generator.GenerateSourceFileData())

if __name__ == "__main__":
    main()



