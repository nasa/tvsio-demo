/* Created : Mon Oct 29 09:53:04 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s):  */

#ifndef _SCH_TT_TYPES_H_
#define _SCH_TT_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define SCH_TT_NOOP_CC           0x0
#define SCH_TT_RESET_CC          0x1
#define SCH_TT_ENABLE_ENTRY_CC   0x2
#define SCH_TT_DISABLE_ENTRY_CC  0x3
#define SCH_TT_ENABLE_GROUP_CC   0x4
#define SCH_TT_DISABLE_GROUP_CC  0x5
#define SCH_TT_MODE_ENABLE_CC    0x6
#define SCH_TT_MODE_DISABLE_CC   0x7

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  SCH_TT_NOOP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SCH_TT_NOOP_CC_t;

/**  SCH_TT_RESET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SCH_TT_RESET_CC_t;

/**  SCH_TT_ENABLE_ENTRY_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SCH_TT_ENABLE_ENTRY_CC_t;

/**  SCH_TT_DISABLE_ENTRY_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SCH_TT_DISABLE_ENTRY_CC_t;

/**  SCH_TT_ENABLE_GROUP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SCH_TT_ENABLE_GROUP_CC_t;

/**  SCH_TT_DISABLE_GROUP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SCH_TT_DISABLE_GROUP_CC_t;

/**  SCH_TT_MODE_ENABLE_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SCH_TT_MODE_ENABLE_CC_t;

/**  SCH_TT_MODE_DISABLE_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SCH_TT_MODE_DISABLE_CC_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _SCH_TT_TYPES_H_
