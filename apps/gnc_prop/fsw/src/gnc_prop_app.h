#ifndef GNC_PROP_APP_H
#define GNC_PROP_APP_H

#include "cfe.h"
#include "gnc_prop_app_msg.h"
#include "gnc_prop_app_msgids.h"
#include "gnc_prop_app_msgdefs.h"
#include "gnc_prop_app_events.h"
#include "gnc_prop_app_version.h"

#define GNC_PROP_TVSIO_PIPE_DEPTH  20
#define GYRO_MAG_THRUSTER_ENABLE   0.02

typedef struct
{
    /* cFS runtime fields */
    CFE_ES_RunStatus_Enum_t  RunStatus;

    /* Command counters */
    uint16 CmdCounter;
    uint16 ErrCounter;

    /* TVSIO Pipe */
    CFE_SB_PipeId_t TvsioPipeId;
    uint16          TvsioPipeDepth;
    char            TvsioPipeName[OS_MAX_API_NAME];

    /* Output control vars */
    uint32 PrintCounter;
    bool   ThrustersWereFiring;

    /* Cached telemetry from SIM_SENSORS */
    GNC_SENSORS_TLM_t   SensorsTlm;

    /* Cached telemetry from SIM_THRUSTERS */
    GNC_THRUSTER_TLM_t  ThrusterTlm;

    /* Outgoing command packet (to Trick via TVSIO) */
    GNC_THRUSTER_CMD_t  ThrusterCmd;

} GNC_PROP_AppData_t;


extern GNC_PROP_AppData_t g_GNC_PROP_AppData;

/* Entry point */
void GNC_PROP_AppMain(void);

/* Init */
int32 GNC_PROP_AppInit(void);

/* Command dispatcher */
void GNC_PROP_ProcessCommandPacket(CFE_MSG_Message_t *Msg);

#endif