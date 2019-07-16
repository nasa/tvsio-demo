/* Created : Tue Jul 17 07:08:44 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): mda, CCSDS_TLM_HDR, CCSDS_Primary */

#ifndef _MDA_TYPES_H_
#define _MDA_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure mda (4196 bytes in size)  **/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  char device[11];                            ///< [   16] (11x1=11 bytes)  The device the epoch is associated with. Example: HX-00001689
  uint8_t pad;                                ///< [   27] (1 bytes)  Force next item to start on address divisible by 8
  uint64_t record;                            ///< [   28] (8 bytes)  The record the epoch is associated with (epoch + record/256 gives the UNIX timestamp of the data (seconds since 1/1/1970).)
  uint32_t epoch;                             ///< [   36] (4 bytes)  The epoch number (epoch + record/256 gives the UNIX timestamp of the data (seconds since 1/1/1970).)
  uint32_t battery;                           ///< [   40] (4 bytes)  Raw ADC battery value
  uint32_t ecg_status;                        ///< [   44] (4 bytes)  The ECG channels status
  uint32_t resp_status;                       ///< [   48] (4 bytes)  The respiration channels status
  uint32_t ppg_status;                        ///< [   52] (4 bytes)  PPG channel status
  int32_t ecg_I[256];                         ///< [   56] (256x4=1024 bytes)  ECG Lead I
  int32_t ecg_II[256];                        ///< [ 1080] (256x4=1024 bytes)  ECG Lead II
  uint32_t abdo[128];                         ///< [ 2104] (128x4=512 bytes)  Abdominal respiration
  uint32_t thor[128];                         ///< [ 2616] (128x4=512 bytes)  Thoracic respiration
  int32_t x[64];                              ///< [ 3128] (64x4=256 bytes)  Acc X
  int32_t y[64];                              ///< [ 3384] (64x4=256 bytes)  Acc Y
  int32_t z[64];                              ///< [ 3640] (64x4=256 bytes)  Acc Z
  uint32_t ppg[64];                           ///< [ 3896] (64x4=256 bytes)  Astroskin only; Photoplethysmography
  uint32_t temperatureSample;                 ///< [ 4152] (4 bytes)  Astroskin only; Raw ADC temperature value
  uint32_t e_hr;                              ///< [ 4156] (4 bytes)  Heart Rate value from the ECG signal in beat per minute
  uint32_t br;                                ///< [ 4160] (4 bytes)  Breathing rate value in breath per minute
  uint32_t mv;                                ///< [ 4164] (4 bytes)  Minute ventillation value in
  uint32_t vt;                                ///< [ 4168] (4 bytes)  Tidal volume value in
  uint32_t act;                               ///< [ 4172] (4 bytes)  Activity amplitude value in g
  uint32_t cad;                               ///< [ 4176] (4 bytes)  Cadence value in steps per minutes
  uint32_t p_hr;                              ///< [ 4180] (4 bytes)  Heart Rate value from the PPG in beat per minute
  uint32_t spo2;                              ///< [ 4184] (4 bytes)  SPO2 value in percent
  float temperature;                          ///< [ 4188] (4 bytes)  Temperature value in celsius
  uint32_t bp;                                ///< [ 4192] (4 bytes)  Systolic Blood Pressure in mmHG
} mda;     ///<  Total size of 4196 bytes

void byteswap_mda(mda *inPtr, mda *outPtr, int direction);
void bitswap_mda(mda *inPtr, mda *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _MDA_TYPES_H_
