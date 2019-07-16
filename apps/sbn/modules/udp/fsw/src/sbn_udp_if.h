#ifndef _sbn_udp_if_h_
#define _sbn_udp_if_h_

#include "sbn_constants.h"
#include "sbn_interfaces.h"
#include "cfe.h"

/**
 * UDP-specific message types.
 */
#define SBN_UDP_HEARTBEAT_MSG 0xA0
#define SBN_UDP_ANNOUNCE_MSG 0xA1

int SBN_UDP_LoadNet(const char **Row, int FieldCount,
    SBN_NetInterface_t *Net);

int SBN_UDP_LoadPeer(const char **Row, int FieldCount,
    SBN_PeerInterface_t *Peer);

int SBN_UDP_InitNet(SBN_NetInterface_t *NetInterface);

int SBN_UDP_InitPeer(SBN_PeerInterface_t *PeerInterface);

int SBN_UDP_PollPeer(SBN_PeerInterface_t *PeerInterface);

int SBN_UDP_Send(SBN_PeerInterface_t *Peer, SBN_MsgType_t MsgType,
    SBN_MsgSize_t MsgSize, SBN_Payload_t Payload);

int SBN_UDP_Recv(SBN_NetInterface_t *Net, SBN_MsgType_t *MsgTypePtr,
        SBN_MsgSize_t *MsgSizePtr, SBN_CpuID_t *CpuIDPtr,
        SBN_Payload_t PayloadBuffer);

int SBN_UDP_ReportModuleStatus(SBN_ModuleStatusPacket_t *Packet);

int SBN_UDP_ResetPeer(SBN_PeerInterface_t *PeerInterface);

int SBN_UDP_UnloadNet(SBN_NetInterface_t *NetInterface);

int SBN_UDP_UnloadPeer(SBN_PeerInterface_t *PeerInterface);

void set_CPU_ID_for_SBN_UDP(int newID);


SBN_IfOps_t SBN_UDP_Ops =
{
    FALSE,
    SBN_UDP_LoadNet,
    SBN_UDP_LoadPeer,
    SBN_UDP_InitNet,
    SBN_UDP_InitPeer,
    SBN_UDP_PollPeer,
    SBN_UDP_Send,
    NULL,
    SBN_UDP_Recv,
    SBN_UDP_ReportModuleStatus,
    SBN_UDP_ResetPeer,
    SBN_UDP_UnloadNet,
    SBN_UDP_UnloadPeer
};

#endif /* _sbn_udp_if_h_ */
