/* Created : Tue Jul 17 07:08:44 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): L1V_HAB_VOTE, CCSDS_TLM_HDR, CCSDS_Primary */

#ifndef _L1V_TYPES_H_
#define _L1V_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure L1V_HAB_VOTE (20 bytes in size)  *
* L1V "voter app" that remediates three input messages into one output message
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  int32_t tbd;                                ///< [   16] (4 bytes)  
} L1V_HAB_VOTE;     ///<  Total size of 20 bytes

void byteswap_L1V_HAB_VOTE(L1V_HAB_VOTE *inPtr, L1V_HAB_VOTE *outPtr, int direction);
void bitswap_L1V_HAB_VOTE(L1V_HAB_VOTE *inPtr, L1V_HAB_VOTE *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _L1V_TYPES_H_
