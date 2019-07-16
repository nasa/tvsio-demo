/*
 *      Copyright (c) 2004-2017, United States government as represented by the 
 *      administrator of the National Aeronautics Space Administration.  
 *      All rights reserved. This software(cFE) was created at NASA's Goddard 
 *      Space Flight Center pursuant to government contracts.
 *
 *      This is governed by the NASA Open Source Agreement and may be used,
 *      distributed and modified only pursuant to the terms of that agreement. 
 */

#ifndef _CFE_TBL_EXTERN_TYPEDEFS_H_
#define _CFE_TBL_EXTERN_TYPEDEFS_H_

/* This header may be generated from an EDS file, 
 * tools are available and the feature is enabled */
#ifdef CFE_EDS_ENABLED_BUILD

/* Use the EDS generated version of these types */
#include "cfe_tbl_eds_typedefs.h"

#else
/* Use the local definitions of these types */

#include "common_types.h"

/**
 * @brief Label definitions associated with CFE_TBL_BufferSelect_Enum_t
 */
enum CFE_TBL_BufferSelect
{

   /**
    * @brief Select the Inactive buffer for validate or dump
    */
   CFE_TBL_BufferSelect_INACTIVE                      = 0,

   /**
    * @brief Select the Active buffer for validate or dump
    */
   CFE_TBL_BufferSelect_ACTIVE                        = 1
};

/**
 * @brief Selects the buffer to operate on for validate or dump commands
 *
 *
 * @sa enum CFE_TBL_BufferSelect
 */
typedef uint16                                           CFE_TBL_BufferSelect_Enum_t;


#endif /* CFE_EDS_ENABLED_BUILD */

#endif /* _CFE_TBL_EXTERN_TYPEDEFS_H_ */

