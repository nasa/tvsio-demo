/* Created : Thu Nov 29 16:11:02 CST 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): ACAWS_DE_DiagData_t, CCSDS_TLM_HDR, CCSDS_Primary, TEAMS_health_t, ACAWS_DE_ImpactReq_t, TEAMS_failure_t */

#ifndef _ACAWS_DE_TYPES_H_
#define _ACAWS_DE_TYPES_H_

#include "shared_types.h"
///* @file */
#include "acaws_model_config.h"

/* Constants for Reasoner_t */
#define  TEAMS 0
#define  HYDE  1
/* Constants for Certainty_t */
#define  CONFIRMED 0
#define  POSSIBLY  1



#ifdef __cplusplus
extern "C" {
#endif
/** Structure TEAMS_failure_t (4 bytes in size)  **/
typedef struct
{
  uint16_t failure_index;                                      ///< [    0] (2 bytes)  
  uint16_t failure_certainty;                                  ///< [    2] (2 bytes)  change to Certainty_t
} TEAMS_failure_t;     ///<  Total size of 4 bytes

/** Structure TEAMS_health_t (2 bytes in size)  **/
typedef struct
{
  uint16_t unknown:1;                                    /* */ ///< [    0]   
  uint16_t bad:1;                                              ///< [    0]   
  uint16_t suspect:1;                                          ///< [    0]   
  uint16_t minimal:1;                                          ///< [    0]   
  uint16_t residual:1;                                         ///< [    0]   
  uint16_t minimal_group:10;                                   ///< [    0]   
  uint16_t minimal_group_ovrflw:1;                             ///< [    0]   
} TEAMS_health_t;     ///<  Total size of 2 bytes

/** Structure ACAWS_DE_DiagData_t (336 bytes in size)  **/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                     ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t source_id;                                          ///< [   16] (2 bytes)  change data type to Reasoner_t
  uint16_t session_id;                                         ///< [   18] (2 bytes)  
  uint16_t unique_instance_id;                                 ///< [   20] (2 bytes)  
  uint16_t aspect_count;                                       ///< [   22] (2 bytes)  
  TEAMS_health_t aspect_diag[DIAG_MAX_ELEM_SIZE];              ///< [   24] (DIAG_MAX_ELEM_SIZE x 2=312 bytes)  
} ACAWS_DE_DiagData_t;     ///<  Total size of 336 bytes

/** Structure ACAWS_DE_ImpactReq_t (54 bytes in size)  *
* impact request message from "diag Exec" of ACAWS
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                     ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t mode_aware;                                         ///< [   16] (2 bytes)  
  uint16_t unique_instance_id;                                 ///< [   18] (2 bytes)  
  uint16_t failure_list_cnt;                                   ///< [   20] (2 bytes)  
  TEAMS_failure_t failure_list[DIAG_MAX_IMPACT_REQ_SIZE];      ///< [   22] (DIAG_MAX_IMPACT_REQ_SIZE x 4=32 bytes)  
} ACAWS_DE_ImpactReq_t;     ///<  Total size of 54 bytes

void byteswap_ACAWS_DE_ImpactReq_t(ACAWS_DE_ImpactReq_t *inPtr, ACAWS_DE_ImpactReq_t *outPtr, int direction);
void bitswap_ACAWS_DE_ImpactReq_t(ACAWS_DE_ImpactReq_t *inPtr, ACAWS_DE_ImpactReq_t *outPtr, int direction);
void byteswap_ACAWS_DE_DiagData_t(ACAWS_DE_DiagData_t *inPtr, ACAWS_DE_DiagData_t *outPtr, int direction);
void bitswap_ACAWS_DE_DiagData_t(ACAWS_DE_DiagData_t *inPtr, ACAWS_DE_DiagData_t *outPtr, int direction);
void byteswap_TEAMS_health_t(TEAMS_health_t *inPtr, TEAMS_health_t *outPtr, int direction);
void bitswap_TEAMS_health_t(TEAMS_health_t *inPtr, TEAMS_health_t *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void byteswap_TEAMS_failure_t(TEAMS_failure_t *inPtr, TEAMS_failure_t *outPtr, int direction);
void bitswap_TEAMS_failure_t(TEAMS_failure_t *inPtr, TEAMS_failure_t *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _ACAWS_DE_TYPES_H_
