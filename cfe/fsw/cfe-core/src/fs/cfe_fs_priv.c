/*
** $Id: cfe_fs_priv.c 1.6 2012/01/13 12:11:29GMT-05:00 acudmore Exp  $
**
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.
** 
** Purpose:  cFE File Services (FS) library API Initialization 
**
** Author:  Alan Cudmore/NASA GSFC 
**
** Notes:
**
*/


/*
** Required header files
*/
#include "osapi.h"
#include "private/cfe_private.h"
#include "cfe_es.h"
#include "cfe_fs.h"
#include "cfe_fs_priv.h"

#include <string.h>

/*
** Global data
** 
*/
CFE_FS_t CFE_FS;

/******************************************************************************
**  Function:  CFE_FS_EarlyInit()
**
**  Purpose:
**    Initialize the FS data structures before the cFE runs.
**
**  Arguments:
**
**  Notes:
**    This function MUST be called before any FS API's are called.
**
**  Return:
**    CFE_SUCCESS
*/
int32 CFE_FS_EarlyInit (void) 
{
    int32 Stat = CFE_SUCCESS;

    Stat = OS_MutSemCreate(&CFE_FS.SharedDataMutexId, "CFE_FS_SharedMutex", 0);
    if( Stat != OS_SUCCESS )
    {
      CFE_ES_WriteToSysLog("FS Shared Data Mutex creation failed! RC=0x%08x\n",(unsigned int)Stat);
      return Stat;
    }/* end if */

    return Stat;

}/* end CFE_FS_EarlyInit */

/******************************************************************************
**  Function:  CFE_FS_LockSharedData()
**
**  Purpose:
**    FS internal function to handle a semaphore take failure for the FS 
**    Data Mutex
**
**  Arguments:
**    FunctionName   - the Function Name of the code that generated the error.
**
**  Return:
**    None
*/
void CFE_FS_LockSharedData(const char *FunctionName)
{
    int32   Status;
    uint32  AppId = 0;

    Status = OS_MutSemTake(CFE_FS.SharedDataMutexId);
    if (Status != OS_SUCCESS) 
    {
        CFE_ES_GetAppID(&AppId);

        CFE_ES_WriteToSysLog("FS SharedData Mutex Take Err Stat=0x%x,App=%d,Function=%s\n",
                (unsigned int)Status,(int)AppId,FunctionName);

    }/* end if */

    return;

}/* end CFE_FS_LockSharedData */

/******************************************************************************
**  Function:  CFE_FS_UnlockSharedData()
**
**  Purpose:
**    FS internal function to handle a semaphore give failure for the Shared
**    Data Mutex
**
**  Arguments:
**    FunctionName - the Function containing the code that generated the error.
**
**  Return:
**    None
*/
void CFE_FS_UnlockSharedData(const char *FunctionName)
{
   int32   Status;
   uint32  AppId = 0;

   Status = OS_MutSemGive(CFE_FS.SharedDataMutexId);
   if (Status != OS_SUCCESS) 
   {
       CFE_ES_GetAppID(&AppId);
       CFE_ES_WriteToSysLog("FS SharedData Mutex Give Err Stat=0x%x,App=%d,Function=%s\n",
               (unsigned int)Status,(int)AppId,FunctionName);

   }/* end if */
   return;

}/* end CFE_FS_UnlockSharedData */

/************************/
/*  End of File Comment */
/************************/
