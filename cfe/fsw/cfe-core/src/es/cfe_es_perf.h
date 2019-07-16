/*
** File:  cfe_es_perf.h
**
**      Copyright (c) 2004-2012, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA's Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used,
**      distributed and modified only pursuant to the terms of that agreement.
**
** Purpose: Performance Analyzer data structures
**
** Design Notes:
**
** References:
**
*/

#ifndef _cfe_es_perf_
#define _cfe_es_perf_


/*
** Include Files
*/
#include "common_types.h"
#include "osapi.h"
#include "cfe_es.h"
#include "cfe_es_msg.h"
#include "cfe_es_events.h"
#include "cfe_sb.h"
#include "cfe_evs.h"
#include "cfe_perfids.h"
#include "cfe_psp.h"

/*
**  Defines
*/
#define CFE_ES_PERF_CHILD_NAME           "ES_PerfFileWriter"
#define CFE_ES_PERF_CHILD_STACK_PTR      0
#define CFE_ES_PERF_CHILD_FLAGS          0


enum CFE_ES_PerfState_t {
    CFE_ES_PERF_IDLE = 0,
    CFE_ES_PERF_WAITING_FOR_TRIGGER,
    CFE_ES_PERF_TRIGGERED,
    CFE_ES_PERF_MAX_STATES
};

enum CFE_ES_PerfMode_t {
    CFE_ES_PERF_TRIGGER_START = 0,
    CFE_ES_PERF_TRIGGER_CENTER,
    CFE_ES_PERF_TRIGGER_END,
    CFE_ES_PERF_MAX_MODES
};

typedef struct {
    uint32                         DataToWrite;
    uint32                         ChildID;
    char                           DataFileName[OS_MAX_PATH_LEN];
    int32                          DataFileDescriptor;
} CFE_ES_PerfLogDump_t;

extern CFE_ES_PerfLogDump_t    CFE_ES_PerfLogDumpStatus;

#endif /* _cfe_es_perf_ */

