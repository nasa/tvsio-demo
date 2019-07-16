/* Created : Tue Nov 13 11:10:32 CST 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s):  */

#ifndef _MISC_TYPES_H_
#define _MISC_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define CI_NOOP_CC                   0x0
#define CI_RESET_CC                  0x1
#define CI_ENABLE_TO_CC              0x2
#define LC_NOOP_CC                   0x0
#define LC_RESET_CC                  0x1
#define LC_SET_LC_STATE_CC           0x2
#define LC_SET_AP_STATE_CC           0x3
#define LC_SET_AP_PERMOFF_CC         0x4
#define LC_RESET_AP_STATS_CC         0x5
#define LC_RESET_WP_STATS_CC         0x6
#define LC_RTS_REQ_AP_CC             0x0
#define LC_SEND_HK_CC                0x0
#define SIMPLE_COUNTER_NOOP_CC       0x0
#define SIMPLE_COUNTER_RESET_CC      0x1
#define SIMPLE_COUNTER_INCREMENT_CC  0x2
#define SIMPLE_COUNTER_SET_CC        0x3
#define LC_SAMPLE_AP_CC              0x0
#define TO_NOOP_CC                   0x0
#define TO_RESET_CC                  0x1
#define TO_ENABLE_OUTPUT_CC          0x2
#define TO_DISABLE_OUTPUT_CC         0x3
#define TO_PAUSE_OUTPUT_CC           0x4
#define TO_RESUME_OUTPUT_CC          0x5
#define TO_ADD_TBL_ENTRY_CC          0x6
#define TO_REMOVE_TBL_ENTRY_CC       0x7
#define TO_ENABLE_TBL_ENTRY_CC       0x8
#define TO_DISABLE_TBL_ENTRY_CC      0x9
#define TO_ENABLE_GROUP_CC           0xa
#define TO_DISABLE_GROUP_CC          0xb
#define TO_ENABLE_ALL_CC             0xc
#define TO_DISABLE_ALL_CC            0xd
#define TO_SET_ROUTE_BY_MID_CC       0xe
#define TO_SET_ROUTE_BY_GROUP_CC     0xf
#define TO_MANAGE_TABLE_CC           0x10
#define TO_ACTIVATE_ROUTES_CC        0x11
#define TO_DEACTIVATE_ROUTES_CC      0x12
#define TO_SET_ROUTE_PERIOD_CC       0x13
#define TO_SET_WAKEUP_TIMEOUT_CC     0x14

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  CI_NOOP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}CI_NOOP_CC_t;

/**  CI_RESET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}CI_RESET_CC_t;

/**  CI_ENABLE_TO_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 char cDestIp[16];
 uint16_t usDestPort;
}CI_ENABLE_TO_CC_t;

/**  LC_NOOP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}LC_NOOP_CC_t;

/**  LC_RESET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}LC_RESET_CC_t;

/**  LC_SET_LC_STATE_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t NewLCState;      ///<  New LC application state
 uint16_t Padding;
}LC_SET_LC_STATE_CC_t;

/**  LC_SET_AP_STATE_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t APNumber;      ///<  Which actionpoint(s) to change
 uint16_t NewAPState;
}LC_SET_AP_STATE_CC_t;

/**  LC_SET_AP_PERMOFF_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t APNumber;      ///<  Which actionpoint to change
 uint16_t Padding;
}LC_SET_AP_PERMOFF_CC_t;

/**  LC_RESET_AP_STATS_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t APNumber;      ///<  Which actionpoint(s) to change
 uint16_t Padding;
}LC_RESET_AP_STATS_CC_t;

/**  LC_RESET_WP_STATS_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t WPNumber;      ///<  Which watchpoint(s) to change
 uint16_t Padding;
}LC_RESET_WP_STATS_CC_t;

/**  LC_RTS_REQ_AP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t RTSId;      ///<  unknown
}LC_RTS_REQ_AP_CC_t;

/**  LC_SEND_HK_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}LC_SEND_HK_CC_t;

/**  SIMPLE_COUNTER_NOOP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SIMPLE_COUNTER_NOOP_CC_t;

/**  SIMPLE_COUNTER_RESET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SIMPLE_COUNTER_RESET_CC_t;

/**  SIMPLE_COUNTER_INCREMENT_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}SIMPLE_COUNTER_INCREMENT_CC_t;

/**  SIMPLE_COUNTER_SET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t counterValue;      ///<  new value to set counter to
}SIMPLE_COUNTER_SET_CC_t;

/**  LC_SAMPLE_AP_CC : does**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t StartIndex;      ///<  Which actionpoint(s) to sample
 uint16_t EndIndex;
 uint16_t UpdateAge;      ///<  Update WP results age (T or F)
}LC_SAMPLE_AP_CC_t;

/**  TO_NOOP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TO_NOOP_CC_t;

/**  TO_RESET_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TO_RESET_CC_t;

/**  TO_ENABLE_OUTPUT_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 char cDestIp[16];
 uint16_t usDestPort;
}TO_ENABLE_OUTPUT_CC_t;

/**  TO_DISABLE_OUTPUT_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TO_DISABLE_OUTPUT_CC_t;

/**  TO_PAUSE_OUTPUT_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TO_PAUSE_OUTPUT_CC_t;

/**  TO_RESUME_OUTPUT_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TO_RESUME_OUTPUT_CC_t;

/**  TO_ADD_TBL_ENTRY_CC : pending**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t usMsgId;
 uint16_t qos;
 uint16_t usMsgLimit;
 uint16_t usRouteMask;
 uint32_t uiGroupData;
 uint16_t usFlag;
 int16_t usState;
}TO_ADD_TBL_ENTRY_CC_t;

/**  TO_REMOVE_TBL_ENTRY_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t usMsgId;
}TO_REMOVE_TBL_ENTRY_CC_t;

/**  TO_ENABLE_TBL_ENTRY_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t usMsgId;
}TO_ENABLE_TBL_ENTRY_CC_t;

/**  TO_DISABLE_TBL_ENTRY_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t usMsgId;
}TO_DISABLE_TBL_ENTRY_CC_t;

/**  TO_ENABLE_GROUP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t uiGroupData;
}TO_ENABLE_GROUP_CC_t;

/**  TO_DISABLE_GROUP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t uiGroupData;
}TO_DISABLE_GROUP_CC_t;

/**  TO_ENABLE_ALL_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TO_ENABLE_ALL_CC_t;

/**  TO_DISABLE_ALL_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}TO_DISABLE_ALL_CC_t;

/**  TO_SET_ROUTE_BY_MID_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t usMsgId;
 uint16_t usRouteMask;
}TO_SET_ROUTE_BY_MID_CC_t;

/**  TO_SET_ROUTE_BY_GROUP_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint32_t uiGroupData;
 uint16_t usRouteMask;
 uint16_t spare;
}TO_SET_ROUTE_BY_GROUP_CC_t;

/**  TO_MANAGE_TABLE_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint32_t Parameter;
}TO_MANAGE_TABLE_CC_t;

/**  TO_ACTIVATE_ROUTES_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t usRouteMask;
}TO_ACTIVATE_ROUTES_CC_t;

/**  TO_DEACTIVATE_ROUTES_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t usRouteMask;
}TO_DEACTIVATE_ROUTES_CC_t;

/**  TO_SET_ROUTE_PERIOD_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint16_t usRouteMask;
 uint16_t usWakePeriod;
}TO_SET_ROUTE_PERIOD_CC_t;

/**  TO_SET_WAKEUP_TIMEOUT_CC : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint32_t uiWakeupTimeout;
}TO_SET_WAKEUP_TIMEOUT_CC_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _MISC_TYPES_H_
