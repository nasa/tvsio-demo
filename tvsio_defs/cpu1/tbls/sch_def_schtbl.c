/*
** $Id: sch_def_schtbl.c 1.3 2017/06/21 15:29:50EDT mdeschu Exp  $
**
**  Copyright (c) 2007-2014 United States Government as represented by the 
**  Administrator of the National Aeronautics and Space Administration. 
**  All Other Rights Reserved.  
**
**  This software was created at NASA's Goddard Space Flight Center.
**  This software is governed by the NASA Open Source Agreement and may be 
**  used, distributed and modified only pursuant to the terms of that 
**  agreement.
**
** Purpose: Scheduler (SCH) default schedule table data
**
** Author: 
**
** Notes:
**
*/

/*************************************************************************
**
** Include section
**
**************************************************************************/

#include "cfe.h"
#include "cfe_tbl_filedef.h"

#include "sch_tbldefs.h"
#include "sch_msgdefs.h"

/*************************************************************************
**
** Macro definitions
**
**************************************************************************/

/*
** Schedule Table "group" definitions
*/
#define SCH_GROUP_NONE      (0)
#define SCH_GROUP_CFE_HK    (0x000001) 
#define SCH_GROUP_CFS_HK    (0x000002)

/*
** Table indices into sch_def_msgtbl
*/
#define CFE_ES_SEND_HK_MIDX     1
#define CFE_EVS_SEND_HK_MIDX    2
#define CFE_SB_SEND_HK_MIDX     3
#define CFE_TIME_SEND_HK_MIDX   4
#define CFE_TBL_SEND_HK_MIDX    5

#define CI_SEND_HK_MIDX         6
#define CI_WAKEUP_MIDX          7
#define TO_SEND_HK_MIDX         8
#define TO_WAKEUP_MIDX          9
#define SCH_SEND_HK_MIDX       10
#define SP0_HS_SEND_HK_MIDX    16
#define SP0_HS_WAKEUP_MIDX     17
#define NETWK_HS_SEND_HK_MIDX  18
#define NETWK_HS_WAKEUP_MIDX   19
#define ISS_IO_SEND_HK_MIDX    20
#define ISS_IO_WAKEUP_MIDX     21
#define MSM_WAKEUP_MIDX        22
#define AUDIO_WAKEUP_MIDX      11
#define AUDIO_SEND_HK_MIDX     12
#define AUDIO_SIM_UDP_SND_MIDX 13
#define AUDIO_SIM_UDP_RCV_MIDX 14
#define POWER_WAKEUP_MIDX      15
#define ECLS_WAKEUP_MIDX       16
/*************************************************************************
**
** Type definitions
**
**************************************************************************/

/*
** (none)
*/

/*************************************************************************
**
** Exported data
**
**************************************************************************/

/*
** Default schedule table data
*/
SCH_ScheduleEntry_t SCH_DefaultScheduleTable[SCH_TABLE_ENTRIES] =
{

/*
** Structure definition...
**
**    uint8    EnableState  -- SCH_UNUSED, SCH_ENABLED, SCH_DISABLED
**    uint8    Type         -- 0 or SCH_ACTIVITY_SEND_MSG
**    uint16   Frequency    -- how many seconds between Activity execution
**    uint16   Remainder    -- seconds offset to perform Activity
**    uint16   MessageIndex -- Message Index into Message Definition table
**    uint32   GroupData    -- Group and Multi-Group membership definitions
*/

  /* slot #0 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},

  /* slot #1 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},

  /* slot #2 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, SP0_HS_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},  
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},

  /* slot #3 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, NETWK_HS_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #4 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #5 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                            
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #6 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, ISS_IO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #7 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_SEND_HK_MIDX, SCH_GROUP_CFS_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                    
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #8 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #9 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #10 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CFE_ES_SEND_HK_MIDX, SCH_GROUP_CFE_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #11 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CFE_EVS_SEND_HK_MIDX, SCH_GROUP_CFE_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #12 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #13 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  4,  3,  3, SCH_GROUP_CFE_HK },   /* SB HK Request */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1,  0, 13, SCH_GROUP_CFS_HK },                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #14 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CFE_SB_SEND_HK_MIDX, SCH_GROUP_CFE_HK },
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG, 1,  0, 14,  SCH_GROUP_CFS_HK },                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #15 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CFE_TIME_SEND_HK_MIDX, SCH_GROUP_CFE_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #16 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #17 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #18 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CFE_TBL_SEND_HK_MIDX, SCH_GROUP_CFE_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #19 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_SEND_HK_MIDX, SCH_GROUP_CFS_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #20 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #21 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #22 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, SCH_SEND_HK_MIDX, SCH_GROUP_CFS_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #23 */
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE}, 
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #24 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #25 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #26 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, SP0_HS_SEND_HK_MIDX, SCH_GROUP_CFS_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #27 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, NETWK_HS_SEND_HK_MIDX, SCH_GROUP_CFS_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #28 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #29 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #30 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, ISS_IO_SEND_HK_MIDX, SCH_GROUP_CFS_HK },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #31 */
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #32 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, CI_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #33 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, TO_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #34 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, AUDIO_WAKEUP_MIDX, SCH_GROUP_NONE },                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #35 */                                     
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                                                             
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #36 */
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                         
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #37 */
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                         
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #38 */
  {  SCH_ENABLED,  SCH_ACTIVITY_SEND_MSG,  1, 0, MSM_WAKEUP_MIDX, SCH_GROUP_NONE },
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        

  /* slot #39 */
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                           
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE},                                        
  {  SCH_UNUSED,   0,      0,  0, 0,  SCH_GROUP_NONE}
};

/*
** Table file header
*/
CFE_TBL_FILEDEF(SCH_DefaultScheduleTable, SCH.SCHED_DEF, SCH schedule table, sch_def_schtbl.tbl)


