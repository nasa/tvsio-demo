#include "sbn_tcp_if_struct.h"
#include "sbn_tcp_if.h"
#include "sbn_tcp_events.h"
#include "cfe.h"
#include "cfe_platform_cfg.h"
#include <network_includes.h>
#include <string.h>
#include <errno.h>

/* at some point this will be replaced by the OSAL network interface */
#ifdef _VXWORKS_OS_
#include "selectLib.h"
#define MSG_NOSIGNAL 0
#else
#include <sys/select.h>
#endif

static SBN_PackedMsg_t SendBufs[SBN_MAX_NETS];
static int SendBufCount = 0;
int SBN_TCP_LoadNet(const char **Row, int FieldCount, SBN_NetInterface_t *Net)
{
    SBN_TCP_Net_t *NetData = (SBN_TCP_Net_t *)Net->ModulePvt;

    if(FieldCount < SBN_TCP_ITEMS_PER_FILE_LINE)
    {
        CFE_EVS_SendEvent(SBN_TCP_CONFIG_EID, CFE_EVS_ERROR,
                "invalid peer file line (expected %d items, found %d)",
                SBN_TCP_ITEMS_PER_FILE_LINE, FieldCount);
        return SBN_ERROR;
    }/* end if */

    strncpy(NetData->Host, Row[0], sizeof(NetData->Host));
    char *ValidatePtr = NULL;
    NetData->Port = strtol(Row[1], &ValidatePtr, 0);
    if(!ValidatePtr || ValidatePtr == Row[1])
    {
        CFE_EVS_SendEvent(SBN_TCP_CONFIG_EID, CFE_EVS_ERROR,
                "invalid port");
    }/* end if */

    NetData->BufNum = SendBufCount++;

    return SBN_SUCCESS;
}/* end SBN_TCP_LoadHost */

static SBN_PackedMsg_t RecvBufs[SBN_MAX_NETS * SBN_MAX_PEERS_PER_NET];
static int RecvBufCount = 0;
int SBN_TCP_LoadPeer(const char **Row, int FieldCount,
    SBN_PeerInterface_t *Peer)
{
    SBN_TCP_Peer_t *PeerData = (SBN_TCP_Peer_t *)Peer->ModulePvt;

    if(FieldCount < SBN_TCP_ITEMS_PER_FILE_LINE)
    {
        CFE_EVS_SendEvent(SBN_TCP_CONFIG_EID, CFE_EVS_ERROR,
                "invalid peer file line (expected %d items, found %d)",
                SBN_TCP_ITEMS_PER_FILE_LINE, FieldCount);
        return SBN_ERROR;
    }/* end if */

    strncpy(PeerData->Host, Row[0], sizeof(PeerData->Host));
    char *ValidatePtr = NULL;
    PeerData->Port = strtol(Row[1], &ValidatePtr, 0);
    if(!ValidatePtr || ValidatePtr == Row[1])
    {
        CFE_EVS_SendEvent(SBN_TCP_CONFIG_EID, CFE_EVS_ERROR,
                "invalid port");
    }/* end if */

    PeerData->BufNum = RecvBufCount++;

    return SBN_SUCCESS;
}/* end SBN_TCP_LoadEntry */

/**
 * Initializes an TCP host or peer data struct depending on the
 * CPU name.
 *
 * @param  Interface data structure containing the file entry
 * @return SBN_SUCCESS on success, error code otherwise
 */
int SBN_TCP_InitNet(SBN_NetInterface_t *Net)
{
    SBN_TCP_Net_t *NetData = (SBN_TCP_Net_t *)Net->ModulePvt;

    struct sockaddr_in my_addr;
    int OptVal = 0;

    NetData->Socket = -1;
    int Socket = 0;

    CFE_EVS_SendEvent(SBN_TCP_SOCK_EID, CFE_EVS_DEBUG,
        "creating socket for %s:%d", NetData->Host, NetData->Port);

    if((Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        CFE_EVS_SendEvent(SBN_TCP_SOCK_EID, CFE_EVS_ERROR,
            "unable to create socket (errno=%d)", errno);
        return SBN_ERROR;
    }/* end if */

    OptVal = 1;
    setsockopt(Socket, SOL_SOCKET, SO_REUSEADDR,
        (const void *)&OptVal, sizeof(int));

    my_addr.sin_addr.s_addr = inet_addr(NetData->Host);
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(NetData->Port);

    if(bind(Socket, (struct sockaddr *) &my_addr,
        sizeof(my_addr)) < 0)
    {
        close(Socket);
        CFE_EVS_SendEvent(SBN_TCP_SOCK_EID, CFE_EVS_ERROR,
            "bind call failed (%s:%d Socket=%d errno=%d)",
            NetData->Host, NetData->Port, Socket, errno);
        return SBN_ERROR;
    }/* end if */

    if(listen(Socket, SBN_MAX_PEERS_PER_NET) < 0)
    {
        close(Socket);
        CFE_EVS_SendEvent(SBN_TCP_SOCK_EID, CFE_EVS_ERROR,
            "listen call failed (%s:%d Socket=%d errno=%d)",
            NetData->Host, NetData->Port, Socket, errno);
        return SBN_ERROR;
    }/* end if */

    NetData->Socket = Socket;

    return SBN_SUCCESS;
}/* end SBN_TCP_Init */

/**
 * Initializes an TCP peer.
 *
 * @param  Interface data structure containing the file entry
 * @return SBN_SUCCESS on success, error code otherwise
 */
int SBN_TCP_InitPeer(SBN_PeerInterface_t *Peer)
{
    SBN_TCP_Peer_t *PeerData
        = (SBN_TCP_Peer_t *)Peer->ModulePvt;

    PeerData->ConnectOut =
        (Peer->Status.ProcessorID > CFE_PSP_GetProcessorId());
    PeerData->Connected = FALSE;
    PeerData->Socket = -1;

    return SBN_SUCCESS;
}/* end SBN_TCP_Init */

static void CheckNet(SBN_NetInterface_t *Net)
{
    SBN_TCP_Net_t *NetData = (SBN_TCP_Net_t *)Net->ModulePvt;
    fd_set ReadFDs;
    struct timeval timeout;
    struct sockaddr_in ClientAddr;
    socklen_t ClientLen = sizeof(ClientAddr);
    int PeerIdx = 0;

    /**
     * Check for new connections.
     */
    memset(&timeout, 0, sizeof(timeout));
    timeout.tv_usec = 100;

    FD_ZERO(&ReadFDs);
    FD_SET(NetData->Socket, &ReadFDs);

    /* TODO: thread implementation? */
    if(select(NetData->Socket + 1, &ReadFDs, 0, 0, &timeout) < 0)
    {
        return;
    }/* end if */

    if(FD_ISSET(NetData->Socket, &ReadFDs))
    {
        int ClientFd = 0;
        if ((ClientFd
            = accept(NetData->Socket,
                (struct sockaddr *)&ClientAddr, &ClientLen)) < 0)
        {
            return;
        }/* end if */
        
        for(PeerIdx = 0; PeerIdx < Net->Status.PeerCount; PeerIdx++)
        {
            SBN_PeerInterface_t *Peer = &Net->Peers[PeerIdx];
            SBN_TCP_Peer_t *PeerData = (SBN_TCP_Peer_t *)Peer->ModulePvt;
            if(PeerData->Socket == -1)
            {
                CFE_EVS_SendEvent(SBN_TCP_DEBUG_EID, CFE_EVS_INFORMATION,
                    "Anonymous client connected.");

                PeerData->Socket = ClientFd;

                return;
            }/* end if */
        }/* end for */
        
        /* invalid peer */
        close(ClientFd);
    }/* end if */

    /**
     * For peers I connect out to, and which are not currently connected,
     * try connecting now.
     */
    for(PeerIdx = 0; PeerIdx < Net->Status.PeerCount; PeerIdx++)
    {
        SBN_PeerInterface_t *Peer = &Net->Peers[PeerIdx];
        SBN_TCP_Peer_t *PeerData = (SBN_TCP_Peer_t *)Peer->ModulePvt;
        if(PeerData->ConnectOut && !PeerData->Connected)
        {
            OS_time_t LocalTime;
            OS_GetLocalTime(&LocalTime);
            /* TODO: make a #define */
            if(LocalTime.seconds > PeerData->LastConnectTry.seconds + 5)
            {
                int Socket = 0;

                if((Socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
                {
                    CFE_EVS_SendEvent(SBN_TCP_SOCK_EID, CFE_EVS_ERROR,
                        "unable to create socket (errno=%d)", errno);
                    return;
                }/* end if */

                struct sockaddr_in ServerAddr;
                memset(&ServerAddr, 0, sizeof(ServerAddr));
                ServerAddr.sin_family = AF_INET;
                ServerAddr.sin_addr.s_addr = inet_addr(PeerData->Host);
                ServerAddr.sin_port = htons(PeerData->Port);

                if((connect(Socket, (struct sockaddr *)&ServerAddr,
                        sizeof(ServerAddr)))
                    >= 0)
                {
                    CFE_EVS_SendEvent(SBN_TCP_DEBUG_EID, CFE_EVS_INFORMATION,
                        "CPU %d connected", Peer->Status.ProcessorID);

                    PeerData->Socket = Socket;
                    PeerData->Connected = TRUE;

                    SBN_SendLocalSubsToPeer(Peer);

                    OS_GetLocalTime(&Peer->Status.LastRecv);
                }
                else
                {
                    close(Socket);
                    PeerData->LastConnectTry.seconds = LocalTime.seconds;
                }/* end if */
            }/* end if */
        }/* end if */
    }/* end for */
}/* end CheckNet */

int SBN_TCP_PollPeer(SBN_PeerInterface_t *Peer)
{
    CheckNet(Peer->Net);

    SBN_TCP_Peer_t *PeerData = (SBN_TCP_Peer_t *)Peer->ModulePvt;

    if(!PeerData->Connected)
    {
        return 0;
    }/* end if */

    OS_time_t CurrentTime;
    OS_GetLocalTime(&CurrentTime);

    if(CurrentTime.seconds - Peer->Status.LastSend.seconds
        > SBN_TCP_PEER_HEARTBEAT)
    {
        SBN_TCP_Send(Peer, SBN_TCP_HEARTBEAT_MSG, 0, NULL);
    }/* end if */

    if(CurrentTime.seconds - Peer->Status.LastRecv.seconds
        > SBN_TCP_PEER_TIMEOUT)
    {
        CFE_EVS_SendEvent(SBN_TCP_DEBUG_EID, CFE_EVS_INFORMATION,
            "CPU %d disconnected", Peer->Status.ProcessorID);

        shutdown(PeerData->Socket, SHUT_RDWR);
        close(PeerData->Socket);
        PeerData->Socket = -1;
        PeerData->Connected = FALSE;
    }/* end if */

    return 0;
}

int SBN_TCP_Send(SBN_PeerInterface_t *Peer,
    SBN_MsgType_t MsgType, SBN_MsgSize_t MsgSize, SBN_Payload_t Msg)
{
    SBN_TCP_Peer_t *PeerData = (SBN_TCP_Peer_t *)Peer->ModulePvt;
    SBN_NetInterface_t *Net = Peer->Net;
    SBN_TCP_Net_t *NetData = (SBN_TCP_Net_t *)Net->ModulePvt;

    CheckNet(Net);

    if (!PeerData->Connected)
    {
        /* fail silently as the peer is not connected (yet) */
        return SBN_SUCCESS;
    }/* end if */

    SBN_PackMsg(&SendBufs[NetData->BufNum], MsgSize, MsgType, CFE_CPU_ID, Msg);
    size_t sent_size = send(PeerData->Socket, &SendBufs[NetData->BufNum],
        MsgSize + SBN_PACKED_HDR_SIZE, MSG_NOSIGNAL);
    if(sent_size < MsgSize + SBN_PACKED_HDR_SIZE)
    {
        CFE_EVS_SendEvent(SBN_TCP_DEBUG_EID, CFE_EVS_INFORMATION,
            "CPU %d disconnected", Peer->Status.ProcessorID);

        shutdown(PeerData->Socket, SHUT_RDWR);
        close(PeerData->Socket);
        PeerData->Socket = -1;
        PeerData->Connected = FALSE;
    }/* end if */

    OS_GetLocalTime(&Peer->Status.LastSend);

    return SBN_SUCCESS;
}/* end SBN_TCP_Send */

int SBN_TCP_Recv(SBN_NetInterface_t *Net, SBN_PeerInterface_t *Peer,
    SBN_MsgType_t *MsgTypePtr, SBN_MsgSize_t *MsgSizePtr,
    SBN_CpuID_t *CpuIDPtr, SBN_Payload_t MsgBuf)
{
    SBN_TCP_Peer_t *PeerData = (SBN_TCP_Peer_t *)Peer->ModulePvt;

    CheckNet(Net);

    if (PeerData->Socket == -1)
    {
        /* fail silently as the peer is not connected (yet) */
        return SBN_IF_EMPTY;
    }/* end if */

#ifndef SBN_RECV_TASK

    /* task-based peer connections block on reads, otherwise use select */

    fd_set ReadFDs;
    struct timeval Timeout;

    FD_ZERO(&ReadFDs);
    FD_SET(PeerData->Socket, &ReadFDs);

    memset(&Timeout, 0, sizeof(Timeout));

    if(select(FD_SETSIZE, &ReadFDs, NULL, NULL, &Timeout) == 0)
    {
        /* nothing to receive */
        return SBN_IF_EMPTY;
    }/* end if */

#endif /* !SBN_RECV_TASK */

    ssize_t Received = 0;

    int ToRead = 0;

    if(!PeerData->ReceivingBody)
    {
        /* recv the header first */
        ToRead = SBN_PACKED_HDR_SIZE - PeerData->RecvSize;

        Received = recv(PeerData->Socket,
            (char *)&RecvBufs[PeerData->BufNum] + PeerData->RecvSize,
            ToRead, 0);

        if(Received <= 0)
        {
           CFE_EVS_SendEvent(SBN_TCP_DEBUG_EID, CFE_EVS_INFORMATION,
               "CPU %d disconnected", Peer->Status.ProcessorID);

           shutdown(PeerData->Socket, SHUT_RDWR);
           close(PeerData->Socket);
           PeerData->Socket = -1;
           PeerData->Connected = FALSE;
           return SBN_IF_EMPTY;
        }/* end if */

        PeerData->RecvSize += Received;

        if(Received >= ToRead)
        {
            PeerData->ReceivingBody = TRUE; /* and continue on to recv body */
        }
        else
        {
            return SBN_IF_EMPTY; /* wait for the complete header */
        }/* end if */
    }/* end if */

    /* only get here if we're recv'd the header and ready for the body */

    ToRead = CFE_MAKE_BIG16(*((SBN_MsgSize_t *)&RecvBufs[PeerData->BufNum].Hdr.MsgSizeBuf)) + SBN_PACKED_HDR_SIZE
          - PeerData->RecvSize;
    if(ToRead)
    {
        Received = recv(PeerData->Socket,
            (char *)&RecvBufs[PeerData->BufNum] + PeerData->RecvSize,
            ToRead, 0);
        if(Received < 0)
        {
            return SBN_ERROR;
        }/* end if */

        PeerData->RecvSize += Received;

        if(Received < ToRead)
        {
            return SBN_IF_EMPTY; /* wait for the complete body */
        }/* end if */
    }/* end if */


    /* we have the complete body, decode! */
    SBN_UnpackMsg(&RecvBufs[PeerData->BufNum], MsgSizePtr, MsgTypePtr, CpuIDPtr,
        MsgBuf);
    if(!PeerData->Connected) {
       SBN_TCP_Net_t *NetData = (SBN_TCP_Net_t *)Net->ModulePvt;
       int TruePeerIdx = 0;
       for(TruePeerIdx = 0; TruePeerIdx < Net->Status.PeerCount; TruePeerIdx++)
       {
           SBN_PeerInterface_t *TruePeer = &Net->Peers[TruePeerIdx];
           SBN_TCP_Peer_t *TruePeerData = (SBN_TCP_Peer_t *)TruePeer->ModulePvt;
           if(TruePeer->Status.ProcessorID == *CpuIDPtr)
           {
               CFE_EVS_SendEvent(SBN_TCP_DEBUG_EID, CFE_EVS_INFORMATION,
                   "CPU %d connected.", TruePeer->Status.ProcessorID);

               if(TruePeer != Peer) {
                  TruePeerData->Socket = PeerData->Socket;
                  PeerData->Socket = -1;
               }
               TruePeerData->Connected = TRUE;

               SBN_SendLocalSubsToPeer(TruePeer);

               OS_GetLocalTime(&TruePeer->Status.LastRecv);
           }/* end if */
       }/* end for */
    }

    PeerData->ReceivingBody = FALSE;
    PeerData->RecvSize = 0;

    return SBN_SUCCESS;
}/* end SBN_TCP_Recv */

int SBN_TCP_ReportModuleStatus(SBN_ModuleStatusPacket_t *Packet)
{
    return SBN_NOT_IMPLEMENTED;
}/* end SBN_TCP_ReportModuleStatus */

int SBN_TCP_ResetPeer(SBN_PeerInterface_t *Peer)
{
    return SBN_NOT_IMPLEMENTED;
}/* end SBN_TCP_ResetPeer */

int SBN_TCP_UnloadNet(SBN_NetInterface_t *Net)
{
    SBN_TCP_Net_t *NetData = (SBN_TCP_Net_t *)Net->ModulePvt;

    if(NetData->Socket)
    {
        shutdown(NetData->Socket, SHUT_RDWR);
        close(NetData->Socket);
        NetData->Socket = -1;
    }/* end if */

    int PeerIdx = 0;
    for(PeerIdx = 0; PeerIdx < Net->Status.PeerCount; PeerIdx++)
    {
        SBN_TCP_UnloadPeer(&Net->Peers[PeerIdx]);
    }/* end if */

    return SBN_SUCCESS;
}/* end SBN_TCP_ResetPeer */

int SBN_TCP_UnloadPeer(SBN_PeerInterface_t *Peer)
{
    SBN_TCP_Peer_t *PeerData = (SBN_TCP_Peer_t *)Peer->ModulePvt;

    if(PeerData->Socket)
    {
        shutdown(PeerData->Socket, SHUT_RDWR);
        close(PeerData->Socket);
        PeerData->Socket = -1;
    }/* end if */

    return SBN_SUCCESS;
}/* end SBN_TCP_ResetPeer */
