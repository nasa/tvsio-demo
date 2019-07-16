/******************************************************************************
** File: sbn_app.h
**
**      Copyright (c) 2004-2006, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA's Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This software may be used only pursuant to a United States government
**      sponsored project and the United States government may not be charged
**      for use thereof.
**
** Purpose:
**      This header file contains prototypes for private functions and type
**      definitions for the Software Bus Network Application.
**
** Authors:   J. Wilmot/GSFC Code582
**            R. McGraw/SSI
**            C. Knight/ARC Code TI
**
******************************************************************************/

#ifndef _sbn_app_
#define _sbn_app_

#include <network_includes.h>
#include <string.h>
#include <errno.h>

#include "osconfig.h"
#include "cfe.h"
#include "sbn_version.h"
#include "sbn_interfaces.h"
#include "sbn_msg.h"
#include "sbn_platform_cfg.h"
#include "cfe_sb_msg.h"
#include "cfe_sb.h"
#include "sbn_msgids.h"
#include "ecls_sbn_msgids.h"
#include "sbn_loader.h"
#include "sbn_cmds.h"
#include "sbn_subs.h"
#include "sbn_main_events.h"
#include "sbn_perfids.h"

#include "sbn_remap_tbldefs.h"
#include "sbn_protobetter_tbldefs.h"

#ifndef SBN_TLM_MID
/* backwards compatability in case you're using a MID generator */
#define SBN_TLM_MID SBN_HK_TLM_MID
#endif /* SBN_TLM_MID */

#define SBN_REMAP_TABLE_NAME  "REMAP_TBL"
#define SBN_PROTOBETTER_TABLE_NAME "PROTOBETTER_TBL"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* SBN application data structures                                 */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void SBN_ShowPeerData(void);
int32 SBN_GetPeerFileData(void);

int SBN_InitInterfaces(void);
int32 SBN_LoadTables(void);

#ifndef SBN_RECV_TASK
void SBN_RecvNetMsgs(void);
#endif /* !SBN_RECV_TASK */

#ifndef SBN_SEND_TASK
void SBN_CheckPeerPipes(void);
#endif /* !SBN_SEND_TASK */

int SBN_SendNetMsg(SBN_MsgType_t MsgType, SBN_MsgSize_t MsgSize,
    SBN_Payload_t *Msg, SBN_PeerInterface_t *Peer);

typedef struct
{
   uint32 numEntries;
   uint64 MapValue[SBN_REMAP_TABLE_SIZE];
   uint32 EntryIdx[SBN_REMAP_TABLE_SIZE];
} SBN_RemapCache_t;

typedef struct
{
   uint32 EntryIdx;
   size_t (*PackFuncPtr)( void * outputBuffer,
                          void * InSBMsg );
   size_t (*UnpackFuncPtr)( void * OutSBMsg,
                            void * inputBuffer );

} SBN_ProtoBetterCache_Entry_t;

typedef struct
{
   uint32 numEntries;
   SBN_ProtoBetterCache_Entry_t entries[SBN_PROTOBETTER_TABLE_SIZE];

} SBN_ProtobetterCache_t;

/**
 * \brief SBN global data structure definition
 */
typedef struct
{
    /** \brief Data only on host definitions. */
    SBN_NetInterface_t Nets[SBN_MAX_NETS];

    /** \brief The application ID provided by ES */
    uint32 AppID;

    /** \brief The application full name provided by SB */
    char App_FullName[(OS_MAX_API_NAME * 2)];

    /**
     * \brief The subscription pipe used to monitor local subscriptions.
     */
    CFE_SB_PipeId_t SubPipe;

    /**
     * \brief The command pipe used to receive commands.
     */
    CFE_SB_PipeId_t CmdPipe;

    /**
     * \brief All subscriptions by apps connected to the SB.
     *
     * When a peer and I connect, I send that peer all subscriptions I have
     * and they send me theirs. All messages on the local bus that are
     * subscribed to by the peer are sent over, and vice-versa.
     */
    SBN_Subs_t LocalSubs[SBN_MAX_SUBS_PER_PEER + 1];

    /** \brief CFE scheduling pipe */
    CFE_SB_PipeId_t SchPipe;

    /**
     * Each SBN back-end module provides a number of functions to
     * implement the protocols to connect peers.
     */
    SBN_IfOps_t *IfOps[SBN_MAX_INTERFACE_TYPES];

    /**
     * Retain the module ID's for each interface.
     */
    uint32 ModuleIDs[SBN_MAX_INTERFACE_TYPES];

    /** \brief Housekeeping information. */
    SBN_HkPacket_t Hk;

    CFE_TBL_Handle_t RemapTableHandle;
    SBN_RemapTable_t *RemapTable;
    SBN_RemapCache_t RemapCache;

    CFE_TBL_Handle_t ProtobetterTableHandle;
    SBN_ProtoBetterEntry_t *ProtoBetterTable;
    SBN_ProtobetterCache_t ProtoCache;


#ifdef SBN_SEND_TASK

    /** Global mutex for Send Tasks. */
    uint32 SendMutex;

#endif

} SBN_App_t;

/**
 * \brief SBN glocal data structure references, indexed by AppId.
 */
extern SBN_App_t SBN;

/*
** Prototypes
*/
void SBN_AppMain(void);
void SBN_ProcessNetMsg(SBN_NetInterface_t *Net, SBN_MsgType_t MsgType,
    SBN_CpuID_t CpuID, SBN_MsgSize_t MsgSize, void *Msg);
SBN_PeerInterface_t *SBN_GetPeer(SBN_NetInterface_t *Net, uint32 ProcessorID);

void SetPeerPipeSubscribes(SBN_NetInterface_t *Net);

#endif /* _sbn_app_ */
/*****************************************************************************/
