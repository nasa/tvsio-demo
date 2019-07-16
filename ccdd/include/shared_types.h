/* Created : Thu Jan 31 10:43:29 CST 2019
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabMsgidHeader.js
   Table(s): ACAWS_DE_DiagData_t, CCSDS_TLM_HDR, CCSDS_Primary, TEAMS_health_t, ACAWS_DE_ImpactReq_t, TEAMS_failure_t, acaws_fd_test_results_type, ACAWS_FIR_HkTlm_t, APC_AVAILIBILITY, apc_telemetry, system_faults_t, fault, load_shed_state_t, switch_state, request_energy_return_t, energyAvailability, powerProfileRow, APC_EA_RESPONSE, apc_load_schedule_response, DUP_HkTlm_t, ECLSS_PPA_tlm_packet_t, ECLSS_PPA_tlm_payload_t, HAB_ECLSS_ARS_TLM, HAB_ECLSS_ARS_SAM_TLM, HAB_ECLSS_ARS_CPM_TLM, HAB_ECLSS_ARS_TCCS_TLM, HAB_ECLSS_ARS_CDRA_TLM, HAB_ECLSS_ARS_CDRA_CO2BED_TLM, HAB_ECLSS_PCS_TLM, HAB_ECLSS_PCS_CNTLR_TLM, HAB_ECLSS_PCS_FLUID_TLM, HAB_ECLSS_WMS_TLM, HAB_ECLSS_WMS_PW_TLM, HAB_ECLSS_WMS_WW_TLM, HAB_TCS_ETCS_TLM, HAB_TCS_ETCS_LOOP_TLM, HAB_TCS_ITCS_TLM, HERA_CW_DATA, THERAHEADER, L1V_HAB_VOTE, loadSchedule, loadScheduleRow, MBSU1, MBSU2, mda, mPDU1, PDU1, PDU2, PDU3, PDU4, PPA_HYDE_HkTlm_t, PPA_HYDE_OutData_t, hyde_out_t, request_energy, TTE_DiagPacket_t, TTE_PortInfo_t, TTE_HkPacket_t, HAB_Power_Source1, sim_power_source, HAB_Power_Source2, HAL_MBSU1, MBSU_telemetry, HAL_MBSU2, HAL_PDU1, PDU_telemetry, HAL_PDU2, HAL_Power_Source1, HAL_Power_Source2, PPE_MBSU1, PPE_MBSU2, PPE_PDU1, PPE_PDU2, PPE_Power_Source1, PPE_Power_Source2, PPE_NAV_STATE_TLM, MPCV_NAV_STATE_TLM, ACAWS_FIR_OutData_t, ACAWS_FIR_ImpactType_t, HAL_PDU3, HAL_PDU4, mast_ppe_esm_command, mast_ppe_esm_state_description, mast_state_description, NPAS_AV_OUT, NPAS_PWR_OUT, NPAS_VM_OUT, DSG_GNC_TLM, ROVER_GNC_TLM */

#ifndef _shared_types_H_
#define _shared_types_H_
#include <stdint.h>
/** Structure CCSDS_Primary (10 bytes in size)  *
* CCSDS packet primary header: Starts all CMD/TLM messages on SB. Contents are always in BE format, and are packed as defined below.

 packet identifier bits (inside streamID)
bits  shift   ------------ description ---------------- 
0x07FF    0  : application ID                            
0x0800   11  : secondary header: 0 = absent, 1 = present 
0x1000   12  : packet type:      0 = TLM, 1 = CMD        
0xE000   13  : CCSDS version:    0 = ver 1, 1 = ver 2  

packet Sequence bits 
      bits  shift   ------------ description ---------------- 
0x3FFF    0  : sequence count                            
0xC000   14  : segmentation flags:  3 = complete packet  

APIDSubsystem bits
bits  shift   ------------ description ---------------- 
0x01FF   0  : Subsystem Id  mission defined              
0x0200   9  : Playback flag  0 = original, 1 = playback  
0x0400  10  : Endian:   Big = 0, Little (Intel) = 1      
0xF800  11  : EDS Version for packet definition used

StreamId  -- packet identifier word (stream ID) -- uint8_t -- 2
*/ 
typedef struct
{
  uint8_t StreamID[2];                                                         ///< [ 0] (2x1=2 Bytes)  packet identifier word (stream ID) -- Use macros to access individual items (e.g. CCSDS_RD_APID() )
  uint8_t Sequence[2];                                                         ///< [ 2] (2x1=2 Bytes)  packet sequence word  -- Use macros to access individual items (e.g. CCSDS_RD_SEQFLG() )
  uint8_t Length[2];                                                           ///< [ 4] (2x1=2 Bytes)  Actual message length minus 7 (CCSDS convention, dont ask why 7)
  uint8_t APIDQSubsystem[2];                                                   ///< [ 6] (2x1=2 Bytes)  APIDSubsystem bits -- Use macros to access individual items (e.g. CCSDS_RD_SUBSYSTEM_ID() )
  uint8_t APIDQSystemId[2];                                                    ///< [ 8] (2x1=2 Bytes)  reserved (not used by Habulous) -- Access using CCSDS_RD_SYSTEM_ID() or CCSDS_WR_SYSTEM_ID()
} CCSDS_Primary;     ///<  Total size of 10 bytes

/** Structure CCSDS_TLM_HDR (16 bytes in size)  *
* CCSDS telemetry header
*/ 
typedef struct
{
  CCSDS_Primary primaryHdr;                                                    ///< [ 0] (10 Bytes)  CCSDS V2 Primary header (10 bytes) -- NOTE: All items in structure are defined to be BE (Big Endian) format
  char TimeStamp_sec[4];                                                       ///< [10] (4x1=4 Bytes)  4 bytes of whole number of seconds since epoch -- Access using CCSDS_RD_SEC_HDR_SEC
  char TimeStamp_frac[2];                                                      ///< [14] (2x1=2 Bytes)  2 byte fraction of a second (1/65536 sec LSB) -- Access using CCSDS_RD_SEC_HDR_SUBSEC()
} CCSDS_TLM_HDR;     ///<  Total size of 16 bytes

/** Structure PDU_telemetry (136 bytes in size)  *
* PDU telemetry message based on AMPS PDU
*/ 
typedef struct
{
  uint8_t PDU_UNITID;                                                          ///< [  0] (1 Bytes)  unique ID of the component
  uint8_t STATUS_INPUTBUS1:2;                                        /*  */    ///< [  1] (2  bits)  shows state of output register that drives relays - input 1 (was PDU_INPUTBUSSTATUS)
  uint8_t STATUS_INPUTBUS2:2;                                                  ///< [  1] (2  bits)  shows state of output register that drives relays - input 2 (was PDU_INPUTBUSSTATUS)
  uint8_t STATUS_INPUTPAD:4;                                                   ///< [  1] (4  bits)  
  uint8_t FEEDBACK_INPUTRELAY1:2;                                    /*  */    ///< [  2] (2  bits)  shows the actual relay state read from feedback contacts - input 1 (was PDU_INPUTRELAYFEEDBACK)
  uint8_t FEEDBACK_INPUTRELAY2:2;                                              ///< [  2] (2  bits)  shows the actual relay state read from feedback contacts - input 2 (was PDU_INPUTRELAYFEEDBACK)
  uint8_t FEEDBACK_INPUT_PAD:4;                                                ///< [  2] (4  bits)  
  uint8_t PDU_INVALIDCOMMANDERROR;                                             ///< [  3] (1 Bytes)  0= OK, 1 = Error (indicates that more than one input has been selected)
  uint8_t FEEDBACKSTATEMISMATCHERROR_INPUTBUS1:2;                    /*  */    ///< [  4] (2  bits)  0=OK, 1 = Error (Indicates the On/Off patterns of status register and feedback contact do not agree (possible relay or relay driver fault) (was PDU_INPUTFEEDBACKSTATEMISMATCHERROR)
  uint8_t FEEDBACKSTATEMISMATCHERROR_INPUTBUS2:2;                              ///< [  4] (2  bits)  0=OK, 1 = Error (Indicates the On/Off patterns of status register and feedback contact do not agree (possible relay or relay driver fault) (was PDU_INPUTFEEDBACKSTATEMISMATCHERROR)
  uint8_t FEEDBACKSTATEMISMATCHERROR_PAD:4;                                    ///< [  4] (4  bits)  
  uint8_t POSNEGMISMATCHERROR_INPUT1:1;                              /*  */    ///< [  5] (1  bits)  0=OK, 1 = Error (Indicates that Positive and Negative relays are not in same state (PDU_POSNEGMISMATCHERROR)
  uint8_t POSNEGMISMATCHERROR_INPUT2:1;                                        ///< [  5] (1  bits)  0=OK, 1 = Error (Indicates that Positive and Negative relays are not in same state (PDU_POSNEGMISMATCHERROR)
  uint8_t POSNEGMISMATCHERROR_PAD:6;                                           ///< [  5] (6  bits)  
  uint8_t CHANNELSTATUS_RPC1:1;                                      /*  */    ///< [  6] (1  bits)  0= OFF 1= ON Indicates state of RPC device for channel 1 (was PDU_RPCCHANNELSTATUS)
  uint8_t CHANNELSTATUS_RPC2:1;                                                ///< [  6] (1  bits)  0= OFF 1= ON Indicates state of RPC device for channel 2 (was PDU_RPCCHANNELSTATUS)
  uint8_t CHANNELSTATUS_RPC3:1;                                                ///< [  6] (1  bits)  0= OFF 1= ON Indicates state of RPC device for channel 3 (was PDU_RPCCHANNELSTATUS)
  uint8_t CHANNELSTATUS_RPC4:1;                                                ///< [  6] (1  bits)  0= OFF 1= ON Indicates state of RPC device for channel 4 (was PDU_RPCCHANNELSTATUS)
  uint8_t CHANNELSTATUS_RPC5:1;                                                ///< [  6] (1  bits)  0= OFF 1= ON Indicates state of RPC device for channel 5 (was PDU_RPCCHANNELSTATUS)
  uint8_t CHANNELSTATUS_RPC6:1;                                                ///< [  6] (1  bits)  0= OFF 1= ON Indicates state of RPC device for channel 6 (was PDU_RPCCHANNELSTATUS)
  uint8_t CHANNELSTATUS_RPC7:1;                                                ///< [  6] (1  bits)  0= OFF 1= ON Indicates state of RPC device for channel 7 (was PDU_RPCCHANNELSTATUS)
  uint8_t CHANNELSTATUS_RPC8:1;                                                ///< [  6] (1  bits)  0= OFF 1= ON Indicates state of RPC device for channel 8 (was PDU_RPCCHANNELSTATUS)
  uint8_t TRIPSTATUS_RPC1:1;                                         /*  */    ///< [  7] (1  bits)  0= OK 1= TRIPPED Indicates that channel 1 has tripped (was PDU_RPCTRIPSTATUS)
  uint8_t TRIPSTATUS_RPC2:1;                                                   ///< [  7] (1  bits)  0= OK 1= TRIPPED Indicates that channel 2 has tripped (was PDU_RPCTRIPSTATUS)
  uint8_t TRIPSTATUS_RPC3:1;                                                   ///< [  7] (1  bits)  0= OK 1= TRIPPED Indicates that channel 3 has tripped (was PDU_RPCTRIPSTATUS)
  uint8_t TRIPSTATUS_RPC4:1;                                                   ///< [  7] (1  bits)  0= OK 1= TRIPPED Indicates that channel 4 has tripped (was PDU_RPCTRIPSTATUS)
  uint8_t TRIPSTATUS_RPC5:1;                                                   ///< [  7] (1  bits)  0= OK 1= TRIPPED Indicates that channel 5 has tripped (was PDU_RPCTRIPSTATUS)
  uint8_t TRIPSTATUS_RPC6:1;                                                   ///< [  7] (1  bits)  0= OK 1= TRIPPED Indicates that channel 6 has tripped (was PDU_RPCTRIPSTATUS)
  uint8_t TRIPSTATUS_RPC7:1;                                                   ///< [  7] (1  bits)  0= OK 1= TRIPPED Indicates that channel 7 has tripped (was PDU_RPCTRIPSTATUS)
  uint8_t TRIPSTATUS_RPC8:1;                                                   ///< [  7] (1  bits)  0= OK 1= TRIPPED Indicates that channel 8 has tripped (was PDU_RPCTRIPSTATUS)
  uint8_t OUTSTATUS_RPC1:1;                                          /*  */    ///< [  8] (1  bits)  the last commanded state of the RPC1 (was PDU_RPCOUTSTATUS)
  uint8_t OUTSTATUS_RPC2:1;                                                    ///< [  8] (1  bits)  the last commanded state of the RPC2 (was PDU_RPCOUTSTATUS)
  uint8_t OUTSTATUS_RPC3:1;                                                    ///< [  8] (1  bits)  the last commanded state of the RPC3 (was PDU_RPCOUTSTATUS)
  uint8_t OUTSTATUS_RPC4:1;                                                    ///< [  8] (1  bits)  the last commanded state of the RPC4 (was PDU_RPCOUTSTATUS)
  uint8_t OUTSTATUS_RPC5:1;                                                    ///< [  8] (1  bits)  the last commanded state of the RPC5 (was PDU_RPCOUTSTATUS)
  uint8_t OUTSTATUS_RPC6:1;                                                    ///< [  8] (1  bits)  the last commanded state of the RPC6 (was PDU_RPCOUTSTATUS)
  uint8_t OUTSTATUS_RPC7:1;                                                    ///< [  8] (1  bits)  the last commanded state of the RPC7 (was PDU_RPCOUTSTATUS)
  uint8_t OUTSTATUS_RPC8:1;                                                    ///< [  8] (1  bits)  the last commanded state of the RPC8 (was PDU_RPCOUTSTATUS)
  uint8_t MISMATCHERROR_RPC1:1;                                      /*  */    ///< [  9] (1  bits)  mismatch of last commanded state and measured state of RPC1 (was PDU_RPCMISMATCHERROR)
  uint8_t MISMATCHERROR_RPC2:1;                                                ///< [  9] (1  bits)  mismatch of last commanded state and measured state of RPC2 (was PDU_RPCMISMATCHERROR)
  uint8_t MISMATCHERROR_RPC3:1;                                                ///< [  9] (1  bits)  mismatch of last commanded state and measured state of RPC3 (was PDU_RPCMISMATCHERROR)
  uint8_t MISMATCHERROR_RPC4:1;                                                ///< [  9] (1  bits)  mismatch of last commanded state and measured state of RPC4 (was PDU_RPCMISMATCHERROR)
  uint8_t MISMATCHERROR_RPC5:1;                                                ///< [  9] (1  bits)  mismatch of last commanded state and measured state of RPC5 (was PDU_RPCMISMATCHERROR)
  uint8_t MISMATCHERROR_RPC6:1;                                                ///< [  9] (1  bits)  mismatch of last commanded state and measured state of RPC6 (was PDU_RPCMISMATCHERROR)
  uint8_t MISMATCHERROR_RPC7:1;                                                ///< [  9] (1  bits)  mismatch of last commanded state and measured state of RPC7 (was PDU_RPCMISMATCHERROR)
  uint8_t MISMATCHERROR_RPC8:1;                                                ///< [  9] (1  bits)  mismatch of last commanded state and measured state of RPC8 (was PDU_RPCMISMATCHERROR)
  uint8_t PDU_PAD[6];                                                          ///< [ 10] (6x1=6 Bytes)  GBA - padding to 8-byte boundary for first double at byte 24 from start of header
  double PDU_CURRENTBUS_1;                                                     ///< [ 16] (8 Bytes)  CurrentBus1: Main Bus 1 input currents
  double PDU_CURRENTBUS_2;                                                     ///< [ 24] (8 Bytes)  CurrentBus2: Main Bus 2 input currents
  double PDU_CURRENTINTERNALBUS;                                               ///< [ 32] (8 Bytes)  CurrentInternalBus: Current inside the PDU upstream of RPCs
  double PDU_VOLTAGEBUS_1;                                                     ///< [ 40] (8 Bytes)  VoltageBus1: Main bus voltage at input 1
  double PDU_VOLTAGEBUS_2;                                                     ///< [ 48] (8 Bytes)  VoltageBus2: Main bus voltage at input 2
  double PDU_VOLTAGEINTERNAL;                                                  ///< [ 56] (8 Bytes)  VoltageInternal: Voltage inside the PDU upstream of RPCs
  double PDU_VOLTAGEHKPG;                                                      ///< [ 64] (8 Bytes)  VoltageHKPG: Voltage of the power supply for the internal controller
  double PDU_CURRENTRPC_1;                                                     ///< [ 72] (8 Bytes)  CurrentRPC1: Indicates current of each RPC channel
  double PDU_CURRENTRPC_2;                                                     ///< [ 80] (8 Bytes)  CurrentRPC2: Indicates current of each RPC channel
  double PDU_CURRENTRPC_3;                                                     ///< [ 88] (8 Bytes)  CurrentRPC3: Indicates current of each RPC channel
  double PDU_CURRENTRPC_4;                                                     ///< [ 96] (8 Bytes)  CurrentRPC4: Indicates current of each RPC channel
  double PDU_CURRENTRPC_5;                                                     ///< [104] (8 Bytes)  CurrentRPC5: Indicates current of each RPC channel
  double PDU_CURRENTRPC_6;                                                     ///< [112] (8 Bytes)  CurrentRPC6: Indicates current of each RPC channel
  double PDU_CURRENTRPC_7;                                                     ///< [120] (8 Bytes)  CurrentRPC7: Indicates current of each RPC channel
  double PDU_CURRENTRPC_8;                                                     ///< [128] (8 Bytes)  CurrentRPC8: Indicates current of each RPC channel
} PDU_telemetry;     ///<  Total size of 136 bytes

/** Structure sim_power_source (61 bytes in size)  *
* power source definition that is reused to create HAB, HAL, and PPE sim power sources
*/ 
typedef struct
{
  int8_t UNITID;                                                               ///< [ 0] (1 Bytes)  unit ID of the component
  uint8_t SAR_SWITCH_FEEDBACK;                                                 ///< [ 1] (1 Bytes)  actual state of SAR switch (true=close; false=open)
  uint8_t BATT_SWItCH_FEEDBACK;                                                ///< [ 2] (1 Bytes)  actual state of battery switch (true=close; false=open)
  uint8_t CROSS_CONNECT_SWITCH_FEEDBACK;                                       ///< [ 3] (1 Bytes)  actual state of cross connect switch (true=close; false=open)
  uint8_t SAR_FEEDBACK;                                                        ///< [ 4] (1 Bytes)  actual state of SAR (true = ON; false = OFF)
  double SOLARARRAY_VOLTAGE;                                                   ///< [ 5] (8 Bytes)  solar array output voltage
  double BATT_VOLTAGE;                                                         ///< [13] (8 Bytes)  battery voltage
  double SAR_VOLTAGE;                                                          ///< [21] (8 Bytes)  SAR output (regulated) voltage
  double SOLARARRAY_CURRENT;                                                   ///< [29] (8 Bytes)  solar array output current
  double BATT_CURRENT;                                                         ///< [37] (8 Bytes)  battery current
  double SAR_CURRENT;                                                          ///< [45] (8 Bytes)  SAR output current
  double BATT_SOC;                                                             ///< [53] (8 Bytes)  battery state of charge
} sim_power_source;     ///<  Total size of 61 bytes

/** Structure MBSU_telemetry (168 bytes in size)  *
* MBSU telemetry message based on AMPS MBSU
*/ 
typedef struct
{
  uint8_t MBSU_ID;                                                             ///< [  0] (1 Bytes)  unique ID of component
  uint8_t SOURCESELECT_STATUS_INPUT1:2;                              /*  */    ///< [  1] (2  bits)  Shows state of input 1 (was MBSU_INPUT_SOURCESELECT_STATUS)
  uint8_t SOURCESELECT_STATUS_INPUT2:2;                                        ///< [  1] (2  bits)  Shows state of input 2 (was MBSU_INPUT_SOURCESELECT_STATUS)
  uint8_t SOURCESELECT_STATUS_INPUT3:2;                                        ///< [  1] (2  bits)  Shows state of input 3 (was MBSU_INPUT_SOURCESELECT_STATUS)
  uint8_t SOURCESELECT_STATUS_PAD:2;                                           ///< [  1] (2  bits)  
  uint8_t FEEDBACK_STATUS_INPUTRELAY1:2;                             /*  */    ///< [  2] (2  bits)  shows the actual relay state read from feedback contact1 (was MBSU_INPUTRELAY_FEEDBACK_STATUS)
  uint8_t FEEDBACK_STATUS_INPUTRELAY2:2;                                       ///< [  2] (2  bits)  shows the actual relay state read from feedback contact2 (was MBSU_INPUTRELAY_FEEDBACK_STATUS)
  uint8_t FEEDBACK_STATUS_INPUTRELAY3:2;                                       ///< [  2] (2  bits)  shows the actual relay state read from feedback contact3 (was MBSU_INPUTRELAY_FEEDBACK_STATUS)
  uint8_t FEEDBACK_STATUS_PAD:2;                                               ///< [  2] (2  bits)  
  uint8_t MBSU_INPUT_INVALIDBATTERY_ERROR;                                     ///< [  3] (1 Bytes)  0 = OK, 1 = indicates hat the aux mbsu port is NOT in OFF state when selecting battery
  uint8_t MBSU_INPUT_INVALIDSOLARARRAY_ERROR;                                  ///< [  4] (1 Bytes)  0 = OK, 1 = indicates hat the aux mbsu port is NOT in OFF state when selecting solar array
  uint8_t MBSU_INPUT_INVALIDAUXMBSUINPUT_ERROR;                                ///< [  5] (1 Bytes)  0 = OK, 1 = indicates hat the aux mbsu port is NOT in OFF state when selecting aux mbsu as input
  uint8_t MBSU_INPUT_INVALIDAUXMBSUOUTPUT_ERROR;                               ///< [  6] (1 Bytes)  0 = OK, 1 = indicates hat the aux mbsu port is NOT in OFF state when selecting aux mbsu as output
  uint8_t STATEMISMATCH_ERROR_INPUT_RELAY1:2;                        /*  */    ///< [  7] (2  bits)  0 = ok, 1 = error (was MBSU_INPUT_RELAYSTATEMISMATCH_ERROR)
  uint8_t STATEMISMATCH_ERROR_INPUT_RELAY2:2;                                  ///< [  7] (2  bits)  0 = ok, 1 = error (was MBSU_INPUT_RELAYSTATEMISMATCH_ERROR)
  uint8_t STATEMISMATCH_ERROR_INPUT_RELAY3:2;                                  ///< [  7] (2  bits)  0 = ok, 1 = error (was MBSU_INPUT_RELAYSTATEMISMATCH_ERROR)
  uint8_t STATEMISMATCH_ERROR_PAD:2;                                           ///< [  7] (2  bits)  
  uint8_t POSNEGSTATEMISMATCH_ERROR_INPUT1:1;                        /*  */    ///< [  8] (1  bits)  0 = ok, 1 = indicates that pos and neg relay contact states are mismatched (was MBSU_INPUT_POSNEGSTATEMISMATCH_ERROR)
  uint8_t POSNEGSTATEMISMATCH_ERROR_INPUT2:1;                                  ///< [  8] (1  bits)  0 = ok, 1 = indicates that pos and neg relay contact states are mismatched (was MBSU_INPUT_POSNEGSTATEMISMATCH_ERROR)
  uint8_t POSNEGSTATEMISMATCH_ERROR_INPUT3:1;                                  ///< [  8] (1  bits)  0 = ok, 1 = indicates that pos and neg relay contact states are mismatched (was MBSU_INPUT_POSNEGSTATEMISMATCH_ERROR)
  uint8_t POSNEGSTATEMISMATCH_ERROR_PAD:5;                                     ///< [  8] (5  bits)  
  uint8_t OUTSTATUS_BUS1:2;                                          /*  */    ///< [  9] (2  bits)  shows state of output register that drives relay1 (was MBSU_BUSOUTSTATUS)
  uint8_t OUTSTATUS_BUS2:2;                                                    ///< [  9] (2  bits)  shows state of output register that drives relay2 (was MBSU_BUSOUTSTATUS)
  uint8_t OUTSTATUS_PAD:4;                                                     ///< [  9] (4  bits)  
  uint8_t RELAYFEEDBACKSTATUS_BUSOUT1:2;                             /*  */    ///< [ 10] (2  bits)  shows the actual relay state read from feedback contact 1 (was MBSU_BUSOUTERLAYFEEDBACKSTATUS)
  uint8_t RELAYFEEDBACKSTATUS_BUSOUT2:2;                                       ///< [ 10] (2  bits)  shows the actual relay state read from feedback contact 2 (was MBSU_BUSOUTERLAYFEEDBACKSTATUS)
  uint8_t RELAYFEEDBACK_PAD:4;                                                 ///< [ 10] (4  bits)  
  uint8_t RELAYSTATEMISMATCHERROR_BUSOUT1:2;                         /*  */    ///< [ 11] (2  bits)  0 = ok, 1 = error (was MBSU_BUSOUTRELAYSTATEMISMATCHERROR)
  uint8_t RELAYSTATEMISMATCHERROR_BUSOUT2:2;                                   ///< [ 11] (2  bits)  0 = ok, 1 = error (was MBSU_BUSOUTRELAYSTATEMISMATCHERROR)
  uint8_t RELAYSTATE_PAD:4;                                                    ///< [ 11] (4  bits)  
  uint8_t MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN1:1;              /*  */    ///< [ 12] (1  bits)  0 = ok 1 = error
  uint8_t MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN2:1;                        ///< [ 12] (1  bits)  
  uint8_t MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN3:1;                        ///< [ 12] (1  bits)  
  uint8_t MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN4:1;                        ///< [ 12] (1  bits)  
  uint8_t MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_PAD:4;                          ///< [ 12] (4  bits)  
  uint8_t TRIPSTATE_INPUTRELAY1:2;                                   /*  */    ///< [ 13] (2  bits)  relay trip state of input relay1 (was MBSU_INPUTRELAYTRIPSTATE)
  uint8_t TRIPSTATE_INPUTRELAY2:2;                                             ///< [ 13] (2  bits)  relay trip state of input relay2 (was MBSU_INPUTRELAYTRIPSTATE)
  uint8_t TRIPSTATE_INPUTRELAY3:2;                                             ///< [ 13] (2  bits)  relay trip state of input relay3 (was MBSU_INPUTRELAYTRIPSTATE)
  uint8_t TRIPSTATE_INPUTRELAY_PAD:2;                                          ///< [ 13] (2  bits)  
  uint8_t TRIPSTATE_OUTPUTRELAY1:1;                                  /*  */    ///< [ 14] (1  bits)  relay trip state of output relay1 (was MBSU_OUTPUTRELAYTRIPSTATE)
  uint8_t TRIPSTATE_OUTPUTRELAY2:1;                                            ///< [ 14] (1  bits)  relay trip state of output relay2 (was MBSU_OUTPUTRELAYTRIPSTATE)
  uint8_t TRIPSTATE_OUTPUTRELAY3:1;                                            ///< [ 14] (1  bits)  relay trip state of output relay3 (was MBSU_OUTPUTRELAYTRIPSTATE)
  uint8_t TRIPSTATE_OUTPUTRELAY4:1;                                            ///< [ 14] (1  bits)  relay trip state of output relay4 (was MBSU_OUTPUTRELAYTRIPSTATE)
  uint8_t TRIPSTATE_PAD:4;                                                     ///< [ 14] (4  bits)  
  uint8_t MBSU_PAD;                                                            ///< [ 15] (1 Bytes)  GBA - to align on even 8-byte boundary, counting from start of header, puts the first double at byte #32
  double MBSU_SOLAR_ARRAY_INPUT_CURRENT;                                       ///< [ 16] (8 Bytes)  current frmo solar array
  double MBSU_BATTERY_BIDIRECTIONAL_CURRENT;                                   ///< [ 24] (8 Bytes)  current to/from battery
  double MBSU_AUXMBSU_BIDIRECTIONAL_CURRENT;                                   ///< [ 32] (8 Bytes)  current to/from aux port
  double MBSU_AUX_VOLTAGE;                                                     ///< [ 40] (8 Bytes)  voltage of the aux mbsu port
  double MBSU_HKPS_VOLTAGE;                                                    ///< [ 48] (8 Bytes)  voltage of the house keeping power supply
  double MBSU_OUTPUT_CURRENT_1;                                                ///< [ 56] (8 Bytes)  mbsu output current 1
  double MBSU_OUTPUT_CURRENT_2;                                                ///< [ 64] (8 Bytes)  mbsu output current 2
  double MBSU_OUTPUT_CURRENT_3;                                                ///< [ 72] (8 Bytes)  mbsu output current 3
  double MBSU_OUTPUT_CURRENT_4;                                                ///< [ 80] (8 Bytes)  mbsu output current 4
  double MBSU_SARVOLTAGE;                                                      ///< [ 88] (8 Bytes)  solar array regulator voltage
  double MBSU_BATTVOLTAGE;                                                     ///< [ 96] (8 Bytes)  battery input voltage
  double MBSU_INNERVOLTAGE;                                                    ///< [104] (8 Bytes)  inner bus voltage
  double MBSU_SARCURRTRIPSP;                                                   ///< [112] (8 Bytes)  trip setpoint for SAR input
  double MBSU_BATTCURRTRIPSP;                                                  ///< [120] (8 Bytes)  trip setpoint for battery
  double MBSU_AUXCURRTRIPSP;                                                   ///< [128] (8 Bytes)  trip setpoint for aux input
  double MBSU_OUTPUTCURRTRIPSP_1;                                              ///< [136] (8 Bytes)  output ch1 trip setpoint
  double MBSU_OUTPUTCURRTRIPSP_2;                                              ///< [144] (8 Bytes)  output ch2 trip setpoint
  double MBSU_OUTPUTCURRTRIPSP_3;                                              ///< [152] (8 Bytes)  output ch3 trip setpoint
  double MBSU_OUTPUTCURRTRIPSP_4;                                              ///< [160] (8 Bytes)  output ch3 trip setpoint
} MBSU_telemetry;     ///<  Total size of 168 bytes

/** Structure powerProfileRow (12 bytes in size)  **/ 
typedef struct
{
  int32_t timeUnit;                                                            ///< [ 0] (4 Bytes)  
  float peakPower;                                                             ///< [ 4] (4 Bytes)  
  float nominalPower;                                                          ///< [ 8] (4 Bytes)  
} powerProfileRow;     ///<  Total size of 12 bytes

/** Structure energyAvailability (292 bytes in size)  *
* APC to VM supplied energy availablity
*/ 
typedef struct
{
  powerProfileRow powerProfile[24];                                            ///< [  0] (24x12=288 Bytes)  
  float energy_available;                                                      ///< [288] (4 Bytes)  
} energyAvailability;     ///<  Total size of 292 bytes

/** Structure request_energy_return_t (300 bytes in size)  *
* structure containing return code and energy availibility sent by APC
*/ 
typedef struct
{
  int32_t timestamp;                                                           ///< [  0] (4 Bytes)  TBD timestamp format
  int32_t return_code;                                                         ///< [  4] (4 Bytes)  
  energyAvailability value;                                                    ///< [  8] (292 Bytes)  
} request_energy_return_t;     ///<  Total size of 300 bytes

/** Structure switch_state (12 bytes in size)  *
* load shed switch state
*/ 
typedef struct
{
  int32_t oru_id;                                                              ///< [ 0] (4 Bytes)  
  int32_t switch_id;                                                           ///< [ 4] (4 Bytes)  
  int32_t state;                                                               ///< [ 8] (4 Bytes)  
} switch_state;     ///<  Total size of 12 bytes

/** Structure load_shed_state_t (196 bytes in size)  *
* rpc switch states of loads that have been shed
*/ 
typedef struct
{
  int32_t timestamp;                                                           ///< [  0] (4 Bytes)  TBD timestamp format
  switch_state states[16];                                                     ///< [  4] (16x12=192 Bytes)  
} load_shed_state_t;     ///<  Total size of 196 bytes

/** Structure fault (12 bytes in size)  *
* APC generated fault map
*/ 
typedef struct
{
  int32_t oru_id;                                                              ///< [ 0] (4 Bytes)  PDU/MBSU index
  int32_t switch_id;                                                           ///< [ 4] (4 Bytes)  RPC/RBI index
  int32_t fault_type;                                                          ///< [ 8] (4 Bytes)  Type of fault
} fault;     ///<  Total size of 12 bytes

/** Structure system_faults_t (128 bytes in size)  *
* system faults
*/ 
typedef struct
{
  int32_t timestamp;                                                           ///< [  0] (4 Bytes)  TBD timestamp format
  int32_t number_of_faults;                                                    ///< [  4] (4 Bytes)  
  fault faults[10];                                                            ///< [  8] (10x12=120 Bytes)  
} system_faults_t;     ///<  Total size of 128 bytes

/** Structure apc_telemetry (628 bytes in size)  *
* APC generated message containing energy availibility, fault map, and shed loads
*/ 
typedef struct
{
  int32_t timestamp;                                                           ///< [  0] (4 Bytes)  TBD format timestamp
  system_faults_t system_faults;                                               ///< [  4] (128 Bytes)  
  load_shed_state_t load_shed_state;                                           ///< [132] (196 Bytes)  
  request_energy_return_t request_energy_return;                               ///< [328] (300 Bytes)  
} apc_telemetry;     ///<  Total size of 628 bytes

#endif /// #ifndef _shared_types_H_
