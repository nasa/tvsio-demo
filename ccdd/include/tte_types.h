/* Created : Mon Aug 13 16:21:52 CDT 2018
   User    : rhirsh
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): TTE_DiagPacket_t, CCSDS_TLM_HDR, CCSDS_Primary, TTE_PortInfo_t, TTE_HkPacket_t */

#ifndef _TTE_TYPES_H_
#define _TTE_TYPES_H_

#include "shared_types.h"
///* @file */
/*
** Public Defines
*/
/**
** \brief Define the maximum possible command message size (in bytes).
**
** \par Description:
** This definition must be set to the size of the largest possible software bus
** message that the application may receive and is able to successfully process.
** It may be used to size buffers used to process command messages.
*/
#define TTE_MAX_CMD_MSG_SIZE TTE_MSG_SIZE_NOARGS_CMD /**< \brief Maximum size */
#define TTE_DATAPORT_COUNT_MAX 32
/**
** \brief Specifies the size of all serialized software bus messages.
**
** \par Description:
** This enum contains the size of each message with all non-explicit padding
** removed. These values may be used to size buffers used for processing each
** respective message, and to verify that structure packing was performed
** correctly at compile time.
*/
enum {
/** \brief Packed size of #TTE_NoArgsCmd_t */
TTE_MSG_SIZE_NOARGS_CMD  = 8,
/** \brief Packed size of #TTE_HkPacket_t */
TTE_MSG_SIZE_HK_PACKET   = 20,
/** \brief Packed size of #TTE_DiagPacket_t */
TTE_MSG_SIZE_DIAG_PACKET = (12 + (200 * TTE_DATAPORT_COUNT_MAX))
};


#ifdef __cplusplus
extern "C" {
#endif
/** Structure TTE_PortInfo_t (200 bytes in size)  *
* port info packet from tte monitoring application "tte"
*/
typedef struct
{
  char port_name[48];                                ///< [    0] (48x1=48 bytes)  Name identifying the dataport
  char port_dir[16];                                 ///< [   48] (16x1=16 bytes)  Direction of the dataport
  char port_type[16];                                ///< [   64] (16x1=16 bytes)  Type of the dataport
  char port_mode[16];                                ///< [   80] (16x1=16 bytes)  Mode of the dataport
  char task_name[32];                                ///< [   96] (32x1=32 bytes)  Name of task which owns dataport
  uint32_t sent_msgs;                                ///< [  128] (4 bytes)  Count of messages sent successfully
  uint32_t recv_msgs;                                ///< [  132] (4 bytes)  Count of messages received successfully
  uint32_t sent_msgs_err;                            ///< [  136] (4 bytes)  Count of messages transmission errors
  uint32_t recv_msgs_err;                            ///< [  140] (4 bytes)  Count of messages reception errors
  uint32_t recv_channel;                             ///< [  144] (4 bytes)  Channel where last message was received
  uint32_t recv_drops;                               ///< [  148] (4 bytes)  Count of messages dropped from full buffer
  char time_sent[24];                                ///< [  152] (24x1=24 bytes)  Timestamp when last message sent
  char time_recv[24];                                ///< [  176] (24x1=24 bytes)  Timestamp when last message received
} TTE_PortInfo_t;     ///<  Total size of 200 bytes

/** Structure TTE_DiagPacket_t (6416 bytes in size)  **/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                           ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  TTE_PortInfo_t ports[TTE_DATAPORT_COUNT_MAX];      ///< [   16] (TTE_DATAPORT_COUNT_MAX x 200=6400 bytes)  each entry in the array contains detailed information about an avaiable TTE dataport
} TTE_DiagPacket_t;     ///<  Total size of 6416 bytes

/** Structure TTE_HkPacket_t (24 bytes in size)  *
* hk packet from tte monitoring application "tte"
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                           ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint32_t app_state;                                ///< [   16] (4 bytes)  Application state vector (host-order)
  uint16_t cmd_count;                                ///< [   20] (2 bytes)  Command execution counter (host-order)
  uint16_t cmd_err_count;                            ///< [   22] (2 bytes)  Command error counter (host-order)
} TTE_HkPacket_t;     ///<  Total size of 24 bytes

void byteswap_TTE_HkPacket_t(TTE_HkPacket_t *inPtr, TTE_HkPacket_t *outPtr, int direction);
void bitswap_TTE_HkPacket_t(TTE_HkPacket_t *inPtr, TTE_HkPacket_t *outPtr, int direction);
void byteswap_TTE_DiagPacket_t(TTE_DiagPacket_t *inPtr, TTE_DiagPacket_t *outPtr, int direction);
void bitswap_TTE_DiagPacket_t(TTE_DiagPacket_t *inPtr, TTE_DiagPacket_t *outPtr, int direction);
void byteswap_TTE_PortInfo_t(TTE_PortInfo_t *inPtr, TTE_PortInfo_t *outPtr, int direction);
void bitswap_TTE_PortInfo_t(TTE_PortInfo_t *inPtr, TTE_PortInfo_t *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define TTE_NOOP_CC       0x0
#define TTE_RESET_CC      0x1
#define TTE_SEND_DIAG_CC  0x2

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  TTE_NOOP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TTE_NOOP_CC_t;

/**  TTE_RESET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TTE_RESET_CC_t;

/**  TTE_SEND_DIAG_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TTE_SEND_DIAG_CC_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _TTE_TYPES_H_
