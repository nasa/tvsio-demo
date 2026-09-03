#ifndef __RPODVSM_STRUCT_DEF_H__
#define __RPODVSM_STRUCT_DEF_H__



typedef struct
{
    CFE_MSG_TelemetryHeader_t  TlmHeader;
    double vv_range;                          ///< [   16] (8 bytes)  MPCV range relative to the Gateway
    double vv_rangerate;                      ///< [   24] (8 bytes)  MPCV range rate relative to the Gateway

} MPCV_GNC_TLM;     ///<  Total size of 32 bytes

typedef struct
{

    CFE_MSG_CommandHeader_t commandHeader;
    float temperature;

} RPOD_TEMP_CMD;

#endif