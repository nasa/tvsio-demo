#ifndef GNC_PROP_APP_MSG_H
#define GNC_PROP_APP_MSG_H

#include "cfe.h"

/**********************************************
 *  Sensors Telemetry (SIM_SENSORS → cFS)
 **********************************************/
typedef struct
{
    CFE_MSG_TelemetryHeader_t TlmHeader;

    double gyro_x;
    double gyro_y;
    double gyro_z;

    double accel_x;
    double accel_y;
    double accel_z;

    int32  health_counter;
    int32  sensor_mode;
    int32  sun_visible;

    char   status_msg[32];

    double timestamp;

    double pkt0_temp;
    double pkt0_volt;
    int32  pkt0_fault;

    double pkt1_temp;
    double pkt1_volt;
    int32  pkt1_fault;

} GNC_SENSORS_TLM_t;


/**********************************************
 *  Thruster Telemetry (SIM_THRUSTERS → cFS)
 **********************************************/
typedef struct
{
    CFE_MSG_TelemetryHeader_t TlmHeader;

    double amom_x;
    double amom_y;
    double amom_z;

    float  prop_mass;

    int32  valve0;
    int32  valve1;
    int32  valve2;
    int32  valve3;

    char   info_msg[32];

} GNC_THRUSTER_TLM_t;


/**********************************************
 *  Thruster Command Packet (cFS → Trick)
 **********************************************/
typedef struct
{
    CFE_MSG_CommandHeader_t CommandHeader;

    float  thr_cmd_0;
    float  thr_cmd_1;
    float  thr_cmd_2;
    float  thr_cmd_3;

    int32  enable_fire;
    int32  fire_mode;

    double config_maxf;
    int32  config_id;

} GNC_THRUSTER_CMD_t;

#endif