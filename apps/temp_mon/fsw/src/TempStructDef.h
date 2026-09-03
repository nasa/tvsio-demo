#ifndef __TEMP_STRUCT_DEF_H__
#define __TEMP_STRUCT_DEF_H__

typedef struct
{

    CFE_MSG_TelemetryHeader_t cfsHeader;
    float temperature;

} Struct_Temp;

typedef struct
{
    
    CFE_MSG_CommandHeader_t commandHeader;
    uint8 reset_flag;
    uint8 pad[3];

} Temp_Cmd;

#endif
