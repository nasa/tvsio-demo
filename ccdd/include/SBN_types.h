/* Created : Mon Oct 29 09:53:04 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s):  */

#ifndef _SBN_TYPES_H_
#define _SBN_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define SBN_NOOP_CC         0x0
#define SBN_RESET_CC        0x1
#define SBN_RESET_PEER_CC   0x2
#define SBN_HK_CC           0xa
#define SBN_HK_NET_CC       0xb
#define SBN_HK_PEER_CC      0xc
#define SBN_HK_PEERSUBS_CC  0xd
#define SBN_HK_MYSUBS_CC    0xe
#define SBN_WAKEUP_CC       0x0

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  SBN_NOOP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SBN_NOOP_CC_t;

/**  SBN_RESET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SBN_RESET_CC_t;

/**  SBN_RESET_PEER_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t NetIdx;
 uint8_t PeerIdx;
}SBN_RESET_PEER_CC_t;

/**  SBN_HK_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SBN_HK_CC_t;

/**  SBN_HK_NET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t NetIdx;
}SBN_HK_NET_CC_t;

/**  SBN_HK_PEER_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t NetIdx;
 uint8_t PeerIdx;
}SBN_HK_PEER_CC_t;

/**  SBN_HK_PEERSUBS_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t NetIdx;
 uint8_t PeerIdx;
}SBN_HK_PEERSUBS_CC_t;

/**  SBN_HK_MYSUBS_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SBN_HK_MYSUBS_CC_t;

/**  SBN_WAKEUP_CC : Wakeup**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SBN_WAKEUP_CC_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _SBN_TYPES_H_
