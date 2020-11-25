/*******************************************************************************
**
**      GSC-18128-1, "Core Flight Executive Version 6.7"
**
**      Copyright (c) 2006-2019 United States Government as represented by
**      the Administrator of the National Aeronautics and Space Administration.
**      All Rights Reserved.
**
**      Licensed under the Apache License, Version 2.0 (the "License");
**      you may not use this file except in compliance with the License.
**      You may obtain a copy of the License at
**
**        http://www.apache.org/licenses/LICENSE-2.0
**
**      Unless required by applicable law or agreed to in writing, software
**      distributed under the License is distributed on an "AS IS" BASIS,
**      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**      See the License for the specific language governing permissions and
**      limitations under the License.
**
** File: temp_mon_app.h
**
** Purpose:
**   This file is main hdr file for the TEMP_MON application.
**
**
*******************************************************************************/

#ifndef _temp_mon_app_h_
#define _temp_mon_app_h_

/*
** Required header files.
*/
#include "cfe.h"
#include "cfe_error.h"
#include "cfe_evs.h"
#include "cfe_sb.h"
#include "cfe_es.h"

#include "temp_mon_msgids.h"
#include "temp_mon_msg.h"
#include "TempStructDef.h"
#include "rpodvsmStructDef.h"

/***********************************************************************/
#define TEMP_MON_PIPE_DEPTH                     32 /* Depth of the Command Pipe for Application */

/************************************************************************
** Type Definitions
*************************************************************************/

/*
 * Buffer to hold telemetry data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t        MsgHdr;
    TEMP_MON_HkTlm_t      HkTlm;
} TEMP_MON_HkBuffer_t;

/*
** Global Data
*/
typedef struct
{
    /*
    ** Command interface counters...
    */
    uint8                 CmdCounter;
    uint8                 ErrCounter;

    /*
    ** Housekeeping telemetry packet...
    */
    TEMP_MON_HkBuffer_t     HkBuf;

    /*
    ** Run Status variable used in the main processing loop
    */
    uint32 RunStatus;

    /*
    ** Operational data (not reported in housekeeping)...
    */
    CFE_SB_PipeId_t    CommandPipe;
    CFE_SB_MsgPtr_t    MsgPtr;

    /*
    ** Initialization data (not reported in housekeeping)...
    */
    char     PipeName[16];
    uint16   PipeDepth;

    /* TVSIO Inbound pipe */
    CFE_SB_PipeId_t tvsioPipeId;
    uint16          tvsioPipeDepth;
    char            tvsioPipeName[OS_MAX_API_NAME];

} TEMP_MON_AppData_t;

/****************************************************************************/
/*
** Local function prototypes.
**
** Note: Except for the entry point (TEMP_MON_AppMain), these
**       functions are not called from any other source module.
*/
void  TEMP_MON_AppMain(void);
int32 TEMP_MON_AppInit(void);
void  TEMP_MON_ProcessCommandPacket(CFE_SB_MsgPtr_t Msg);
void  TEMP_MON_ProcessGroundCommand(CFE_SB_MsgPtr_t Msg);
int32 TEMP_MON_ReportHousekeeping(const CCSDS_CommandPacket_t *Msg);
int32 TEMP_MON_ResetCounters(const TEMP_MON_ResetCounters_t *Msg);
int32 TEMP_MON_Process(const TEMP_MON_Process_t *Msg);
int32 TEMP_MON_Noop(const TEMP_MON_Noop_t *Msg);
void  TEMP_MON_GetCrc(const char *TableName);
boolean  TEMP_MON_VerifyCmdLength(CFE_SB_MsgPtr_t Msg, uint16 ExpectedLength);
int32 TEMP_MON_TVSIO_Init();

void TEMP_MON_ProcessNewData();

#endif /* _temp_mon_app_h_ */
