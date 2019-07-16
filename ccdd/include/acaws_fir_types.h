/* Created : Thu Nov 29 16:11:07 CST 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): ACAWS_FIR_HkTlm_t, CCSDS_TLM_HDR, CCSDS_Primary, ACAWS_FIR_OutData_t, ACAWS_FIR_ImpactType_t */

#ifndef _ACAWS_FIR_TYPES_H_
#define _ACAWS_FIR_TYPES_H_

#include "shared_types.h"
///* @file */

#include "acaws_de_types.h"
#include "acaws_model_config.h"



#ifdef __cplusplus
extern "C" {
#endif
/** Structure ACAWS_FIR_ImpactType_t (1 bytes in size)  *
* // The fixed width integer bitfields are a GCC extension, ISO C99 only
  // allows for int, unsigned int. We are using them to have a better
  // correspondence between the struct and serialized formats.
*/
typedef struct
{
  uint8_t noImpact:1;                                         /* */ ///< [    0]   
  uint8_t lor:1;                                                    ///< [    0]   
  uint8_t func:1;                                                   ///< [    0]   
  uint8_t pad:5;                                                    ///< [    0]   
} ACAWS_FIR_ImpactType_t;     ///<  Total size of 1 bytes

/** Structure ACAWS_FIR_HkTlm_t (20 bytes in size)  *
* hk tlm message from "FIR" of ACAWS
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                          ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t usCmdCnt;                                                ///< [   16] (2 bytes)  
  uint16_t usCmdErrCnt;                                             ///< [   18] (2 bytes)  
} ACAWS_FIR_HkTlm_t;     ///<  Total size of 20 bytes

/** Structure ACAWS_FIR_OutData_t (119 bytes in size)  *
* out data of "FIR" of ACAWS
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                          ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t unique_instance_id;                                      ///< [   16] (2 bytes)  
  uint16_t failure_list_cnt;                                        ///< [   18] (2 bytes)  
  uint16_t acaws_fir_effects_cnt;                                   ///< [   20] (2 bytes)  
  ACAWS_FIR_ImpactType_t acaws_fir_effects[FIR_MAX_ELEM_SIZE];      ///< [   22] (FIR_MAX_ELEM_SIZE x 1=97 bytes)  
} ACAWS_FIR_OutData_t;     ///<  Total size of 119 bytes

void byteswap_ACAWS_FIR_OutData_t(ACAWS_FIR_OutData_t *inPtr, ACAWS_FIR_OutData_t *outPtr, int direction);
void bitswap_ACAWS_FIR_OutData_t(ACAWS_FIR_OutData_t *inPtr, ACAWS_FIR_OutData_t *outPtr, int direction);
void byteswap_ACAWS_FIR_HkTlm_t(ACAWS_FIR_HkTlm_t *inPtr, ACAWS_FIR_HkTlm_t *outPtr, int direction);
void bitswap_ACAWS_FIR_HkTlm_t(ACAWS_FIR_HkTlm_t *inPtr, ACAWS_FIR_HkTlm_t *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void byteswap_ACAWS_FIR_ImpactType_t(ACAWS_FIR_ImpactType_t *inPtr, ACAWS_FIR_ImpactType_t *outPtr, int direction);
void bitswap_ACAWS_FIR_ImpactType_t(ACAWS_FIR_ImpactType_t *inPtr, ACAWS_FIR_ImpactType_t *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _ACAWS_FIR_TYPES_H_
