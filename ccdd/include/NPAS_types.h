/* Created : Thu Nov 29 16:11:00 CST 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): NPAS_AV_OUT, CCSDS_TLM_HDR, CCSDS_Primary, NPAS_PWR_OUT, NPAS_VM_OUT */

#ifndef _NPAS_TYPES_H_
#define _NPAS_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure NPAS_AV_OUT (24 bytes in size)  *
* NPAS avionics status message
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  int32_t timestamp;                          ///< [   16] (4 bytes)  The UNIX time the status_code was evaluated
  int32_t status_code;                        ///< [   20] (4 bytes)  NPAS status code. 0 = nominal, 1 = degraded, 2 = failed
} NPAS_AV_OUT;     ///<  Total size of 24 bytes

/** Structure NPAS_PWR_OUT (24 bytes in size)  *
* NPAS power status message
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  int32_t timestamp;                          ///< [   16] (4 bytes)  The UNIX time the status_code was evaluated
  int32_t status_code;                        ///< [   20] (4 bytes)  NPAS status code. 0 = nominal, 1 = degraded, 2 = failed
} NPAS_PWR_OUT;     ///<  Total size of 24 bytes

/** Structure NPAS_VM_OUT (24 bytes in size)  *
* NPAS Vehicle manager status message
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  int32_t timestamp;                          ///< [   16] (4 bytes)  The UNIX time the status_code was evaluated
  int32_t status_code;                        ///< [   20] (4 bytes)  NPAS status code. 0 = nominal, 1 = degraded, 2 = failed
} NPAS_VM_OUT;     ///<  Total size of 24 bytes

void byteswap_NPAS_VM_OUT(NPAS_VM_OUT *inPtr, NPAS_VM_OUT *outPtr, int direction);
void bitswap_NPAS_VM_OUT(NPAS_VM_OUT *inPtr, NPAS_VM_OUT *outPtr, int direction);
void byteswap_NPAS_PWR_OUT(NPAS_PWR_OUT *inPtr, NPAS_PWR_OUT *outPtr, int direction);
void bitswap_NPAS_PWR_OUT(NPAS_PWR_OUT *inPtr, NPAS_PWR_OUT *outPtr, int direction);
void byteswap_NPAS_AV_OUT(NPAS_AV_OUT *inPtr, NPAS_AV_OUT *outPtr, int direction);
void bitswap_NPAS_AV_OUT(NPAS_AV_OUT *inPtr, NPAS_AV_OUT *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _NPAS_TYPES_H_
