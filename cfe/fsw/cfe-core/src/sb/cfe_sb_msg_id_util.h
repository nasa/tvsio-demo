/******************************************************************************
** File: cfe_sb_msg_id_util.h
**
**      Copyright (c) 2004-2012, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA's Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used,
**      distributed and modified only pursuant to the terms of that agreement.
**
**
**
** Purpose:
**      This header file contains prototypes for private functions and type
**      definitions for SB internal use.
**
** Author:   J. Wilmot/NASA
**
** $Log: cfe_sb_priv.h  $
**
******************************************************************************/

#ifndef _cfe_sb_msg_id_util_
#define _cfe_sb_msg_id_util_

/*
** Includes
*/
#include "common_types.h"

/**
**      For MESSAGE_FORMAT_IS_CCSDS_VER_2 the default layout of the message id is:
**       7 bits from the primary header APID
**       1 bit for the command/telemetry flag 
**       0 bits from the Playback flag
**       8 bits from the secondary header APID qualifier (Subsystem)
**       0 bits from the secondary header APID qualifier as the System
**    = 16 bits total 
**     
**                  Byte 1              Byte 0
**            7 6 5 4 3 2 1 0     7      6 5 4 3 2 1 0
**           +-+-+-+-+-+-+-+-+|--------|+-+-+-+-+-+-+-+
**           | APID Qualifier |C/T flg | Pri Hdr APID |
**           +-+-+-+-+-+-+-+-+|--------|+-+-+-+-+-+-+-+
**   This layout may be modified via the 4 macros
**   CFE_SB_CMD_MESSAGE_TYPE, CFE_SB_RD_APID_FROM_MSGID
**   CFE_SB_RD_SUBSYS_ID_FROM_MSGID and CFE_SB_RD_TYPE_FROM_MSGID
**   
*/

/*
** Macro Definitions
*/

/* 
 * Mission defined bit used to indicate message is a command type. A 0 in this bit position indicates 
 * a telemetry message type. This bit is included in the message id.
 */
#define CFE_SB_APID_COMPONENT          0x000001FF  /* 0-8(9) bits for Pri Hdr APID */
#define CFE_SB_APID_OFFSET                      0
#define CFE_SB_TYPE_COMPONENT          0x00008000  /* 1 Cmd/Tlm Bit (bit #15) */
#define CFE_SB_TYPE_OFFSET                     15
#define CFE_SB_SUBSYS_COMPONENT        0x00007E00  /* bits 9-14(6) bits for APID Subsystem ID */
#define CFE_SB_SUBSYS_OFFSET                    9
#define CFE_SB_SYSTEM_COMPONENT        0x00000000
#define CFE_SB_SYSTEM_OFFSET                   16

/* 
 * Mission defined macros to extract message id fields from the  primary and secondary headers
*/
#define CFE_SB_WR_MSGID_FROM_APID(ApidId)            ((ApidId << CFE_SB_APID_OFFSET) & CFE_SB_APID_COMPONENT)
#define CFE_SB_WR_MSGID_FROM_SUBSYS_ID(SubSystemId)  ((SubSystemId << CFE_SB_SUBSYS_OFFSET) & CFE_SB_SUBSYS_COMPONENT)
#define CFE_SB_WR_MSGID_FROM_SYSTEM_ID(SystemId)     ((SystemId << CFE_SB_SYSTEM_OFFSET) & CFE_SB_SYSTEM_COMPONENT)
#define CFE_SB_WR_MSGID_FROM_TYPE(Type)              ((Type << CFE_SB_TYPE_OFFSET) & CFE_SB_TYPE_COMPONENT)

#define CFE_SB_RD_APID_FROM_MSGID(MsgId)       ((MsgId & CFE_SB_APID_COMPONENT) >> CFE_SB_APID_OFFSET)
#define CFE_SB_RD_SUBSYS_ID_FROM_MSGID(MsgId)  ((MsgId & CFE_SB_SUBSYS_COMPONENT) >> CFE_SB_SUBSYS_OFFSET)
#define CFE_SB_RD_SYSTEM_ID_FROM_MSGID(MsgId)  ((MsgId & CFE_SB_SYSTEM_COMPONENT) >> CFE_SB_SYSTEM_OFFSET)
#define CFE_SB_RD_TYPE_FROM_MSGID(MsgId)       ((MsgId & CFE_SB_TYPE_COMPONENT) >> CFE_SB_TYPE_OFFSET)

#endif /* _cfe_sb_msg_id_util_ */
/*****************************************************************************/
