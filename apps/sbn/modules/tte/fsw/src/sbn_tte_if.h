#ifndef _sbn_tte_if_h_
#define _sbn_tte_if_h_

#include "sbn_constants.h"
#include "sbn_interfaces.h"
#include "cfe.h"

/**
 * TTE-specific message types.
 * - None. TTE does not use announce/heartbeat
 */

/* */
int SBN_TTE_LoadNet(const char **Row, int FieldCount,
    SBN_NetInterface_t *Net);

/* Load TTE information from the config file lines pointed to by Row.
   Note that Row does not point to a whole line, but only to the TTE-specific
   fields, currently starting at field 7. 

   TTE does not have a concept of "peer" equivalent to TCP/UDP, so in place of
   peer, we use ports. */
int SBN_TTE_LoadPeer(const char **Row, int FieldCount,
    SBN_PeerInterface_t *Peer);

int SBN_TTE_InitNet(SBN_NetInterface_t *NetInterface);

int SBN_TTE_InitPeer(SBN_PeerInterface_t *PeerInterface);

int SBN_TTE_PollPeer(SBN_PeerInterface_t *PeerInterface);

int SBN_TTE_Send(SBN_PeerInterface_t *Peer, SBN_MsgType_t MsgType,
    SBN_MsgSize_t MsgSize, SBN_Payload_t Payload);

int SBN_TTE_Recv(SBN_NetInterface_t *Net, SBN_MsgType_t *MsgTypePtr,
        SBN_MsgSize_t *MsgSizePtr, SBN_CpuID_t *CpuIDPtr,
        SBN_Payload_t PayloadBuffer);

int SBN_TTE_ReportModuleStatus(SBN_ModuleStatusPacket_t *Packet);

int SBN_TTE_ResetPeer(SBN_PeerInterface_t *PeerInterface);

int SBN_TTE_UnloadNet(SBN_NetInterface_t *NetInterface);

int SBN_TTE_UnloadPeer(SBN_PeerInterface_t *PeerInterface);

SBN_IfOps_t SBN_TTE_Ops =
{
    TRUE,
    SBN_TTE_LoadNet,
    SBN_TTE_LoadPeer,
    SBN_TTE_InitNet,
    SBN_TTE_InitPeer,
    SBN_TTE_PollPeer,
    SBN_TTE_Send,
    NULL,
    SBN_TTE_Recv,
    SBN_TTE_ReportModuleStatus,
    SBN_TTE_ResetPeer,
    SBN_TTE_UnloadNet,
    SBN_TTE_UnloadPeer
};

#endif /* _sbn_tte_if_h_ */
