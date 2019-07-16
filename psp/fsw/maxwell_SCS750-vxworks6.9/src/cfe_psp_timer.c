/************************************************************************************************
** File:  cfe_psp_timer.c
**
**
**      Copyright (c) 2004-2006, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This software may be used only pursuant to a United States government
**      sponsored project and the United States government may not be charged
**      for use thereof.
**
**
** Purpose:
**   This file contains glue routines between the cFE and the OS Board Support Package ( BSP ).
**   The functions here allow the cFE to interface functions that are board and OS specific
**   and usually dont fit well in the OS abstraction layer.
**
**   NOTE:
**   On this board, per section 7.1.2 in the Software User's Manual, the
**   decrementer and time base registers cannot be used because the resync
**   process resets the 3 processors.  Instead, use the BSP function
**   scsFrtcGet() which supplies the number of board clock ticks since
**   power up using a 64-bit mission timer.
**
** History:
**   2005/06/05  K.Audra    | Initial version,
**   2014/04/30  S.Duran    | Modified for Maxwell SCS750 processor board
**
*************************************************************************************************/

/*
**  Include Files
*/

/*
**  Include Files
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vxWorks.h"
#include "sysLib.h"
#include "vxLib.h"
#include "taskLib.h"
#include "ramDrv.h"
#include "dosFsLib.h"
#include "errnoLib.h"
#include "usrLib.h"
#include "cacheLib.h"

#include "time.h"

/*
** cFE includes
*/
#include "common_types.h"
#include "osapi.h"
#include "cfe_es.h"            /* For reset types */
#include "cfe_platform_cfg.h"  /* for processor ID */
#include "cfe_psp.h"
#include "cfe_time_msg.h"
/*
** Types and prototypes for this module
*/
void CFE_PSP_InitLocalTime(void);
void CFE_PSP_Init1HzTimer(void);
void CFE_PSP_AuxClkHandler(int arg);

/* External Declarations
**
*/
extern void	vxMsrSet (UINT32);          /* machine status reg */
extern UINT32 vxMsrGet (void);

extern unsigned long long scsFrtcGet(unsigned long long *);


/* see psp/fsw/shared/cfe_psp_timer_shared.c for declaration
 * and initialization */

extern void CFE_TIME_Tone1HzISR(void);
extern void CFE_TIME_Local1HzISR(void);


/******************* Macro Definitions ***********************/

/* This is the value of the system clock
 * The timer will take TODO: XXX years to roll over.
 */
#define CFE_PSP_TIMER_TICKS_PER_SECOND       40000000 /* SCS750_SYSTEM_CLOCK_FREQ */
													  /* Resolution of the least significant 32 bits of the 64 bit
                                                         time stamp returned by CFE_PSP_Get_Timebase in timer ticks per second.
                                                         The timer resolution for accuracy should not be any slower than 1000000
                                                         ticks per second or 1 us per tick */

#define CFE_PSP_TIMER_LOW32_ROLLOVER         0        /* The number that the least significant 32 bits of the 64 bit
                                                         time stamp returned by CFE_PSP_Get_Timebase rolls over.  If the lower 32
                                                         bits rolls at 1 second, then the CFE_PSP_TIMER_LOW32_ROLLOVER will be 1000000.
                                                         if the lower 32 bits rolls at its maximum value (2^32) then
                                                         CFE_PSP_TIMER_LOW32_ROLLOVER will be 0. */

/* The number of ticks or interrupts per second */
#define CFE_PSP_TIMER_AUX_TICK_PER_SEC       100

#define CFE_PSP_TIMER_PRINT_DBG              TRUE

/******************************************************************************
**  Function:  CFE_PSP_InitLocalTime()
**
**  Purpose: Initializes the vxWorks Aux and TimeStamp timers.
**
**  Arguments: none
******************************************************************************/
void CFE_PSP_InitLocalTime(void)
{
   // Set the sys clock rate
   sysClkRateSet(200);
   
   /*
   ** Disable the Aux timer interrupt
   */
   sysAuxClkDisable();

   /*
   ** Set the Aux timer rate
   */
   if(sysAuxClkRateGet() != CFE_PSP_TIMER_AUX_TICK_PER_SEC)
   {
      if(sysAuxClkRateSet(CFE_PSP_TIMER_AUX_TICK_PER_SEC) == ERROR)
      {
         OS_printf("CFE_PSP: Unable to set Aux Clock Rate!\n");
      }

      if(CFE_PSP_TIMER_PRINT_DBG == TRUE)
      {
         OS_printf("CFE_PSP: Aux Clock Rate %d.\n", sysAuxClkRateGet());
      }
   }

}/* end CFE_PSP_InitLocalTime */

/******************************************************************************
**  Function:  CFE_PSP_Init1HzTimer()
**  
**  Purpose: Initializes the 1Hz Timer and connects it to the cFE TIME 1Hz routine
**  
**  NOTE: This function has to be called after CFE_ES_Main() in CFE_PSP_Start()
**  because the 1Hz ISR has a semaphore that is created in CFE_ES_Main().
**  
**  **  Arguments: none
*/
void CFE_PSP_Init1HzTimer(void)
{
    /*
    ** Attach a handler to the Aux timer interrupt
    */
    if(sysAuxClkConnect((FUNCPTR)CFE_PSP_AuxClkHandler, 
    		             CFE_PSP_TIMER_AUX_TICK_PER_SEC) == ERROR)
    {
       printf("CFE_PSP: Unable to connect handler to Aux Clock!\n");
    }
    
    sysAuxClkEnable();
	
}/* end CFE_PSP_Init1HzTimer */

/******************************************************************************
**  Function:  CFE_PSP_AuxClkHandler()
**
**  Purpose:
**    A timer int handler to keep track of seconds.
**
**  Arguments:
**
**  Return:
*/
void CFE_PSP_AuxClkHandler(int arg)
{
   static int auxCount = 0;

   /* divide down to 1Hz to call 1Hz ISR 
    * NOTE: Other higher rate stuff could be triggered in this ISR
    * */
   if(++auxCount >= CFE_PSP_TIMER_AUX_TICK_PER_SEC)
   {
      auxCount = 0;

      CFE_TIME_Local1HzISR();

      /* FOR DEBUG *
      OS_time_t LocalTime;
      CFE_PSP_GetTime(&LocalTime);
      logMsg("aux clk handler: %d.%d\n", LocalTime.seconds,LocalTime.microsecs,0,0,0,0);
      */
   }

   return;
}


/******************************************************************************
**  Function:  CFE_PSP_GetTime()
**
**  Purpose: Gets the value of the time from the hardware using the PPC
**  		 time base register
**  	
**  NOTE: Cannot use time base register to time on the Maxwell board.  
**  Maxwell board SUM, section 7.1.2 Restrictions on Decrementer and 
**  time base registers says to use scsFrtcGet() instead of the time base 
**  register on this board.  scsFrtcGet() returns the 64-bit 
**  mission timer in ticks since board power-up.  This timer is timer 0
**  in the system controller.
**  The usage of scsFrtcGet() is from
**  Maxwell board BSP function defined in BSP_6_9/z8530Sio.c
**  returns microseconds since boot getSystemTimeInUsec();  
**
**  Arguments: LocalTime - where the time is returned through
******************************************************************************/
void CFE_PSP_GetTime(OS_time_t *LocalTime)
{ 
	unsigned int msr = 0;
	unsigned long long ts_val = 0;
	unsigned long long tb = 0;
	
	/* got this from BSP6_9/z8530sio.c, not sure why they mod the msr */
	msr = vxMsrGet();
	msr |= 0x2000;
	vxMsrSet(msr);
	
	/* this function returns number of ticks since power up, basically what the 
	 * time base register provides, but cannot use TB on maxwell board */
	scsFrtcGet(&ts_val);

	/* Time in uSeconds.	*/
	ts_val = (ts_val * 1000000);
	tb = ts_val / CFE_PSP_TIMER_TICKS_PER_SECOND; /* set to SCS750_SYSTEM_CLOCK_FREQ */
	
	/* convert to seconds and microseconds using only integer computations,
	 * since this function may be used in an ISR to get a timestamp */
	LocalTime->seconds = (tb / 1000000);
	LocalTime->microsecs = tb - (LocalTime->seconds * 1000000);
	
}/* end CFE_PSP_GetLocalTime */

/******************************************************************************
**  Function:  CFE_PSP_Get_Timer_Tick()
**
**  Purpose:
**    Provides a common interface to system clock tick. This routine
**    is in the BSP because it is sometimes implemented in hardware and
**    sometimes taken care of by the RTOS.
**
**  Arguments:
**
**  Return:
**  OS system clock ticks per second
*/
uint32 CFE_PSP_Get_Timer_Tick(void)
{
   return (sysClkRateGet());
}

/******************************************************************************
**  Function:  CFE_PSP_GetTimerTicksPerSecond()
**
**  Purpose:
**    Provides the resolution of the least significant 32 bits of the 64 bit
**    time stamp returned by CFE_PSP_Get_Timebase in timer ticks per second.
**    The timer resolution for accuracy should not be any slower than 1000000
**    ticks per second or 1 us per tick
**
**  Arguments:
**
**  Return:
**    The number of timer ticks per second of the time stamp returned
**    by CFE_PSP_Get_Timebase
*/
uint32 CFE_PSP_GetTimerTicksPerSecond(void)
{
    return(CFE_PSP_TIMER_TICKS_PER_SECOND);
}

/******************************************************************************
**  Function:  CFE_PSP_GetTimerLow32Rollover()
**
**  Purpose:
**    Provides the number that the least significant 32 bits of the 64 bit
**    time stamp returned by CFE_PSP_Get_Timebase rolls over.  If the lower 32
**    bits rolls at 1 second, then the CFE_PSP_TIMER_LOW32_ROLLOVER will be 1000000.
**    if the lower 32 bits rolls at its maximum value (2^32) then
**    CFE_PSP_TIMER_LOW32_ROLLOVER will be 0.
**
**  Arguments:
**
**  Return:
**    The number that the least significant 32 bits of the 64 bit time stamp
**    returned by CFE_PSP_Get_Timebase rolls over.
*/
uint32 CFE_PSP_GetTimerLow32Rollover(void)
{
    return(CFE_PSP_TIMER_LOW32_ROLLOVER);
}

/******************************************************************************
**  Function:  CFE_PSP_Get_Timebase()
**
**  Purpose:
**    Provides a common interface to system timebase. This routine
**    is in the BSP because it is sometimes implemented in hardware and
**    sometimes taken care of by the RTOS.
**
**  Arguments:
**
**  Return:
**  Timebase register value
*/
void CFE_PSP_Get_Timebase(uint32 *Tbu, uint32* Tbl)
{
	unsigned int msr;
	unsigned long long ts_val;

	/* got this from BSP6_9/z8530sio.c, not sure why they mod the msr */
	msr = vxMsrGet();
	msr |= 0x2000;
	vxMsrSet(msr);
	
	/* this function returns number of ticks since power up, basically what the 
	 * time base register provides, but cannot use TB on maxwell board */
	scsFrtcGet(&ts_val);
	
    *Tbu = (uint32) (0x00000000FFFFFFFF & (ts_val >> 32));
    *Tbl = (uint32) (0x00000000FFFFFFFF & ts_val);
}

/******************************************************************************
**  Function:  CFE_PSP_Get_Dec()
**
**  Purpose:
**    Provides a common interface to decrementer counter. This routine
**    is in the BSP because it is sometimes implemented in hardware and
**    sometimes taken care of by the RTOS.
**
**  Arguments:
**
**  Return:
**  Timebase register value
*/

uint32 CFE_PSP_Get_Dec(void)
{
   //return(vxDecGet());
    return(0);
}







