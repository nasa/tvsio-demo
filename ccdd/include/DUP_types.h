/* Created : Mon Aug 13 15:56:02 CDT 2018
   User    : rhirsh
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): DUP_HkTlm_t, CCSDS_TLM_HDR, CCSDS_Primary */

#ifndef _DUP_TYPES_H_
#define _DUP_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure DUP_HkTlm_t (20 bytes in size)  *
* hk tlm message for the DUP Application
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t usCmdCnt;                          ///< [   16] (2 bytes)  
  uint16_t usCmdErrCnt;                       ///< [   18] (2 bytes)  
} DUP_HkTlm_t;     ///<  Total size of 20 bytes

void byteswap_DUP_HkTlm_t(DUP_HkTlm_t *inPtr, DUP_HkTlm_t *outPtr, int direction);
void bitswap_DUP_HkTlm_t(DUP_HkTlm_t *inPtr, DUP_HkTlm_t *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define DUP_NOOP_CC     0x0
#define DUP_PROCESS_CC  0x1
#define DUP_ADD_CC      0x2
#define DUP_DEL_CC      0x3
#define DUP_HK_CC       0x4

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  DUP_NOOP_CC : does nothing**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}DUP_NOOP_CC_t;

/**  DUP_PROCESS_CC : processes all duplications configured**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}DUP_PROCESS_CC_t;

/**  DUP_ADD_CC : technically, "set", as it will override an existing configuration**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t MID;
 uint16_t DupMID;
 uint8_t DropPct;
 uint8_t ExtraPct;
 uint8_t SizeErrPct;
 uint8_t DataCorruptErrPct;
}DUP_ADD_CC_t;

/**  DUP_DEL_CC : removes a duplication configured**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}DUP_DEL_CC_t;

/**  DUP_HK_CC : requests housekeeping be sent**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}DUP_HK_CC_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _DUP_TYPES_H_
