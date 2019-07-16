/*
**  Filename: cfe_evs_utils.h
**  $Id: cfe_evs_utils.h 1.5 2012/01/13 12:00:56GMT-05:00 acudmore Exp  $
**
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.
**  
**
**  Title:    Event Services Task and API - Utility functions.
**
**  Purpose:
**            Unit specification for the event services utility functions.
**
**  Contents:
**       I.  macro and constant type definitions
**      II.  EVS utility internal structures
**     III.  function prototypes
**
**  Design Notes:
**
**  References:
**     Flight Software Branch C Coding Standard Version 1.0a
**
*/

#ifndef _cfe_evs_utils_
#define _cfe_evs_utils_

/********************* Include Files  ************************/

#include "cfe_evs_task.h"        /* EVS internal definitions */

/* ==============   Section I: Macro and Constant Type Definitions   =========== */

/* ==============   Section II: Internal Structures ============ */     

/* ==============   Section III: Function Prototypes =========== */

int32 EVS_GetAppID(uint32 *AppIdPtr);

int32 EVS_GetApplicationInfo(uint32 *pAppID, const char *pAppName);

int32 EVS_NotRegistered(uint32 AppID);

boolean EVS_IsFiltered(uint32 AppID, uint16 EventID, uint16 EventType);

EVS_BinFilter_t *EVS_FindEventID(int16 EventID, EVS_BinFilter_t *FilterArray);

void EVS_EnableTypes(uint8 BitMask, uint32 AppID);

void EVS_DisableTypes(uint8 BitMask, uint32 AppID);

void EVS_GenerateEventTelemetry(uint32 AppID, uint16 EventID, uint16 EventType,
        const CFE_TIME_SysTime_t *Time, const char *MsgSpec, va_list ArgPtr);

int32 EVS_SendEvent (uint16 EventID, uint16 EventType, const char *Spec, ... );

#endif  /* _cfe_evs_utils_ */
