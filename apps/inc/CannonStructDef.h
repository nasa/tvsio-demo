#ifndef __CANNON_STRUCT_DEF_H__
#define __CANNON_STRUCT_DEF_H__

#include "shared_types.h"
#include "common_types.h"

#define STRUCT_CANNON_MID 0x7e6a
#define STRUCT_CANNON_2_MID 0x7e6b
#define STRUCT_CANNON_3_MID 0x7e6c
#define STRUCT_CANNON_SET_VEL_CMD_MID 0x843d

typedef struct
{
    CCSDS_Primary primaryHeader;
    uint16 secondaryHeader;

    float vel[2];

    char mystring[512];

} Struct_Cannon_SetVelCmd;

typedef struct
{
    CCSDS_TLM_HDR header;
    
    int16 lower_set : 4;
    int16 upper_set : 3;
    double delta_time;

} Regula_Falsi;

typedef struct
{
    CCSDS_TLM_HDR header;

    Regula_Falsi rf;

    float impact;
    float pos[2];
    float vel[2];

    char mystring[512];

} Struct_Cannon;

typedef struct 
{
    CCSDS_TLM_HDR header;

    char blob[8171];

    float vel0[2];
    float pos0[2];

} Struct_Cannon2;

typedef struct 
{
    CCSDS_TLM_HDR header;

    Struct_Cannon2 cannon2;

    int16 impact;

} Struct_Cannon3;

#endif