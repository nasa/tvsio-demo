/*==============================================================================
** File Name: to_config.c
**
** Title:     TO table definition
**
** $Author: $
** $Revision: $
** $Date:  $
**
** Purpose:   To provide the table for default data config.
**
** Functions Contained:
**    None
**
**
** Limitations, Assumptions, External Events, and Notes:
**  1.   None
**
**
**==============================================================================
*/

/*
#ifndef _TO_CONFIG_
#define _TO_CONFIG_


#ifdef   __cplusplus
extern "C" {
#endif
*/

/*
** Pragmas
*/

/*
** Include Files
*/
#include "cfe.h"
#include "cfe_tbl_filedef.h"

#include "to_tbldefs.h"
#include "to_grpids.h"

#include "cfe_msgids.h"
#include "cfs_msgids.h"

/*
** Default TO iLoad table data
*/
TO_ConfigTable_t to_ConfigTable =
{
   {
       /* 0 - 9 */
       {CFE_ES_APP_TLM_MID,           {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_ES_HK_TLM_MID,            {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_ES_MEMSTATS_TLM_MID,      {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_ES_SHELL_TLM_MID,         {0,0},  32,  0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_EVS_LONG_EVENT_MSG_MID,   {0,0},  32,  0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_EVS_HK_TLM_MID,           {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_SB_ALLSUBS_TLM_MID,       {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_SB_HK_TLM_MID,            {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_SB_ONESUB_TLM_MID,        {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_SB_STATS_TLM_MID,         {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
                                                         
       /* 10 - 19 */                                     
       {CFE_TBL_HK_TLM_MID,           {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_TBL_REG_TLM_MID,          {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_TIME_DIAG_TLM_MID,        {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {CFE_TIME_HK_TLM_MID,          {0,0},  1,   0xffff,     TO_GROUP_CFE | TO_MGROUP_ONE, 0,1},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
                                                         
       /* 20 - 29 */                                     
       {SCH_DIAG_TLM_MID,             {0,0},  1,   0xffff,     TO_GROUP_APP | TO_MGROUP_ONE, 0,1},
       {SCH_HK_TLM_MID,               {0,0},  1,   0xffff,     TO_GROUP_APP | TO_MGROUP_ONE, 0,1},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {CI_HK_TLM_MID,                {0,0},  1,   0xffff,     TO_GROUP_APP | TO_MGROUP_ONE, 0,1},
       {TO_HK_TLM_MID,                {0,0},  1,   0xffff,     TO_GROUP_APP | TO_MGROUP_ONE, 0,1},
       {TO_DATA_TYPE_MID,             {0,0},  1,   0xffff,     TO_GROUP_APP | TO_MGROUP_ONE, 0,1},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       
       /* 30 - 39 */
       {TO_REMOVED_ENTRY,             {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0}, 
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},

       /* 40 - 49 */
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},

       /* 50 - 59 */
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},

       /* 60 - 69 */
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},

       /* 70 - 79 */
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},

       /* 80 - 89 */
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},

       /* 90 - 99 */
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0},
       {TO_UNUSED_ENTRY,              {0,0},  0,   0x0000,     TO_GROUP_NONE,            0,0}
    }
};

/*
** Table file header
*/
CFE_TBL_FILEDEF(to_ConfigTable, TO.to_config, TO subscription table, to_config.tbl)

/* _TO_CONFIG_ */
