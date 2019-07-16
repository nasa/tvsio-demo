/*
** $Id: cfe.h 1.4 2010/10/25 14:01:09GMT-05:00 jmdagost Exp  $
**
**      Copyright (c) 2004-2006, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement. 
**
** Purpose:  cFE header file
**
** Author:   David Kobe, the Hammers Company, Inc.
**
** Notes:    This header file centralizes the includes for all cFE
**           Applications.  It includes all header files necessary
**           to completely define the cFE interface.
**
*/

/*************************************************************************/

/*
** Ensure that header is included only once...
*/
#ifndef _cfe_
#define _cfe_

#include "common_types.h"     /* Define basic data types */

#include "osapi.h"            /* Define OS API function prototypes */

#include "cfe_mission_cfg.h"  /* Define mission configuration parameters */

/*
 * Note that the platform configuration is _not_ included with cfe.h anymore.
 *
 * Most applications should not depend on any of the #defines in that file.
 * If an application truly does need a value from the platform config, then
 * it can retrieve it from the mission data dictionary using a public API.
 */
#if !defined(_ENHANCED_BUILD_)
#include "cfe_platform_cfg.h" /* Define platform configuration parameters */
#include "cfe_msgids.h"       /* Define common cFE Message IDs */
#endif

#include "cfe_error.h"        /* Define common cFE error codes */

#include "cfe_es.h"           /* Define Executive Service API */
#include "cfe_evs.h"          /* Define Event Service API */
#include "cfe_fs.h"           /* Define File Service API */
#include "cfe_sb.h"           /* Define Software Bus API */
#include "cfe_time.h"         /* Define Time Service API */
#include "cfe_tbl.h"          /* Define Table Service API */

#include "cfe_psp.h"          /* Define Platform Support Package API */

#endif  /* _cfe_ */
