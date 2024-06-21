#ifndef __RPODVSM_STRUCT_DEF_H__
#define __RPODVSM_STRUCT_DEF_H__

#define STRUCT_RPODVSM_MID 0x6A01
#define RPOD_TEMP_CMD_MID 0xBABF

typedef struct
{
    char cfsHeader[16];                       ///< [    0] (16 bytes) Extended CFS SB message Header #CCSDS_TLM_HDR
    double vv_range;                          ///< [   16] (8 bytes)  MPCV range relative to the Gateway
    double vv_rangerate;                      ///< [   24] (8 bytes)  MPCV range rate relative to the Gateway

} MPCV_GNC_TLM;     ///<  Total size of 32 bytes

typedef struct
{
    char commandHeader[CFE_SB_CMD_HDR_SIZE];
    float temperature;
    float speed;

} RPOD_TEMP_CMD;

#endif