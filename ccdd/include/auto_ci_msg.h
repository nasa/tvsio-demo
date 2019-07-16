/* Created : Tue May 07 15:25:41 CDT 2019
   User    : aes
   Project : cert_cfs
   Script  : /home/tngo/AES_workspace/js-er-code/aes_ccdd/scripts/CCSDS_V2_Msgs.js
   Group(s): ci_msg
*/

#ifndef _auto_ci_msg_h_
#define _auto_ci_msg_h_

/* Top Includes */
#include "cfe.h"
#include "auto_to_msg.h"

/* Structure: CI_HkTlm_t (20 bytes total) */
typedef struct
{
   uint8 ucTlmHeader[CFE_SB_TLM_HDR_SIZE]; /* [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes) */
   uint16 usCmdCnt;        /* [   16] (2 bytes)  Count of valid commands received */
   uint16 usCmdErrCnt;     /* [   18] (2 bytes)  Count of command errors */
} CI_HkTlm_t;              /* Total size of 20 bytes */

/* Structure: CI_NoArgCmd_t (12 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
} CI_NoArgCmd_t;           /* Total size of 12 bytes */

/* Structure: CI_OutData_t (16 bytes total) */
typedef struct
{
   uint8 ucTlmHeader[CFE_SB_TLM_HDR_SIZE]; /* [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes) */
} CI_OutData_t;            /* Total size of 16 bytes */

/* TypeDefs */
typedef TO_EnableOutputCmd_t                CI_EnableTOCmd_t;
/* Bottom Includes */

#endif /* #ifndef _auto_ci_msg_h_ */

