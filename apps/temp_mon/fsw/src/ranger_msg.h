#ifndef RANGER_MSG_H
#define RANGER_MSG_H

#include "cfe_msg_api_typedefs.h"

typedef struct
{
    CFE_MSG_TelemetryHeader_t  TlmHeader;
    double vv_range;                          ///< [   16] (8 bytes)  MPCV range relative to the Gateway
    double vv_rangerate;                      ///< [   24] (8 bytes)  MPCV range rate relative to the Gateway

} RANGER_TLM_t;     ///<  Total size of 32 bytes

typedef struct
{

    CFE_MSG_CommandHeader_t commandHeader;
    float temperature;

} RANGER_CMD_t;

#endif