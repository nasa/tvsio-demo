/******************************************************************************

**

** File:  cfe_psp_exception.c

**

**      MCP750 vxWorks 6.2 Version

**

**      Copyright (c) 2004-2006, United States government as represented by the

**      administrator of the National Aeronautics Space Administration.

**      All rights reserved. This software(cFE) was created at NASA's Goddard

**      Space Flight Center pursuant to government contracts.

**

**      This software may be used only pursuant to a United States government

**      sponsored project and the United States government may not be charged

**      for use thereof.

**

**

** Purpose:

**   cFE PSP Exception related functions.

**

** History:

**   2007/05/29  A. Cudmore      | vxWorks 6.2 MCP750 version

**

******************************************************************************/



/*

**  Include Files

*/

#include <stdio.h>

#include <string.h>

#include <vxWorks.h>

#include <sysLib.h>

#include "fppLib.h"

#include "excLib.h"

#include "taskLib.h"

#include "arch/ppc/vxPpcLib.h"

#include "arch/ppc/esfPpc.h"



/*

** cFE includes

*/

#include "common_types.h"

#include "osapi.h"

#include "cfe_es.h"            /* For reset types */
#include "cfe_platform_cfg.h"  /* for processor ID */



#include "cfe_psp.h"
#include "cfe_psp_memory.h"


/*

** Types and prototypes for this module

*/





/*

** BSP Specific defines

*/



/*

**  External Declarations

*/



/*

** Global variables

*/

int disableExceptions = FALSE;


CFE_PSP_ExceptionContext_t CFE_PSP_ExceptionContext;

char                  CFE_PSP_ExceptionReasonString[256];



/*

**

** IMPORTED FUNCTIONS

**

*/



void CFE_ES_ProcessCoreException(uint32  HostTaskId,     const char *ReasonString,
                                 const uint32 *ContextPointer, uint32 ContextSize);


/*

**

** LOCAL FUNCTION PROTOTYPES

**

*/



void CFE_PSP_ExceptionHook ( int task_id, int vector, ESFPPC* pEsf );





/***************************************************************************

 **                        FUNCTIONS DEFINITIONS

 ***************************************************************************/



/*

**

**   Name: CFE_PSP_AttachExceptions

**

**   Purpose: This function Initializes the task execptions and adds a hook

**              into the VxWorks exception handling.  The below hook is called

**              for every exception that VxWorks catches.

**

**   Notes: if desired - to attach a custom handler put following code in

**          this function:  excConnect ((VOIDFUNCPTR*)VECTOR, ExceptionHandler);

**

*/



void CFE_PSP_AttachExceptions(void)

{

    if (disableExceptions == FALSE)

    {

        excHookAdd((FUNCPTR)CFE_PSP_ExceptionHook);

        OS_printf("CFE_PSP: Attached cFE Exception Handler. Context Size = %d bytes.\n",CFE_PSP_CPU_CONTEXT_SIZE);

    }

}





/*

** Name: CFE_PSP_ExceptionHook

**

** Purpose: Make the proper call to CFE_ES_ProcessCoreException

**

** Notes:   pEsf - pointer to exception stack frame.

**          fppSave - When it makes this call, it captures the last floating

**                      point context - which may not be valid.  If a floating

**                      point exception occurs you can be almost 100% sure

**                      that this will reflect the proper context.  But if another

**                      type of exception occurred then this has the possibility

**                      of not being valid.  Specifically if a task that is not

**                      enabled for floating point causes a non-floating point

**                      exception, then the meaning of the floating point context

**                      will not be valid.  If the task is enabled for floating point,

**                      then it will be valid.

**

*/

void CFE_PSP_ExceptionHook (int task_id, int vector, ESFPPC* pEsf )

{



    char *TaskName;



    /*

    ** Get the vxWorks task name

    */

    TaskName = taskName(task_id);



    if ( TaskName == NULL )

    {

       sprintf(CFE_PSP_ExceptionReasonString, "Exception: Vector=0x%06X, vxWorks Task Name=NULL, Task ID=0x%08X",

               vector,task_id);

    }

    else

    {

       sprintf(CFE_PSP_ExceptionReasonString, "Exception: Vector=0x%06X, vxWorks Task Name=%s, Task ID=0x%08X",

                vector, TaskName, task_id);

    }



    /*

    ** Save Exception Stack frame

    */

    memcpy(&(CFE_PSP_ExceptionContext.esf), pEsf, sizeof(ESFPPC));



#if (CPU != PPC440 && CPU != PPC85XX)
    /*

    ** Save floating point registers

    */

    if (disableExceptions == FALSE)
    {
    fppSave(&CFE_PSP_ExceptionContext.fp);

    }
#endif


    /*

    ** Call the Generic cFE routine to finish processing the exception and

    ** restart the cFE

    */

    CFE_ES_ProcessCoreException((uint32 )task_id, CFE_PSP_ExceptionReasonString,
                                (void *)&CFE_PSP_ExceptionContext, sizeof(CFE_PSP_ExceptionContext_t));


    /*

    ** No return to here

    */



} /* end function */





/*

**

**   Name: CFE_PSP_SetDefaultExceptionEnvironment

**

**   Purpose: This function sets a default exception environment that can be used

**

**   Notes: The exception environment is local to each task Therefore this must be

**          called for each task that that wants to do floating point and catch exceptions

**          Currently, this is automatically called from OS_TaskRegister for every task

*/

void CFE_PSP_SetDefaultExceptionEnvironment(void)

{

    /* FIXME: one or more of the exception settings below are causing the

     * Maxwell board to through an exception

     * Need to figure out the proper exception settings at some point for

     * the Maxwell board...

    */

    /*

    ld<cfe-core.o

    value = 20424240 = 0x137a630 = '0'

    CFE_PSP_Main(1, "/cf/apps/cfe_es_startup.scr")

    value = 20962304 = 0x13fdc00

    ->

    data access

    Exception current instruction address: 0x001e52b8

    Machine Status Register: 0x0000b032

    Data Access Register: 0x00000000

    Condition Register: 0x82000220

    Data storage interrupt Register: 0x0a000000

    Task: 0x12857a0 "tErfTask"

    0x12857a0 (tErfTask): task 0x12857a0 has had a failure and has been stopped.

    0x12857a0 (tErfTask): The task has been terminated because it triggered an exception that raised the signal 11.

    DBG: CFE_PSP: mode Id: 1  file: /cf/apps/cfe_es_startup.scr

    DBG:CFE_PSP: size of reserve memory struct: 3450896, CFE_PSP_ReservedMemoryPtr: 0x00000000

    DBG:CFE_PSP: after sysMemTop(), CFE_PSP_ReservedMemoryPtr: 0x0F800000

    CFE_PSP: Aux Clock Rate 100.

    CFE_PSP: Clearing Processor Reserved Memory.

    1980-001-00:01:55.64419 ES Startup: CFE_ES_Main started

    */

}

void CFE_PSP_SetDefaultExceptionEnvironment_XXX(void)

{

    vxMsrSet( _PPC_MSR_EE               |   /* enable the external interrupt */

              _PPC_MSR_FP               |   /* enable floating point */

              _PPC_MSR_ME               |   /* major hardware failures */

              _PPC_MSR_FE1              |   /* generate unrecoverable floating point exceptions */

              _PPC_MSR_DR               );  /* enable data address translation (dbats?) */



    vxFpscrSet(  _PPC_FPSCR_VE              |       /* enable exceptions for invalid operations */

                 _PPC_FPSCR_OE              |       /* enable overflow exceptions */

                 _PPC_FPSCR_NI              |       /* Non-IEEE mode for denormailized numbers */

                 _PPC_FPSCR_ZE                  );  /* enable divide by zero exceptions */

}



