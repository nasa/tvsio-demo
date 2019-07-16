/* Created : Thu Nov 29 16:11:06 CST 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): acaws_fd_test_results_type, CCSDS_TLM_HDR, CCSDS_Primary */

#ifndef _ACAWS_FD_TYPES_H_
#define _ACAWS_FD_TYPES_H_

#include "shared_types.h"
///* @file */
#include "acaws_model_config.h"
// Here are the values that our test results and switch modes can have.
// These are defined constants instead of an enum to save space, since they
// can fit into a byte. (An enum is the size of an int.)
#define  CFS_ACAWS_FD_TEST_PASS          0
#define  CFS_ACAWS_FD_TEST_FAIL          1
#define  CFS_ACAWS_FD_TEST_UNKNOWN       2
#define  CFS_ACAWS_FD_TEST_UNSET         3
#define  CFS_ACAWS_FD_SWITCH_ON          4
#define  CFS_ACAWS_FD_SWITCH_OFF         5
#define  CFS_ACAWS_FD_SWITCH_UNSET       6
#define  CFS_ACAWS_FD_ENUM_RESULT_COUNT  7
#define  CFS_ACAWS_FD_INVALID_ENUM_RESULT CFS_ACAWS_FD_ENUM_RESULT_COUNT



#ifdef __cplusplus
extern "C" {
#endif
/** Structure acaws_fd_test_results_type (164 bytes in size)  *
* test results message from "fd" of ACAWS
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                       ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t modes_on_count;                       ///< [   16] (2 bytes)  
  uint16_t test_results_count;                   ///< [   18] (2 bytes)  
  uint8_t modes_on[ACAWS_FD_MAX_MODES];          ///< [   20] (ACAWS_FD_MAX_MODES x 1=2 bytes)  change to acaws_mode_type
  uint8_t test_results[ACAWS_FD_MAX_TESTS];      ///< [   22] (ACAWS_FD_MAX_TESTS x 1=142 bytes)  change to acaws_fd_test_result_type
} acaws_fd_test_results_type;     ///<  Total size of 164 bytes

void byteswap_acaws_fd_test_results_type(acaws_fd_test_results_type *inPtr, acaws_fd_test_results_type *outPtr, int direction);
void bitswap_acaws_fd_test_results_type(acaws_fd_test_results_type *inPtr, acaws_fd_test_results_type *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define CFS_ACAWS_FD_WAKEUP_PROCESS  0x2
#define CFS_ACAWS_FD_WAKEUP_SEND     0x3

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  CFS_ACAWS_FD_WAKEUP_PROCESS : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}CFS_ACAWS_FD_WAKEUP_PROCESS_t;

/**  CFS_ACAWS_FD_WAKEUP_SEND : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}CFS_ACAWS_FD_WAKEUP_SEND_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _ACAWS_FD_TYPES_H_
