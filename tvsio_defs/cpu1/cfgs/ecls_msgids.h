 /*************************************************************************
 ** File:
 **  ecls_msgids.h
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
 **     - 2019-07-17 | Ephram Rubin | Adding UM Specific Command Messages for 
 **                                   PCA/VPA/CAL
 *************************************************************************/
#ifndef _ecls_msgids_
#define _ecls_msgids_

#include "auto_cfs_mids.h"

/*************************************************************************
 ** Macro Definitions
 *************************************************************************/

/**
 ** \name ECLS Command Message Numbers */
/** \{ */
#define ECLS_CMD_MID          GRP1_CFS_ECLS_CMD_MID
#define ECLS_SEND_HK_MID      GRP1_CFS_ECLS_SEND_HK_MID
#define ECLS_WAKEUP_MID       GRP1_CFS_ECLS_WAKEUP_MID
#define UM_CMD_ECLSS_PCA_MID  GRP1_CFS_UM_CMD_ECLSS_PCA_MID
#define UM_CMD_ECLSS_VPA_MID  GRP1_CFS_UM_CMD_ECLSS_VPA_MID
#define UM_CMD_ECLSS_CAL_MID  GRP1_CFS_UM_CMD_ECLSS_CAL_MID
/** \} */

/**
 ** \name ECLS Telemetery Message Number */
/** \{ */
#define ECLS_HK_TLM_MID       GRP1_CFS_ECLS_HK_TLM_MID
#define ECLS_OUT_DATA_MID     GRP1_CFS_ECLS_OUT_DATA_MID
#define UM_ECLSS_TLM_MID      GRP1_CFS_UM_ECLSS_TLM_MID
/** \} */

#endif /*_ecls_msgids_*/

/************************/
/*  End of File Comment */
/************************/
