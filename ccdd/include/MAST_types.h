/* Created : Mon Oct 29 15:25:20 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): mast_ppe_esm_command, CCSDS_TLM_HDR, CCSDS_Primary, mast_ppe_esm_state_description, mast_state_description */

#ifndef _MAST_TYPES_H_
#define _MAST_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure mast_ppe_esm_command (656 bytes in size)  *
* mast to mast exchange of power information
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                      ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  char power_advisory[256];                     ///< [   16] (256x1=256 bytes)  
  char power_request_for_information[256];      ///< [  272] (256x1=256 bytes)  
  uint32_t power_command_pdu1_rpc1;             ///< [  528] (4 bytes)  
  uint32_t power_command_pdu1_rpc1_ext;         ///< [  532] (4 bytes)  
  uint32_t power_command_pdu1_rpc2;             ///< [  536] (4 bytes)  
  uint32_t power_command_pdu1_rpc2_ext;         ///< [  540] (4 bytes)  
  uint32_t power_command_pdu1_rpc3;             ///< [  544] (4 bytes)  
  uint32_t power_command_pdu1_rpc3_ext;         ///< [  548] (4 bytes)  
  uint32_t power_command_pdu1_rpc4;             ///< [  552] (4 bytes)  
  uint32_t power_command_pdu1_rpc4_ext;         ///< [  556] (4 bytes)  
  uint32_t power_command_pdu1_rpc5;             ///< [  560] (4 bytes)  
  uint32_t power_command_pdu1_rpc5_ext;         ///< [  564] (4 bytes)  
  uint32_t power_command_pdu1_rpc6;             ///< [  568] (4 bytes)  
  uint32_t power_command_pdu1_rpc6_ext;         ///< [  572] (4 bytes)  
  uint32_t power_command_pdu1_rpc7;             ///< [  576] (4 bytes)  
  uint32_t power_command_pdu1_rpc7_ext;         ///< [  580] (4 bytes)  
  uint32_t power_command_pdu1_rpc8;             ///< [  584] (4 bytes)  
  uint32_t power_command_pdu1_rpc8_ext;         ///< [  588] (4 bytes)  
  uint32_t power_command_pdu2_rpc1;             ///< [  592] (4 bytes)  
  uint32_t power_command_pdu2_rpc1_ext;         ///< [  596] (4 bytes)  
  uint32_t power_command_pdu2_rpc2;             ///< [  600] (4 bytes)  
  uint32_t power_command_pdu2_rpc2_ext;         ///< [  604] (4 bytes)  
  uint32_t power_command_pdu2_rpc3;             ///< [  608] (4 bytes)  
  uint32_t power_command_pdu2_rpc3_ext;         ///< [  612] (4 bytes)  
  uint32_t power_command_pdu2_rpc4;             ///< [  616] (4 bytes)  
  uint32_t power_command_pdu2_rpc4_ext;         ///< [  620] (4 bytes)  
  uint32_t power_command_pdu2_rpc5;             ///< [  624] (4 bytes)  
  uint32_t power_command_pdu2_rpc5_ext;         ///< [  628] (4 bytes)  
  uint32_t power_command_pdu2_rpc6;             ///< [  632] (4 bytes)  
  uint32_t power_command_pdu2_rpc6_ext;         ///< [  636] (4 bytes)  
  uint32_t power_command_pdu2_rpc7;             ///< [  640] (4 bytes)  
  uint32_t power_command_pdu2_rpc7_ext;         ///< [  644] (4 bytes)  
  uint32_t power_command_pdu2_rpc8;             ///< [  648] (4 bytes)  
  uint32_t power_command_pdu2_rpc8_ext;         ///< [  652] (4 bytes)  
} mast_ppe_esm_command;     ///<  Total size of 656 bytes

/** Structure mast_ppe_esm_state_description (788 bytes in size)  **/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                      ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint32_t health;                              ///< [   16] (4 bytes)  
  uint32_t power_mode;                          ///< [   20] (4 bytes)  
  uint32_t element_mode;                        ///< [   24] (4 bytes)  
  uint32_t power_plan_command_id;               ///< [   28] (4 bytes)  
  char power_plan_steps[256];                   ///< [   32] (256x1=256 bytes)  
  uint32_t esm_plan_command_id;                 ///< [  288] (4 bytes)  
  char esm_plan_steps[256];                     ///< [  292] (256x1=256 bytes)  
  double power_available;                       ///< [  548] (8 bytes)  
  double power_generation_rate;                 ///< [  556] (8 bytes)  
  uint32_t power_battery1_trend_health;         ///< [  564] (4 bytes)  
  uint32_t power_battery2_trend_health;         ///< [  568] (4 bytes)  
  uint32_t power_solararray1_trend_health;      ///< [  572] (4 bytes)  
  uint32_t power_solararray2_trend_health;      ///< [  576] (4 bytes)  
  uint32_t power_pdu1_fault_list;               ///< [  580] (4 bytes)  
  uint32_t power_pdu1_box_fault;                ///< [  584] (4 bytes)  
  uint32_t power_pdu1_rpc1_trip_fault;          ///< [  588] (4 bytes)  
  uint32_t power_pdu1_rpc1_open_fault;          ///< [  592] (4 bytes)  
  uint32_t power_pdu1_rpc1_status;              ///< [  596] (4 bytes)  
  uint32_t power_pdu1_rpc2_trip_fault;          ///< [  600] (4 bytes)  
  uint32_t power_pdu1_rpc2_open_fault;          ///< [  604] (4 bytes)  
  uint32_t power_pdu1_rpc2_status;              ///< [  608] (4 bytes)  
  uint32_t power_pdu1_rpc3_trip_fault;          ///< [  612] (4 bytes)  
  uint32_t power_pdu1_rpc3_open_fault;          ///< [  616] (4 bytes)  
  uint32_t power_pdu1_rpc3_status;              ///< [  620] (4 bytes)  
  uint32_t power_pdu1_rpc4_trip_fault;          ///< [  624] (4 bytes)  
  uint32_t power_pdu1_rpc4_open_fault;          ///< [  628] (4 bytes)  
  uint32_t power_pdu1_rpc4_status;              ///< [  632] (4 bytes)  
  uint32_t power_pdu1_rpc5_trip_fault;          ///< [  636] (4 bytes)  
  uint32_t power_pdu1_rpc5_open_fault;          ///< [  640] (4 bytes)  
  uint32_t power_pdu1_rpc5_status;              ///< [  644] (4 bytes)  
  uint32_t power_pdu1_rpc6_trip_fault;          ///< [  648] (4 bytes)  
  uint32_t power_pdu1_rpc6_open_fault;          ///< [  652] (4 bytes)  
  uint32_t power_pdu1_rpc6_status;              ///< [  656] (4 bytes)  
  uint32_t power_pdu1_rpc7_trip_fault;          ///< [  660] (4 bytes)  
  uint32_t power_pdu1_rpc7_open_fault;          ///< [  664] (4 bytes)  
  uint32_t power_pdu1_rpc7_status;              ///< [  668] (4 bytes)  
  uint32_t power_pdu1_rpc8_trip_fault;          ///< [  672] (4 bytes)  
  uint32_t power_pdu1_rpc8_open_fault;          ///< [  676] (4 bytes)  
  uint32_t power_pdu1_rpc8_status;              ///< [  680] (4 bytes)  
  uint32_t power_pdu2_fault_list;               ///< [  684] (4 bytes)  
  uint32_t power_pdu2_box_fault;                ///< [  688] (4 bytes)  
  uint32_t power_pdu2_rpc1_trip_fault;          ///< [  692] (4 bytes)  
  uint32_t power_pdu2_rpc1_open_fault;          ///< [  696] (4 bytes)  
  uint32_t power_pdu2_rpc1_status;              ///< [  700] (4 bytes)  
  uint32_t power_pdu2_rpc2_trip_fault;          ///< [  704] (4 bytes)  
  uint32_t power_pdu2_rpc2_open_fault;          ///< [  708] (4 bytes)  
  uint32_t power_pdu2_rpc2_status;              ///< [  712] (4 bytes)  
  uint32_t power_pdu2_rpc3_trip_fault;          ///< [  716] (4 bytes)  
  uint32_t power_pdu2_rpc3_open_fault;          ///< [  720] (4 bytes)  
  uint32_t power_pdu2_rpc3_status;              ///< [  724] (4 bytes)  
  uint32_t power_pdu2_rpc4_trip_fault;          ///< [  728] (4 bytes)  
  uint32_t power_pdu2_rpc4_open_fault;          ///< [  732] (4 bytes)  
  uint32_t power_pdu2_rpc4_status;              ///< [  736] (4 bytes)  
  uint32_t power_pdu2_rpc5_trip_fault;          ///< [  740] (4 bytes)  
  uint32_t power_pdu2_rpc5_open_fault;          ///< [  744] (4 bytes)  
  uint32_t power_pdu2_rpc5_status;              ///< [  748] (4 bytes)  
  uint32_t power_pdu2_rpc6_trip_fault;          ///< [  752] (4 bytes)  
  uint32_t power_pdu2_rpc6_open_fault;          ///< [  756] (4 bytes)  
  uint32_t power_pdu2_rpc6_status;              ///< [  760] (4 bytes)  
  uint32_t power_pdu2_rpc7_trip_fault;          ///< [  764] (4 bytes)  
  uint32_t power_pdu2_rpc7_open_fault;          ///< [  768] (4 bytes)  
  uint32_t power_pdu2_rpc7_status;              ///< [  772] (4 bytes)  
  uint32_t power_pdu2_rpc8_trip_fault;          ///< [  776] (4 bytes)  
  uint32_t power_pdu2_rpc8_open_fault;          ///< [  780] (4 bytes)  
  uint32_t power_pdu2_rpc8_status;              ///< [  784] (4 bytes)  
} mast_ppe_esm_state_description;     ///<  Total size of 788 bytes

/** Structure mast_state_description (52 bytes in size)  *
* system health status message published by mast_hab app
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                      ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint32_t systemHealth:32;               /* */ ///< [   16]   health of overall system
  uint32_t vehicleMode:32;                /* */ ///< [   20]   mode of overall system
  uint32_t ppeHealth:32;                  /* */ ///< [   24]   health of ppe
  uint32_t habHealth:32;                  /* */ ///< [   28]   health of hab
  uint32_t ppePowerMode:32;               /* */ ///< [   32]   mode of the ppe amps subsystem
  uint32_t ppeElementMode:32;             /* */ ///< [   36]   mode of the ppe esm
  uint32_t habPowerMode:32;               /* */ ///< [   40]   mode of the hab amps subsystem
  uint32_t habEclssMode:32;               /* */ ///< [   44]   mode of the hab eclss subsystem
  uint32_t habElementMode:32;             /* */ ///< [   48]   mode of the hab esm
} mast_state_description;     ///<  Total size of 52 bytes

void byteswap_mast_state_description(mast_state_description *inPtr, mast_state_description *outPtr, int direction);
void bitswap_mast_state_description(mast_state_description *inPtr, mast_state_description *outPtr, int direction);
void byteswap_mast_ppe_esm_state_description(mast_ppe_esm_state_description *inPtr, mast_ppe_esm_state_description *outPtr, int direction);
void bitswap_mast_ppe_esm_state_description(mast_ppe_esm_state_description *inPtr, mast_ppe_esm_state_description *outPtr, int direction);
void byteswap_mast_ppe_esm_command(mast_ppe_esm_command *inPtr, mast_ppe_esm_command *outPtr, int direction);
void bitswap_mast_ppe_esm_command(mast_ppe_esm_command *inPtr, mast_ppe_esm_command *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _MAST_TYPES_H_
