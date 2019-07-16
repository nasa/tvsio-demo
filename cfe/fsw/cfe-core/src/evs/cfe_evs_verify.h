/******************************************************************************
** File: cfe_evs_verify.h
**
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.
**  
** Purpose:
**   This header file performs compile time checking for EVS configuration
**   parameters.
**
** Author:   K.Audra(Microtel)
**
** Notes:
**
**
******************************************************************************/

#ifndef _cfe_evs_verify_
#define _cfe_evs_verify_

/* NOTE: Besides the checks in this file, there is one more in cfe_evs_task.h.
 * The check is not here because it is checking a local #define based on a 
 * configuration parameter
 */

#if CFE_PLATFORM_EVS_DEFAULT_TYPE_FLAG > 0x0F 
    #error CFE_PLATFORM_EVS_DEFAULT_TYPE_FLAG cannot be more than 0x0F!
#endif

#if (CFE_PLATFORM_EVS_DEFAULT_LOG_MODE != 0) && (CFE_PLATFORM_EVS_DEFAULT_LOG_MODE != 1)
    #error CFE_PLATFORM_EVS_DEFAULT_LOG_MODE can only be 0 (Overwrite) or 1 (Discard)!
#endif

#if( CFE_PLATFORM_EVS_DEFAULT_MSG_FORMAT_MODE != CFE_EVS_MsgFormat_LONG) && (CFE_PLATFORM_EVS_DEFAULT_MSG_FORMAT_MODE != CFE_EVS_MsgFormat_SHORT)
    #error CFE_EVS_DEFAULT_MSG_FORMAT can only be CFE_EVS_MsgFormat_LONG or CFE_EVS_MsgFormat_SHORT !
#endif

#if CFE_PLATFORM_EVS_PORT_DEFAULT > 0x0F
    #error CFE_PLATFORM_EVS_PORT_DEFAULT cannot be greater than 0x0F!
#endif

/*
** Validate task stack size...
*/
#if CFE_PLATFORM_EVS_START_TASK_STACK_SIZE < 2048
    #error CFE_PLATFORM_EVS_START_TASK_STACK_SIZE must be greater than or equal to 2048
#endif

#endif /* _cfe_evs_verify_ */
/*****************************************************************************/
