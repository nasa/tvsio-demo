#ifndef TEMP_CONTROLLER_MSG_H
#define TEMP_CONTROLLER_MSG_H

#include "cfe_msg_api_typedefs.h"

typedef struct
{

    CFE_MSG_TelemetryHeader_t cfsHeader;
    float temperature;

} TEMP_CONTROLLER_TLM_t;

typedef struct
{
    
    CFE_MSG_CommandHeader_t commandHeader;
    uint8 reset_flag;
    uint8 pad[3];

} TEMP_CONTROLLER_CMD_t;

#endif
