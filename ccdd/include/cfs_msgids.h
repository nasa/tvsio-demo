/* Created : Tue Feb 12 14:54:11 CST 2019
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabMsgidHeader.js
   Table(s): ACAWS_DE_DiagData_t,ACAWS_DE_ImpactReq_t,ACAWS_FIR_HkTlm_t,ACAWS_FIR_ImpactType_t,ACAWS_FIR_OutData_t,APC_AVAILIBILITY,APC_EA_RESPONSE,DSG_GNC_TLM,DUP_HkTlm_t,ECLSS_PPA_tlm_packet_t,HAB_ECLSS_ARS_TLM,HAB_ECLSS_PCS_TLM,HAB_ECLSS_WMS_TLM,HAB_Power_Source1,HAB_Power_Source2,HAB_TCS_ETCS_TLM,HAB_TCS_ITCS_TLM,HAL_MBSU1,HAL_MBSU2,HAL_PDU1,HAL_PDU2,HAL_PDU3,HAL_PDU4,HAL_Power_Source1,HAL_Power_Source2,HERA_CW_DATA,L1V_HAB_VOTE,MBSU1,MBSU2,MPCV_NAV_STATE_TLM,NPAS_AV_OUT,NPAS_PWR_OUT,NPAS_VM_OUT,PDU1,PDU2,PDU3,PDU4,PPA_HYDE_HkTlm_t,PPA_HYDE_OutData_t,PPE_MBSU1,PPE_MBSU2,PPE_NAV_STATE_TLM,PPE_PDU1,PPE_PDU2,PPE_Power_Source1,PPE_Power_Source2,ROVER_GNC_TLM,TTE_DiagPacket_t,TTE_HkPacket_t,acaws_fd_test_results_type,apc_load_schedule_response,loadSchedule,mPDU1,mast_ppe_esm_command,mast_ppe_esm_state_description,mast_state_description,mda,request_energy
   CMD(s)  : LC_CMD_MID,LC_RTS_REQ_MID,LC_SAMPLE_AP_MID,LC_SEND_HK_MID,SBN_WAKEUP_MID,SBN_CMD_MID,CI_APP_CMD_MID,TO_APP_CMD_MID,HAB_ECLSS_ARS_CMD,HAB_ECLSS_PCS_CMD,HAB_ECLSS_WMS_CMD,HAB_Power_Source1_CMD,HAB_Power_Source2_CMD,HAL_MBSU1_CMD,HAL_MBSU2_CMD,HAL_PDU1_CMD,HAL_PDU2_CMD,HAL_PDU3_CMD,HAL_PDU4_CMD,ACAWS_FD_WAKEUP_MID,SCH_TT_CMD_MID,AMPSDB_IO_CMD_MID,SIMPLE_COUNTER_CMD_MID,TTE_CMD_MID,MBSU1_CMD,MBSU2_CMD,HAL_Power_Source1_CMD,HAL_Power_Source2_CMD,HAB_TCS_ETCS_A_CMD,HAB_TCS_ETCS_B_CMD,HAB_TCS_ITCS_CMD,DUP_CMD,PDU1_CMD,PDU2_CMD,PDU3_CMD,PDU4_CMD,PPE_MBSU1_CMD,PPE_MBSU2_CMD,PPE_PDU1_CMD,PPE_PDU2_CMD,PPE_Power_Source1_CMD,PPE_Power_Source2_CMD */

#ifndef _CFS_MSGIDS_H_
#define _CFS_MSGIDS_H_

#include "cfe_mission_cfg.h"
#include "cfe_platform_cfg.h" 

//  Number of 'duplicated' MID's on each CFS CPU: 3 types (coreCFS, Habitat, and 'spare') 
#define CFS_NUM_CPU_CMD_MIDS           (52 + 13 + 447)
#define CFS_NUM_CPU_TLM_MIDS           (47 + 40 + 425)
//  Number of 'global' MID's: 2 types (coreCFS and Habitat)
#define CFS_NUM_GBL_CMD_MIDS           (14 + 29)
#define CFS_NUM_GBL_TLM_MIDS           (16 + 47)

/* The lowest-value MID not in a cFE reserved range, see cfe_mission_cfg.h &
	   cfe_msgids.h.  This shouldn't change because we're reserving enough to pad out to 512 MIDs above 
	   the highest cFE reservation. */
#define CFE_CMD_MID_MAX_RESERVED   (CFE_CMD_MID_BASE_GLOB + 0x01c0) /* 0x8200 */
#define CFE_TLM_MID_MAX_RESERVED   (CFE_TLM_MID_BASE_GLOB + 0x01c0) /* 0x0200 */

/* Specify the base address for each CPU's (non-global) command MIDs below */
#define CFS_CMD_MID_BASE_CPU1       (CFE_CMD_MID_MAX_RESERVED + (0* CFS_NUM_CPU_CMD_MIDS ))   /* 0x8200 */
#define CFS_CMD_MID_BASE_CPU2       (CFE_CMD_MID_MAX_RESERVED + (1* CFS_NUM_CPU_CMD_MIDS ))   /* 0x8400 */
#define CFS_CMD_MID_BASE_CPU3       (CFE_CMD_MID_MAX_RESERVED + (2* CFS_NUM_CPU_CMD_MIDS ))   /* 0x8600 */
#define CFS_CMD_MID_BASE_CPU4       (CFE_CMD_MID_MAX_RESERVED + (3* CFS_NUM_CPU_CMD_MIDS ))   /* 0x8800 */
#define CFS_CMD_MID_BASE_CPU5       (CFE_CMD_MID_MAX_RESERVED + (4* CFS_NUM_CPU_CMD_MIDS ))   /* 0x8a00 */
#define CFS_CMD_MID_BASE_CPU6       (CFE_CMD_MID_MAX_RESERVED + (5* CFS_NUM_CPU_CMD_MIDS ))   /* 0x8c00 */
#define CFS_CMD_MID_BASE_CPU7       (CFE_CMD_MID_MAX_RESERVED + (6* CFS_NUM_CPU_CMD_MIDS ))   /* 0x8e00 */
#define CFS_CMD_MID_BASE_CPU8       (CFE_CMD_MID_MAX_RESERVED + (7* CFS_NUM_CPU_CMD_MIDS ))   /* 0x9000 */
#define CFS_CMD_MID_BASE_CPU9       (CFE_CMD_MID_MAX_RESERVED + (8* CFS_NUM_CPU_CMD_MIDS ))   /* 0x9200 */
#define CFS_CMD_MID_BASE_CPU10      (CFE_CMD_MID_MAX_RESERVED + (9* CFS_NUM_CPU_CMD_MIDS ))   /* 0x9400 */
#define CFS_CMD_MID_BASE_CPU11      (CFE_CMD_MID_MAX_RESERVED + (10* CFS_NUM_CPU_CMD_MIDS ))   /* 0x9600 */
#define CFS_CMD_MID_BASE_CPU12      (CFE_CMD_MID_MAX_RESERVED + (11* CFS_NUM_CPU_CMD_MIDS ))   /* 0x9800 */
#define CFS_CMD_MID_BASE_CPU16      (CFE_CMD_MID_MAX_RESERVED + (15* CFS_NUM_CPU_CMD_MIDS ))   /* 0xa000 */
#define CFS_CMD_MID_BASE_CPU33      (CFE_CMD_MID_MAX_RESERVED + (32* CFS_NUM_CPU_CMD_MIDS ))   /* 0xc200 */
#define CFS_CMD_MID_BASE_CPU34      (CFE_CMD_MID_MAX_RESERVED + (33* CFS_NUM_CPU_CMD_MIDS ))   /* 0xc400 */
#define CFS_CMD_MID_BASE_CPU35      (CFE_CMD_MID_MAX_RESERVED + (34* CFS_NUM_CPU_CMD_MIDS ))   /* 0xc600 */
#define CFS_CMD_MID_BASE_CPU36      (CFE_CMD_MID_MAX_RESERVED + (35* CFS_NUM_CPU_CMD_MIDS ))   /* 0xc800 */
#define CFS_CMD_MID_BASE_CPU37      (CFE_CMD_MID_MAX_RESERVED + (36* CFS_NUM_CPU_CMD_MIDS ))   /* 0xca00 */
#define CFS_CMD_MID_BASE_CPU38      (CFE_CMD_MID_MAX_RESERVED + (37* CFS_NUM_CPU_CMD_MIDS ))   /* 0xcc00 */
#define CFS_CMD_MID_BASE_CPU39      (CFE_CMD_MID_MAX_RESERVED + (38* CFS_NUM_CPU_CMD_MIDS ))   /* 0xce00 */
#define CFS_CMD_MID_BASE_CPU40      (CFE_CMD_MID_MAX_RESERVED + (39* CFS_NUM_CPU_CMD_MIDS ))   /* 0xd000 */
#define CFS_CMD_MID_BASE_CPU41      (CFE_CMD_MID_MAX_RESERVED + (40* CFS_NUM_CPU_CMD_MIDS ))   /* 0xd200 */
#define CFS_CMD_MID_BASE_CPU42      (CFE_CMD_MID_MAX_RESERVED + (41* CFS_NUM_CPU_CMD_MIDS ))   /* 0xd400 */
#define CFS_CMD_MID_BASE_CPU43      (CFE_CMD_MID_MAX_RESERVED + (42* CFS_NUM_CPU_CMD_MIDS ))   /* 0xd600 */
#define CFS_CMD_MID_BASE_CPU44      (CFE_CMD_MID_MAX_RESERVED + (43* CFS_NUM_CPU_CMD_MIDS ))   /* 0xd800 */
#define CFS_CMD_MID_BASE_CPU45      (CFE_CMD_MID_MAX_RESERVED + (44* CFS_NUM_CPU_CMD_MIDS ))   /* 0xda00 */
#define CFS_CMD_MID_BASE_CPU46      (CFE_CMD_MID_MAX_RESERVED + (45* CFS_NUM_CPU_CMD_MIDS ))   /* 0xdc00 */
#define CFS_CMD_MID_BASE_CPU47      (CFE_CMD_MID_MAX_RESERVED + (46* CFS_NUM_CPU_CMD_MIDS ))   /* 0xde00 */
#define CFS_CMD_MID_BASE_CPU48      (CFE_CMD_MID_MAX_RESERVED + (47* CFS_NUM_CPU_CMD_MIDS ))   /* 0xe000 */

/* Specify the base address for each CPU's (non-global) telemetry MIDs below */
#define CFS_TLM_MID_BASE_CPU1       (CFE_TLM_MID_MAX_RESERVED + (0* CFS_NUM_CPU_TLM_MIDS ))   /* 0x0200 */
#define CFS_TLM_MID_BASE_CPU2       (CFE_TLM_MID_MAX_RESERVED + (1* CFS_NUM_CPU_TLM_MIDS ))   /* 0x0400 */
#define CFS_TLM_MID_BASE_CPU3       (CFE_TLM_MID_MAX_RESERVED + (2* CFS_NUM_CPU_TLM_MIDS ))   /* 0x0600 */
#define CFS_TLM_MID_BASE_CPU4       (CFE_TLM_MID_MAX_RESERVED + (3* CFS_NUM_CPU_TLM_MIDS ))   /* 0x0800 */
#define CFS_TLM_MID_BASE_CPU5       (CFE_TLM_MID_MAX_RESERVED + (4* CFS_NUM_CPU_TLM_MIDS ))   /* 0x0a00 */
#define CFS_TLM_MID_BASE_CPU6       (CFE_TLM_MID_MAX_RESERVED + (5* CFS_NUM_CPU_TLM_MIDS ))   /* 0x0c00 */
#define CFS_TLM_MID_BASE_CPU7       (CFE_TLM_MID_MAX_RESERVED + (6* CFS_NUM_CPU_TLM_MIDS ))   /* 0x0e00 */
#define CFS_TLM_MID_BASE_CPU8       (CFE_TLM_MID_MAX_RESERVED + (7* CFS_NUM_CPU_TLM_MIDS ))   /* 0x1000 */
#define CFS_TLM_MID_BASE_CPU9       (CFE_TLM_MID_MAX_RESERVED + (8* CFS_NUM_CPU_TLM_MIDS ))   /* 0x1200 */
#define CFS_TLM_MID_BASE_CPU10      (CFE_TLM_MID_MAX_RESERVED + (9* CFS_NUM_CPU_TLM_MIDS ))   /* 0x1400 */
#define CFS_TLM_MID_BASE_CPU11      (CFE_TLM_MID_MAX_RESERVED + (10* CFS_NUM_CPU_TLM_MIDS ))   /* 0x1600 */
#define CFS_TLM_MID_BASE_CPU12      (CFE_TLM_MID_MAX_RESERVED + (11* CFS_NUM_CPU_TLM_MIDS ))   /* 0x1800 */
#define CFS_TLM_MID_BASE_CPU16      (CFE_TLM_MID_MAX_RESERVED + (15* CFS_NUM_CPU_TLM_MIDS ))   /* 0x2000 */
#define CFS_TLM_MID_BASE_CPU33      (CFE_TLM_MID_MAX_RESERVED + (32* CFS_NUM_CPU_TLM_MIDS ))   /* 0x4200 */
#define CFS_TLM_MID_BASE_CPU34      (CFE_TLM_MID_MAX_RESERVED + (33* CFS_NUM_CPU_TLM_MIDS ))   /* 0x4400 */
#define CFS_TLM_MID_BASE_CPU35      (CFE_TLM_MID_MAX_RESERVED + (34* CFS_NUM_CPU_TLM_MIDS ))   /* 0x4600 */
#define CFS_TLM_MID_BASE_CPU36      (CFE_TLM_MID_MAX_RESERVED + (35* CFS_NUM_CPU_TLM_MIDS ))   /* 0x4800 */
#define CFS_TLM_MID_BASE_CPU37      (CFE_TLM_MID_MAX_RESERVED + (36* CFS_NUM_CPU_TLM_MIDS ))   /* 0x4a00 */
#define CFS_TLM_MID_BASE_CPU38      (CFE_TLM_MID_MAX_RESERVED + (37* CFS_NUM_CPU_TLM_MIDS ))   /* 0x4c00 */
#define CFS_TLM_MID_BASE_CPU39      (CFE_TLM_MID_MAX_RESERVED + (38* CFS_NUM_CPU_TLM_MIDS ))   /* 0x4e00 */
#define CFS_TLM_MID_BASE_CPU40      (CFE_TLM_MID_MAX_RESERVED + (39* CFS_NUM_CPU_TLM_MIDS ))   /* 0x5000 */
#define CFS_TLM_MID_BASE_CPU41      (CFE_TLM_MID_MAX_RESERVED + (40* CFS_NUM_CPU_TLM_MIDS ))   /* 0x5200 */
#define CFS_TLM_MID_BASE_CPU42      (CFE_TLM_MID_MAX_RESERVED + (41* CFS_NUM_CPU_TLM_MIDS ))   /* 0x5400 */
#define CFS_TLM_MID_BASE_CPU43      (CFE_TLM_MID_MAX_RESERVED + (42* CFS_NUM_CPU_TLM_MIDS ))   /* 0x5600 */
#define CFS_TLM_MID_BASE_CPU44      (CFE_TLM_MID_MAX_RESERVED + (43* CFS_NUM_CPU_TLM_MIDS ))   /* 0x5800 */
#define CFS_TLM_MID_BASE_CPU45      (CFE_TLM_MID_MAX_RESERVED + (44* CFS_NUM_CPU_TLM_MIDS ))   /* 0x5a00 */
#define CFS_TLM_MID_BASE_CPU46      (CFE_TLM_MID_MAX_RESERVED + (45* CFS_NUM_CPU_TLM_MIDS ))   /* 0x5c00 */
#define CFS_TLM_MID_BASE_CPU47      (CFE_TLM_MID_MAX_RESERVED + (46* CFS_NUM_CPU_TLM_MIDS ))   /* 0x5e00 */
#define CFS_TLM_MID_BASE_CPU48      (CFE_TLM_MID_MAX_RESERVED + (47* CFS_NUM_CPU_TLM_MIDS ))   /* 0x6000 */

/* Re-use the global cFE base.  The hardcoded offset here is to deconflict with cFE. */

#define CFS_CMD_MID_BASE_GLOB      (CFE_CMD_MID_MAX_RESERVED + (62 * CFS_NUM_CPU_CMD_MIDS))   /* 0xfe00 */
#define CFS_TLM_MID_BASE_GLOB      (CFE_TLM_MID_MAX_RESERVED + (62 * CFS_NUM_CPU_TLM_MIDS))   /* 0x7e00 */


#if ((CFS_CMD_MID_BASE_GLOB + CFS_NUM_GBL_CMD_MIDS + 1) > CFE_SB_HIGHEST_VALID_MSGID)
    #error "CFS CMD MIDs exceed CFE_SB_HIGHEST_VALID_MSGID"
    #endif
    #if ((CFS_TLM_MID_BASE_GLOB + CFS_NUM_GBL_TLM_MIDS + 1) > (CFE_SB_HIGHEST_VALID_MSGID / 2))
    #error "CFS TLM MIDs exceed CCSDS application ID"
    #endif

/*
 * Platform-specific definitions
 */

/* Select the base address for the CPU's
  The hardcoded offsets here are to deconflict with cFE. */
#if CFE_CPU_ID  == 1
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU1)   /* 0x8200 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU1)   /* 0x0200 */
#elif CFE_CPU_ID  == 2
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU2)   /* 0x8400 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU2)   /* 0x0400 */
#elif CFE_CPU_ID  == 3
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU3)   /* 0x8600 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU3)   /* 0x0600 */
#elif CFE_CPU_ID  == 4
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU4)   /* 0x8800 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU4)   /* 0x0800 */
#elif CFE_CPU_ID  == 5
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU5)   /* 0x8a00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU5)   /* 0x0a00 */
#elif CFE_CPU_ID  == 6
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU6)   /* 0x8c00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU6)   /* 0x0c00 */
#elif CFE_CPU_ID  == 7
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU7)   /* 0x8e00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU7)   /* 0x0e00 */
#elif CFE_CPU_ID  == 8
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU8)   /* 0x9000 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU8)   /* 0x1000 */
#elif CFE_CPU_ID  == 9
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU9)   /* 0x9200 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU9)   /* 0x1200 */
#elif CFE_CPU_ID  == 10
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU10)   /* 0x9400 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU10)   /* 0x1400 */
#elif CFE_CPU_ID  == 11
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU11)   /* 0x9600 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU11)   /* 0x1600 */
#elif CFE_CPU_ID  == 12
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU12)   /* 0x9800 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU12)   /* 0x1800 */
#elif CFE_CPU_ID  == 16
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU16)   /* 0xa000 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU16)   /* 0x2000 */
#elif CFE_CPU_ID  == 33
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU33)   /* 0xc200 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU33)   /* 0x4200 */
#elif CFE_CPU_ID  == 34
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU34)   /* 0xc400 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU34)   /* 0x4400 */
#elif CFE_CPU_ID  == 35
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU35)   /* 0xc600 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU35)   /* 0x4600 */
#elif CFE_CPU_ID  == 36
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU36)   /* 0xc800 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU36)   /* 0x4800 */
#elif CFE_CPU_ID  == 37
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU37)   /* 0xca00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU37)   /* 0x4a00 */
#elif CFE_CPU_ID  == 38
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU38)   /* 0xcc00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU38)   /* 0x4c00 */
#elif CFE_CPU_ID  == 39
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU39)   /* 0xce00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU39)   /* 0x4e00 */
#elif CFE_CPU_ID  == 40
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU40)   /* 0xd000 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU40)   /* 0x5000 */
#elif CFE_CPU_ID  == 41
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU41)   /* 0xd200 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU41)   /* 0x5200 */
#elif CFE_CPU_ID  == 42
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU42)   /* 0xd400 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU42)   /* 0x5400 */
#elif CFE_CPU_ID  == 43
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU43)   /* 0xd600 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU43)   /* 0x5600 */
#elif CFE_CPU_ID  == 44
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU44)   /* 0xd800 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU44)   /* 0x5800 */
#elif CFE_CPU_ID  == 45
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU45)   /* 0xda00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU45)   /* 0x5a00 */
#elif CFE_CPU_ID  == 46
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU46)   /* 0xdc00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU46)   /* 0x5c00 */
#elif CFE_CPU_ID  == 47
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU47)   /* 0xde00 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU47)   /* 0x5e00 */
#elif CFE_CPU_ID  == 48
#define CFS_CMD_MID_BASE_THISCPU   (CFS_CMD_MID_BASE_CPU48)   /* 0xe000 */
#define CFS_TLM_MID_BASE_THISCPU   (CFS_TLM_MID_BASE_CPU48)   /* 0x6000 */
#endif   //// CFE_CPU_ID checks

/* Local CFS CMD IDs  -- Multiple instances, this is version running on this CPU*/
#define CFE_SB_CMD_MID                              ( CFS_CMD_MID_BASE_THISCPU  + 0x0003 ) 
#define CFE_TBL_CMD_MID                             ( CFS_CMD_MID_BASE_THISCPU  + 0x0004 ) 
#define CFE_TIME_CMD_MID                            ( CFS_CMD_MID_BASE_THISCPU  + 0x0005 ) 
#define CFE_ES_CMD_MID                              ( CFS_CMD_MID_BASE_THISCPU  + 0x0006 ) 
#define CFE_ES_SEND_HK_MID                          ( CFS_CMD_MID_BASE_THISCPU  + 0x0008 ) 
#define CFE_EVS_SEND_HK_MID                         ( CFS_CMD_MID_BASE_THISCPU  + 0x0009 ) 
#define HK_CMD_MID                                  ( CFS_CMD_MID_BASE_THISCPU  + 0x0013 ) 
#define HK_SEND_COMBINED_PKT_MID                    ( CFS_CMD_MID_BASE_THISCPU  + 0x0014 ) 
#define HK_SEND_HK_MID                              ( CFS_CMD_MID_BASE_THISCPU  + 0x0015 ) 
#define SBN_SEND_HK_MID                             ( CFS_CMD_MID_BASE_THISCPU  + 0x0025 ) 
#define SC_1HZ_WAKEUP_MID                           ( CFS_CMD_MID_BASE_THISCPU  + 0x0027 ) 
#define SCH_CMD_MID                                 ( CFS_CMD_MID_BASE_THISCPU  + 0x002a ) 
#define SCH_SEND_HK_MID                             ( CFS_CMD_MID_BASE_THISCPU  + 0x002b ) 
#define SCH_UNUSED_MID                              ( CFS_CMD_MID_BASE_THISCPU  + 0x002c ) 
#define DS_REPLAY_CMD_MID                           ( CFS_CMD_MID_BASE_THISCPU  + 0x002f ) 
#define DS_CMD_MID                                  ( CFS_CMD_MID_BASE_THISCPU  + 0x0031 ) 
#define DS_SEND_HK_MID                              ( CFS_CMD_MID_BASE_THISCPU  + 0x0032 ) 
#define CI_GATE_CMD_MID                             ( CFS_CMD_MID_BASE_THISCPU  + 0x003e ) 
#define CI_SEND_HK_MID                              ( CFS_CMD_MID_BASE_THISCPU  + 0x003f ) 
#define CI_WAKEUP_MID                               ( CFS_CMD_MID_BASE_THISCPU  + 0x0040 ) 
#define TO_SEND_HK_MID                              ( CFS_CMD_MID_BASE_THISCPU  + 0x0042 ) 
#define TO_WAKEUP_MID                               ( CFS_CMD_MID_BASE_THISCPU  + 0x0043 ) 
#define SAMPLE_APP_CMD_MID                          ( CFS_CMD_MID_BASE_THISCPU  + 0x0050 ) 
#define SAMPLE_APP_SEND_HK_MID                      ( CFS_CMD_MID_BASE_THISCPU  + 0x0051 ) 
#define ACAWS_DE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_THISCPU  + 0x0052 ) 
#define ACAWS_DE_WAKEUP_MID                         ( CFS_CMD_MID_BASE_THISCPU  + 0x0053 ) 
#define ACAWS_DE_CMD_MID                            ( CFS_CMD_MID_BASE_THISCPU  + 0x0054 ) 
#define ACAWS_FD_SEND_HK_MID                        ( CFS_CMD_MID_BASE_THISCPU  + 0x0055 ) 
#define ACAWS_FD_CMD_MID                            ( CFS_CMD_MID_BASE_THISCPU  + 0x0057 ) 
#define ACAWS_SE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_THISCPU  + 0x0058 ) 
#define ACAWS_SE_WAKEUP_MID                         ( CFS_CMD_MID_BASE_THISCPU  + 0x0059 ) 
#define SCH_TT_SEND_HK_MID                          ( CFS_CMD_MID_BASE_THISCPU  + 0x005b ) 
#define SCH_TT_WAKEUP_MID                           ( CFS_CMD_MID_BASE_THISCPU  + 0x005c ) 
#define AMPSDB_IO_SEND_HK_MID                       ( CFS_CMD_MID_BASE_THISCPU  + 0x005f ) 
#define AMPSDB_IO_WAKEUP_MID                        ( CFS_CMD_MID_BASE_THISCPU  + 0x0060 ) 
#define SIMPLE_COUNTER_SEND_HK_MID                  ( CFS_CMD_MID_BASE_THISCPU  + 0x0062 ) 
#define SIMPLE_COUNTER_WAKEUP_MID                   ( CFS_CMD_MID_BASE_THISCPU  + 0x0063 ) 
#define TTE_SEND_HK_MID                             ( CFS_CMD_MID_BASE_THISCPU  + 0x0065 ) 
#define ACAWS_FIR_CMD_MID                           ( CFS_CMD_MID_BASE_THISCPU  + 0x0070 ) 
#define PPA_HYDE_CMD_MID                            ( CFS_CMD_MID_BASE_THISCPU  + 0x0071 ) 
#define PPA_HYDE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_THISCPU  + 0x0072 ) 
#define ACAWS_FIR_WAKEUP_MID                        ( CFS_CMD_MID_BASE_THISCPU  + 0x007f ) 
#define SB_MONITOR_APP_CMD_MID                      ( CFS_CMD_MID_BASE_THISCPU  + 0x0087 ) 
#define SB_MONITOR_APP_SEND_HK_MID                  ( CFS_CMD_MID_BASE_THISCPU  + 0x0088 ) 
#define CF_SEND_HK_MID                              ( CFS_CMD_MID_BASE_THISCPU  + 0x008a ) 
#define CF_WAKE_UP_REQ_CMD_MID                      ( CFS_CMD_MID_BASE_THISCPU  + 0x008b ) 
#define CF_CMD_MID                                  ( CFS_CMD_MID_BASE_THISCPU  + 0x008c ) 
#define CF_INCOMING_PDU_MID                         ( CFS_CMD_MID_BASE_THISCPU  + 0x008d ) 
#define XRAY_SEND_HK_MID                            ( CFS_CMD_MID_BASE_THISCPU  + 0x008e ) 
#define XRAY_NAV_CMD_MID                            ( CFS_CMD_MID_BASE_THISCPU  + 0x008f ) 
#define XRAY_WAKEUP_MID                             ( CFS_CMD_MID_BASE_THISCPU  + 0x0090 ) 


/* Local CFS TLM IDs  -- Multiple instances, this is version running on this CPU*/
#define CFE_ES_HK_TLM_MID                           ( CFS_TLM_MID_BASE_THISCPU  + 0x0000 ) 
#define CFE_EVS_HK_TLM_MID                          ( CFS_TLM_MID_BASE_THISCPU  + 0x0001 ) 
#define CFE_SB_HK_TLM_MID                           ( CFS_TLM_MID_BASE_THISCPU  + 0x0003 ) 
#define CFE_TBL_HK_TLM_MID                          ( CFS_TLM_MID_BASE_THISCPU  + 0x0004 ) 
#define CFE_TIME_HK_TLM_MID                         ( CFS_TLM_MID_BASE_THISCPU  + 0x0005 ) 
#define CFE_TIME_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_THISCPU  + 0x0006 ) 
#define CFE_EVS_LONG_EVENT_MSG_MID                  ( CFS_TLM_MID_BASE_THISCPU  + 0x0008 ) 
#define CFE_EVS_SHORT_EVENT_MSG_MID                 ( CFS_TLM_MID_BASE_THISCPU  + 0x0009 ) 
#define CFE_SB_STATS_TLM_MID                        ( CFS_TLM_MID_BASE_THISCPU  + 0x000a ) 
#define CFE_ES_APP_TLM_MID                          ( CFS_TLM_MID_BASE_THISCPU  + 0x000b ) 
#define CFE_TBL_REG_TLM_MID                         ( CFS_TLM_MID_BASE_THISCPU  + 0x000c ) 
#define CFE_SB_ALLSUBS_TLM_MID                      ( CFS_TLM_MID_BASE_THISCPU  + 0x000d ) 
#define CFE_SB_ONESUB_TLM_MID                       ( CFS_TLM_MID_BASE_THISCPU  + 0x000e ) 
#define CFE_ES_SHELL_TLM_MID                        ( CFS_TLM_MID_BASE_THISCPU  + 0x000f ) 
#define CFE_ES_MEMSTATS_TLM_MID                     ( CFS_TLM_MID_BASE_THISCPU  + 0x0010 ) 
#define HK_HK_TLM_MID                               ( CFS_TLM_MID_BASE_THISCPU  + 0x0017 ) 
#define HS_HK_TLM_MID                               ( CFS_TLM_MID_BASE_THISCPU  + 0x0018 ) 
#define LC_HK_TLM_MID                               ( CFS_TLM_MID_BASE_THISCPU  + 0x0019 ) 
#define SAMPLE_APP_HK_TLM_MID                       ( CFS_TLM_MID_BASE_THISCPU  + 0x001d ) 
#define SBN_HK_TLM_MID                              ( CFS_TLM_MID_BASE_THISCPU  + 0x001e ) 
#define SBN_GET_PEER_LIST_RSP_MID                   ( CFS_TLM_MID_BASE_THISCPU  + 0x001f ) 
#define SBN_GET_PEER_STATUS_RSP_MID                 ( CFS_TLM_MID_BASE_THISCPU  + 0x0020 ) 
#define SCH_DIAG_TLM_MID                            ( CFS_TLM_MID_BASE_THISCPU  + 0x0022 ) 
#define SCH_HK_TLM_MID                              ( CFS_TLM_MID_BASE_THISCPU  + 0x0023 ) 
#define CI_OUT_DATA_MID                             ( CFS_TLM_MID_BASE_THISCPU  + 0x002c ) 
#define CI_HK_TLM_MID                               ( CFS_TLM_MID_BASE_THISCPU  + 0x002d ) 
#define TO_DATA_TYPE_MID                            ( CFS_TLM_MID_BASE_THISCPU  + 0x002e ) 
#define TO_OUT_DATA_MID                             ( CFS_TLM_MID_BASE_THISCPU  + 0x002f ) 
#define TO_HK_TLM_MID                               ( CFS_TLM_MID_BASE_THISCPU  + 0x0030 ) 
#define DS_DIAG_TLM_MID                             ( CFS_TLM_MID_BASE_THISCPU  + 0x0031 ) 
#define DS_HK_TLM_MID                               ( CFS_TLM_MID_BASE_THISCPU  + 0x0032 ) 
#define CF_SPACE_TO_GND_PDU_MID                     ( CFS_TLM_MID_BASE_THISCPU  + 0x0033 ) 
#define CF_TRANS_TLM_MID                            ( CFS_TLM_MID_BASE_THISCPU  + 0x0034 ) 
#define CF_HK_TLM_MID                               ( CFS_TLM_MID_BASE_THISCPU  + 0x0035 ) 
#define SCH_TT_HK_TLM_MID                           ( CFS_TLM_MID_BASE_THISCPU  + 0x005d ) 
#define SIMPLE_COUNTER_HK_TLM_MID                   ( CFS_TLM_MID_BASE_THISCPU  + 0x005f ) 
#define SIMPLE_COUNTER_OUT_DATA_MID                 ( CFS_TLM_MID_BASE_THISCPU  + 0x0060 ) 
#define ACAWS_DE_HK_TLM_MID                         ( CFS_TLM_MID_BASE_THISCPU  + 0x0066 ) 
#define PPA_HYDE_HK_TLM_MID                         ( CFS_TLM_MID_BASE_THISCPU  + 0x0067 ) 
#define AMPSDB_IO_HK_TLM_MID                        ( CFS_TLM_MID_BASE_THISCPU  + 0x0070 ) 
#define AMPSDB_IO_OUT_DATA_MID                      ( CFS_TLM_MID_BASE_THISCPU  + 0x0071 ) 
#define DS_REPLAY_TLM_MID                           ( CFS_TLM_MID_BASE_THISCPU  + 0x008e ) 
#define SB_MONITOR_APP_HK_TLM_MID                   ( CFS_TLM_MID_BASE_THISCPU  + 0x00a0 ) 
#define XRAY_HK_TLM_MID                             ( CFS_TLM_MID_BASE_THISCPU  + 0x00a1 ) 
#define XRAY_OUTDATA_MID                            ( CFS_TLM_MID_BASE_THISCPU  + 0x00a2 ) 
#define SBN_TLM_MID                                 ( CFS_TLM_MID_BASE_THISCPU  + 0x00a3 ) 


/*Duplicated Habitat TLM message IDs ( for local processor) */
#define L1V_MID                                     ( CFS_TLM_MID_BASE_THISCPU + 0x0052 ) 
#define PPA_HYDE_OutData_MID                        ( CFS_TLM_MID_BASE_THISCPU + 0x005b ) 
#define TTE_DIAG_TLM_MID                            ( CFS_TLM_MID_BASE_THISCPU + 0x0061 ) 
#define TTE_HK_TLM_MID                              ( CFS_TLM_MID_BASE_THISCPU + 0x0062 ) 
#define PPA_HYDE_HkTlm_MID                          ( CFS_TLM_MID_BASE_THISCPU + 0x006f ) 
#define ACAWS_FIR_HK_TLM_MID                        ( CFS_TLM_MID_BASE_THISCPU + 0x007a ) 
#define ACAWS_DE_DIAGDATA_MID                       ( CFS_TLM_MID_BASE_THISCPU + 0x0080 ) 
#define ACAWS_DE_IMPACTREQ_MID                      ( CFS_TLM_MID_BASE_THISCPU + 0x0081 ) 
#define ACAWS_FD_TEST_RESULTS_MID                   ( CFS_TLM_MID_BASE_THISCPU + 0x0082 ) 
#define ACAWS_FIR_OUT_DATA_MID                      ( CFS_TLM_MID_BASE_THISCPU + 0x0083 ) 

/*Duplicated Habitat CMD message IDs ( for local processor) */
/*Non-core CFS Defined CMD message IDs */
#define LC_CMD_MID                                  ( CFS_CMD_MID_BASE_THISCPU + 0x0019 ) 
#define LC_RTS_REQ_MID                              ( CFS_CMD_MID_BASE_THISCPU + 0x001a ) 
#define LC_SAMPLE_AP_MID                            ( CFS_CMD_MID_BASE_THISCPU + 0x001b ) 
#define LC_SEND_HK_MID                              ( CFS_CMD_MID_BASE_THISCPU + 0x001c ) 
#define SBN_WAKEUP_MID                              ( CFS_CMD_MID_BASE_THISCPU + 0x0024 ) 
#define SBN_CMD_MID                                 ( CFS_CMD_MID_BASE_THISCPU + 0x0026 ) 
#define CI_APP_CMD_MID                              ( CFS_CMD_MID_BASE_THISCPU + 0x003d ) 
#define TO_APP_CMD_MID                              ( CFS_CMD_MID_BASE_THISCPU + 0x0041 ) 
#define ACAWS_FD_WAKEUP_MID                         ( CFS_CMD_MID_BASE_THISCPU + 0x0056 ) 
#define SCH_TT_CMD_MID                              ( CFS_CMD_MID_BASE_THISCPU + 0x005d ) 
#define AMPSDB_IO_CMD_MID                           ( CFS_CMD_MID_BASE_THISCPU + 0x005e ) 
#define SIMPLE_COUNTER_CMD_MID                      ( CFS_CMD_MID_BASE_THISCPU + 0x0061 ) 
#define TTE_CMD_MID                                 ( CFS_CMD_MID_BASE_THISCPU + 0x0064 ) 

/* Globaly Unique Reserverd CMD MIDs (i.e. not defined in CCDD) */
#define DUP_WAKEUP_MID                              ( CFS_CMD_MID_BASE_GLOB  + 0x006e )    /* 0xfe6e */
#define L1V_CMD_MID                                 ( CFS_CMD_MID_BASE_GLOB  + 0x006f )    /* 0xfe6f */
#define VMS_SIM_SEND_HK_MID                         ( CFS_CMD_MID_BASE_GLOB  + 0x0077 )    /* 0xfe77 */
#define VMS_SIM_CMD_MID                             ( CFS_CMD_MID_BASE_GLOB  + 0x0078 )    /* 0xfe78 */
#define VMS_SEND_HK_MID                             ( CFS_CMD_MID_BASE_GLOB  + 0x0079 )    /* 0xfe79 */
#define VMS_CMD_MID                                 ( CFS_CMD_MID_BASE_GLOB  + 0x007a )    /* 0xfe7a */
#define PowerSource1_CMD_MID                        ( CFS_CMD_MID_BASE_GLOB  + 0x007b )    /* 0xfe7b */
#define PowerSource2_CMD_MID                        ( CFS_CMD_MID_BASE_GLOB  + 0x007c )    /* 0xfe7c */
#define MpcvGncProtoNomCmd_MID                      ( CFS_CMD_MID_BASE_GLOB  + 0x007d )    /* 0xfe7d */
#define HERA_CMD_MID                                ( CFS_CMD_MID_BASE_GLOB  + 0x007e )    /* 0xfe7e */
#define MAST_HAB_CMD_MID                            ( CFS_CMD_MID_BASE_GLOB  + 0x0091 )    /* 0xfe91 */
#define MAST_HAB_WAKEUP_MID                         ( CFS_CMD_MID_BASE_GLOB  + 0x0092 )    /* 0xfe92 */
#define MAST_PPE_CMD_MID                            ( CFS_CMD_MID_BASE_GLOB  + 0x0093 )    /* 0xfe93 */
#define MAST_PPE_WAKEUP_MID                         ( CFS_CMD_MID_BASE_GLOB  + 0x0094 )    /* 0xfe94 */

/* Global (i.e. unique) CCDD MIDs (Cmd Structure defined in CCDD) */
#define HAB_ECLSS_ARS_CMD_MID                       ( CFS_CMD_MID_BASE_GLOB  + 0x0044 )    /* 0xfe44 */
#define HAB_ECLSS_PCS_CMD_MID                       ( CFS_CMD_MID_BASE_GLOB  + 0x0045 )    /* 0xfe45 */
#define HAB_ECLSS_WMS_CMD_MID                       ( CFS_CMD_MID_BASE_GLOB  + 0x0046 )    /* 0xfe46 */
#define HAB_Power_Source1_CMD_MID                   ( CFS_CMD_MID_BASE_GLOB  + 0x0047 )    /* 0xfe47 */
#define HAB_Power_Source2_CMD_MID                   ( CFS_CMD_MID_BASE_GLOB  + 0x0048 )    /* 0xfe48 */
#define HAL_MBSU1_CMD_MID                           ( CFS_CMD_MID_BASE_GLOB  + 0x0049 )    /* 0xfe49 */
#define HAL_MBSU2_CMD_MID                           ( CFS_CMD_MID_BASE_GLOB  + 0x004a )    /* 0xfe4a */
#define HAL_PDU1_CMD_MID                            ( CFS_CMD_MID_BASE_GLOB  + 0x004b )    /* 0xfe4b */
#define HAL_PDU2_CMD_MID                            ( CFS_CMD_MID_BASE_GLOB  + 0x004c )    /* 0xfe4c */
#define HAL_PDU3_CMD_MID                            ( CFS_CMD_MID_BASE_GLOB  + 0x004d )    /* 0xfe4d */
#define HAL_PDU4_CMD_MID                            ( CFS_CMD_MID_BASE_GLOB  + 0x004e )    /* 0xfe4e */
#define MBSU1_CMD_MID                               ( CFS_CMD_MID_BASE_GLOB  + 0x0066 )    /* 0xfe66 */
#define MBSU2_CMD_MID                               ( CFS_CMD_MID_BASE_GLOB  + 0x0067 )    /* 0xfe67 */
#define HAL_Power_Source1_CMD_MID                   ( CFS_CMD_MID_BASE_GLOB  + 0x0068 )    /* 0xfe68 */
#define HAL_Power_Source2_CMD_MID                   ( CFS_CMD_MID_BASE_GLOB  + 0x0069 )    /* 0xfe69 */
#define HAB_TCS_ETCS_A_CMD_MID                      ( CFS_CMD_MID_BASE_GLOB  + 0x006a )    /* 0xfe6a */
#define HAB_TCS_ETCS_B_CMD_MID                      ( CFS_CMD_MID_BASE_GLOB  + 0x006b )    /* 0xfe6b */
#define HAB_TCS_ITCS_CMD_MID                        ( CFS_CMD_MID_BASE_GLOB  + 0x006c )    /* 0xfe6c */
#define DUP_CMD_MID                                 ( CFS_CMD_MID_BASE_GLOB  + 0x006d )    /* 0xfe6d */
#define PDU1_CMD_MID                                ( CFS_CMD_MID_BASE_GLOB  + 0x0073 )    /* 0xfe73 */
#define PDU2_CMD_MID                                ( CFS_CMD_MID_BASE_GLOB  + 0x0074 )    /* 0xfe74 */
#define PDU3_CMD_MID                                ( CFS_CMD_MID_BASE_GLOB  + 0x0075 )    /* 0xfe75 */
#define PDU4_CMD_MID                                ( CFS_CMD_MID_BASE_GLOB  + 0x0076 )    /* 0xfe76 */
#define PPE_MBSU1_CMD_MID                           ( CFS_CMD_MID_BASE_GLOB  + 0x0081 )    /* 0xfe81 */
#define PPE_MBSU2_CMD_MID                           ( CFS_CMD_MID_BASE_GLOB  + 0x0082 )    /* 0xfe82 */
#define PPE_PDU1_CMD_MID                            ( CFS_CMD_MID_BASE_GLOB  + 0x0083 )    /* 0xfe83 */
#define PPE_PDU2_CMD_MID                            ( CFS_CMD_MID_BASE_GLOB  + 0x0084 )    /* 0xfe84 */
#define PPE_Power_Source1_CMD_MID                   ( CFS_CMD_MID_BASE_GLOB  + 0x0085 )    /* 0xfe85 */
#define PPE_Power_Source2_CMD_MID                   ( CFS_CMD_MID_BASE_GLOB  + 0x0086 )    /* 0xfe86 */

/* Globaly Unique Reserverd TLM MIDs (i.e. not defined in CCDD) */
#define ACAWS_DE_DiagData_Msg_MANGLED_MID           ( CFS_TLM_MID_BASE_GLOB  + 0x0040 )    /* 0x7e40 */
#define ACAWS_DE_DiagData_Msg_VOTED_MID             ( CFS_TLM_MID_BASE_GLOB  + 0x0042 )    /* 0x7e42 */
#define ACAWS_FD_TEST_RESULTS_MSG_MANGLED_MID       ( CFS_TLM_MID_BASE_GLOB  + 0x0044 )    /* 0x7e44 */
#define ACAWS_FD_TEST_RESULTS_MSG_VOTED_MID         ( CFS_TLM_MID_BASE_GLOB  + 0x0046 )    /* 0x7e46 */
#define ACAWS_SE_OutData_Msg_MANGLED_MID            ( CFS_TLM_MID_BASE_GLOB  + 0x0048 )    /* 0x7e48 */
#define ACAWS_SE_OutData_Msg_VOTED_MID              ( CFS_TLM_MID_BASE_GLOB  + 0x004a )    /* 0x7e4a */
#define ACAWS_ISP_BRIDGE_RECEIVE_ISP_MSG_MID        ( CFS_TLM_MID_BASE_GLOB  + 0x004c )    /* 0x7e4c */
#define ACAWS_ISP_BRIDGE_SEND_ISP_MSG_MID           ( CFS_TLM_MID_BASE_GLOB  + 0x004d )    /* 0x7e4d */
#define PPA_HYDE_OutData_MANGLED_MID                ( CFS_TLM_MID_BASE_GLOB  + 0x005a )    /* 0x7e5a */
#define PPA_HYDE_OutData_VOTED_MID                  ( CFS_TLM_MID_BASE_GLOB  + 0x005c )    /* 0x7e5c */
#define APC_LOAD_SCH_MID                            ( CFS_TLM_MID_BASE_GLOB  + 0x005e )    /* 0x7e5e */
#define PPA_TLM_MID                                 ( CFS_TLM_MID_BASE_GLOB  + 0x0065 )    /* 0x7e65 */
#define DTN_OUT_MID                                 ( CFS_TLM_MID_BASE_GLOB  + 0x0072 )    /* 0x7e72 */
#define ACAWS_FIR_OUT_DATA_VOTED_MID                ( CFS_TLM_MID_BASE_GLOB  + 0x007b )    /* 0x7e7b */
#define ACAWS_FIR_OUT_DATA_MANGLED_MID              ( CFS_TLM_MID_BASE_GLOB  + 0x007d )    /* 0x7e7d */
#define SCH_TT_UNUSED_MID                           ( CFS_TLM_MID_BASE_GLOB  + 0x007e )    /* 0x7e7e */

/* Global (i.e. unique) CCDD MIDs (Tlm Structure defined in CCDD) */
#define HAB_ECLSS_PCS_TLM_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x004b )    /* 0x7e4b */
#define ECLSS_PPA_tlm_packet_MID                    ( CFS_TLM_MID_BASE_GLOB  + 0x004e )    /* 0x7e4e */
#define APC_AVAILIBILITY_MID                        ( CFS_TLM_MID_BASE_GLOB  + 0x004f )    /* 0x7e4f */
#define APC_EA_RESPONSE_MID                         ( CFS_TLM_MID_BASE_GLOB  + 0x0050 )    /* 0x7e50 */
#define APC_PLS_RESPONSE_MID                        ( CFS_TLM_MID_BASE_GLOB  + 0x0051 )    /* 0x7e51 */
#define MBSU1_OUT_MID                               ( CFS_TLM_MID_BASE_GLOB  + 0x0053 )    /* 0x7e53 */
#define MBSU2_OUT_MID                               ( CFS_TLM_MID_BASE_GLOB  + 0x0054 )    /* 0x7e54 */
#define MDA_OUT_MID                                 ( CFS_TLM_MID_BASE_GLOB  + 0x0055 )    /* 0x7e55 */
#define HAB_ECLSS_ARS_TLM_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x0056 )    /* 0x7e56 */
#define MPDU1_OUT_MID                               ( CFS_TLM_MID_BASE_GLOB  + 0x0057 )    /* 0x7e57 */
#define HAB_TCS_ETCS_TLM_MID                        ( CFS_TLM_MID_BASE_GLOB  + 0x0058 )    /* 0x7e58 */
#define HAB_TCS_ITCS_TLM_MID                        ( CFS_TLM_MID_BASE_GLOB  + 0x0059 )    /* 0x7e59 */
#define VMS_LOAD_SCH_MID                            ( CFS_TLM_MID_BASE_GLOB  + 0x0063 )    /* 0x7e63 */
#define DUP_HK_TLM_MID                              ( CFS_TLM_MID_BASE_GLOB  + 0x0064 )    /* 0x7e64 */
#define PDU1_OUT_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x006a )    /* 0x7e6a */
#define PDU2_OUT_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x006b )    /* 0x7e6b */
#define PDU3_OUT_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x006c )    /* 0x7e6c */
#define PDU4_OUT_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x006d )    /* 0x7e6d */
#define REQUEST_ENERGY_MID                          ( CFS_TLM_MID_BASE_GLOB  + 0x006e )    /* 0x7e6e */
#define NPAS_AV_OUT_MID                             ( CFS_TLM_MID_BASE_GLOB  + 0x0073 )    /* 0x7e73 */
#define NPAS_VM_OUT_MID                             ( CFS_TLM_MID_BASE_GLOB  + 0x0074 )    /* 0x7e74 */
#define NPAS_PWR_OUT_MID                            ( CFS_TLM_MID_BASE_GLOB  + 0x0075 )    /* 0x7e75 */
#define HERA_OUT_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x0079 )    /* 0x7e79 */
#define HAB_ECLSS_WMS_TLM_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x007f )    /* 0x7e7f */
#define HAB_POWER_SOURCE1_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x0085 )    /* 0x7e85 */
#define HAB_POWER_SOURCE2_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x0086 )    /* 0x7e86 */
#define HAL_POWER_SOURCE1_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x008b )    /* 0x7e8b */
#define HAL_POWER_SOURCE2_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x008c )    /* 0x7e8c */
#define MPCV_NAV_STATE_TLM_MID                      ( CFS_TLM_MID_BASE_GLOB  + 0x008d )    /* 0x7e8d */
#define PPE_NAV_STATE_TLM_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x0090 )    /* 0x7e90 */
#define PPE_POWER_SOURCE1_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x0093 )    /* 0x7e93 */
#define PPE_POWER_SOURCE2_MID                       ( CFS_TLM_MID_BASE_GLOB  + 0x0094 )    /* 0x7e94 */
#define HAL_MBSU1_MID                               ( CFS_TLM_MID_BASE_GLOB  + 0x0095 )    /* 0x7e95 */
#define HAL_MBSU2_MID                               ( CFS_TLM_MID_BASE_GLOB  + 0x0096 )    /* 0x7e96 */
#define HAL_PDU1_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x0097 )    /* 0x7e97 */
#define HAL_PDU2_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x0098 )    /* 0x7e98 */
#define HAL_PDU3_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x0099 )    /* 0x7e99 */
#define HAL_PDU4_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x009a )    /* 0x7e9a */
#define PPE_MBSU1_MID                               ( CFS_TLM_MID_BASE_GLOB  + 0x009b )    /* 0x7e9b */
#define PPE_MBSU2_MID                               ( CFS_TLM_MID_BASE_GLOB  + 0x009c )    /* 0x7e9c */
#define PPE_PDU1_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x009d )    /* 0x7e9d */
#define PPE_PDU2_MID                                ( CFS_TLM_MID_BASE_GLOB  + 0x009e )    /* 0x7e9e */
#define mast_state_description_MID                  ( CFS_TLM_MID_BASE_GLOB  + 0x00a4 )    /* 0x7ea4 */
#define mast_ppe_esm_command_MID                    ( CFS_TLM_MID_BASE_GLOB  + 0x00a5 )    /* 0x7ea5 */
#define mast_ppe_esm_state_description_MID          ( CFS_TLM_MID_BASE_GLOB  + 0x00a6 )    /* 0x7ea6 */
#define DSG_GNC_TLM_MID                             ( CFS_TLM_MID_BASE_GLOB  + 0x00a7 )    /* 0x7ea7 */
#define ROVER_GNC_TLM_MID                           ( CFS_TLM_MID_BASE_GLOB  + 0x00a8 )    /* 0x7ea8 */

/* All version of repeated CFS CMD message IDs */
#define CPU1_SCH_CMD_MID                            ( CFS_CMD_MID_BASE_CPU1 + 0x002a )    /* 0x822a */
#define CPU1_SCH_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU1 + 0x002b )    /* 0x822b */
#define CPU1_DS_CMD_MID                             ( CFS_CMD_MID_BASE_CPU1 + 0x0031 )    /* 0x8231 */
#define CPU1_DS_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU1 + 0x0032 )    /* 0x8232 */
#define CPU1_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU1 + 0x003f )    /* 0x823f */
#define CPU1_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU1 + 0x0040 )    /* 0x8240 */
#define CPU1_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU1 + 0x0042 )    /* 0x8242 */
#define CPU1_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU1 + 0x0043 )    /* 0x8243 */
#define CPU1_ACAWS_DE_WAKEUP_MID                    ( CFS_CMD_MID_BASE_CPU1 + 0x0053 )    /* 0x8253 */
#define CPU1_ACAWS_DE_CMD_MID                       ( CFS_CMD_MID_BASE_CPU1 + 0x0054 )    /* 0x8254 */
#define CPU1_ACAWS_FD_CMD_MID                       ( CFS_CMD_MID_BASE_CPU1 + 0x0057 )    /* 0x8257 */
#define CPU1_SIMPLE_COUNTER_SEND_HK_MID             ( CFS_CMD_MID_BASE_CPU1 + 0x0062 )    /* 0x8262 */
#define CPU1_SIMPLE_COUNTER_WAKEUP_MID              ( CFS_CMD_MID_BASE_CPU1 + 0x0063 )    /* 0x8263 */
#define CPU1_TTE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU1 + 0x0065 )    /* 0x8265 */
#define CPU1_ACAWS_FIR_CMD_MID                      ( CFS_CMD_MID_BASE_CPU1 + 0x0070 )    /* 0x8270 */
#define CPU1_ACAWS_FIR_WAKEUP_MID                   ( CFS_CMD_MID_BASE_CPU1 + 0x007f )    /* 0x827f */
#define CPU1_LC_CMD_MID                             ( CFS_CMD_MID_BASE_CPU1 + 0x0019 )    /* 0x8219 */
#define CPU1_LC_RTS_REQ_MID                         ( CFS_CMD_MID_BASE_CPU1 + 0x001a )    /* 0x821a */
#define CPU1_LC_SAMPLE_AP_MID                       ( CFS_CMD_MID_BASE_CPU1 + 0x001b )    /* 0x821b */
#define CPU1_LC_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU1 + 0x001c )    /* 0x821c */
#define CPU1_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU1 + 0x0024 )    /* 0x8224 */
#define CPU1_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU1 + 0x0026 )    /* 0x8226 */
#define CPU1_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU1 + 0x003d )    /* 0x823d */
#define CPU1_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU1 + 0x0041 )    /* 0x8241 */
#define CPU1_ACAWS_FD_WAKEUP_MID                    ( CFS_CMD_MID_BASE_CPU1 + 0x0056 )    /* 0x8256 */
#define CPU1_SIMPLE_COUNTER_CMD_MID                 ( CFS_CMD_MID_BASE_CPU1 + 0x0061 )    /* 0x8261 */
#define CPU1_TTE_CMD_MID                            ( CFS_CMD_MID_BASE_CPU1 + 0x0064 )    /* 0x8264 */
#define CPU2_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU2 + 0x003f )    /* 0x843f */
#define CPU2_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU2 + 0x0040 )    /* 0x8440 */
#define CPU2_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU2 + 0x0042 )    /* 0x8442 */
#define CPU2_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU2 + 0x0043 )    /* 0x8443 */
#define CPU2_ACAWS_DE_WAKEUP_MID                    ( CFS_CMD_MID_BASE_CPU2 + 0x0053 )    /* 0x8453 */
#define CPU2_ACAWS_DE_CMD_MID                       ( CFS_CMD_MID_BASE_CPU2 + 0x0054 )    /* 0x8454 */
#define CPU2_ACAWS_FD_CMD_MID                       ( CFS_CMD_MID_BASE_CPU2 + 0x0057 )    /* 0x8457 */
#define CPU2_SIMPLE_COUNTER_SEND_HK_MID             ( CFS_CMD_MID_BASE_CPU2 + 0x0062 )    /* 0x8462 */
#define CPU2_SIMPLE_COUNTER_WAKEUP_MID              ( CFS_CMD_MID_BASE_CPU2 + 0x0063 )    /* 0x8463 */
#define CPU2_TTE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU2 + 0x0065 )    /* 0x8465 */
#define CPU2_ACAWS_FIR_CMD_MID                      ( CFS_CMD_MID_BASE_CPU2 + 0x0070 )    /* 0x8470 */
#define CPU2_ACAWS_FIR_WAKEUP_MID                   ( CFS_CMD_MID_BASE_CPU2 + 0x007f )    /* 0x847f */
#define CPU2_LC_CMD_MID                             ( CFS_CMD_MID_BASE_CPU2 + 0x0019 )    /* 0x8419 */
#define CPU2_LC_RTS_REQ_MID                         ( CFS_CMD_MID_BASE_CPU2 + 0x001a )    /* 0x841a */
#define CPU2_LC_SAMPLE_AP_MID                       ( CFS_CMD_MID_BASE_CPU2 + 0x001b )    /* 0x841b */
#define CPU2_LC_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU2 + 0x001c )    /* 0x841c */
#define CPU2_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU2 + 0x0024 )    /* 0x8424 */
#define CPU2_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU2 + 0x0026 )    /* 0x8426 */
#define CPU2_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU2 + 0x003d )    /* 0x843d */
#define CPU2_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU2 + 0x0041 )    /* 0x8441 */
#define CPU2_ACAWS_FD_WAKEUP_MID                    ( CFS_CMD_MID_BASE_CPU2 + 0x0056 )    /* 0x8456 */
#define CPU2_SIMPLE_COUNTER_CMD_MID                 ( CFS_CMD_MID_BASE_CPU2 + 0x0061 )    /* 0x8461 */
#define CPU2_TTE_CMD_MID                            ( CFS_CMD_MID_BASE_CPU2 + 0x0064 )    /* 0x8464 */
#define CPU3_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU3 + 0x003f )    /* 0x863f */
#define CPU3_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU3 + 0x0040 )    /* 0x8640 */
#define CPU3_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU3 + 0x0042 )    /* 0x8642 */
#define CPU3_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU3 + 0x0043 )    /* 0x8643 */
#define CPU3_ACAWS_DE_WAKEUP_MID                    ( CFS_CMD_MID_BASE_CPU3 + 0x0053 )    /* 0x8653 */
#define CPU3_ACAWS_DE_CMD_MID                       ( CFS_CMD_MID_BASE_CPU3 + 0x0054 )    /* 0x8654 */
#define CPU3_ACAWS_FD_CMD_MID                       ( CFS_CMD_MID_BASE_CPU3 + 0x0057 )    /* 0x8657 */
#define CPU3_SIMPLE_COUNTER_SEND_HK_MID             ( CFS_CMD_MID_BASE_CPU3 + 0x0062 )    /* 0x8662 */
#define CPU3_SIMPLE_COUNTER_WAKEUP_MID              ( CFS_CMD_MID_BASE_CPU3 + 0x0063 )    /* 0x8663 */
#define CPU3_TTE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU3 + 0x0065 )    /* 0x8665 */
#define CPU3_ACAWS_FIR_CMD_MID                      ( CFS_CMD_MID_BASE_CPU3 + 0x0070 )    /* 0x8670 */
#define CPU3_ACAWS_FIR_WAKEUP_MID                   ( CFS_CMD_MID_BASE_CPU3 + 0x007f )    /* 0x867f */
#define CPU3_LC_CMD_MID                             ( CFS_CMD_MID_BASE_CPU3 + 0x0019 )    /* 0x8619 */
#define CPU3_LC_RTS_REQ_MID                         ( CFS_CMD_MID_BASE_CPU3 + 0x001a )    /* 0x861a */
#define CPU3_LC_SAMPLE_AP_MID                       ( CFS_CMD_MID_BASE_CPU3 + 0x001b )    /* 0x861b */
#define CPU3_LC_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU3 + 0x001c )    /* 0x861c */
#define CPU3_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU3 + 0x0024 )    /* 0x8624 */
#define CPU3_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU3 + 0x0026 )    /* 0x8626 */
#define CPU3_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU3 + 0x003d )    /* 0x863d */
#define CPU3_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU3 + 0x0041 )    /* 0x8641 */
#define CPU3_ACAWS_FD_WAKEUP_MID                    ( CFS_CMD_MID_BASE_CPU3 + 0x0056 )    /* 0x8656 */
#define CPU3_SIMPLE_COUNTER_CMD_MID                 ( CFS_CMD_MID_BASE_CPU3 + 0x0061 )    /* 0x8661 */
#define CPU3_TTE_CMD_MID                            ( CFS_CMD_MID_BASE_CPU3 + 0x0064 )    /* 0x8664 */
#define CPU4_SCH_CMD_MID                            ( CFS_CMD_MID_BASE_CPU4 + 0x002a )    /* 0x882a */
#define CPU4_SCH_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU4 + 0x002b )    /* 0x882b */
#define CPU4_DS_CMD_MID                             ( CFS_CMD_MID_BASE_CPU4 + 0x0031 )    /* 0x8831 */
#define CPU4_DS_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU4 + 0x0032 )    /* 0x8832 */
#define CPU4_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU4 + 0x003f )    /* 0x883f */
#define CPU4_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU4 + 0x0040 )    /* 0x8840 */
#define CPU4_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU4 + 0x0042 )    /* 0x8842 */
#define CPU4_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU4 + 0x0043 )    /* 0x8843 */
#define CPU4_ACAWS_DE_WAKEUP_MID                    ( CFS_CMD_MID_BASE_CPU4 + 0x0053 )    /* 0x8853 */
#define CPU4_ACAWS_DE_CMD_MID                       ( CFS_CMD_MID_BASE_CPU4 + 0x0054 )    /* 0x8854 */
#define CPU4_ACAWS_FD_CMD_MID                       ( CFS_CMD_MID_BASE_CPU4 + 0x0057 )    /* 0x8857 */
#define CPU4_TTE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU4 + 0x0065 )    /* 0x8865 */
#define CPU4_ACAWS_FIR_CMD_MID                      ( CFS_CMD_MID_BASE_CPU4 + 0x0070 )    /* 0x8870 */
#define CPU4_ACAWS_FIR_WAKEUP_MID                   ( CFS_CMD_MID_BASE_CPU4 + 0x007f )    /* 0x887f */
#define CPU4_LC_CMD_MID                             ( CFS_CMD_MID_BASE_CPU4 + 0x0019 )    /* 0x8819 */
#define CPU4_LC_RTS_REQ_MID                         ( CFS_CMD_MID_BASE_CPU4 + 0x001a )    /* 0x881a */
#define CPU4_LC_SAMPLE_AP_MID                       ( CFS_CMD_MID_BASE_CPU4 + 0x001b )    /* 0x881b */
#define CPU4_LC_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU4 + 0x001c )    /* 0x881c */
#define CPU4_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU4 + 0x0024 )    /* 0x8824 */
#define CPU4_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU4 + 0x0026 )    /* 0x8826 */
#define CPU4_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU4 + 0x003d )    /* 0x883d */
#define CPU4_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU4 + 0x0041 )    /* 0x8841 */
#define CPU4_ACAWS_FD_WAKEUP_MID                    ( CFS_CMD_MID_BASE_CPU4 + 0x0056 )    /* 0x8856 */
#define CPU4_TTE_CMD_MID                            ( CFS_CMD_MID_BASE_CPU4 + 0x0064 )    /* 0x8864 */
#define CPU5_SCH_CMD_MID                            ( CFS_CMD_MID_BASE_CPU5 + 0x002a )    /* 0x8a2a */
#define CPU5_SCH_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU5 + 0x002b )    /* 0x8a2b */
#define CPU5_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU5 + 0x003f )    /* 0x8a3f */
#define CPU5_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU5 + 0x0040 )    /* 0x8a40 */
#define CPU5_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU5 + 0x0042 )    /* 0x8a42 */
#define CPU5_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU5 + 0x0043 )    /* 0x8a43 */
#define CPU5_TTE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU5 + 0x0065 )    /* 0x8a65 */
#define CPU5_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU5 + 0x0024 )    /* 0x8a24 */
#define CPU5_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU5 + 0x0026 )    /* 0x8a26 */
#define CPU5_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU5 + 0x003d )    /* 0x8a3d */
#define CPU5_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU5 + 0x0041 )    /* 0x8a41 */
#define CPU5_TTE_CMD_MID                            ( CFS_CMD_MID_BASE_CPU5 + 0x0064 )    /* 0x8a64 */
#define CPU6_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU6 + 0x003f )    /* 0x8c3f */
#define CPU6_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU6 + 0x0040 )    /* 0x8c40 */
#define CPU6_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU6 + 0x0042 )    /* 0x8c42 */
#define CPU6_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU6 + 0x0043 )    /* 0x8c43 */
#define CPU6_TTE_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU6 + 0x0065 )    /* 0x8c65 */
#define CPU6_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU6 + 0x0024 )    /* 0x8c24 */
#define CPU6_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU6 + 0x0026 )    /* 0x8c26 */
#define CPU6_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU6 + 0x003d )    /* 0x8c3d */
#define CPU6_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU6 + 0x0041 )    /* 0x8c41 */
#define CPU6_TTE_CMD_MID                            ( CFS_CMD_MID_BASE_CPU6 + 0x0064 )    /* 0x8c64 */
#define CPU7_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU7 + 0x003f )    /* 0x8e3f */
#define CPU7_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU7 + 0x0040 )    /* 0x8e40 */
#define CPU7_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU7 + 0x0042 )    /* 0x8e42 */
#define CPU7_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU7 + 0x0043 )    /* 0x8e43 */
#define CPU7_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU7 + 0x0024 )    /* 0x8e24 */
#define CPU7_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU7 + 0x0026 )    /* 0x8e26 */
#define CPU7_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU7 + 0x003d )    /* 0x8e3d */
#define CPU7_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU7 + 0x0041 )    /* 0x8e41 */
#define CPU8_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU8 + 0x003f )    /* 0x903f */
#define CPU8_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU8 + 0x0040 )    /* 0x9040 */
#define CPU8_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU8 + 0x0042 )    /* 0x9042 */
#define CPU8_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU8 + 0x0043 )    /* 0x9043 */
#define CPU8_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU8 + 0x0024 )    /* 0x9024 */
#define CPU8_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU8 + 0x0026 )    /* 0x9026 */
#define CPU8_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU8 + 0x003d )    /* 0x903d */
#define CPU8_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU8 + 0x0041 )    /* 0x9041 */
#define CPU9_CI_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU9 + 0x003f )    /* 0x923f */
#define CPU9_CI_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU9 + 0x0040 )    /* 0x9240 */
#define CPU9_TO_SEND_HK_MID                         ( CFS_CMD_MID_BASE_CPU9 + 0x0042 )    /* 0x9242 */
#define CPU9_TO_WAKEUP_MID                          ( CFS_CMD_MID_BASE_CPU9 + 0x0043 )    /* 0x9243 */
#define CPU9_XRAY_SEND_HK_MID                       ( CFS_CMD_MID_BASE_CPU9 + 0x008e )    /* 0x928e */
#define CPU9_XRAY_NAV_CMD_MID                       ( CFS_CMD_MID_BASE_CPU9 + 0x008f )    /* 0x928f */
#define CPU9_XRAY_WAKEUP_MID                        ( CFS_CMD_MID_BASE_CPU9 + 0x0090 )    /* 0x9290 */
#define CPU9_SBN_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU9 + 0x0024 )    /* 0x9224 */
#define CPU9_SBN_CMD_MID                            ( CFS_CMD_MID_BASE_CPU9 + 0x0026 )    /* 0x9226 */
#define CPU9_CI_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU9 + 0x003d )    /* 0x923d */
#define CPU9_TO_APP_CMD_MID                         ( CFS_CMD_MID_BASE_CPU9 + 0x0041 )    /* 0x9241 */
#define CPU12_CI_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU12 + 0x003f )    /* 0x983f */
#define CPU12_CI_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU12 + 0x0040 )    /* 0x9840 */
#define CPU12_TO_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU12 + 0x0042 )    /* 0x9842 */
#define CPU12_TO_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU12 + 0x0043 )    /* 0x9843 */
#define CPU12_SBN_WAKEUP_MID                        ( CFS_CMD_MID_BASE_CPU12 + 0x0024 )    /* 0x9824 */
#define CPU12_SBN_CMD_MID                           ( CFS_CMD_MID_BASE_CPU12 + 0x0026 )    /* 0x9826 */
#define CPU12_CI_APP_CMD_MID                        ( CFS_CMD_MID_BASE_CPU12 + 0x003d )    /* 0x983d */
#define CPU12_TO_APP_CMD_MID                        ( CFS_CMD_MID_BASE_CPU12 + 0x0041 )    /* 0x9841 */
#define CPU16_CI_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU16 + 0x003f )    /* 0xa03f */
#define CPU16_CI_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU16 + 0x0040 )    /* 0xa040 */
#define CPU16_TO_SEND_HK_MID                        ( CFS_CMD_MID_BASE_CPU16 + 0x0042 )    /* 0xa042 */
#define CPU16_TO_WAKEUP_MID                         ( CFS_CMD_MID_BASE_CPU16 + 0x0043 )    /* 0xa043 */
#define CPU16_SBN_WAKEUP_MID                        ( CFS_CMD_MID_BASE_CPU16 + 0x0024 )    /* 0xa024 */
#define CPU16_SBN_CMD_MID                           ( CFS_CMD_MID_BASE_CPU16 + 0x0026 )    /* 0xa026 */
#define CPU16_CI_APP_CMD_MID                        ( CFS_CMD_MID_BASE_CPU16 + 0x003d )    /* 0xa03d */
#define CPU16_TO_APP_CMD_MID                        ( CFS_CMD_MID_BASE_CPU16 + 0x0041 )    /* 0xa041 */

/* All versions of repeated CFS TLM message IDs */
#define CPU1_LC_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU1 + 0x0019 )    /* 0x0219 */
#define CPU1_SCH_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU1 + 0x0022 )    /* 0x0222 */
#define CPU1_SCH_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU1 + 0x0023 )    /* 0x0223 */
#define CPU1_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU1 + 0x002c )    /* 0x022c */
#define CPU1_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU1 + 0x002d )    /* 0x022d */
#define CPU1_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU1 + 0x002e )    /* 0x022e */
#define CPU1_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU1 + 0x002f )    /* 0x022f */
#define CPU1_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU1 + 0x0030 )    /* 0x0230 */
#define CPU1_DS_DIAG_TLM_MID                        ( CFS_TLM_MID_BASE_CPU1 + 0x0031 )    /* 0x0231 */
#define CPU1_DS_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU1 + 0x0032 )    /* 0x0232 */
#define CPU1_SIMPLE_COUNTER_HK_TLM_MID              ( CFS_TLM_MID_BASE_CPU1 + 0x005f )    /* 0x025f */
#define CPU1_SIMPLE_COUNTER_OUT_DATA_MID            ( CFS_TLM_MID_BASE_CPU1 + 0x0060 )    /* 0x0260 */
#define CPU1_ACAWS_DE_HK_TLM_MID                    ( CFS_TLM_MID_BASE_CPU1 + 0x0066 )    /* 0x0266 */
#define CPU1_PPA_HYDE_OutData_MID                   ( CFS_TLM_MID_BASE_CPU1 + 0x005b )    /* 0x025b */
#define CPU1_TTE_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU1 + 0x0061 )    /* 0x0261 */
#define CPU1_TTE_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU1 + 0x0062 )    /* 0x0262 */
#define CPU1_PPA_HYDE_HkTlm_MID                     ( CFS_TLM_MID_BASE_CPU1 + 0x006f )    /* 0x026f */
#define CPU1_ACAWS_FIR_HK_TLM_MID                   ( CFS_TLM_MID_BASE_CPU1 + 0x007a )    /* 0x027a */
#define CPU1_ACAWS_DE_DIAGDATA_MID                  ( CFS_TLM_MID_BASE_CPU1 + 0x0080 )    /* 0x0280 */
#define CPU1_ACAWS_DE_IMPACTREQ_MID                 ( CFS_TLM_MID_BASE_CPU1 + 0x0081 )    /* 0x0281 */
#define CPU1_ACAWS_FD_TEST_RESULTS_MID              ( CFS_TLM_MID_BASE_CPU1 + 0x0082 )    /* 0x0282 */
#define CPU1_ACAWS_FIR_OUT_DATA_MID                 ( CFS_TLM_MID_BASE_CPU1 + 0x0083 )    /* 0x0283 */
#define CPU2_LC_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU2 + 0x0019 )    /* 0x0419 */
#define CPU2_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU2 + 0x002c )    /* 0x042c */
#define CPU2_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU2 + 0x002d )    /* 0x042d */
#define CPU2_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU2 + 0x002e )    /* 0x042e */
#define CPU2_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU2 + 0x002f )    /* 0x042f */
#define CPU2_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU2 + 0x0030 )    /* 0x0430 */
#define CPU2_SIMPLE_COUNTER_HK_TLM_MID              ( CFS_TLM_MID_BASE_CPU2 + 0x005f )    /* 0x045f */
#define CPU2_SIMPLE_COUNTER_OUT_DATA_MID            ( CFS_TLM_MID_BASE_CPU2 + 0x0060 )    /* 0x0460 */
#define CPU2_ACAWS_DE_HK_TLM_MID                    ( CFS_TLM_MID_BASE_CPU2 + 0x0066 )    /* 0x0466 */
#define CPU2_PPA_HYDE_OutData_MID                   ( CFS_TLM_MID_BASE_CPU2 + 0x005b )    /* 0x045b */
#define CPU2_TTE_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU2 + 0x0061 )    /* 0x0461 */
#define CPU2_TTE_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU2 + 0x0062 )    /* 0x0462 */
#define CPU2_PPA_HYDE_HkTlm_MID                     ( CFS_TLM_MID_BASE_CPU2 + 0x006f )    /* 0x046f */
#define CPU2_ACAWS_FIR_HK_TLM_MID                   ( CFS_TLM_MID_BASE_CPU2 + 0x007a )    /* 0x047a */
#define CPU2_ACAWS_DE_DIAGDATA_MID                  ( CFS_TLM_MID_BASE_CPU2 + 0x0080 )    /* 0x0480 */
#define CPU2_ACAWS_DE_IMPACTREQ_MID                 ( CFS_TLM_MID_BASE_CPU2 + 0x0081 )    /* 0x0481 */
#define CPU2_ACAWS_FD_TEST_RESULTS_MID              ( CFS_TLM_MID_BASE_CPU2 + 0x0082 )    /* 0x0482 */
#define CPU2_ACAWS_FIR_OUT_DATA_MID                 ( CFS_TLM_MID_BASE_CPU2 + 0x0083 )    /* 0x0483 */
#define CPU3_LC_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU3 + 0x0019 )    /* 0x0619 */
#define CPU3_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU3 + 0x002c )    /* 0x062c */
#define CPU3_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU3 + 0x002d )    /* 0x062d */
#define CPU3_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU3 + 0x002e )    /* 0x062e */
#define CPU3_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU3 + 0x002f )    /* 0x062f */
#define CPU3_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU3 + 0x0030 )    /* 0x0630 */
#define CPU3_SIMPLE_COUNTER_HK_TLM_MID              ( CFS_TLM_MID_BASE_CPU3 + 0x005f )    /* 0x065f */
#define CPU3_SIMPLE_COUNTER_OUT_DATA_MID            ( CFS_TLM_MID_BASE_CPU3 + 0x0060 )    /* 0x0660 */
#define CPU3_ACAWS_DE_HK_TLM_MID                    ( CFS_TLM_MID_BASE_CPU3 + 0x0066 )    /* 0x0666 */
#define CPU3_PPA_HYDE_OutData_MID                   ( CFS_TLM_MID_BASE_CPU3 + 0x005b )    /* 0x065b */
#define CPU3_TTE_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU3 + 0x0061 )    /* 0x0661 */
#define CPU3_TTE_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU3 + 0x0062 )    /* 0x0662 */
#define CPU3_PPA_HYDE_HkTlm_MID                     ( CFS_TLM_MID_BASE_CPU3 + 0x006f )    /* 0x066f */
#define CPU3_ACAWS_FIR_HK_TLM_MID                   ( CFS_TLM_MID_BASE_CPU3 + 0x007a )    /* 0x067a */
#define CPU3_ACAWS_DE_DIAGDATA_MID                  ( CFS_TLM_MID_BASE_CPU3 + 0x0080 )    /* 0x0680 */
#define CPU3_ACAWS_DE_IMPACTREQ_MID                 ( CFS_TLM_MID_BASE_CPU3 + 0x0081 )    /* 0x0681 */
#define CPU3_ACAWS_FD_TEST_RESULTS_MID              ( CFS_TLM_MID_BASE_CPU3 + 0x0082 )    /* 0x0682 */
#define CPU3_ACAWS_FIR_OUT_DATA_MID                 ( CFS_TLM_MID_BASE_CPU3 + 0x0083 )    /* 0x0683 */
#define CPU4_LC_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU4 + 0x0019 )    /* 0x0819 */
#define CPU4_SCH_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU4 + 0x0022 )    /* 0x0822 */
#define CPU4_SCH_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU4 + 0x0023 )    /* 0x0823 */
#define CPU4_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU4 + 0x002c )    /* 0x082c */
#define CPU4_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU4 + 0x002d )    /* 0x082d */
#define CPU4_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU4 + 0x002e )    /* 0x082e */
#define CPU4_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU4 + 0x002f )    /* 0x082f */
#define CPU4_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU4 + 0x0030 )    /* 0x0830 */
#define CPU4_DS_DIAG_TLM_MID                        ( CFS_TLM_MID_BASE_CPU4 + 0x0031 )    /* 0x0831 */
#define CPU4_DS_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU4 + 0x0032 )    /* 0x0832 */
#define CPU4_ACAWS_DE_HK_TLM_MID                    ( CFS_TLM_MID_BASE_CPU4 + 0x0066 )    /* 0x0866 */
#define CPU4_PPA_HYDE_OutData_MID                   ( CFS_TLM_MID_BASE_CPU4 + 0x005b )    /* 0x085b */
#define CPU4_TTE_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU4 + 0x0061 )    /* 0x0861 */
#define CPU4_TTE_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU4 + 0x0062 )    /* 0x0862 */
#define CPU4_PPA_HYDE_HkTlm_MID                     ( CFS_TLM_MID_BASE_CPU4 + 0x006f )    /* 0x086f */
#define CPU4_ACAWS_FIR_HK_TLM_MID                   ( CFS_TLM_MID_BASE_CPU4 + 0x007a )    /* 0x087a */
#define CPU4_ACAWS_DE_DIAGDATA_MID                  ( CFS_TLM_MID_BASE_CPU4 + 0x0080 )    /* 0x0880 */
#define CPU4_ACAWS_DE_IMPACTREQ_MID                 ( CFS_TLM_MID_BASE_CPU4 + 0x0081 )    /* 0x0881 */
#define CPU4_ACAWS_FD_TEST_RESULTS_MID              ( CFS_TLM_MID_BASE_CPU4 + 0x0082 )    /* 0x0882 */
#define CPU4_ACAWS_FIR_OUT_DATA_MID                 ( CFS_TLM_MID_BASE_CPU4 + 0x0083 )    /* 0x0883 */
#define CPU5_SCH_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU5 + 0x0022 )    /* 0x0a22 */
#define CPU5_SCH_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU5 + 0x0023 )    /* 0x0a23 */
#define CPU5_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU5 + 0x002c )    /* 0x0a2c */
#define CPU5_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU5 + 0x002d )    /* 0x0a2d */
#define CPU5_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU5 + 0x002e )    /* 0x0a2e */
#define CPU5_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU5 + 0x002f )    /* 0x0a2f */
#define CPU5_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU5 + 0x0030 )    /* 0x0a30 */
#define CPU5_TTE_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU5 + 0x0061 )    /* 0x0a61 */
#define CPU5_TTE_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU5 + 0x0062 )    /* 0x0a62 */
#define CPU6_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU6 + 0x002c )    /* 0x0c2c */
#define CPU6_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU6 + 0x002d )    /* 0x0c2d */
#define CPU6_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU6 + 0x002e )    /* 0x0c2e */
#define CPU6_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU6 + 0x002f )    /* 0x0c2f */
#define CPU6_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU6 + 0x0030 )    /* 0x0c30 */
#define CPU6_L1V_MID                                ( CFS_TLM_MID_BASE_CPU6 + 0x0052 )    /* 0x0c52 */
#define CPU6_TTE_DIAG_TLM_MID                       ( CFS_TLM_MID_BASE_CPU6 + 0x0061 )    /* 0x0c61 */
#define CPU6_TTE_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU6 + 0x0062 )    /* 0x0c62 */
#define CPU7_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU7 + 0x002c )    /* 0x0e2c */
#define CPU7_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU7 + 0x002d )    /* 0x0e2d */
#define CPU7_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU7 + 0x002e )    /* 0x0e2e */
#define CPU7_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU7 + 0x002f )    /* 0x0e2f */
#define CPU7_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU7 + 0x0030 )    /* 0x0e30 */
#define CPU8_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU8 + 0x002c )    /* 0x102c */
#define CPU8_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU8 + 0x002d )    /* 0x102d */
#define CPU8_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU8 + 0x002e )    /* 0x102e */
#define CPU8_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU8 + 0x002f )    /* 0x102f */
#define CPU8_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU8 + 0x0030 )    /* 0x1030 */
#define CPU9_CI_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU9 + 0x002c )    /* 0x122c */
#define CPU9_CI_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU9 + 0x002d )    /* 0x122d */
#define CPU9_TO_DATA_TYPE_MID                       ( CFS_TLM_MID_BASE_CPU9 + 0x002e )    /* 0x122e */
#define CPU9_TO_OUT_DATA_MID                        ( CFS_TLM_MID_BASE_CPU9 + 0x002f )    /* 0x122f */
#define CPU9_TO_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU9 + 0x0030 )    /* 0x1230 */
#define CPU9_CF_SPACE_TO_GND_PDU_MID                ( CFS_TLM_MID_BASE_CPU9 + 0x0033 )    /* 0x1233 */
#define CPU9_CF_TRANS_TLM_MID                       ( CFS_TLM_MID_BASE_CPU9 + 0x0034 )    /* 0x1234 */
#define CPU9_CF_HK_TLM_MID                          ( CFS_TLM_MID_BASE_CPU9 + 0x0035 )    /* 0x1235 */
#define CPU9_XRAY_HK_TLM_MID                        ( CFS_TLM_MID_BASE_CPU9 + 0x00a1 )    /* 0x12a1 */
#define CPU9_XRAY_OUTDATA_MID                       ( CFS_TLM_MID_BASE_CPU9 + 0x00a2 )    /* 0x12a2 */
#define CPU12_CI_OUT_DATA_MID                       ( CFS_TLM_MID_BASE_CPU12 + 0x002c )    /* 0x182c */
#define CPU12_CI_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU12 + 0x002d )    /* 0x182d */
#define CPU12_TO_DATA_TYPE_MID                      ( CFS_TLM_MID_BASE_CPU12 + 0x002e )    /* 0x182e */
#define CPU12_TO_OUT_DATA_MID                       ( CFS_TLM_MID_BASE_CPU12 + 0x002f )    /* 0x182f */
#define CPU12_TO_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU12 + 0x0030 )    /* 0x1830 */
#define CPU16_CI_OUT_DATA_MID                       ( CFS_TLM_MID_BASE_CPU16 + 0x002c )    /* 0x202c */
#define CPU16_CI_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU16 + 0x002d )    /* 0x202d */
#define CPU16_TO_DATA_TYPE_MID                      ( CFS_TLM_MID_BASE_CPU16 + 0x002e )    /* 0x202e */
#define CPU16_TO_OUT_DATA_MID                       ( CFS_TLM_MID_BASE_CPU16 + 0x002f )    /* 0x202f */
#define CPU16_TO_HK_TLM_MID                         ( CFS_TLM_MID_BASE_CPU16 + 0x0030 )    /* 0x2030 */



#endif    /*  _CFS_MSGIDS_H_ */
