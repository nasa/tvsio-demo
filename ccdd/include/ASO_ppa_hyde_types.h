/* Created : Tue Jul 17 07:08:43 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): PPA_HYDE_HkTlm_t, CCSDS_TLM_HDR, CCSDS_Primary, PPA_HYDE_OutData_t, hyde_out_t */

#ifndef _ASO_PPA_HYDE_TYPES_H_
#define _ASO_PPA_HYDE_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure hyde_out_t (11 bytes in size)  **/
typedef struct
{
  uint8_t isFaultless;                        ///< [    0] (1 bytes)  
  uint16_t candidateCount;                    ///< [    1] (2 bytes)  
  char fault[8];                              ///< [    3] (8x1=8 bytes)  
} hyde_out_t;     ///<  Total size of 11 bytes

/** Structure PPA_HYDE_HkTlm_t (20 bytes in size)  *
* hk tlm msg from ppaHyde - specified by M. Scott 8/23/17
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t usCmdCnt;                          ///< [   16] (2 bytes)  
  uint16_t usCmdErrCnt;                       ///< [   18] (2 bytes)  
} PPA_HYDE_HkTlm_t;     ///<  Total size of 20 bytes

/** Structure PPA_HYDE_OutData_t (31 bytes in size)  *
* fault diagnosis message from ppaHyde
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint32_t uiCounter;                         ///< [   16] (4 bytes)  
  hyde_out_t hyde_out;                        ///< [   20] (11 bytes)  
} PPA_HYDE_OutData_t;     ///<  Total size of 31 bytes

void byteswap_PPA_HYDE_OutData_t(PPA_HYDE_OutData_t *inPtr, PPA_HYDE_OutData_t *outPtr, int direction);
void bitswap_PPA_HYDE_OutData_t(PPA_HYDE_OutData_t *inPtr, PPA_HYDE_OutData_t *outPtr, int direction);
void byteswap_PPA_HYDE_HkTlm_t(PPA_HYDE_HkTlm_t *inPtr, PPA_HYDE_HkTlm_t *outPtr, int direction);
void bitswap_PPA_HYDE_HkTlm_t(PPA_HYDE_HkTlm_t *inPtr, PPA_HYDE_HkTlm_t *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void byteswap_hyde_out_t(hyde_out_t *inPtr, hyde_out_t *outPtr, int direction);
void bitswap_hyde_out_t(hyde_out_t *inPtr, hyde_out_t *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _ASO_PPA_HYDE_TYPES_H_
