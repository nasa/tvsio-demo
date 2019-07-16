/*
**
**  Filename: cfe_evs_log.h
**    $Id: cfe_evs_log.h 1.5 2012/01/13 12:00:54GMT-05:00 acudmore Exp  $
**
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.  
**
**  Title:    Event Services API Log Control Interfaces.
**
**  Purpose: 
**            Unit specification for the event services log control interfaces.
**
**  Contents:
**       I.  macro and constant type definitions 
**      II.  EVM internal structures
**     III.  function prototypes
**
**  Design Notes: 
**
**  References:
**     Flight Software Branch C Coding Standard Version 1.0a
**
**  Notes:
**
**/

#ifndef _cfe_evs_log_
#define _cfe_evs_log_

/********************* Include Files  ************************/

#include "cfe_evs_msg.h"         /* EVS public definitions */

/* ==============   Section I: Macro and Constant Type Definitions   =========== */

/* ==============   Section II: Internal Structures ============ */    

/* ==============   Section III: Function Prototypes =========== */

void    EVS_AddLog ( CFE_EVS_LongEventTlm_t *EVS_PktPtr );
void    EVS_ClearLog ( void );
int32 CFE_EVS_WriteLogDataFileCmd(const CFE_EVS_WriteLogDataFile_t *data);
int32 CFE_EVS_SetLogModeCmd(const CFE_EVS_SetLogMode_t *data);

#endif  /* _cfe_evs_log_ */
