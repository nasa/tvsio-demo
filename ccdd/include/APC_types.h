/* Created : Tue Jul 17 07:08:41 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): APC_AVAILIBILITY, CCSDS_TLM_HDR, CCSDS_Primary, apc_telemetry, system_faults_t, fault, load_shed_state_t, switch_state, request_energy_return_t, energyAvailability, powerProfileRow, APC_EA_RESPONSE, apc_load_schedule_response */

#ifndef _APC_TYPES_H_
#define _APC_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure APC_AVAILIBILITY (644 bytes in size)  *
* apc telemetry response in the fault case
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  apc_telemetry apc_availibility;             ///< [   16] (628 bytes)  
} APC_AVAILIBILITY;     ///<  Total size of 644 bytes

/** Structure APC_EA_RESPONSE (644 bytes in size)  *
* apc telemetry sent to vm after a request_energy message
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  apc_telemetry apc_ea_response;              ///< [   16] (628 bytes)  
} APC_EA_RESPONSE;     ///<  Total size of 644 bytes

/** Structure apc_load_schedule_response (24 bytes in size)  *
* APC response to VM supplied load schedule message
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  int32_t timestamp;                          ///< [   16] (4 bytes)  TBD timestamp format
  int32_t return_code;                        ///< [   20] (4 bytes)  
} apc_load_schedule_response;     ///<  Total size of 24 bytes

void byteswap_apc_load_schedule_response(apc_load_schedule_response *inPtr, apc_load_schedule_response *outPtr, int direction);
void bitswap_apc_load_schedule_response(apc_load_schedule_response *inPtr, apc_load_schedule_response *outPtr, int direction);
void byteswap_APC_EA_RESPONSE(APC_EA_RESPONSE *inPtr, APC_EA_RESPONSE *outPtr, int direction);
void bitswap_APC_EA_RESPONSE(APC_EA_RESPONSE *inPtr, APC_EA_RESPONSE *outPtr, int direction);
void byteswap_APC_AVAILIBILITY(APC_AVAILIBILITY *inPtr, APC_AVAILIBILITY *outPtr, int direction);
void bitswap_APC_AVAILIBILITY(APC_AVAILIBILITY *inPtr, APC_AVAILIBILITY *outPtr, int direction);
void byteswap_apc_telemetry(apc_telemetry *inPtr, apc_telemetry *outPtr, int direction);
void bitswap_apc_telemetry(apc_telemetry *inPtr, apc_telemetry *outPtr, int direction);
void byteswap_system_faults_t(system_faults_t *inPtr, system_faults_t *outPtr, int direction);
void bitswap_system_faults_t(system_faults_t *inPtr, system_faults_t *outPtr, int direction);
void byteswap_fault(fault *inPtr, fault *outPtr, int direction);
void bitswap_fault(fault *inPtr, fault *outPtr, int direction);
void byteswap_load_shed_state_t(load_shed_state_t *inPtr, load_shed_state_t *outPtr, int direction);
void bitswap_load_shed_state_t(load_shed_state_t *inPtr, load_shed_state_t *outPtr, int direction);
void byteswap_switch_state(switch_state *inPtr, switch_state *outPtr, int direction);
void bitswap_switch_state(switch_state *inPtr, switch_state *outPtr, int direction);
void byteswap_request_energy_return_t(request_energy_return_t *inPtr, request_energy_return_t *outPtr, int direction);
void bitswap_request_energy_return_t(request_energy_return_t *inPtr, request_energy_return_t *outPtr, int direction);
void byteswap_energyAvailability(energyAvailability *inPtr, energyAvailability *outPtr, int direction);
void bitswap_energyAvailability(energyAvailability *inPtr, energyAvailability *outPtr, int direction);
void byteswap_powerProfileRow(powerProfileRow *inPtr, powerProfileRow *outPtr, int direction);
void bitswap_powerProfileRow(powerProfileRow *inPtr, powerProfileRow *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _APC_TYPES_H_
