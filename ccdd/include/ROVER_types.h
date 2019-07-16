/* Created : Thu Jan 31 12:25:02 CST 2019
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): ROVER_GNC_TLM, CCSDS_TLM_HDR, CCSDS_Primary */

#ifndef _ROVER_TYPES_H_
#define _ROVER_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure ROVER_GNC_TLM (467 bytes in size)  *
* Rover simulation GNC data for downlink to drive MCC gaphical scene generation
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                      ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  double ROVER_FIXED_NODE1_R_REF2NODE_X;        ///< [   16] (8 bytes)  
  double ROVER_FIXED_NODE1_R_REF2NODE_Y;        ///< [   24] (8 bytes)  
  double ROVER_FIXED_NODE1_R_REF2NODE_Z;        ///< [   32] (8 bytes)  
  double ROVER_FIXED_NODE1_E_REF2NODE_0;        ///< [   40] (8 bytes)  
  double ROVER_FIXED_NODE1_E_REF2NODE_1;        ///< [   48] (8 bytes)  
  double ROVER_FIXED_NODE1_E_REF2NODE_2;        ///< [   56] (8 bytes)  
  double ROVER_FIXED_NODE2_R_REF2NODE_X;        ///< [   64] (8 bytes)  
  double ROVER_FIXED_NODE2_R_REF2NODE_Y;        ///< [   72] (8 bytes)  
  double ROVER_FIXED_NODE2_R_REF2NODE_Z;        ///< [   80] (8 bytes)  
  double ROVER_FIXED_NODE2_E_REF2NODE_0;        ///< [   88] (8 bytes)  
  double ROVER_FIXED_NODE2_E_REF2NODE_1;        ///< [   96] (8 bytes)  
  double ROVER_FIXED_NODE2_E_REF2NODE_2;        ///< [  104] (8 bytes)  
  double ROVER_POI0_R_DISPLAY2POI_X;            ///< [  112] (8 bytes)  
  double ROVER_POI0_R_DISPLAY2POI_Y;            ///< [  120] (8 bytes)  
  double ROVER_POI0_R_DISPLAY2POI_Z;            ///< [  128] (8 bytes)  
  double ROVER_POI0_E_DISPLAY2POI_0;            ///< [  136] (8 bytes)  
  double ROVER_POI0_E_DISPLAY2POI_1;            ///< [  144] (8 bytes)  
  double ROVER_POI0_E_DISPLAY2POI_2;            ///< [  152] (8 bytes)  
  double ROVER_POI1_R_DISPLAY2POI_X;            ///< [  160] (8 bytes)  
  double ROVER_POI1_R_DISPLAY2POI_Y;            ///< [  168] (8 bytes)  
  double ROVER_POI1_R_DISPLAY2POI_Z;            ///< [  176] (8 bytes)  
  double ROVER_POI1_E_DISPLAY2POI_0;            ///< [  184] (8 bytes)  
  double ROVER_POI1_E_DISPLAY2POI_1;            ///< [  192] (8 bytes)  
  double ROVER_POI1_E_DISPLAY2POI_2;            ///< [  200] (8 bytes)  
  double ROVER_POI2_R_DISPLAY2POI_X;            ///< [  208] (8 bytes)  
  double ROVER_POI2_R_DISPLAY2POI_Y;            ///< [  216] (8 bytes)  
  double ROVER_POI2_R_DISPLAY2POI_Z;            ///< [  224] (8 bytes)  
  double ROVER_POI2_E_DISPLAY2POI_0;            ///< [  232] (8 bytes)  
  double ROVER_POI2_E_DISPLAY2POI_1;            ///< [  240] (8 bytes)  
  double ROVER_POI2_E_DISPLAY2POI_2;            ///< [  248] (8 bytes)  
  double ROVER_POI3_R_DISPLAY2POI_X;            ///< [  256] (8 bytes)  
  double ROVER_POI3_R_DISPLAY2POI_Y;            ///< [  264] (8 bytes)  
  double ROVER_POI3_R_DISPLAY2POI_Z;            ///< [  272] (8 bytes)  
  double ROVER_POI3_E_DISPLAY2POI_0;            ///< [  280] (8 bytes)  
  double ROVER_POI3_E_DISPLAY2POI_1;            ///< [  288] (8 bytes)  
  double ROVER_POI3_E_DISPLAY2POI_2;            ///< [  296] (8 bytes)  
  double ROVER_POI4_R_DISPLAY2POI_X;            ///< [  304] (8 bytes)  
  double ROVER_POI4_R_DISPLAY2POI_Y;            ///< [  312] (8 bytes)  
  double ROVER_POI4_R_DISPLAY2POI_Z;            ///< [  320] (8 bytes)  
  double ROVER_POI4_E_DISPLAY2POI_0;            ///< [  328] (8 bytes)  
  double ROVER_POI4_E_DISPLAY2POI_1;            ///< [  336] (8 bytes)  
  double ROVER_POI4_E_DISPLAY2POI_2;            ///< [  344] (8 bytes)  
  double ROVER_RANGEFINDER_CAM_ANG_0;           ///< [  352] (8 bytes)  
  double ROVER_RANGEFINDER_CAM_ANG_1;           ///< [  360] (8 bytes)  
  double ROVER_RANGEFINDER_CAM_ANG_2;           ///< [  368] (8 bytes)  
  double ROVER_RANGEFINDER_CAM_ZOOM;            ///< [  376] (8 bytes)  
  uint8_t ROVER_RANGEFINDER_CAM_HOMING;         ///< [  384] (1 bytes)  
  uint8_t ROVER_RANGEFINDER_CAM_FIXATED;        ///< [  385] (1 bytes)  
  double ROVER_RANGEFINDER_CAM_RANGE;           ///< [  386] (8 bytes)  
  double ROVER_RANGEFINDER_CAM_RANGE_RATE;      ///< [  394] (8 bytes)  
  double ROVER_CONTROL_VEL_X;                   ///< [  402] (8 bytes)  
  double ROVER_CONTROL_VEL_Y;                   ///< [  410] (8 bytes)  
  double ROVER_CONTROL_VEL_Z;                   ///< [  418] (8 bytes)  
  double ROVER_CONTROL_RANGE;                   ///< [  426] (8 bytes)  
  double ROVER_CONTROL_RATE_AVERAGE;            ///< [  434] (8 bytes)  
  double ROVER_LATITUDE;                        ///< [  442] (8 bytes)  
  double ROVER_LONGITUDE;                       ///< [  450] (8 bytes)  
  double ROVER_ALTITUDE;                        ///< [  458] (8 bytes)  
  uint8_t ROVER_BRAKE_APPLIED;                  ///< [  466] (1 bytes)  
} ROVER_GNC_TLM;     ///<  Total size of 467 bytes

void byteswap_ROVER_GNC_TLM(ROVER_GNC_TLM *inPtr, ROVER_GNC_TLM *outPtr, int direction);
void bitswap_ROVER_GNC_TLM(ROVER_GNC_TLM *inPtr, ROVER_GNC_TLM *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _ROVER_TYPES_H_
