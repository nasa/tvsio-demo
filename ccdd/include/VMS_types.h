/* Created : Tue Jul 17 07:08:42 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): loadSchedule, CCSDS_TLM_HDR, CCSDS_Primary, loadScheduleRow, request_energy */

#ifndef _VMS_TYPES_H_
#define _VMS_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure loadScheduleRow (112 bytes in size)  *
* Vehicle manager defined load schedule entry
*/
typedef struct
{
  int32_t component[2];                       ///< [    0] (2x4=8 bytes)  PDU/RPC index
  double nominalPower;                        ///< [    8] (8 bytes)  
  int32_t priority[24];                       ///< [   16] (24x4=96 bytes)  priority for each time unit
} loadScheduleRow;     ///<  Total size of 112 bytes

/** Structure loadSchedule (1808 bytes in size)  *
* VM to APC load schedule including priority(s)
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  loadScheduleRow loadSched[16];              ///< [   16] (16x112=1792 bytes)  load schedule for each RPC of each PDU
} loadSchedule;     ///<  Total size of 1808 bytes

/** Structure request_energy (17 bytes in size)  *
* request flag sent by VMS to APC, requesting an energy availability message
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint8_t request_energy;                     ///< [   16] (1 bytes)  request energy flag, set to 1 when an energy availability message is desired from APC
} request_energy;     ///<  Total size of 17 bytes

void byteswap_request_energy(request_energy *inPtr, request_energy *outPtr, int direction);
void bitswap_request_energy(request_energy *inPtr, request_energy *outPtr, int direction);
void byteswap_loadSchedule(loadSchedule *inPtr, loadSchedule *outPtr, int direction);
void bitswap_loadSchedule(loadSchedule *inPtr, loadSchedule *outPtr, int direction);
void byteswap_loadScheduleRow(loadScheduleRow *inPtr, loadScheduleRow *outPtr, int direction);
void bitswap_loadScheduleRow(loadScheduleRow *inPtr, loadScheduleRow *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _VMS_TYPES_H_
