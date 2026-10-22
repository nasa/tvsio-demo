#include "gnc_prop_app.h"
#include "gnc_prop_app_events.h"
#include "gnc_prop_app_version.h"

#include <string.h>
#include <math.h>

/* Global application data */
GNC_PROP_AppData_t g_GNC_PROP_AppData;

/******************************************************************************
** Application entry point
******************************************************************************/
void GNC_PROP_AppMain(void)
{
    int32 status;
    CFE_SB_Buffer_t *pMsg = NULL;
    CFE_SB_MsgId_t msgId;

    status = GNC_PROP_AppInit();
    if (status != CFE_SUCCESS)
    {
        g_GNC_PROP_AppData.RunStatus = CFE_ES_RunStatus_APP_ERROR;
    }

    /* Main loop */
    while (CFE_ES_RunLoop(&g_GNC_PROP_AppData.RunStatus))
    {
        status = CFE_SB_ReceiveBuffer(&pMsg, g_GNC_PROP_AppData.TvsioPipeId, CFE_SB_PEND_FOREVER);
        if (status == CFE_SUCCESS && pMsg != NULL)
        {
            CFE_MSG_GetMsgId(&pMsg->Msg, &msgId);

            switch (CFE_SB_MsgIdToValue(msgId))
            {
                /* Sensors telemetry (SIM_SENSORS → cFS) */
                case GNC_SENSORS_TLM_MID:
                    memcpy(&g_GNC_PROP_AppData.SensorsTlm, pMsg, sizeof(GNC_SENSORS_TLM_t));
                    break;

                /* Thruster telemetry (SIM_THRUSTERS → cFS) */
                case GNC_THRUSTER_TLM_MID:
                    memcpy(&g_GNC_PROP_AppData.ThrusterTlm, pMsg, sizeof(GNC_THRUSTER_TLM_t));
                    break;

                /* Commands directed to this app (NOOP, RESET, etc.) */
                case GNC_PROP_CMD_MID:
                    GNC_PROP_ProcessCommandPacket(&pMsg->Msg);
                    break;

                default:
                    CFE_EVS_SendEvent(GNC_PROP_INVALID_MSGID_ERR_EID,
                                      CFE_EVS_EventType_ERROR,
                                      "GNC_PROP: Invalid message ID 0x%08X",
                                      CFE_SB_MsgIdToValue(msgId));
                    break;
            }
            /* Increment print counter for periodic status messages */
            g_GNC_PROP_AppData.PrintCounter++;

            /* Simple GNC test logic: If gyro magnitude > threshold → fire thrusters */
            double mag = fabs(g_GNC_PROP_AppData.SensorsTlm.gyro_x) +
                         fabs(g_GNC_PROP_AppData.SensorsTlm.gyro_y) +
                         fabs(g_GNC_PROP_AppData.SensorsTlm.gyro_z);

            if (mag > GYRO_MAG_THRUSTER_ENABLE)
            {
                g_GNC_PROP_AppData.ThrusterCmd.thr_cmd_0 = 0.2f;
                g_GNC_PROP_AppData.ThrusterCmd.thr_cmd_1 = 0.1f;
                g_GNC_PROP_AppData.ThrusterCmd.thr_cmd_2 = 0.0f;
                g_GNC_PROP_AppData.ThrusterCmd.thr_cmd_3 = 0.1f;
                g_GNC_PROP_AppData.ThrusterCmd.enable_fire = 1;

                /* low‑spam logging */
                if (!g_GNC_PROP_AppData.ThrustersWereFiring)
                {
                    OS_printf("GNC_PROP: Thrusters ACTIVATED due to gyro magnitude %.4f\n", mag);
                }

                g_GNC_PROP_AppData.ThrustersWereFiring = true;
            }
            else
            {
                /* Deactivate thrusters */
                g_GNC_PROP_AppData.ThrusterCmd.thr_cmd_0 = 0.0f;
                g_GNC_PROP_AppData.ThrusterCmd.thr_cmd_1 = 0.0f;
                g_GNC_PROP_AppData.ThrusterCmd.thr_cmd_2 = 0.0f;
                g_GNC_PROP_AppData.ThrusterCmd.thr_cmd_3 = 0.0f;
                g_GNC_PROP_AppData.ThrusterCmd.enable_fire = 0;
            
                if (g_GNC_PROP_AppData.ThrustersWereFiring)
                {
                    OS_printf("GNC_PROP: Thrusters DEACTIVATED (mag=%.4f)\n", mag);
                }

                g_GNC_PROP_AppData.ThrustersWereFiring = false;
            }

            /* Send the command packet to TVS‑IO so it reaches SIM_THRUSTERS */
            CFE_SB_TimeStampMsg(&g_GNC_PROP_AppData.ThrusterCmd.CommandHeader.Msg);
            CFE_SB_TransmitMsg(&g_GNC_PROP_AppData.ThrusterCmd.CommandHeader.Msg, true);
        
            if (g_GNC_PROP_AppData.PrintCounter % 50 == 0) // 10Hz loop -> 5s heartbeat print
            {
                OS_printf("GNC_PROP STATUS: GyroMag=%.4f  PropMass=%.3f  Valve0=%d\n",
                          mag,
                          g_GNC_PROP_AppData.ThrusterTlm.prop_mass,
                          g_GNC_PROP_AppData.ThrusterTlm.valve0);
            }
        }
    }

    CFE_ES_ExitApp(g_GNC_PROP_AppData.RunStatus);
}

/******************************************************************************
** Initialization
******************************************************************************/
int32 GNC_PROP_AppInit(void)
{
    int32 status;

    g_GNC_PROP_AppData.RunStatus = CFE_ES_RunStatus_APP_RUN;

    /* Register events */
    status = CFE_EVS_Register(NULL, 0, 0);
    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("GNC_PROP: Error registering events RC=0x%08lX\n", (unsigned long)status);
        return status;
    }

    /* Initialize command counters */
    g_GNC_PROP_AppData.CmdCounter = 0;
    g_GNC_PROP_AppData.ErrCounter = 0;

    g_GNC_PROP_AppData.PrintCounter = 0;
    g_GNC_PROP_AppData.ThrustersWereFiring = false;

    /* Create TVS‑IO pipe */
    snprintf(g_GNC_PROP_AppData.TvsioPipeName, OS_MAX_API_NAME, "GNC_PROP_TVSIO_PIPE");

    status = CFE_SB_CreatePipe(&g_GNC_PROP_AppData.TvsioPipeId,
                               GNC_PROP_TVSIO_PIPE_DEPTH,
                               g_GNC_PROP_AppData.TvsioPipeName);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("GNC_PROP: Error creating pipe RC=0x%08lX\n", (unsigned long)status);
        return status;
    }

    /* Subscribe to TVS‑IO telemetry MIDs */
    status = CFE_SB_Subscribe(CFE_SB_ValueToMsgId(GNC_SENSORS_TLM_MID), g_GNC_PROP_AppData.TvsioPipeId);
    status |= CFE_SB_Subscribe(CFE_SB_ValueToMsgId(GNC_THRUSTER_TLM_MID), g_GNC_PROP_AppData.TvsioPipeId);

    /* Subscribe to commands */
    status |= CFE_SB_Subscribe(CFE_SB_ValueToMsgId(GNC_PROP_CMD_MID), g_GNC_PROP_AppData.TvsioPipeId);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("GNC_PROP: Error subscribing RC=0x%08lX\n", (unsigned long)status);
        return status;
    }

    /* Initialize the thruster command message */
    CFE_MSG_Init(&g_GNC_PROP_AppData.ThrusterCmd.CommandHeader.Msg,
                 CFE_SB_ValueToMsgId(GNC_THRUSTER_CMD_MID),
                 sizeof(GNC_THRUSTER_CMD_t));

    /* Set function code (required if nonzero in tvm file) */
    CFE_MSG_SetFcnCode(&g_GNC_PROP_AppData.ThrusterCmd.CommandHeader.Msg, 1);

    CFE_EVS_SendEvent(GNC_PROP_STARTUP_INF_EID,
                      CFE_EVS_EventType_INFORMATION,
                      "GNC_PROP App Initialized.");

    memset(&g_GNC_PROP_AppData.SensorsTlm, 0, sizeof(GNC_SENSORS_TLM_t));
    memset(&g_GNC_PROP_AppData.ThrusterTlm, 0, sizeof(GNC_THRUSTER_TLM_t));

    return CFE_SUCCESS;
}

/******************************************************************************
** Command Dispatcher (Only simple commands used for now)
******************************************************************************/
void GNC_PROP_ProcessCommandPacket(CFE_MSG_Message_t *Msg)
{
    CFE_MSG_FcnCode_t cmdCode;
    CFE_MSG_GetFcnCode(Msg, &cmdCode);

    switch (cmdCode)
    {
        case GNC_PROP_NOOP_CC:
            g_GNC_PROP_AppData.CmdCounter++;
            CFE_EVS_SendEvent(GNC_PROP_NOOP_INF_EID,
                              CFE_EVS_EventType_INFORMATION,
                              "GNC_PROP: NOOP");
            break;

        case GNC_PROP_RESET_CC:
            g_GNC_PROP_AppData.CmdCounter = 0;
            g_GNC_PROP_AppData.ErrCounter = 0;
            CFE_EVS_SendEvent(GNC_PROP_RESET_INF_EID,
                              CFE_EVS_EventType_INFORMATION,
                              "GNC_PROP: RESET counters");
            break;

        default:
            g_GNC_PROP_AppData.ErrCounter++;
            CFE_EVS_SendEvent(GNC_PROP_COMMAND_ERR_EID,
                              CFE_EVS_EventType_ERROR,
                              "GNC_PROP: Invalid Cmd Code %d",
                              cmdCode);
            break;
    }
}