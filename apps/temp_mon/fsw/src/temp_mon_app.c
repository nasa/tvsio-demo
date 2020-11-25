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
** File: temp_mon_app.c
**
** Purpose:
**   This file contains the source code for a skeleton application that does
**   nothing and is the minimum required for a valid cFS application.
**
*******************************************************************************/

/*
** Include Files:
*/
#include "temp_mon_events.h"
#include "temp_mon_version.h"
#include "temp_mon_app.h"
#include "temp_mon_platform_cfg.h"

#include <string.h>

/*
** global data
*/
TEMP_MON_AppData_t g_TEMP_MON_AppData;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * *  * * * * **/
/* TEMP_MON_AppMain() -- Application entry point and main process loop        */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * *  * * * * **/
void TEMP_MON_AppMain( void )
{
    int32  iStatus;

    /*
    ** Register the app with Executive services
    */
    CFE_ES_RegisterApp();

    /*
    ** Perform application specific initialization
    ** If the Initialization fails, set the RunStatus to
    ** CFE_ES_RunStatus_APP_ERROR and the App will not enter the RunLoop
    */
    iStatus = TEMP_MON_AppInit();
    if (iStatus != CFE_SUCCESS)
    {
        OS_printf( "\e[31m***** TEMP_MON *****\e[39m func: %s line: %d Failed top Init app data\n", __func__, __LINE__ );
        g_TEMP_MON_AppData.RunStatus = CFE_ES_RunStatus_APP_ERROR;
    }

    CFE_SB_MsgPtr_t pMsg = NULL;
    CFE_SB_MsgId_t msgId;
    Struct_Temp* temp_tlm;
    MPCV_GNC_TLM* range_tlm;

    /*
    ** TEMP_MON Runloop
    */

    while ( CFE_ES_RunLoop(&g_TEMP_MON_AppData.RunStatus) == TRUE )
    {
        iStatus = CFE_SB_RcvMsg(&pMsg, g_TEMP_MON_AppData.tvsioPipeId, CFE_SB_PEND_FOREVER );
        if( iStatus == CFE_SUCCESS )
        {
            msgId = CFE_SB_GetMsgId(pMsg);
            switch(msgId)
            {
                case STRUCT_TEMP_MID:
                    temp_tlm = (Struct_Temp*) pMsg;
                    OS_printf( "\e[32m***** TEMP_MON *****\e[39m Received MID 0x%04X, Temp %f\n",msgId,temp_tlm->temperature );
                    break;
                case STRUCT_RPODVSM_MID:
                    range_tlm = (MPCV_GNC_TLM*) pMsg;
                    OS_printf( "\e[32m***** TEMP_MON *****\e[39m Received MID 0x%04X, Range %f, RangeRate %f\n",msgId,range_tlm->vv_range, range_tlm->vv_rangerate );
                    break;
                default: 
                    OS_printf( "\e[32m***** TEMP_MON *****\e[39m Received invalid TLM MID (0x%04X)\n",(unsigned int)msgId);
            }
        }

    }

    CFE_ES_ExitApp(g_TEMP_MON_AppData.RunStatus);

} /* End of TEMP_MON_AppMain() */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
/*                                                                            */
/* TEMP_MON_AppInit() --  initialization                                      */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
int32 TEMP_MON_AppInit( void )
{
    OS_printf("***** TEMP_MON ***** func: %s line: %d\n", __func__, __LINE__);
    int32    status;

    g_TEMP_MON_AppData.RunStatus = CFE_ES_RunStatus_APP_RUN;

    /*
    ** Initialize app command execution counters
    */
    g_TEMP_MON_AppData.CmdCounter = 0;
    g_TEMP_MON_AppData.ErrCounter = 0;

    /*
    ** Initialize app configuration data
    */
    g_TEMP_MON_AppData.PipeDepth = TEMP_MON_PIPE_DEPTH;

    strcpy(g_TEMP_MON_AppData.PipeName, "TEMP_MON_CMD_PIPE");

    /*
    ** Register the events
    */
    if ((status = CFE_EVS_Register(NULL, 0, 0)) != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Temp Mon App: Error Registering Events, RC = %lu\n",
                             (unsigned long)status);
        return ( status );
    }

    /*
    ** Initialize housekeeping packet (clear user data area).
    */
    CFE_SB_InitMsg(&g_TEMP_MON_AppData.HkBuf.MsgHdr,
                   TEMP_MON_HK_TLM_MID,
                   sizeof(g_TEMP_MON_AppData.HkBuf),
                   TRUE);

    /*
    ** Create Software Bus message pipe.
    */
    status = CFE_SB_CreatePipe(&g_TEMP_MON_AppData.CommandPipe,
                               g_TEMP_MON_AppData.PipeDepth,
                               g_TEMP_MON_AppData.PipeName);
    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Temp Mon App: Error creating pipe, RC = 0x%08lX\n",
                             (unsigned long)status);
        return ( status );
    }

    /*
    ** Subscribe to Housekeeping request commands
    */
    status = CFE_SB_Subscribe(TEMP_MON_SEND_HK_MID,
                              g_TEMP_MON_AppData.CommandPipe);
    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Temp Mon App: Error Subscribing to HK request, RC = 0x%08lX\n",
                             (unsigned long)status);
        return ( status );
    }

    /*
    ** Subscribe to ground command packets
    */
    status = CFE_SB_Subscribe(TEMP_MON_CMD_MID,
                              g_TEMP_MON_AppData.CommandPipe);
    if (status != CFE_SUCCESS )
    {
        CFE_ES_WriteToSysLog("Temp Mon App: Error Subscribing to Command, RC = 0x%08lX\n",
                             (unsigned long)status);

        return ( status );
    }

    CFE_EVS_SendEvent (TEMP_MON_STARTUP_INF_EID,
                       CFE_EVS_EventType_INFORMATION,
                       "TEMP_MON App Initialized. Version %d.%d.%d.%d",
                       TEMP_MON_APP_MAJOR_VERSION,
                       TEMP_MON_APP_MINOR_VERSION,
                       TEMP_MON_APP_REVISION,
                       TEMP_MON_APP_MISSION_REV);

    /* 
    ** Subscribe to TVS IO packets
    */
    status = TEMP_MON_TVSIO_Init();
    if ( status != CFE_SUCCESS )
    {
        CFE_ES_WriteToSysLog("Temp Mon App: Error Subscribing to TVS IO data, RC = 0x%08lx\n",
                             (unsigned long)status);
    }

    return ( CFE_SUCCESS );


} /* End of TEMP_MON_AppInit() */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/*  Name:  TEMP_MON_TVSIO_Init                                                */
/*                                                                            */
/*  Purpose:                                                                  */
/*     This routine initialize all pipes and variables necessary for          */
/*     communicatins with TVS_IO                                              */
/*                                                                            */
/*  Arguments:                                                                */
/*    None                                                                    */
/*                                                                            */
/*  Returns:                                                                  */
/*    int32 iStatus - Status of initialization                                */
/*                                                                            */
/*  Routines Called:                                                          */
/*    CFE_SB_CreatePipe                                                       */
/*    CFE_SB_Subscribe                                                        */
/*                                                                            */
/*  Called By                                                                 */
/*    TEMP_MON_AppInit                                                        */
/* * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *  * *  * * * * */
int32 TEMP_MON_TVSIO_Init( void )
{
    OS_printf("\e[33m***** TEMP_MON *****\e[39m func: %s line: %d\n", __func__, __LINE__);
    int32  iStatus=CFE_SUCCESS;

    /* Init temperature message pipe */
    g_TEMP_MON_AppData.tvsioPipeDepth = TEMP_MON_TVS_IO_PIPE_DEPTH;
    memset((void*)g_TEMP_MON_AppData.tvsioPipeName, '\0', sizeof(g_TEMP_MON_AppData.tvsioPipeName));
    strncpy(g_TEMP_MON_AppData.tvsioPipeName, "TEMP_MON_TVSIO_PIPE", OS_MAX_API_NAME-1);

    iStatus = CFE_SB_CreatePipe( &g_TEMP_MON_AppData.tvsioPipeId,
                                  g_TEMP_MON_AppData.tvsioPipeDepth,
                                  g_TEMP_MON_AppData.tvsioPipeName);

    OS_printf( "\ttvsioPipeId: %d\n", g_TEMP_MON_AppData.tvsioPipeId );
    if ( iStatus == CFE_SUCCESS )
    {
        /* Subscribe to TVSIO data */
        iStatus = CFE_SB_Subscribe( STRUCT_TEMP_MID, g_TEMP_MON_AppData.tvsioPipeId);
        if ( iStatus == CFE_SUCCESS )
            OS_printf( "\tSubscribed to MID: 0x%04x\n", STRUCT_TEMP_MID );
        else
            OS_printf("\e[31m***** TEMP_MON *****\e[39m func: %s line: %d: Failed to Subscribe TVS_IO pipe\n", __func__, __LINE__);

        iStatus = CFE_SB_Subscribe( STRUCT_RPODVSM_MID, g_TEMP_MON_AppData.tvsioPipeId);
        if ( iStatus == CFE_SUCCESS )
            OS_printf( "\tSubscribed to MID: 0x%04x\n", STRUCT_RPODVSM_MID );
        else
            OS_printf("\e[31m***** TEMP_MON *****\e[39m func: %s line: %d: Failed to Subscribe TVS_IO pipe\n", __func__, __LINE__);
    } else 
        OS_printf("\e[31m***** TEMP_MON *****\e[39m func: %s line: %d: Failed to init TVS_IO pipe\n", __func__, __LINE__);
    return iStatus;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/*  Name:  TEMP_MON_ProcessCommandPacket                                      */
/*                                                                            */
/*  Purpose:                                                                  */
/*     This routine will process any packet that is received on the TEMP_MON  */
/*     command pipe.                                                          */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *  * *  * * * * */
void TEMP_MON_ProcessCommandPacket( CFE_SB_MsgPtr_t Msg )
{
    CFE_SB_MsgId_t  MsgId;

    MsgId = CFE_SB_GetMsgId(Msg);

    switch (MsgId)
    {
        case TEMP_MON_CMD_MID:
            TEMP_MON_ProcessGroundCommand(Msg);
            break;

        case TEMP_MON_SEND_HK_MID:
            TEMP_MON_ReportHousekeeping((CCSDS_CommandPacket_t *)Msg);
            break;

        default:
            CFE_EVS_SendEvent(TEMP_MON_INVALID_MSGID_ERR_EID,
                              CFE_EVS_EventType_ERROR,
         	              "TEMP_MON: invalid command packet,MID = 0x%x",
                              MsgId);
            break;
    }

    return;

} /* End TEMP_MON_ProcessCommandPacket */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/*                                                                            */
/* TEMP_MON_ProcessGroundCommand() -- TEMP_MON ground commands                */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
void TEMP_MON_ProcessGroundCommand( CFE_SB_MsgPtr_t Msg )
{
    uint16 CommandCode;

    CommandCode = CFE_SB_GetCmdCode(Msg);

    /*
    ** Process "known" TEMP_MON app ground commands
    */
    switch (CommandCode)
    {
        case TEMP_MON_NOOP_CC:
            if (TEMP_MON_VerifyCmdLength(Msg, sizeof(TEMP_MON_Noop_t)))
            {
                TEMP_MON_Noop((TEMP_MON_Noop_t *)Msg);
            }

            break;

        case TEMP_MON_RESET_COUNTERS_CC:
            if (TEMP_MON_VerifyCmdLength(Msg, sizeof(TEMP_MON_ResetCounters_t)))
            {
                TEMP_MON_ResetCounters((TEMP_MON_ResetCounters_t *)Msg);
            }

            break;

        case TEMP_MON_PROCESS_CC:
            if (TEMP_MON_VerifyCmdLength(Msg, sizeof(TEMP_MON_Process_t)))
            {
                TEMP_MON_Process((TEMP_MON_Process_t *)Msg);
            }

            break;

        /* default case already found during FC vs length test */
        default:
            CFE_EVS_SendEvent(TEMP_MON_COMMAND_ERR_EID,
                              CFE_EVS_EventType_ERROR,
                              "Invalid ground command code: CC = %d",
                              CommandCode);
            break;
    }

    return;

} /* End of TEMP_MON_ProcessGroundCommand() */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/*  Name:  TEMP_MON_ReportHousekeeping                                        */
/*                                                                            */
/*  Purpose:                                                                  */
/*         This function is triggered in response to a task telemetry request */
/*         from the housekeeping task. This function will gather the Apps     */
/*         telemetry, packetize it and send it to the housekeeping task via   */
/*         the software bus                                                   */
/* * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *  * *  * * * * */
int32 TEMP_MON_ReportHousekeeping( const CCSDS_CommandPacket_t *Msg )
{
    /*
    ** Get command execution counters...
    */
    g_TEMP_MON_AppData.HkBuf.HkTlm.Payload.CommandErrorCounter = g_TEMP_MON_AppData.ErrCounter;
    g_TEMP_MON_AppData.HkBuf.HkTlm.Payload.CommandCounter = g_TEMP_MON_AppData.CmdCounter;

    /*
    ** Send housekeeping telemetry packet...
    */
    CFE_SB_TimeStampMsg(&g_TEMP_MON_AppData.HkBuf.MsgHdr);
    CFE_SB_SendMsg(&g_TEMP_MON_AppData.HkBuf.MsgHdr);

    return CFE_SUCCESS;

} /* End of TEMP_MON_ReportHousekeeping() */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/*                                                                            */
/* TEMP_MON_Noop -- TEMP_MON NOOP commands                                    */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
int32 TEMP_MON_Noop( const TEMP_MON_Noop_t *Msg )
{

    g_TEMP_MON_AppData.CmdCounter++;

    CFE_EVS_SendEvent(TEMP_MON_COMMANDNOP_INF_EID,
                      CFE_EVS_EventType_INFORMATION,
                      "TEMP_MON: NOOP command  Version %d.%d.%d.%d",
                      TEMP_MON_APP_MAJOR_VERSION,
                      TEMP_MON_APP_MINOR_VERSION,
                      TEMP_MON_APP_REVISION,
                      TEMP_MON_APP_MISSION_REV);

    return CFE_SUCCESS;

} /* End of TEMP_MON_Noop */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/*  Name:  TEMP_MON_ResetCounters                                             */
/*                                                                            */
/*  Purpose:                                                                  */
/*         This function resets all the global counter variables that are     */
/*         part of the task telemetry.                                        */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *  * *  * * * * */
int32 TEMP_MON_ResetCounters( const TEMP_MON_ResetCounters_t *Msg )
{

    g_TEMP_MON_AppData.CmdCounter = 0;
    g_TEMP_MON_AppData.ErrCounter = 0;

    CFE_EVS_SendEvent(TEMP_MON_COMMANDRST_INF_EID,
                      CFE_EVS_EventType_INFORMATION,
                      "TEMP_MON: RESET command");

    return CFE_SUCCESS;

} /* End of TEMP_MON_ResetCounters() */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/*  Name:  TEMP_MON_Process                                                   */
/*                                                                            */
/*  Purpose:                                                                  */
/*         This function Process Ground Station Command                       */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *  * *  * * * * */
int32  TEMP_MON_Process( const TEMP_MON_Process_t *Msg )
{
    return CFE_SUCCESS;

} /* End of TEMP_MON_ProcessCC */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/*                                                                            */
/* TEMP_MON_VerifyCmdLength() -- Verify command packet length                 */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
boolean TEMP_MON_VerifyCmdLength( CFE_SB_MsgPtr_t Msg, uint16 ExpectedLength )
{
    boolean result = TRUE;

    uint16 ActualLength = CFE_SB_GetTotalMsgLength(Msg);

    /*
    ** Verify the command packet length.
    */
    if (ExpectedLength != ActualLength)
    {
        CFE_SB_MsgId_t MessageID   = CFE_SB_GetMsgId(Msg);
        uint16         CommandCode = CFE_SB_GetCmdCode(Msg);

        CFE_EVS_SendEvent(TEMP_MON_LEN_ERR_EID,
                          CFE_EVS_EventType_ERROR,
                          "Invalid Msg length: ID = 0x%X,  CC = %d, Len = %d, Expected = %d",
                          MessageID,
                          CommandCode,
                          ActualLength,
                          ExpectedLength);

        result = FALSE;

        g_TEMP_MON_AppData.ErrCounter++;
    }

    return( result );

} /* End of TEMP_MON_VerifyCmdLength() */
