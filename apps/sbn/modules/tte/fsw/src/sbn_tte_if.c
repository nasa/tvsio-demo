#include "sbn_tte_if_struct.h"
#include "sbn_tte_if.h"
#include "sbn_tte_events.h"
#include "cfe.h"
#include "sbn_subs.h"
#include <network_includes.h>
#include <string.h>
#include <errno.h>
#include <ctype.h> /* isspace() */
#include <stdio.h>
#ifdef _VXWORKS_OS_ 
#include <selectLib.h>
#else
#include <sys/select.h>
#endif

static uint32 tte_recv_mutex = 0;

#undef SBN_TTE_DEBUG

int SBN_TTE_LoadPeer(const char** Row, int FieldCount, SBN_PeerInterface_t* Peer) {
    CFE_SB_MsgId_t msgId;
    SBN_TTE_Direction_t direction;
    const int DirectionIndex = 0;
    const int StartMsgIdIndex = DirectionIndex + 1;
    int entry = 0;
    SBN_TTE_Port_t *Entry = (SBN_TTE_Port_t *) Peer->ModulePvt;

    /* Parse port direction */
    if ((sscanf(Row[DirectionIndex], "%uc", &direction) != 1)
            || (direction < SBN_TTE_DIRECTION_MIN)
            || (direction > SBN_TTE_DIRECTION_MAX)) {
        CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_ERROR,
                "invalid direction in SBN TTE config: %s",
                Row[DirectionIndex]);
        return SBN_ERROR;
    }
    Entry->Direction = direction;

    /* Store message ids for this port */
    for (entry = StartMsgIdIndex; entry < FieldCount; entry++) {
        uint16_t scanMsgId;
        if (sscanf(Row[entry], "%hx", &scanMsgId) != 1) {
            CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_ERROR,
                    "invalid message id in SBN TTE config: %s",
                    Row[entry]);
            return SBN_ERROR;
        } else {
            msgId = scanMsgId;
            if (Entry->MsgIdCount < SBN_TTE_MAX_PORT_MSGIDS) {
                Entry->MsgIds[Entry->MsgIdCount] = msgId;
                ++(Entry->MsgIdCount);
                CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_INFORMATION,
                        "Added msgid 0x%x for TTE port %s", msgId, Peer->Status.Name);
            } else {
                CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_ERROR,
                        "Max num msgids exceeded for TTE port %s",
                        Peer->Status.Name);
                break;
            }
        }
    }

    /* Fix up the processor ID to match the peer index */
    Peer->Status.ProcessorID = Peer->Net->Status.PeerCount-1;

    return SBN_SUCCESS;
}

/**
 * Loads the TTE network. TTE network configuration is performed outside SBN,
 * so there is nothing to do here except to ensure the TTE driver has time to 
 * initialize before we start asking it to initialize ports.
 *
 * @param Row: set of network parameters (none used at the present time)
 * @param FieldCount: count of parameters in Row
 * @param Net: pointer to the network interface structure
 * @return SBN_SUCCESS on success, error code otherwise
 */
int SBN_TTE_LoadNet(const char **Row, int FieldCount, SBN_NetInterface_t *Net) {
    CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_INFORMATION,
            "Waiting for TTE API to initialize...");
                    
    /* The TTE API requires specifying a timeout parameter, but SBN has no
     * way to recover if the calls times out, so we may as well wait until we 
     * know we have succeeded (or not) by passing a timeout of 0. */
    TTE_ApiRetVal_t TTE_RetVal = TTE_API_WaitForStartup(0);
    
    if (TTE_RetVal == TTE_API_SUCCESS) {
        CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_INFORMATION, 
            "TTE API initialized");
        return SBN_SUCCESS;
    } else {
        CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_ERROR, 
            "TTE API failed to initialize");
        return SBN_ERROR;
    }
}

/**
 * Initializes an TTE network.
 *
 * @param  Interface data structure containing the file entry
 * @return SBN_SUCCESS on success, error code otherwise
 */
int SBN_TTE_InitNet(SBN_NetInterface_t *Net) {
    /* Nothing to do here -- network is initialized outside of SBN */
    return SBN_SUCCESS;
}/* end SBN_TTE_InitHost */

/**
 * Initializes a port data struct.
 *
 * @param  Interface data structure containing the file entry
 * @return SBN_SUCCESS on success, error code otherwise
 */
int SBN_TTE_InitPeer(SBN_PeerInterface_t *PeerInterface) {
    int TTE_RetVal;

    SBN_TTE_Port_t *Entry = (SBN_TTE_Port_t *) PeerInterface->ModulePvt;
    TTE_PortHdl_t handle;
    uint8 MsgIdx = 0;

    TTE_RetVal = TTE_API_PortHdlInit(PeerInterface->Status.Name, &handle);

    if (TTE_RetVal != TTE_API_SUCCESS) {
        CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_ERROR,
                          "Port handle for %s NOT assigned. Error: %d\n",
                          PeerInterface->Status.Name, TTE_RetVal);
        Entry->PortHandle = -1;
        return SBN_ERROR;
    }

        CFE_EVS_SendEvent(SBN_TTE_CONFIG_EID, CFE_EVS_INFORMATION,
                          "Port %s assigned handle %d\n", 
                          PeerInterface->Status.Name, handle);

    /* Register subscriptions for a peer */
    for (MsgIdx = 0; MsgIdx < Entry->MsgIdCount; MsgIdx++) {
        /* QoS is determined at the network level for TTE */
        ProcessSubFromPeer(PeerInterface,
                           Entry->MsgIds[MsgIdx],
                           CFE_SB_Default_Qos);
    }

    Entry->PortHandle = handle;

    return SBN_SUCCESS;
}/* end SBN_TTE_InitPort */

int SBN_TTE_Send(SBN_PeerInterface_t *PeerInterface, SBN_MsgType_t MsgType,
        SBN_MsgSize_t MsgSize, SBN_Payload_t Msg) {
    
    /* TTE does not send subscriptions */
    switch(MsgType) {
        case SBN_SUBSCRIBE_MSG:
        case SBN_UN_SUBSCRIBE_MSG:
            return SBN_SUCCESS;
        case SBN_APP_MSG:
            break; /* continue processing */
        default:
            OS_printf("Attempt to send message with crazy type: %d REJECTED!\n", MsgType);
            return SBN_ERROR;
            break;
    }

    SBN_TTE_Port_t *Entry = (SBN_TTE_Port_t *) PeerInterface->ModulePvt;
    int TTE_RetVal = 0;
    int index;
    boolean msgValid = FALSE;
    CFE_SB_MsgId_t msgId = CFE_SB_GetMsgId(Msg);
    SBN_PackedMsg_t SendBuf;
    
    for (index = 0; index < Entry->MsgIdCount; index++) {
        if (msgId == Entry->MsgIds[index]) {
            msgValid = TRUE;
            break;
        }
    }
    
    if (!msgValid) { 
#ifdef SBN_TTE_DEBUG
        OS_printf("SBN TTE: Message 0x%04x is not valid for port %s\n", msgId, PeerInterface->Status.Name);
#endif
        return SBN_ERROR;
    }

    SBN_PackMsg(&SendBuf, MsgSize, MsgType, CFE_CPU_ID, Msg);

    /* TODO: Temporary debug */
#ifdef SBN_TTE_DEBUG
    OS_printf("Sending message: 0x%02x%02x to %s (size %d)\n", SendBuf.Payload[0], SendBuf.Payload[1], PeerInterface->Status.Name, MsgSize + SBN_PACKED_HDR_SIZE);
#endif

    /* Adjust MsgSize to include the SBN header size */
    TTE_RetVal = TTE_API_PortSendMsg(Entry->PortHandle, 
                                     MsgSize + SBN_PACKED_HDR_SIZE, 
                                     &SendBuf, 
                                     NULL);

    if (TTE_RetVal != TTE_API_SUCCESS) {
        OS_printf("Error sending message: 0x%02x%02x on %s: code %d\n", SendBuf.Payload[0], SendBuf.Payload[1], PeerInterface->Status.Name, TTE_RetVal);
        return SBN_ERROR;
    }

    return SBN_SUCCESS;
}/* end SBN_TTE_Send */

/* Note that this Recv function is indiscriminate: packets will be received
 * on all ports, but that's ok -- I just inject them into the SB and all is
 * good!
 */
int SBN_TTE_Recv(SBN_NetInterface_t *Net, SBN_MsgType_t *MsgTypePtr,
        SBN_MsgSize_t *MsgSizePtr, SBN_CpuID_t *CpuIDPtr, SBN_Payload_t MsgBuf) {

    int PeerIdx = 0;
    uint8 Channel = 0;
    SBN_PackedMsg_t RecvBuf;

    for (PeerIdx = 0; PeerIdx < Net->Status.PeerCount; PeerIdx++) {

        SBN_TTE_Port_t *Entry = (SBN_TTE_Port_t *) Net->Peers[PeerIdx].ModulePvt;

        /* Skip over send ports */
        if (Entry->Direction == SBN_TTE_DIRECTION_SEND) continue;

        /** Create mutex for send tasks */
        if (tte_recv_mutex == 0) {
            OS_MutSemCreate(&(tte_recv_mutex), "sbn_tte_recv_mutex", 0);
        }

        /* Look for messages */
        uint32 Status = TTE_API_PortReadMsg(Entry->PortHandle,
                MsgSizePtr,
                (uint8*) & RecvBuf,
                CFE_SB_MAX_SB_MSG_SIZE,
                &Channel,
                NULL);
        if (Status == TTE_API_SUCCESS) {
     
            SBN_UnpackMsg(&RecvBuf, MsgSizePtr, MsgTypePtr, CpuIDPtr, MsgBuf);
            *CpuIDPtr = PeerIdx;
#ifdef SBN_TTE_DEBUG
            OS_printf("Received message: 0x%02x%02x from %s (size %d) peer index %lu\n", 
                   RecvBuf.Payload[0], RecvBuf.Payload[1], 
                   Net->Peers[PeerIdx].Status.Name,
                   *MsgSizePtr,
                   *CpuIDPtr);
#endif

            /* TTE uses port index rather than CPU ID */
            return SBN_SUCCESS;
        } else {
            if (Status != TTE_API_NO_MESSAGE) {
            /* There's nothing to receive. */
                OS_printf("Error receiving message: %d\n", Status);
            }
        }
    }
    return SBN_IF_EMPTY;

}/* end SBN_TTE_Recv */

int SBN_TTE_PollPeer(SBN_PeerInterface_t *Peer) {
    return SBN_NOT_IMPLEMENTED;
} /* end SBN_TTE_PollPeer */

int SBN_TTE_ReportModuleStatus(SBN_ModuleStatusPacket_t *Packet) {
    return SBN_NOT_IMPLEMENTED;
}/* end SBN_TTE_ReportModuleStatus */

int SBN_TTE_ResetPeer(SBN_PeerInterface_t *Peer) {
    return SBN_NOT_IMPLEMENTED;
}/* end SBN_TTE_ResetPeer */

int SBN_TTE_UnloadNet(SBN_NetInterface_t *Net) {
    return SBN_NOT_IMPLEMENTED;
}/* end SBN_TTE_UnloadNet */

int SBN_TTE_UnloadPeer(SBN_PeerInterface_t *Peer) {
    return SBN_SUCCESS;
}/* end SBN_TTE_UnloadPeer */
