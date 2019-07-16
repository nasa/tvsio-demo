/*
**  File:  
**    cfe_es_shell.h
**
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.
**
**  Purpose:  
**    This file contains definitions needed for the internal shell functions.
**
**  References:
**     Flight Software Branch C Coding Standard Version 1.0a
**     cFE Flight Software Application Developers Guide
**
**  Notes:
** 
*/

#ifndef _cfe_es_shell_
#define _cfe_es_shell_

/*
** Include Files
*/
#include "cfe.h"

/*
** Macro Definitions
*/
#define CFE_ES_LIST_APPS_CMD        "ES_ListApps"
#define CFE_ES_LIST_RESOURCES_CMD   "ES_ListResources"
#define CFE_ES_LIST_TASKS_CMD       "ES_ListTasks"

/*
** Type Definitions
*/


/*
** Function prototypes
*/
/*
** Operating System Shell function
*/

int32 CFE_ES_ShellOutputCommand(const char * CmdString, const char *Filename);

int32 CFE_ES_ListApplications(int32 fd);
int32 CFE_ES_ListTasks(int32 fd);
int32 CFE_ES_ListResources(int32 fd);
#endif  /* cfe_es_shell_ */
