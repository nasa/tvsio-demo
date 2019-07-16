/*
**   File:
**    cfe_es_objtab.c
**
**      Copyright (c) 2004-2012, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA's Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used,
**      distributed and modified only pursuant to the terms of that agreement.
**
**   Purpose:
**     This file contains the OS_object_table for MAP Build1.
**
**  References:
**     Flight Software Branch C Coding Standard Version 1.0a
**     cFE Flight Software Application Developers Guide
**
**  Notes:
**
*/

/*
** Include files
*/
#include "private/cfe_private.h"
#include "cfe_es_global.h"
#include "cfe_es_start.h"

/*
**
** ES_object_table
** Note: The name field in this table should be no more than OS_MAX_API_NAME -1 characters.
**
*/
CFE_ES_ObjectTable_t  CFE_ES_ObjectTable[CFE_PLATFORM_ES_OBJECT_TABLE_SIZE] =
{
   /*
   ** Spare entries -- The spares should be distributed evenly through this table
   */
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   
   /*
   ** cFE core early initialization calls. These must be done before the tasks start
   */
   {
           .ObjectType = CFE_ES_FUNCTION_CALL,
           .ObjectName = "CFE_ES_CDSEarlyInit",
           .FuncPtrUnion.FunctionPtr = CFE_ES_CDS_EarlyInit
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_FUNCTION_CALL,
           .ObjectName = "CFE_EVS_EarlyInit",
           .FuncPtrUnion.FunctionPtr = CFE_EVS_EarlyInit
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_FUNCTION_CALL,
           .ObjectName = "CFE_SB_EarlyInit",
           .FuncPtrUnion.FunctionPtr = CFE_SB_EarlyInit
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_FUNCTION_CALL,
           .ObjectName = "CFE_TIME_EarlyInit",
           .FuncPtrUnion.FunctionPtr = CFE_TIME_EarlyInit
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY },
#ifndef EXCLUDE_CFE_TBL
   {
           .ObjectType = CFE_ES_FUNCTION_CALL,
           .ObjectName = "CFE_TBL_EarlyInit",
           .FuncPtrUnion.FunctionPtr = CFE_TBL_EarlyInit
   },

#else
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
#endif
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_FUNCTION_CALL,
           .ObjectName = "CFE_FS_EarlyInit",
           .FuncPtrUnion.FunctionPtr = CFE_FS_EarlyInit
   },


   /*
   ** Spare entries
   */
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },

   /*
   ** cFE core tasks
   */
   {
           .ObjectType = CFE_ES_CORE_TASK,
           .ObjectName = "CFE_EVS",
           .FuncPtrUnion.MainAppPtr = CFE_EVS_TaskMain,
           .ObjectPriority = CFE_PLATFORM_EVS_START_TASK_PRIORITY,
           .ObjectSize = CFE_PLATFORM_EVS_START_TASK_STACK_SIZE
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_CORE_TASK,
           .ObjectName = "CFE_SB",
           .FuncPtrUnion.MainAppPtr = CFE_SB_TaskMain,
           .ObjectPriority = CFE_PLATFORM_SB_START_TASK_PRIORITY,
           .ObjectSize = CFE_PLATFORM_SB_START_TASK_STACK_SIZE
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_CORE_TASK,
           .ObjectName = "CFE_ES",
           .FuncPtrUnion.MainAppPtr = CFE_ES_TaskMain,
           .ObjectPriority = CFE_PLATFORM_ES_START_TASK_PRIORITY,
           .ObjectSize = CFE_PLATFORM_ES_START_TASK_STACK_SIZE
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_CORE_TASK,
           .ObjectName = "CFE_TIME",
           .FuncPtrUnion.MainAppPtr = CFE_TIME_TaskMain,
           .ObjectPriority = CFE_PLATFORM_TIME_START_TASK_PRIORITY,
           .ObjectSize = CFE_PLATFORM_TIME_START_TASK_STACK_SIZE
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
#ifndef EXCLUDE_CFE_TBL
   {
           .ObjectType = CFE_ES_CORE_TASK,
           .ObjectName = "CFE_TBL",
           .FuncPtrUnion.MainAppPtr = CFE_TBL_TaskMain,
           .ObjectPriority = CFE_PLATFORM_TBL_START_TASK_PRIORITY,
           .ObjectSize = CFE_PLATFORM_TBL_START_TASK_STACK_SIZE
   },
#else
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
#endif

   /*
   ** Spare entries
   */
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   },
   {
           .ObjectType = CFE_ES_NULL_ENTRY
   }

};
