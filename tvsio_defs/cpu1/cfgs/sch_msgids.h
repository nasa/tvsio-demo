/************************************************************************
** File:
**   $Id: sch_msgids.h 1.3 2017/06/21 15:28:57EDT mdeschu Exp  $
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
** Purpose: 
**  The CFS Scheduler (SCH) Application Message IDs header file
**
** Notes:
**
*************************************************************************/
#ifndef _sch_msgids_h_
#define _sch_msgids_h_

#include "cfe_platform_cfg.h"
#include "auto_cfs_mids.h"

/**************************
** SCH Command Message IDs
***************************/
#define SCH_CMD_MID                    GRP1_CFS_SCH_CMD_MID     /**< \brief SCH Ground Commands Message ID */
#define SCH_SEND_HK_MID                GRP1_CFS_SCH_SEND_HK_MID /**< \brief SCH Send Housekeeping Message ID */

#define SCH_UNUSED_MID                 (CFE_SB_HIGHEST_VALID_MSGID+1) /**< \brief SCH MDT Unused Message Message ID */


/***************************
** SCH Telemetry Message IDs
****************************/
#define SCH_HK_TLM_MID                 GRP1_CFS_SCH_HK_TLM_MID   /**< \brief SCH Housekeeping Telemetry Message ID */
#define SCH_DIAG_TLM_MID               GRP1_CFS_SCH_DIAG_TLM_MID /**< \brief SCH Diagnostic Telemetry Message ID */


#endif /* _sch_msgids_h_ */

/************************/
/*  End of File Comment */
/************************/
