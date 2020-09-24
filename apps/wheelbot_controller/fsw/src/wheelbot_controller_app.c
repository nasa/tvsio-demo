/*=======================================================================================
** File Name:  wheelbot_controller_app.c
**
** Title:  Function Definitions for WHEELBOT_CONTROLLER Application
**
** $Author:    Nexsys
** $Revision: 
** $Date:      
**
** Purpose:  This source file contains all necessary function definitions to run WHEELBOT_CONTROLLER
**           application.
**
** Functions Defined:
**    Function X - Brief purpose of function X
**    Function Y - Brief purpose of function Y
**    Function Z - Brief purpose of function Z
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to all functions in the file.
**    2. List the external source(s) and event(s) that can cause the funcs in this
**       file to execute.
**    3. List known limitations that apply to the funcs in this file.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   
**
**=====================================================================================*/

/*
** Pragmas
*/

/*
** Include Files
*/
#include <string.h>

#include "cfe.h"

#include "wheelbot_controller_platform_cfg.h"
#include "wheelbot_controller_mission_cfg.h"
#include "wheelbot_controller_app.h"

/*
** Local Defines
*/

/*
** Local Structure Declarations
*/

/*
** External Global Variables
*/

/*
** Global Variables
*/
WHEELBOT_CONTROLLER_AppData_t  g_WHEELBOT_CONTROLLER_AppData;

/*
** Local Variables
*/

/*
** Local Function Definitions
*/
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_InitEvent
**
** Purpose: To initialize and register event table for WHEELBOT_CONTROLLER application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization
**
** Routines Called:
**    CFE_EVS_Register
**    CFE_ES_WriteToSysLog
**
** Called By:
**    WHEELBOT_CONTROLLER_InitApp
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    g_WHEELBOT_CONTROLLER_AppData.EventTbl
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 WHEELBOT_CONTROLLER_InitEvent()
{
    int32  iStatus=CFE_SUCCESS;

    /* Create the event table */
    memset((void*)g_WHEELBOT_CONTROLLER_AppData.EventTbl, 0x00, sizeof(g_WHEELBOT_CONTROLLER_AppData.EventTbl));

    g_WHEELBOT_CONTROLLER_AppData.EventTbl[0].EventID = WHEELBOT_CONTROLLER_RESERVED_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[1].EventID = WHEELBOT_CONTROLLER_INF_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[2].EventID = WHEELBOT_CONTROLLER_INIT_INF_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[3].EventID = WHEELBOT_CONTROLLER_ILOAD_INF_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[4].EventID = WHEELBOT_CONTROLLER_CDS_INF_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[5].EventID = WHEELBOT_CONTROLLER_CMD_INF_EID;

    g_WHEELBOT_CONTROLLER_AppData.EventTbl[ 6].EventID = WHEELBOT_CONTROLLER_ERR_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[ 7].EventID = WHEELBOT_CONTROLLER_INIT_ERR_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[ 8].EventID = WHEELBOT_CONTROLLER_ILOAD_ERR_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[ 9].EventID = WHEELBOT_CONTROLLER_CDS_ERR_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[10].EventID = WHEELBOT_CONTROLLER_CMD_ERR_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[11].EventID = WHEELBOT_CONTROLLER_PIPE_ERR_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[12].EventID = WHEELBOT_CONTROLLER_MSGID_ERR_EID;
    g_WHEELBOT_CONTROLLER_AppData.EventTbl[13].EventID = WHEELBOT_CONTROLLER_MSGLEN_ERR_EID;

    /* Register the table with CFE */
    iStatus = CFE_EVS_Register(g_WHEELBOT_CONTROLLER_AppData.EventTbl,
                               WHEELBOT_CONTROLLER_EVT_CNT, CFE_EVS_BINARY_FILTER);
    if (iStatus != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - Failed to register with EVS (0x%08X)\n", iStatus);
    }

    return (iStatus);
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_InitPipe
**
** Purpose: To initialize all message pipes and subscribe to messages for WHEELBOT_CONTROLLER application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization
**
** Routines Called:
**    CFE_SB_CreatePipe
**    CFE_SB_Subscribe
**    CFE_ES_WriteToSysLog
**
** Called By:
**    WHEELBOT_CONTROLLER_InitApp
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    g_WHEELBOT_CONTROLLER_AppData.usSchPipeDepth
**    g_WHEELBOT_CONTROLLER_AppData.cSchPipeName
**    g_WHEELBOT_CONTROLLER_AppData.SchPipeId
**    g_WHEELBOT_CONTROLLER_AppData.usCmdPipeDepth
**    g_WHEELBOT_CONTROLLER_AppData.cCmdPipeName
**    g_WHEELBOT_CONTROLLER_AppData.CmdPipeId
**    g_WHEELBOT_CONTROLLER_AppData.usTlmPipeDepth
**    g_WHEELBOT_CONTROLLER_AppData.cTlmPipeName
**    g_WHEELBOT_CONTROLLER_AppData.TlmPipeId
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 WHEELBOT_CONTROLLER_InitPipe()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init schedule pipe */
    g_WHEELBOT_CONTROLLER_AppData.usSchPipeDepth = WHEELBOT_CONTROLLER_SCH_PIPE_DEPTH;
    memset((void*)g_WHEELBOT_CONTROLLER_AppData.cSchPipeName, '\0', sizeof(g_WHEELBOT_CONTROLLER_AppData.cSchPipeName));
    strncpy(g_WHEELBOT_CONTROLLER_AppData.cSchPipeName, "WHEELBOT_CONTROLLER_SCH_PIPE", OS_MAX_API_NAME-1);

    /* Subscribe to Wakeup messages */
    iStatus = CFE_SB_CreatePipe(&g_WHEELBOT_CONTROLLER_AppData.SchPipeId,
                                 g_WHEELBOT_CONTROLLER_AppData.usSchPipeDepth,
                                 g_WHEELBOT_CONTROLLER_AppData.cSchPipeName);
    if (iStatus == CFE_SUCCESS)
    {
        iStatus = CFE_SB_SubscribeEx(WHEELBOT_CONTROLLER_WAKEUP_MID, g_WHEELBOT_CONTROLLER_AppData.SchPipeId, CFE_SB_Default_Qos, 1);

        if (iStatus != CFE_SUCCESS)
        {
            CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - Sch Pipe failed to subscribe to WHEELBOT_CONTROLLER_WAKEUP_MID. (0x%08X)\n", iStatus);
            goto WHEELBOT_CONTROLLER_InitPipe_Exit_Tag;
        }
        
    }
    else
    {
        CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - Failed to create SCH pipe (0x%08X)\n", iStatus);
        goto WHEELBOT_CONTROLLER_InitPipe_Exit_Tag;
    }

    /* Init command pipe */
    g_WHEELBOT_CONTROLLER_AppData.usCmdPipeDepth = WHEELBOT_CONTROLLER_CMD_PIPE_DEPTH ;
    memset((void*)g_WHEELBOT_CONTROLLER_AppData.cCmdPipeName, '\0', sizeof(g_WHEELBOT_CONTROLLER_AppData.cCmdPipeName));
    strncpy(g_WHEELBOT_CONTROLLER_AppData.cCmdPipeName, "WHEELBOT_CONTROLLER_CMD_PIPE", OS_MAX_API_NAME-1);

    /* Subscribe to command messages */
    iStatus = CFE_SB_CreatePipe(&g_WHEELBOT_CONTROLLER_AppData.CmdPipeId,
                                 g_WHEELBOT_CONTROLLER_AppData.usCmdPipeDepth,
                                 g_WHEELBOT_CONTROLLER_AppData.cCmdPipeName);
    if (iStatus == CFE_SUCCESS)
    {
        /* Subscribe to command messages */
        iStatus = CFE_SB_Subscribe(WHEELBOT_CONTROLLER_CMD_MID, g_WHEELBOT_CONTROLLER_AppData.CmdPipeId);

        if (iStatus != CFE_SUCCESS)
        {
            CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - CMD Pipe failed to subscribe to WHEELBOT_CONTROLLER_CMD_MID. (0x%08X)\n", iStatus);
            goto WHEELBOT_CONTROLLER_InitPipe_Exit_Tag;
        }

        iStatus = CFE_SB_Subscribe(WHEELBOT_CONTROLLER_SEND_HK_MID, g_WHEELBOT_CONTROLLER_AppData.CmdPipeId);

        if (iStatus != CFE_SUCCESS)
        {
            CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - CMD Pipe failed to subscribe to WHEELBOT_CONTROLLER_SEND_HK_MID. (0x%08X)\n", iStatus);
            goto WHEELBOT_CONTROLLER_InitPipe_Exit_Tag;
        }
        
    }
    else
    {
        CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - Failed to create CMD pipe (0x%08X)\n", iStatus);
        goto WHEELBOT_CONTROLLER_InitPipe_Exit_Tag;
    }

    /* Init telemetry pipe */
    g_WHEELBOT_CONTROLLER_AppData.usTlmPipeDepth = WHEELBOT_CONTROLLER_TLM_PIPE_DEPTH;
    memset((void*)g_WHEELBOT_CONTROLLER_AppData.cTlmPipeName, '\0', sizeof(g_WHEELBOT_CONTROLLER_AppData.cTlmPipeName));
    strncpy(g_WHEELBOT_CONTROLLER_AppData.cTlmPipeName, "WHEELBOT_CONTROLLER_TLM_PIPE", OS_MAX_API_NAME-1);

    /* Subscribe to telemetry messages on the telemetry pipe */
    iStatus = CFE_SB_CreatePipe(&g_WHEELBOT_CONTROLLER_AppData.TlmPipeId,
                                 g_WHEELBOT_CONTROLLER_AppData.usTlmPipeDepth,
                                 g_WHEELBOT_CONTROLLER_AppData.cTlmPipeName);
    if (iStatus == CFE_SUCCESS)
    {
        /* TODO:  Add CFE_SB_Subscribe() calls for other apps' output data here.
        **
        ** Examples:
        **     CFE_SB_Subscribe(GNCEXEC_OUT_DATA_MID, g_WHEELBOT_CONTROLLER_AppData.TlmPipeId);
        */
    }
    else
    {
        CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - Failed to create TLM pipe (0x%08X)\n", iStatus);
        goto WHEELBOT_CONTROLLER_InitPipe_Exit_Tag;
    }

WHEELBOT_CONTROLLER_InitPipe_Exit_Tag:
    return (iStatus);
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_InitData
**
** Purpose: To initialize global variables used by WHEELBOT_CONTROLLER application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization
**
** Routines Called:
**    CFE_SB_InitMsg
**
** Called By:
**    WHEELBOT_CONTROLLER_InitApp
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    g_WHEELBOT_CONTROLLER_AppData.InData
**    g_WHEELBOT_CONTROLLER_AppData.OutData
**    g_WHEELBOT_CONTROLLER_AppData.HkTlm
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 WHEELBOT_CONTROLLER_InitData()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init input data */
    memset((void*)&g_WHEELBOT_CONTROLLER_AppData.InData, 0x00, sizeof(g_WHEELBOT_CONTROLLER_AppData.InData));

    /* Init output data */
    memset((void*)&g_WHEELBOT_CONTROLLER_AppData.OutData, 0x00, sizeof(g_WHEELBOT_CONTROLLER_AppData.OutData));
    CFE_SB_InitMsg(&g_WHEELBOT_CONTROLLER_AppData.OutData,
                   WHEELBOT_CONTROLLER_OUT_DATA_MID, sizeof(g_WHEELBOT_CONTROLLER_AppData.OutData), TRUE);

    /* Init housekeeping packet */
    memset((void*)&g_WHEELBOT_CONTROLLER_AppData.HkTlm, 0x00, sizeof(g_WHEELBOT_CONTROLLER_AppData.HkTlm));
    CFE_SB_InitMsg(&g_WHEELBOT_CONTROLLER_AppData.HkTlm,
                   WHEELBOT_CONTROLLER_HK_TLM_MID, sizeof(g_WHEELBOT_CONTROLLER_AppData.HkTlm), TRUE);

    return (iStatus);
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_InitApp
**
** Purpose: To initialize all data local to and used by WHEELBOT_CONTROLLER application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization
**
** Routines Called:
**    CFE_ES_RegisterApp
**    CFE_ES_WriteToSysLog
**    CFE_EVS_SendEvent
**    OS_TaskInstallDeleteHandler
**    WHEELBOT_CONTROLLER_InitEvent
**    WHEELBOT_CONTROLLER_InitPipe
**    WHEELBOT_CONTROLLER_InitData
**
** Called By:
**    WHEELBOT_CONTROLLER_AppMain
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 WHEELBOT_CONTROLLER_InitApp()
{
    int32  iStatus=CFE_SUCCESS;

    g_WHEELBOT_CONTROLLER_AppData.uiRunStatus = CFE_ES_APP_RUN;

    iStatus = CFE_ES_RegisterApp();
    if (iStatus != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - Failed to register the app (0x%08X)\n", iStatus);
        goto WHEELBOT_CONTROLLER_InitApp_Exit_Tag;
    }

    if ((WHEELBOT_CONTROLLER_InitEvent() != CFE_SUCCESS) || 
        (WHEELBOT_CONTROLLER_InitPipe() != CFE_SUCCESS) || 
        (WHEELBOT_CONTROLLER_InitData() != CFE_SUCCESS))
    {
        iStatus = -1;
        goto WHEELBOT_CONTROLLER_InitApp_Exit_Tag;
    }

    /* Install the cleanup callback */
    OS_TaskInstallDeleteHandler((void*)&WHEELBOT_CONTROLLER_CleanupCallback);

WHEELBOT_CONTROLLER_InitApp_Exit_Tag:
    if (iStatus == CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_INIT_INF_EID, CFE_EVS_INFORMATION,
                          "WHEELBOT_CONTROLLER - Application initialized");
    }
    else
    {
        CFE_ES_WriteToSysLog("WHEELBOT_CONTROLLER - Application failed to initialize\n");
    }

    return (iStatus);
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_CleanupCallback
**
** Purpose: To handle any neccesary cleanup prior to application exit
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    TBD
**
** Called By:
**    TBD
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void WHEELBOT_CONTROLLER_CleanupCallback()
{
    /* TODO:  Add code to cleanup memory and other cleanup here */
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_RcvMsg
**
** Purpose: To receive and process messages for WHEELBOT_CONTROLLER application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization 
**
** Routines Called:
**    CFE_SB_RcvMsg
**    CFE_SB_GetMsgId
**    CFE_EVS_SendEvent
**    CFE_ES_PerfLogEntry
**    CFE_ES_PerfLogExit
**    WHEELBOT_CONTROLLER_ProcessNewCmds
**    WHEELBOT_CONTROLLER_ProcessNewData
**    WHEELBOT_CONTROLLER_SendOutData
**
** Called By:
**    WHEELBOT_CONTROLLER_Main
**
** Global Inputs/Reads:
**    g_WHEELBOT_CONTROLLER_AppData.SchPipeId
**
** Global Outputs/Writes:
**    g_WHEELBOT_CONTROLLER_AppData.uiRunStatus
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 WHEELBOT_CONTROLLER_RcvMsg(int32 iBlocking)
{
    int32           iStatus=CFE_SUCCESS;
    CFE_SB_Msg_t*   MsgPtr=NULL;
    CFE_SB_MsgId_t  MsgId;

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(WHEELBOT_CONTROLLER_MAIN_TASK_PERF_ID);

    /* Wait for WakeUp messages from scheduler */
    iStatus = CFE_SB_RcvMsg(&MsgPtr, g_WHEELBOT_CONTROLLER_AppData.SchPipeId, iBlocking);

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(WHEELBOT_CONTROLLER_MAIN_TASK_PERF_ID);

    if (iStatus == CFE_SUCCESS)
    {
        MsgId = CFE_SB_GetMsgId(MsgPtr);
        switch (MsgId)
	{
            case WHEELBOT_CONTROLLER_WAKEUP_MID:
                WHEELBOT_CONTROLLER_ProcessNewCmds();
                WHEELBOT_CONTROLLER_ProcessNewData();

                /* TODO:  Add more code here to handle other things when app wakes up */

                /* The last thing to do at the end of this Wakeup cycle should be to
                   automatically publish new output. */
                WHEELBOT_CONTROLLER_SendOutData();
                break;

            default:
                CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_MSGID_ERR_EID, CFE_EVS_ERROR,
                                  "WHEELBOT_CONTROLLER - Recvd invalid SCH msgId (0x%08X)", MsgId);
        }
    }
    else if (iStatus == CFE_SB_NO_MESSAGE)
    {
        /* If there's no incoming message, you can do something here, or nothing */
    }
    else
    {
        /* This is an example of exiting on an error.
        ** Note that a SB read error is not always going to result in an app quitting.
        */
        CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_PIPE_ERR_EID, CFE_EVS_ERROR,
			  "WHEELBOT_CONTROLLER: SB pipe read error (0x%08X), app will exit", iStatus);
        g_WHEELBOT_CONTROLLER_AppData.uiRunStatus= CFE_ES_APP_ERROR;
    }

    return (iStatus);
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_ProcessNewData
**
** Purpose: To process incoming data subscribed by WHEELBOT_CONTROLLER application
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    CFE_SB_RcvMsg
**    CFE_SB_GetMsgId
**    CFE_EVS_SendEvent
**
** Called By:
**    WHEELBOT_CONTROLLER_RcvMsg
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    None
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void WHEELBOT_CONTROLLER_ProcessNewData()
{
    int iStatus = CFE_SUCCESS;
    CFE_SB_Msg_t*   TlmMsgPtr=NULL;
    CFE_SB_MsgId_t  TlmMsgId;

    /* Process telemetry messages till the pipe is empty */
    while (1)
    {
        iStatus = CFE_SB_RcvMsg(&TlmMsgPtr, g_WHEELBOT_CONTROLLER_AppData.TlmPipeId, CFE_SB_POLL);
        if (iStatus == CFE_SUCCESS)
        {
            TlmMsgId = CFE_SB_GetMsgId(TlmMsgPtr);
            switch (TlmMsgId)
            {
                /* TODO:  Add code to process all subscribed data here 
                **
                ** Example:
                **     case NAV_OUT_DATA_MID:
                **         WHEELBOT_CONTROLLER_ProcessNavData(TlmMsgPtr);
                **         break;
                */

                default:
                    CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_MSGID_ERR_EID, CFE_EVS_ERROR,
                                      "WHEELBOT_CONTROLLER - Recvd invalid TLM msgId (0x%08X)", TlmMsgId);
                    break;
            }
        }
        else if (iStatus == CFE_SB_NO_MESSAGE)
        {
            break;
        }
        else
        {
            CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_PIPE_ERR_EID, CFE_EVS_ERROR,
                  "WHEELBOT_CONTROLLER: CMD pipe read error (0x%08X)", iStatus);
            g_WHEELBOT_CONTROLLER_AppData.uiRunStatus = CFE_ES_APP_ERROR;
            break;
        }
    }
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_ProcessNewCmds
**
** Purpose: To process incoming command messages for WHEELBOT_CONTROLLER application
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    CFE_SB_RcvMsg
**    CFE_SB_GetMsgId
**    CFE_EVS_SendEvent
**    WHEELBOT_CONTROLLER_ProcessNewAppCmds
**    WHEELBOT_CONTROLLER_ReportHousekeeping
**
** Called By:
**    WHEELBOT_CONTROLLER_RcvMsg
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    None
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void WHEELBOT_CONTROLLER_ProcessNewCmds()
{
    int iStatus = CFE_SUCCESS;
    CFE_SB_Msg_t*   CmdMsgPtr=NULL;
    CFE_SB_MsgId_t  CmdMsgId;

    /* Process command messages till the pipe is empty */
    while (1)
    {
        iStatus = CFE_SB_RcvMsg(&CmdMsgPtr, g_WHEELBOT_CONTROLLER_AppData.CmdPipeId, CFE_SB_POLL);
        if(iStatus == CFE_SUCCESS)
        {
            CmdMsgId = CFE_SB_GetMsgId(CmdMsgPtr);
            switch (CmdMsgId)
            {
                case WHEELBOT_CONTROLLER_CMD_MID:
                    WHEELBOT_CONTROLLER_ProcessNewAppCmds(CmdMsgPtr);
                    break;

                case WHEELBOT_CONTROLLER_SEND_HK_MID:
                    WHEELBOT_CONTROLLER_ReportHousekeeping();
                    break;

                /* TODO:  Add code to process other subscribed commands here
                **
                ** Example:
                **     case CFE_TIME_DATA_CMD_MID:
                **         WHEELBOT_CONTROLLER_ProcessTimeDataCmd(CmdMsgPtr);
                **         break;
                */

                default:
                    CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_MSGID_ERR_EID, CFE_EVS_ERROR,
                                      "WHEELBOT_CONTROLLER - Recvd invalid CMD msgId (0x%08X)", CmdMsgId);
                    break;
            }
        }
        else if (iStatus == CFE_SB_NO_MESSAGE)
        {
            break;
        }
        else
        {
            CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_PIPE_ERR_EID, CFE_EVS_ERROR,
                  "WHEELBOT_CONTROLLER: CMD pipe read error (0x%08X)", iStatus);
            g_WHEELBOT_CONTROLLER_AppData.uiRunStatus = CFE_ES_APP_ERROR;
            break;
        }
    }
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_ProcessNewAppCmds
**
** Purpose: To process command messages targeting WHEELBOT_CONTROLLER application
**
** Arguments:
**    CFE_SB_Msg_t*  MsgPtr - new command message pointer
**
** Returns:
**    None
**
** Routines Called:
**    CFE_SB_GetCmdCode
**    CFE_EVS_SendEvent
**
** Called By:
**    WHEELBOT_CONTROLLER_ProcessNewCmds
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    g_WHEELBOT_CONTROLLER_AppData.HkTlm.usCmdCnt
**    g_WHEELBOT_CONTROLLER_AppData.HkTlm.usCmdErrCnt
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void WHEELBOT_CONTROLLER_ProcessNewAppCmds(CFE_SB_Msg_t* MsgPtr)
{
    uint32  uiCmdCode=0;

    if (MsgPtr != NULL)
    {
        uiCmdCode = CFE_SB_GetCmdCode(MsgPtr);
        switch (uiCmdCode)
        {
            case WHEELBOT_CONTROLLER_NOOP_CC:
                g_WHEELBOT_CONTROLLER_AppData.HkTlm.usCmdCnt++;
                CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "WHEELBOT_CONTROLLER - Recvd NOOP cmd (%d)", uiCmdCode);
                break;

            case WHEELBOT_CONTROLLER_RESET_CC:
                g_WHEELBOT_CONTROLLER_AppData.HkTlm.usCmdCnt = 0;
                g_WHEELBOT_CONTROLLER_AppData.HkTlm.usCmdErrCnt = 0;
                CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "WHEELBOT_CONTROLLER - Recvd RESET cmd (%d)", uiCmdCode);
                break;

            /* TODO:  Add code to process the rest of the WHEELBOT_CONTROLLER commands here */

            default:
                g_WHEELBOT_CONTROLLER_AppData.HkTlm.usCmdErrCnt++;
                CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_MSGID_ERR_EID, CFE_EVS_ERROR,
                                  "WHEELBOT_CONTROLLER - Recvd invalid cmdId (%d)", uiCmdCode);
                break;
        }
    }
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_ReportHousekeeping
**
** Purpose: To send housekeeping message
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    TBD
**
** Called By:
**    WHEELBOT_CONTROLLER_ProcessNewCmds
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  GSFC, Nexsys
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void WHEELBOT_CONTROLLER_ReportHousekeeping()
{
    /* TODO:  Add code to update housekeeping data, if needed, here.  */

    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&g_WHEELBOT_CONTROLLER_AppData.HkTlm);
    CFE_SB_SendMsg((CFE_SB_Msg_t*)&g_WHEELBOT_CONTROLLER_AppData.HkTlm);
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_SendOutData
**
** Purpose: To publish 1-Wakeup cycle output data
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    TBD
**
** Called By:
**    WHEELBOT_CONTROLLER_RcvMsg
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void WHEELBOT_CONTROLLER_SendOutData()
{
    /* TODO:  Add code to update output data, if needed, here.  */

    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&g_WHEELBOT_CONTROLLER_AppData.OutData);
    CFE_SB_SendMsg((CFE_SB_Msg_t*)&g_WHEELBOT_CONTROLLER_AppData.OutData);
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_VerifyCmdLength
**
** Purpose: To verify command length for a particular command message
**
** Arguments:
**    CFE_SB_Msg_t*  MsgPtr      - command message pointer
**    uint16         usExpLength - expected command length
**
** Returns:
**    boolean bResult - result of verification
**
** Routines Called:
**    TBD
**
** Called By:
**    WHEELBOT_CONTROLLER_ProcessNewCmds
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
boolean WHEELBOT_CONTROLLER_VerifyCmdLength(CFE_SB_Msg_t* MsgPtr,
                           uint16 usExpectedLen)
{
    boolean bResult=FALSE;
    uint16  usMsgLen=0;

    if (MsgPtr != NULL)
    {
        usMsgLen = CFE_SB_GetTotalMsgLength(MsgPtr);

        if (usExpectedLen != usMsgLen)
        {
            CFE_SB_MsgId_t MsgId = CFE_SB_GetMsgId(MsgPtr);
            uint16 usCmdCode = CFE_SB_GetCmdCode(MsgPtr);

            CFE_EVS_SendEvent(WHEELBOT_CONTROLLER_MSGLEN_ERR_EID, CFE_EVS_ERROR,
                              "WHEELBOT_CONTROLLER - Rcvd invalid msgLen: msgId=0x%08X, cmdCode=%d, "
                              "msgLen=%d, expectedLen=%d",
                              MsgId, usCmdCode, usMsgLen, usExpectedLen);
            g_WHEELBOT_CONTROLLER_AppData.HkTlm.usCmdErrCnt++;
        }
    }

    return (bResult);
}
    
/*=====================================================================================
** Name: WHEELBOT_CONTROLLER_AppMain
**
** Purpose: To define WHEELBOT_CONTROLLER application's entry point and main process loop
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    CFE_ES_RegisterApp
**    CFE_ES_RunLoop
**    CFE_ES_PerfLogEntry
**    CFE_ES_PerfLogExit
**    CFE_ES_ExitApp
**    CFE_ES_WaitForStartupSync
**    WHEELBOT_CONTROLLER_InitApp
**    WHEELBOT_CONTROLLER_RcvMsg
**
** Called By:
**    TBD
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Nexsys 
**
** History:  Date Written  yyyy-mm-dd
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void WHEELBOT_CONTROLLER_AppMain()
{
    /* Register the application with Executive Services */
    CFE_ES_RegisterApp();

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(WHEELBOT_CONTROLLER_MAIN_TASK_PERF_ID);

    /* Perform application initializations */
    if (WHEELBOT_CONTROLLER_InitApp() != CFE_SUCCESS)
    {
        g_WHEELBOT_CONTROLLER_AppData.uiRunStatus = CFE_ES_APP_ERROR;
    } else {
        /* Do not perform performance monitoring on startup sync */
        CFE_ES_PerfLogExit(WHEELBOT_CONTROLLER_MAIN_TASK_PERF_ID);
        CFE_ES_WaitForStartupSync(WHEELBOT_CONTROLLER_TIMEOUT_MSEC);
        CFE_ES_PerfLogEntry(WHEELBOT_CONTROLLER_MAIN_TASK_PERF_ID);
    }

    /* Application main loop */
    while (CFE_ES_RunLoop(&g_WHEELBOT_CONTROLLER_AppData.uiRunStatus) == TRUE)
    {
        WHEELBOT_CONTROLLER_RcvMsg(CFE_SB_PEND_FOREVER);
    }

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(WHEELBOT_CONTROLLER_MAIN_TASK_PERF_ID);

    /* Exit the application */
    CFE_ES_ExitApp(g_WHEELBOT_CONTROLLER_AppData.uiRunStatus);
} 
    
/*=======================================================================================
** End of file wheelbot_controller_app.c
**=====================================================================================*/
    