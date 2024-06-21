#ifndef __TEMP_STRUCT_DEF_H__
#define __TEMP_STRUCT_DEF_H__

#define STRUCT_TEMP_MID 0x01DD
#define STRUCT_TEMP_CMD_MID 0xBABE

typedef struct
{
    char cfsHeader[16];
    float temperature;
    double speed;

} Struct_Temp;

typedef struct
{
    char commandHeader[CFE_SB_CMD_HDR_SIZE];    // 16 bytes
    uint8 reset_flag;

} Temp_Cmd;

#endif
