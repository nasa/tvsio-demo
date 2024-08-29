#ifndef __TEMP_MSG_DEF_H__
#define __TEMP_MSG_DEF_H__

#define STRUCT_TEMP_MSG_MID 0xABCD

typedef struct
{
    char cfsHeader[CFE_SB_CMD_HDR_SIZE];
    char message[50];

} Struct_TempMsg;

#endif
