 /*************************************************************************
 ** File:
 **  to_msgids.h
 **
 **  Copyright © 2016 United States Government as represented by the 
 **  Administrator of the National Aeronautics and Space Administration. 
 **  All Other Rights Reserved.  
 **
 **  This software was created at NASA's Johnson Space Center.
 **  This software is governed by the NASA Open Source Agreement and may be 
 **  used, distributed and modified only pursuant to the terms of that 
 **  agreement.
 **
 ** Purpose: 
 **   This file contains the message ID's used by Telemetry Output
 **
 ** References:
 **   Flight Software Branch C Coding Standard Version 1.2
 **   CFS Development Standards Document
 **
 ** Notes:
 **
 **  \par Modification History:
 **     - 2016-05-11 | Allen Brown | Initial Version
 **
 *************************************************************************/
#ifndef _to_msgids_
#define _to_msgids_

#include "auto_cfs_mids.h"

/*************************************************************************
 ** Macro Definitions
 *************************************************************************/

/**
 ** \name TO Command Message Numbers */ 
/** \{ */
#define TO_APP_CMD_MID      GRP1_CFS_TO_CMD_MID
#define TO_SEND_HK_MID      GRP1_CFS_TO_SEND_HK_MID
#define TO_WAKEUP_MID       GRP1_CFS_TO_WAKEUP_MID
/** \} */

/**
 ** \name TO Telemetery Message Number */ 
/** \{ */
#define TO_HK_TLM_MID       GRP1_CFS_TO_HK_TLM_MID
#define TO_OUT_DATA_MID     GRP1_CFS_TO_OUT_DATA_MID
#define TO_DATA_TYPE_MID    GRP1_CFS_TO_DATA_TYPE_MID
/** \} */

#endif /*_to_msgids_*/

/************************/
/*  End of File Comment */
/************************/
