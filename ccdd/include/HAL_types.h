/* Created : Tue Nov 13 10:47:51 CST 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): HAL_MBSU1, CCSDS_TLM_HDR, CCSDS_Primary, MBSU_telemetry, HAL_MBSU2, HAL_PDU1, PDU_telemetry, HAL_PDU2, HAL_PDU3, HAL_PDU4, HAL_Power_Source1, sim_power_source, HAL_Power_Source2 */

#ifndef _HAL_TYPES_H_
#define _HAL_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure HAL_MBSU1 (184 bytes in size)  *
* MBSU and PDU definitions for Trick simulated PPE and HAL; based on AMPS (HAB) MBSU and PDU
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  MBSU_telemetry hal_mbsu1;                   ///< [   16] (168 bytes)  
} HAL_MBSU1;     ///<  Total size of 184 bytes

/** Structure HAL_MBSU2 (184 bytes in size)  *
* MBSU and PDU definitions for Trick simulated PPE and HAL; based on AMPS (HAB) MBSU and PDU
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  MBSU_telemetry hal_mbsu2;                   ///< [   16] (168 bytes)  
} HAL_MBSU2;     ///<  Total size of 184 bytes

/** Structure HAL_PDU1 (152 bytes in size)  *
* MBSU and PDU definitions for Trick simulated PPE and HAL; based on AMPS (HAB) MBSU and PDU
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  PDU_telemetry hal_pdu1;                     ///< [   16] (136 bytes)  
} HAL_PDU1;     ///<  Total size of 152 bytes

/** Structure HAL_PDU2 (152 bytes in size)  *
* MBSU and PDU definitions for Trick simulated PPE and HAL; based on AMPS (HAB) MBSU and PDU
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  PDU_telemetry hal_pdu2;                     ///< [   16] (136 bytes)  
} HAL_PDU2;     ///<  Total size of 152 bytes

/** Structure HAL_PDU3 (152 bytes in size)  *
* MBSU and PDU definitions for Trick simulated PPE and HAL; based on AMPS (HAB) MBSU and PDU
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  PDU_telemetry hal_pdu3;                     ///< [   16] (136 bytes)  
} HAL_PDU3;     ///<  Total size of 152 bytes

/** Structure HAL_PDU4 (152 bytes in size)  *
* MBSU and PDU definitions for Trick simulated PPE and HAL; based on AMPS (HAB) MBSU and PDU
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  PDU_telemetry hal_pdu4;                     ///< [   16] (136 bytes)  
} HAL_PDU4;     ///<  Total size of 152 bytes

/** Structure HAL_Power_Source1 (77 bytes in size)  *
* "power source" system generated by the Trick simulation, they only exist virtually (combination of solar array and battery); there are two per element
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  sim_power_source hal_power_source1;         ///< [   16] (61 bytes)  
} HAL_Power_Source1;     ///<  Total size of 77 bytes

/** Structure HAL_Power_Source2 (77 bytes in size)  *
* "power source" system generated by the Trick simulation, they only exist virtually (combination of solar array and battery); there are two per element
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  sim_power_source hal_power_source2;         ///< [   16] (61 bytes)  
} HAL_Power_Source2;     ///<  Total size of 77 bytes

void byteswap_HAL_Power_Source2(HAL_Power_Source2 *inPtr, HAL_Power_Source2 *outPtr, int direction);
void bitswap_HAL_Power_Source2(HAL_Power_Source2 *inPtr, HAL_Power_Source2 *outPtr, int direction);
void byteswap_HAL_Power_Source1(HAL_Power_Source1 *inPtr, HAL_Power_Source1 *outPtr, int direction);
void bitswap_HAL_Power_Source1(HAL_Power_Source1 *inPtr, HAL_Power_Source1 *outPtr, int direction);
void byteswap_HAL_PDU4(HAL_PDU4 *inPtr, HAL_PDU4 *outPtr, int direction);
void bitswap_HAL_PDU4(HAL_PDU4 *inPtr, HAL_PDU4 *outPtr, int direction);
void byteswap_HAL_PDU3(HAL_PDU3 *inPtr, HAL_PDU3 *outPtr, int direction);
void bitswap_HAL_PDU3(HAL_PDU3 *inPtr, HAL_PDU3 *outPtr, int direction);
void byteswap_HAL_PDU2(HAL_PDU2 *inPtr, HAL_PDU2 *outPtr, int direction);
void bitswap_HAL_PDU2(HAL_PDU2 *inPtr, HAL_PDU2 *outPtr, int direction);
void byteswap_HAL_PDU1(HAL_PDU1 *inPtr, HAL_PDU1 *outPtr, int direction);
void bitswap_HAL_PDU1(HAL_PDU1 *inPtr, HAL_PDU1 *outPtr, int direction);
void byteswap_HAL_MBSU2(HAL_MBSU2 *inPtr, HAL_MBSU2 *outPtr, int direction);
void bitswap_HAL_MBSU2(HAL_MBSU2 *inPtr, HAL_MBSU2 *outPtr, int direction);
void byteswap_HAL_MBSU1(HAL_MBSU1 *inPtr, HAL_MBSU1 *outPtr, int direction);
void bitswap_HAL_MBSU1(HAL_MBSU1 *inPtr, HAL_MBSU1 *outPtr, int direction);
void byteswap_MBSU_telemetry(MBSU_telemetry *inPtr, MBSU_telemetry *outPtr, int direction);
void bitswap_MBSU_telemetry(MBSU_telemetry *inPtr, MBSU_telemetry *outPtr, int direction);
void byteswap_PDU_telemetry(PDU_telemetry *inPtr, PDU_telemetry *outPtr, int direction);
void bitswap_PDU_telemetry(PDU_telemetry *inPtr, PDU_telemetry *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void byteswap_sim_power_source(sim_power_source *inPtr, sim_power_source *outPtr, int direction);
void bitswap_sim_power_source(sim_power_source *inPtr, sim_power_source *outPtr, int direction);


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define SET_HAL_PS2_OUTPUT_CHANNEL_STATE    0x0
#define SET_HAL_PS2_SAR_STATE               0x1
#define SET_HAL_MBSU1_INPUT_SOURCE_SELECT   0x0
#define SET_HAL_MBSU1_OUTPUT_CHANNEL_STATE  0x1
#define SET_HAL_MBSU1_Input_Curr_Limit      0x2
#define SET_HAL_MBSU1_Output_Curr_Limit     0x3
#define CLEAR_HAL_MBSU1_Input_Curr_Trip     0x4
#define CLEAR_HAL_MBSU1_Output_Curr_Trip    0x5
#define SET_HAL_MBSU1_Relay_CHANNEL_OPEN    0x6
#define HAL_MBSU1_FAIL_INPUT_SOURCE         0x7
#define SET_HAL_MBSU2_INPUT_SOURCE_SELECT   0x0
#define SET_HAL_MBSU2_OUTPUT_CHANNEL_STATE  0x1
#define SET_HAL_MBSU2_Input_Curr_Limit      0x2
#define SET_HAL_MBSU2_Output_Curr_Limit     0x3
#define CLEAR_HAL_MBSU2_Input_Curr_Trip     0x4
#define CLEAR_HAL_MBSU2_Output_Curr_Trip    0x5
#define SET_HAL_MBSU2_Relay_CHANNEL_OPEN    0x6
#define HAL_MBSU2_FAIL_INPUT_SOURCE         0x7
#define SET_HAL_PDU1_INPUT_BUS_SELECT       0x0
#define SET_HAL_PDU1_RPC_CHANNEL_STATE      0x1
#define SET_HAL_PDU1_RPC_CHANNEL_OPEN       0x2
#define SET_HAL_PDU2_INPUT_BUS_SELECT       0x0
#define SET_HAL_PDU2_RPC_CHANNEL_STATE      0x1
#define SET_HAL_PDU2_RPC_CHANNEL_OPEN       0x2
#define SET_HAL_PDU3_INPUT_BUS_SELECT       0x0
#define SET_HAL_PDU3_RPC_CHANNEL_STATE      0x1
#define SET_HAL_PDU3_RPC_CHANNEL_OPEN       0x2
#define SET_HAL_PDU4_INPUT_BUS_SELECT       0x0
#define SET_HAL_PDU4_RPC_CHANNEL_STATE      0x1
#define SET_HAL_PDU4_RPC_CHANNEL_OPEN       0x2
#define SET_HAL_PS1_OUTPUT_CHANNEL_STATE    0x0
#define SET_HAL_PS1_SAR_STATE               0x1

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  SET_HAL_PS2_OUTPUT_CHANNEL_STATE : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t outSTATE;      ///<  Commanded positions for selected channels (outCHANNEL)
 int8_t outCHANNEL;      ///<  Selected Channels for the command (outSTATE); bit 1 = SAR switch; bit 2 = BATT switch; bit 3 = Cross connect switch
}SET_HAL_PS2_OUTPUT_CHANNEL_STATE_t;

/**  SET_HAL_PS2_SAR_STATE : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t sarSTATE;      ///<  Command for SAR (true = ON; false = OFF)
}SET_HAL_PS2_SAR_STATE_t;

/**  SET_HAL_MBSU1_INPUT_SOURCE_SELECT : select input bus to MBSU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t CH_POS;
 uint8_t INPUT_BUS;
}SET_HAL_MBSU1_INPUT_SOURCE_SELECT_t;

/**  SET_HAL_MBSU1_OUTPUT_CHANNEL_STATE : select output channel of MBSU, which PDU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t CH_POS;
 uint8_t OUTPUT_BUS;
}SET_HAL_MBSU1_OUTPUT_CHANNEL_STATE_t;

/**  SET_HAL_MBSU1_Input_Curr_Limit : artificial input current limit**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 double Input_Curr_Limit_SP;
 uint8_t INPUT_BUS;
}SET_HAL_MBSU1_Input_Curr_Limit_t;

/**  SET_HAL_MBSU1_Output_Curr_Limit : artificial output current limit**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 double Output_Curr_Limit_SP;
 uint8_t OUTPUT_BUS;
}SET_HAL_MBSU1_Output_Curr_Limit_t;

/**  CLEAR_HAL_MBSU1_Input_Curr_Trip : reset modified current limit to default**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t INPUT_BUS;
}CLEAR_HAL_MBSU1_Input_Curr_Trip_t;

/**  CLEAR_HAL_MBSU1_Output_Curr_Trip : reset modified current limit to default**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t OUTPUT_BUS;
}CLEAR_HAL_MBSU1_Output_Curr_Trip_t;

/**  SET_HAL_MBSU1_Relay_CHANNEL_OPEN : "silent command" to fail open output relay**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t FORCERelayOFF;
 uint8_t OUTPUT_BUS;
}SET_HAL_MBSU1_Relay_CHANNEL_OPEN_t;

/**  HAL_MBSU1_FAIL_INPUT_SOURCE : "silent command" to fail open selected input bus to MBSU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t FORCERelayOFF;
 uint8_t INPUT_BUS;
}HAL_MBSU1_FAIL_INPUT_SOURCE_t;

/**  SET_HAL_MBSU2_INPUT_SOURCE_SELECT : select input bus to MBSU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t CH_POS;
 uint8_t INPUT_BUS;
}SET_HAL_MBSU2_INPUT_SOURCE_SELECT_t;

/**  SET_HAL_MBSU2_OUTPUT_CHANNEL_STATE : select output channel of MBSU, which PDU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t CH_POS;
 uint8_t OUTPUT_BUS;
}SET_HAL_MBSU2_OUTPUT_CHANNEL_STATE_t;

/**  SET_HAL_MBSU2_Input_Curr_Limit : artificial input current limit**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 double Input_Curr_Limit_SP;
 uint8_t INPUT_BUS;
}SET_HAL_MBSU2_Input_Curr_Limit_t;

/**  SET_HAL_MBSU2_Output_Curr_Limit : artificial output current limit**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 double Output_Curr_Limit_SP;
 uint8_t OUTPUT_BUS;
}SET_HAL_MBSU2_Output_Curr_Limit_t;

/**  CLEAR_HAL_MBSU2_Input_Curr_Trip : reset modified current limit to default**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t INPUT_BUS;
}CLEAR_HAL_MBSU2_Input_Curr_Trip_t;

/**  CLEAR_HAL_MBSU2_Output_Curr_Trip : reset modified current limit to default**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t OUTPUT_BUS;
}CLEAR_HAL_MBSU2_Output_Curr_Trip_t;

/**  SET_HAL_MBSU2_Relay_CHANNEL_OPEN : "silent command" to fail open output relay**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t FORCERelayOFF;
 uint8_t OUTPUT_BUS;
}SET_HAL_MBSU2_Relay_CHANNEL_OPEN_t;

/**  HAL_MBSU2_FAIL_INPUT_SOURCE : "silent command" to fail open selected input bus to MBSU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t FORCERelayOFF;
 uint8_t INPUT_BUS;
}HAL_MBSU2_FAIL_INPUT_SOURCE_t;

/**  SET_HAL_PDU1_INPUT_BUS_SELECT : select input bus to PDU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t INPUT_BUS;
}SET_HAL_PDU1_INPUT_BUS_SELECT_t;

/**  SET_HAL_PDU1_RPC_CHANNEL_STATE : select RPC state, which loads**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t RPCONOFFSTATE;
 uint8_t rpcCHANNEL;
}SET_HAL_PDU1_RPC_CHANNEL_STATE_t;

/**  SET_HAL_PDU1_RPC_CHANNEL_OPEN : "silent command" to fail open RPC**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t FORCERPCOFF;
 uint8_t rpcCHANNEL;
}SET_HAL_PDU1_RPC_CHANNEL_OPEN_t;

/**  SET_HAL_PDU2_INPUT_BUS_SELECT : select input bus to PDU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t INPUT_BUS;
}SET_HAL_PDU2_INPUT_BUS_SELECT_t;

/**  SET_HAL_PDU2_RPC_CHANNEL_STATE : select RPC state, which loads**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t RPCONOFFSTATE;
 uint8_t rpcCHANNEL;
}SET_HAL_PDU2_RPC_CHANNEL_STATE_t;

/**  SET_HAL_PDU2_RPC_CHANNEL_OPEN : "silent command" to fail open RPC**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t FORCERPCOFF;
 uint8_t rpcCHANNEL;
}SET_HAL_PDU2_RPC_CHANNEL_OPEN_t;

/**  SET_HAL_PDU3_INPUT_BUS_SELECT : select input bus to PDU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t INPUT_BUS;
}SET_HAL_PDU3_INPUT_BUS_SELECT_t;

/**  SET_HAL_PDU3_RPC_CHANNEL_STATE : select RPC state, which loads**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t RPCONOFFSTATE;
 uint8_t rpcCHANNEL;
}SET_HAL_PDU3_RPC_CHANNEL_STATE_t;

/**  SET_HAL_PDU3_RPC_CHANNEL_OPEN : "silent command" to fail open RPC**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t FORCERPCOFF;
 uint8_t rpcCHANNEL;
}SET_HAL_PDU3_RPC_CHANNEL_OPEN_t;

/**  SET_HAL_PDU4_INPUT_BUS_SELECT : select input bus to PDU**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t INPUT_BUS;
}SET_HAL_PDU4_INPUT_BUS_SELECT_t;

/**  SET_HAL_PDU4_RPC_CHANNEL_STATE : select RPC state, which loads**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t RPCONOFFSTATE;
 uint8_t rpcCHANNEL;
}SET_HAL_PDU4_RPC_CHANNEL_STATE_t;

/**  SET_HAL_PDU4_RPC_CHANNEL_OPEN : "silent command" to fail open RPC**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t FORCERPCOFF;
 uint8_t rpcCHANNEL;
}SET_HAL_PDU4_RPC_CHANNEL_OPEN_t;

/**  SET_HAL_PS1_OUTPUT_CHANNEL_STATE : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t outSTATE;      ///<  Commanded positions for selected channels (outCHANNEL)
 int8_t outCHANNEL;      ///<  Selected Channels for the command (outSTATE); bit 1 = SAR switch; bit 2 = BATT switch; bit 3 = Cross connect switch
}SET_HAL_PS1_OUTPUT_CHANNEL_STATE_t;

/**  SET_HAL_PS1_SAR_STATE : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t sarSTATE;      ///<  Command for SAR (true = ON; false = OFF)
}SET_HAL_PS1_SAR_STATE_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _HAL_TYPES_H_
