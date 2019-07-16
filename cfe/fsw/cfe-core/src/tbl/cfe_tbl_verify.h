/******************************************************************************
**  $Id: cfe_tbl_verify.h 1.6 2012/01/13 12:17:41GMT-05:00 acudmore Exp  $
**
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.  
**
**  File: cfe_tbl_verify.h
**
**  Purpose:
**    This header file performs compile time checking for TBL configuration
**    parameters.
**
******************************************************************************/

#ifndef _cfe_tbl_verify_
#define _cfe_tbl_verify_
#include "cfe_platform_cfg.h"

#if (2*CFE_PLATFORM_TBL_MAX_DBL_TABLE_SIZE)  > CFE_PLATFORM_TBL_BUF_MEMORY_BYTES
    #error Two buffers of size CFE_PLATFORM_TBL_MAX_DBL_TABLE_SIZE cannot be greater than memory pool size of CFE_PLATFORM_TBL_BUF_MEMORY_BYTES!
#endif

#if ((CFE_PLATFORM_TBL_MAX_SIMULTANEOUS_LOADS+1)*CFE_PLATFORM_TBL_MAX_SNGL_TABLE_SIZE)  >  CFE_PLATFORM_TBL_BUF_MEMORY_BYTES
    #error Shared buffers and table of size CFE_PLATFORM_TBL_MAX_SNGL_TABLE_SIZE cannot be greater than memory pool size of CFE_PLATFORM_TBL_BUF_MEMORY_BYTES!
#endif

#if CFE_PLATFORM_TBL_MAX_NUM_HANDLES < CFE_PLATFORM_TBL_MAX_NUM_TABLES
    #error CFE_PLATFORM_TBL_MAX_NUM_HANDLES cannot be set less than CFE_PLATFORM_TBL_MAX_NUM_TABLES!
#endif

#if CFE_PLATFORM_TBL_MAX_CRITICAL_TABLES > CFE_PLATFORM_ES_CDS_MAX_NUM_ENTRIES
    #error CFE_PLATFORM_TBL_MAX_CRITICAL_TABLES cannot be greater than CFE_PLATFORM_ES_CDS_MAX_NUM_ENTRIES!
#endif

/*
** Any modifications to the "_VALID_" limits defined below must match
** source code changes made to the function CFE_TBL_ReadHeaders() in
** the file "cfe_tbl_internal.c".
*/
#if CFE_PLATFORM_TBL_VALID_SCID_COUNT < 0    
    #error CFE_PLATFORM_TBL_VALID_SCID_COUNT must be greater than or equal to zero
#elif CFE_PLATFORM_TBL_VALID_SCID_COUNT > 2    
    #error CFE_PLATFORM_TBL_VALID_SCID_COUNT must be less than or equal to 2
#endif    

#if CFE_PLATFORM_TBL_VALID_PRID_COUNT < 0    
    #error CFE_PLATFORM_TBL_VALID_PRID_COUNT must be greater than or equal to zero
#elif CFE_PLATFORM_TBL_VALID_PRID_COUNT > 4    
    #error CFE_PLATFORM_TBL_VALID_PRID_COUNT must be less than or equal to 4
#endif

/*
** Validate task stack size...
*/
#if CFE_PLATFORM_TBL_START_TASK_STACK_SIZE < 2048
    #error CFE_PLATFORM_TBL_START_TASK_STACK_SIZE must be greater than or equal to 2048
#endif

/* the following check is removed because some compilers cannot handle the sizeof operator in a #if statement */
/*
#if sizeof(CFE_PLATFORM_TBL_DEFAULT_REG_DUMP_FILE) > OS_MAX_PATH_LEN
    #error The length (including NULL terminator) of CFE_PLATFORM_TBL_DEFAULT_REG_DUMP_FILE cannot be greater than OS_MAX_PATH_LEN
#endif
*/

#endif /* _cfe_tbl_verify_ */
/*****************************************************************************/
