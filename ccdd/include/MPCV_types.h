/* Created : Wed Aug 08 15:13:28 CDT 2018
   User    : rhirsh
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): MPCV_NAV_STATE_TLM, CCSDS_TLM_HDR, CCSDS_Primary */

#ifndef _MPCV_TYPES_H_
#define _MPCV_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure MPCV_NAV_STATE_TLM (144 bytes in size)  *
* generated from Trick sim
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  double TIME_TDB_SECONDS;                    ///< [   16] (8 bytes)  barycentric dynamical time
  double INRTL_ATT_ROLL;                      ///< [   24] (8 bytes)  inertial to body Euler roll angle in RPY sequence
  double INRTL_ATT_PITCH;                     ///< [   32] (8 bytes)  inertial to body Euler pitch angle in RPY sequence
  double INRTL_ATT_YAW;                       ///< [   40] (8 bytes)  inertial to body Euler yaw angle in RPY sequence
  double INRTL_POS_X;                         ///< [   48] (8 bytes)  inertial to c.g. position X expressed in inertial frame
  double INRTL_POS_Y;                         ///< [   56] (8 bytes)  inertial to c.g. position Y expressed in inertial frame
  double INRTL_POS_Z;                         ///< [   64] (8 bytes)  inertial to c.g. position Z expressed in inertial frame
  double TGT_TO_VEH_ATT_ROLL;                 ///< [   72] (8 bytes)  target docking port to vehicle docking port Euler roll angle in RPY sequence
  double TGT_TO_VEH_ATT_PITCH;                ///< [   80] (8 bytes)  target docking port to vehicle docking port Euler pitch angle in RPY sequence
  double TGT_TO_VEH_ATT_YAW;                  ///< [   88] (8 bytes)  target docking port to vehicle docking port Euler yaw angle in RPY sequence
  double TGT_TO_VEH_POS_X;                    ///< [   96] (8 bytes)  target docking port to vehicle docking port position X expressed in target docking port frame
  double TGT_TO_VEH_POS_Y;                    ///< [  104] (8 bytes)  target docking port to vehicle docking port position Y expressed in target docking port frame
  double TGT_TO_VEH_POS_Z;                    ///< [  112] (8 bytes)  target docking port to vehicle docking port position Z expressed in target docking port frame
  double CG_POS_X;                            ///< [  120] (8 bytes)  c.g. position X in structural frame
  double CG_POS_Y;                            ///< [  128] (8 bytes)  c.g. position Y in structural frame
  double CG_POS_Z;                            ///< [  136] (8 bytes)  c.g. position Z in structural frame
} MPCV_NAV_STATE_TLM;     ///<  Total size of 144 bytes

void byteswap_MPCV_NAV_STATE_TLM(MPCV_NAV_STATE_TLM *inPtr, MPCV_NAV_STATE_TLM *outPtr, int direction);
void bitswap_MPCV_NAV_STATE_TLM(MPCV_NAV_STATE_TLM *inPtr, MPCV_NAV_STATE_TLM *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _MPCV_TYPES_H_
