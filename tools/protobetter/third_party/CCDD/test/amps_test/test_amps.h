#ifndef __PROTOBETTER_TEST_A_H__
#define __PROTOBETTER_TEST_A_H__

#include <iostream>
#include <queue>
#include <stdint.h>

extern "C" {
#include "protobetter_generated.h"
}

// main method shows usage of protobetter...
TEST(ProtobetterAmps, Pdu1InputBusSelectCmd)
{
    ClearCmdCodeQueue();

    // push it twice b.c. both pack & unpack will expect the right code
    PushCommandCode(4);
    PushCommandCode(4);

    char buffer[STRUCT_SET_PDU1_INPUT_BUS_SELECT_T_PACKED_SIZE];

    SET_PDU1_INPUT_BUS_SELECT_t inputBusSelect1, inputBusSelect2;

    inputBusSelect1.INPUT_BUS = 42;
    inputBusSelect2.INPUT_BUS = 11;

    ASSERT_NE(inputBusSelect1.INPUT_BUS, inputBusSelect2.INPUT_BUS);

    PackPDU1_CMD(buffer, &inputBusSelect1);
    UnpackPDU1_CMD(&inputBusSelect2, buffer);

    ASSERT_EQ(inputBusSelect1.INPUT_BUS, inputBusSelect2.INPUT_BUS);
}

TEST(ProtobetterAmps, Pdu1RpcChannelState)
{
    ClearCmdCodeQueue();

    // push it twice b.c. both pack & unpack will expect the right code
    PushCommandCode(5);
    PushCommandCode(5);
    
    char buffer[STRUCT_SET_PDU1_RPC_CHANNEL_STATE_T_PACKED_SIZE];

    SET_PDU1_RPC_CHANNEL_STATE_t rpcChannelState1, rpcChannelState2;

    rpcChannelState1.RPCONOFFSTATE = 42;
    rpcChannelState2.RPCONOFFSTATE = 11;
    rpcChannelState1.rpcCHANNEL = 43;
    rpcChannelState2.rpcCHANNEL = 12;

    ASSERT_NE(rpcChannelState1.RPCONOFFSTATE, rpcChannelState2.RPCONOFFSTATE);
    ASSERT_NE(rpcChannelState1.rpcCHANNEL, rpcChannelState2.rpcCHANNEL);

    PackPDU1_CMD(buffer, &rpcChannelState1);
    UnpackPDU1_CMD(&rpcChannelState2, buffer);

    ASSERT_EQ(rpcChannelState1.RPCONOFFSTATE, rpcChannelState2.RPCONOFFSTATE);
    ASSERT_EQ(rpcChannelState1.rpcCHANNEL, rpcChannelState2.rpcCHANNEL);    
}

TEST(ProtobetterAmps, Pdu1RpcChannelOpen)
{
    ClearCmdCodeQueue();

    // push it twice b.c. both pack & unpack will expect the right code
    PushCommandCode(6);
    PushCommandCode(6);
    
    char buffer[STRUCT_SET_PDU1_RPC_CHANNEL_OPEN_T_PACKED_SIZE];

    SET_PDU1_RPC_CHANNEL_OPEN_t rpcChannelOpen1, rpcChannelOpen2;

    rpcChannelOpen1.FORCERPCOFF = 42;
    rpcChannelOpen2.FORCERPCOFF = 11;
    rpcChannelOpen1.rpcCHANNEL = 43;
    rpcChannelOpen2.rpcCHANNEL = 12;

    ASSERT_NE(rpcChannelOpen1.FORCERPCOFF, rpcChannelOpen2.FORCERPCOFF);
    ASSERT_NE(rpcChannelOpen1.rpcCHANNEL, rpcChannelOpen2.rpcCHANNEL);

    PackPDU1_CMD(buffer, &rpcChannelOpen1);
    UnpackPDU1_CMD(&rpcChannelOpen2, buffer);

    ASSERT_EQ(rpcChannelOpen1.FORCERPCOFF, rpcChannelOpen2.FORCERPCOFF);
    ASSERT_EQ(rpcChannelOpen1.rpcCHANNEL, rpcChannelOpen2.rpcCHANNEL);    
}

#endif /* __PROTOBETTER_TEST_A_H__ */
