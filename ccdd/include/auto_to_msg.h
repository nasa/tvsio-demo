/* Created : Tue May 07 15:25:37 CDT 2019
   User    : aes
   Project : cert_cfs
   Script  : /home/tngo/AES_workspace/js-er-code/aes_ccdd/scripts/CCSDS_V2_Msgs.js
   Group(s): to_msg
*/

#ifndef _auto_to_msg_h_
#define _auto_to_msg_h_

/* Top Includes */
#include "cfe.h"

#define TO_MAX_IP_STRING_SIZE  16


/* Structure: TO_AddTblEntryCmd_t (30 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   CFE_SB_MsgId_t usMsgId;  /* [   12] (4 bytes)  Message ID (must be unique) */
   CFE_SB_Qos_t qos;        /* [   16] (2 bytes)  Quality of Service flag */
   uint16 usMsgLimit;       /* [   18] (2 bytes)  Max Num of this Msgs in pipe */
   uint16 usRouteMask;      /* [   20] (2 bytes)  Bitwize Route Mask */
   uint32 uiGroupData;      /* [   22] (4 bytes)  Group Data Mask */
   uint16 usFlag;           /* [   26] (2 bytes)  Custom defined flag */
   uint16 usState;          /* [   28] (2 bytes)  Message ID is enabled=1 */
} TO_AddTblEntryCmd_t;      /* Total size of 30 bytes */

/* Structure: TO_EnableOutputCmd_t (30 bytes total) */
typedef struct
{
   uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   char cDestIp[TO_MAX_IP_STRING_SIZE]; /* [   12] (##TO_MAX_IP_STRING_SIZE##x1=NaN bytes) */
   uint16 usDestPort;    /* [   28] (2 bytes) */
} TO_EnableOutputCmd_t;  /* Total size of 30 bytes */

/* Structure: TO_GroupArgCmd_t (16 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   uint32 uiGroupData;     /* [   12] (4 bytes) */
} TO_GroupArgCmd_t;        /* Total size of 16 bytes */

/* Structure: TO_HkTlm_t (32 bytes total) */
typedef struct
{
   uint8 ucTlmHeader[CFE_SB_TLM_HDR_SIZE]; /* [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes) */
   uint16 usCmdCnt;         /* [   16] (2 bytes)  Count of all commands received */
   uint16 usCmdErrCnt;      /* [   18] (2 bytes)  Count of command errors */
   uint16 usMsgSubCnt;      /* [   20] (2 bytes)  Count of subscribed messages by all telemetry pipe. */
   uint16 usMsgSubErrCnt;   /* [   22] (2 bytes)  Count of subscription errors */
   uint16 usTblUpdateCnt;   /* [   24] (2 bytes)  Count of table updates through CFE_TBL */
   uint16 usTblErrCnt;      /* [   26] (2 bytes)  Count of table update errors */
   uint16 usConfigRoutes;   /* [   28] (2 bytes)  Current mask of configured routes */
   uint16 usEnabledRoutes;  /* [   30] (2 bytes)  Current mask of enabled routes */
} TO_HkTlm_t;               /* Total size of 32 bytes */

/* Structure: TO_MidArgCmd_t (16 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   CFE_SB_MsgId_t usMsgId;  /* [   12] (4 bytes) */
} TO_MidArgCmd_t;           /* Total size of 16 bytes */

/* Structure: TO_NoArgCmd_t (12 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
} TO_NoArgCmd_t;           /* Total size of 12 bytes */

/* Structure: TO_OutData_t (20 bytes total) */
typedef struct
{
   uint8 ucTlmHeader[CFE_SB_TLM_HDR_SIZE]; /* [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes) */
   uint32 uiCounter;       /* [   16] (4 bytes) */
} TO_OutData_t;            /* Total size of 20 bytes */

/* Structure: TO_RouteMaskArgCmd_t (14 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   uint16 usRouteMask;     /* [   12] (2 bytes) */
} TO_RouteMaskArgCmd_t;    /* Total size of 14 bytes */

/* Structure: TO_SetRouteByGroupCmd_t (20 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   uint32 uiGroupData;      /* [   12] (4 bytes) */
   uint16 usRouteMask;      /* [   16] (2 bytes) */
   uint16 spare;            /* [   18] (2 bytes) */
} TO_SetRouteByGroupCmd_t;  /* Total size of 20 bytes */

/* Structure: TO_SetRouteByMidCmd_t (18 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   CFE_SB_MsgId_t usMsgId;  /* [   12] (4 bytes) */
   uint16 usRouteMask;      /* [   16] (2 bytes) */
} TO_SetRouteByMidCmd_t;    /* Total size of 18 bytes */

/* Structure: TO_SetRoutePeriodCmd_t (16 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   uint16 usRouteMask;     /* [   12] (2 bytes) */
   uint16 usWakePeriod;    /* [   14] (2 bytes) */
} TO_SetRoutePeriodCmd_t;  /* Total size of 16 bytes */

/* Structure: TO_SetWakeupTimeoutCmd_t (16 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
   uint32 uiWakeupTimeout;   /* [   12] (4 bytes) */
} TO_SetWakeupTimeoutCmd_t;  /* Total size of 16 bytes */

/* Structure: TO_TypeDefPacket_t (72 bytes total) */
typedef struct
{
   uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE]; /* [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes) */
   uint16 synch;         /* [   16] (2 bytes) */
   uint16 bit1:1;        /* [   18]  */
   uint16 bit2:1;        /* [   18]  */
   uint16 bit34:2;       /* [   18]  */
   uint16 bit56:2;       /* [   18]  */
   uint16 bit78:2;       /* [   18]  */
   uint16 nibble1:4;     /* [   18]  */
   uint16 nibble2:4;     /* [   18]  */
   uint8 bl1;            /* [   20] (1 bytes) */
   uint8 bl2;            /* [   21] (1 bytes) */
   int8 b1;              /* [   22] (1 bytes) */
   int8 b2;              /* [   23] (1 bytes) */
   int8 b3;              /* [   24] (1 bytes) */
   int8 b4;              /* [   25] (1 bytes) */
   int16 w1;             /* [   26] (2 bytes) */
   int16 w2;             /* [   28] (2 bytes) */
   int32 dw1;            /* [   30] (4 bytes) */
   int32 dw2;            /* [   34] (4 bytes) */
   float f1;             /* [   38] (4 bytes) */
   float f2;             /* [   42] (4 bytes) */
   double df1;           /* [   46] (8 bytes) */
   double df2;           /* [   54] (8 bytes) */
   char str[10];         /* [   62] (10x1=10 bytes) */
} TO_TypeDefPacket_t;    /* Total size of 72 bytes */

/* TypeDefs */
typedef TO_NoArgCmd_t                       TO_DisableOutputCmd_t;
/* Bottom Includes */

#endif /* #ifndef _auto_to_msg_h_ */

