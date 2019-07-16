/* Created : Mon Aug 13 15:56:05 CDT 2018
   User    : rhirsh
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): HAB_TCS_ETCS_TLM, CCSDS_TLM_HDR, CCSDS_Primary, HAB_TCS_ETCS_LOOP_TLM, HAB_TCS_ITCS_TLM */

#ifndef _TCS_TYPES_H_
#define _TCS_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure HAB_TCS_ETCS_LOOP_TLM (132 bytes in size)  *
* trick sim generated ETCS loop tlm child of TCS ETCS
*/
typedef struct
{
  float ACCUM_QTY;                            ///< [    0] (4 bytes)  Accumulator fraction of full (0-1)
  float ACCUM_P;                              ///< [    4] (4 bytes)  Accumulator pressure
  float PUMPS_INLET_T;                        ///< [    8] (4 bytes)  Pumps inlet temperature
  float PUMPS_INLET_P;                        ///< [   12] (4 bytes)  Pumps inlet pressure
  float PUMP_1_N;                             ///< [   16] (4 bytes)  Pump 1 speed
  float PUMP_1_DP;                            ///< [   20] (4 bytes)  Pump 1 delta-pressure
  float PUMP_1_FLOW;                          ///< [   24] (4 bytes)  Pump 1 flow rate
  float PUMP_2_N;                             ///< [   28] (4 bytes)  Pump 2 speed
  float PUMP_2_DP;                            ///< [   32] (4 bytes)  Pump 2 delta-pressure
  float PUMP_2_FLOW;                          ///< [   36] (4 bytes)  Pump 2 flow rate
  float IFHX_INLET_T;                         ///< [   40] (4 bytes)  Interloop heat exchanger inlet temperature
  float IFHX_EXIT_T;                          ///< [   44] (4 bytes)  Interloop heat exchanger exit temperature
  float CP_1_T;                               ///< [   48] (4 bytes)  Coldplate 1 temperature
  float CP_2_T;                               ///< [   52] (4 bytes)  Coldplate 2 temperature
  float CP_3_T;                               ///< [   56] (4 bytes)  Coldplate 3 temperature
  float CP_4_T;                               ///< [   60] (4 bytes)  Coldplate 4 temperature
  float REGEN_HX_COLD_T;                      ///< [   64] (4 bytes)  Regenerative heat exchanger cold-side exit temperature
  float REGEN_HX_HOT_T;                       ///< [   68] (4 bytes)  Regenerative heat exchanger hot-side exit temperature
  float RAD_1_EXIT_T;                         ///< [   72] (4 bytes)  Radiator 1 exit temperature
  float RAD_2_EXIT_T;                         ///< [   76] (4 bytes)  Radiator 2 exit temperature
  float ISO_A_POS;                            ///< [   80] (4 bytes)  Isolation valve A position (1 = open)
  float ISO_A_FLOW;                           ///< [   84] (4 bytes)  Isolation valve A flow rate
  float ISO_B_POS;                            ///< [   88] (4 bytes)  Isolation valve B position (1 = open)
  float ISO_B_FLOW;                           ///< [   92] (4 bytes)  Isolation valve B flow rate
  float TCV_A_REGEN_FLOW;                     ///< [   96] (4 bytes)  Temperature control valve A regen HX flow rate
  float TCV_A_BYPASS_FLOW;                    ///< [  100] (4 bytes)  Temperature control valve A bypass flow rate
  float TCV_B_REGEN_FLOW;                     ///< [  104] (4 bytes)  Temperature control valve B regen HX flow rate
  float TCV_B_BYPASS_FLOW;                    ///< [  108] (4 bytes)  Temperature control valve B bypass flow rate
  float RAD_MIX_POS;                          ///< [  112] (4 bytes)  Radiator mixing valve position (1 = radiator 1, 0 = radiator 2)
  uint8_t PUMP_1_ENA_CMD_FEEDBACK;            ///< [  116] (1 bytes)  Pump 1 enable command feedback
  uint8_t PUMP_2_ENA_CMD_FEEDBACK;            ///< [  117] (1 bytes)  Pump 2 enable command feedback
  uint8_t etcs_pad[2];                        ///< [  118] (2x1=2 bytes)  
  float ISO_A_POS_CMD_FEEDBACK;               ///< [  120] (4 bytes)  Iso valve A position command feedback (0-1)
  float ISO_B_POS_CMD_FEEDBACK;               ///< [  124] (4 bytes)  Iso valve B position command feedback (0-1)
  float RAD_MIX_POS_CMD_FEEDBACK;             ///< [  128] (4 bytes)  Radiator mixing valve position command feedback (0-1)
} HAB_TCS_ETCS_LOOP_TLM;     ///<  Total size of 132 bytes

/** Structure HAB_TCS_ETCS_TLM (280 bytes in size)  *
* Trick sim generated TCS ETCS telemetry
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  HAB_TCS_ETCS_LOOP_TLM A;                    ///< [   16] (132 bytes)  Loop A
  HAB_TCS_ETCS_LOOP_TLM B;                    ///< [  148] (132 bytes)  Loop B
} HAB_TCS_ETCS_TLM;     ///<  Total size of 280 bytes

/** Structure HAB_TCS_ITCS_TLM (112 bytes in size)  *
* Trick sim generated TCS ITCS telemetry
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  float PUMPS_INLET_T;                        ///< [   16] (4 bytes)  Pumps inlet temperature
  float PUMPS_INLET_P;                        ///< [   20] (4 bytes)  Pumps inlet pressure
  float CP_1_T;                               ///< [   24] (4 bytes)  Coldplate 1 temperature
  float CP_2_T;                               ///< [   28] (4 bytes)  Coldplate 2 temperature
  float CHX_INLET_T;                          ///< [   32] (4 bytes)  Cabin heat exchanger inlet temperature
  float CHX_EXIT_T;                           ///< [   36] (4 bytes)  Cabin heat exchanget exit temperature
  float AVHX_INLET_T;                         ///< [   40] (4 bytes)  Avionics heat exchanger inlet temperature
  float AVHX_EXIT_T;                          ///< [   44] (4 bytes)  Avionics heat exchanget exit temperature
  float IFHX_INLET_T;                         ///< [   48] (4 bytes)  Interloop heat exchanger inlet temperature
  float IFHX_EXIT_T;                          ///< [   52] (4 bytes)  Interloop heat exchanger exit temperature
  float LINE_HTR_T;                           ///< [   56] (4 bytes)  Line heater temperature
  float LINE_HTR_PWR;                         ///< [   60] (4 bytes)  Line heater power
  float PUMP_1_N;                             ///< [   64] (4 bytes)  Pump 1 speed
  float PUMP_1_DP;                            ///< [   68] (4 bytes)  Pump 1 delta-pressure
  float PUMP_1_FLOW;                          ///< [   72] (4 bytes)  Pump 1 flow rate
  float PUMP_2_N;                             ///< [   76] (4 bytes)  Pump 2 speed
  float PUMP_2_DP;                            ///< [   80] (4 bytes)  Pump 2 delta-pressure
  float PUMP_2_FLOW;                          ///< [   84] (4 bytes)  Pump 2 flow rate
  float ACCUM_1_QTY;                          ///< [   88] (4 bytes)  Accumulator 1 fraction of full (0-1)
  float ACCUM_1_P;                            ///< [   92] (4 bytes)  Accumulator 1 pressure
  float ACCUM_2_QTY;                          ///< [   96] (4 bytes)  Accumulator 2 fraction of full (0-1)
  float ACCUM_2_P;                            ///< [  100] (4 bytes)  Accumulator 2 pressure
  float IFHX_SETPOINT_CMD_FEEDBACK;           ///< [  104] (4 bytes)  Interloop heat exchanger outlet temperature setpoint command feedback
  uint8_t PUMP_1_CMD_FEEDBACK;                ///< [  108] (1 bytes)  Pump 1 enable command feedback
  uint8_t PUMP_2_CMD_FEEDBACK;                ///< [  109] (1 bytes)  Pump 2 enable command feedback
  uint8_t itcs_pad[2];                        ///< [  110] (2x1=2 bytes)  
} HAB_TCS_ITCS_TLM;     ///<  Total size of 112 bytes

void byteswap_HAB_TCS_ITCS_TLM(HAB_TCS_ITCS_TLM *inPtr, HAB_TCS_ITCS_TLM *outPtr, int direction);
void bitswap_HAB_TCS_ITCS_TLM(HAB_TCS_ITCS_TLM *inPtr, HAB_TCS_ITCS_TLM *outPtr, int direction);
void byteswap_HAB_TCS_ETCS_TLM(HAB_TCS_ETCS_TLM *inPtr, HAB_TCS_ETCS_TLM *outPtr, int direction);
void bitswap_HAB_TCS_ETCS_TLM(HAB_TCS_ETCS_TLM *inPtr, HAB_TCS_ETCS_TLM *outPtr, int direction);
void byteswap_HAB_TCS_ETCS_LOOP_TLM(HAB_TCS_ETCS_LOOP_TLM *inPtr, HAB_TCS_ETCS_LOOP_TLM *outPtr, int direction);
void bitswap_HAB_TCS_ETCS_LOOP_TLM(HAB_TCS_ETCS_LOOP_TLM *inPtr, HAB_TCS_ETCS_LOOP_TLM *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define A_ISO_A     0x0
#define A_ISO_B     0x1
#define A_PUMP_1    0x2
#define A_PUMP_2    0x3
#define A_RAD_MIX   0x4
#define B_ISO_A     0x0
#define B_ISO_B     0x1
#define B_PUMP_1    0x2
#define B_PUMP_2    0x3
#define B_RAD_MIX   0x4
#define IFHX_SET    0x0
#define PUMP_1      0x1
#define PUMP_2      0x2

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  A_ISO_A : Iso valve A position command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 float PARAM_1_POS;      ///<  Iso valve A position command (1 = open, 0 = close)
}A_ISO_A_t;

/**  A_ISO_B : Iso valve B position command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 float PARAM_1_POS;      ///<  Iso valve B position command (1 = open, 0 = close)
}A_ISO_B_t;

/**  A_PUMP_1 : Pump 1 enable command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t PARAM_1_ENA;      ///<  Pump 1 enable command (1 = enable, 0 = disable)
}A_PUMP_1_t;

/**  A_PUMP_2 : Pump 2 enable command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t PARAM_1_ENA;      ///<  Pump 2 enable command (1 = enable, 0 = disable)
}A_PUMP_2_t;

/**  A_RAD_MIX : Radiator mixing valve position command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 float PARAM_1_POS;      ///<  Radiator mixing valve position command (1 = radiator 1, 0 = radiator 2, 0.5 = even mix)
}A_RAD_MIX_t;

/**  B_ISO_A : Iso valve A position command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 float PARAM_1_POS;      ///<  Iso valve A position command (1 = open, 0 = close)
}B_ISO_A_t;

/**  B_ISO_B : Iso valve B position command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 float PARAM_1_POS;      ///<  Iso valve B position command (1 = open, 0 = close)
}B_ISO_B_t;

/**  B_PUMP_1 : Pump 1 enable command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t PARAM_1_ENA;      ///<  Pump 1 enable command (1 = enable, 0 = disable)
}B_PUMP_1_t;

/**  B_PUMP_2 : Pump 2 enable command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t PARAM_1_ENA;      ///<  Pump 2 enable command (1 = enable, 0 = disable)
}B_PUMP_2_t;

/**  B_RAD_MIX : Radiator mixing valve position command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 float PARAM_1_POS;      ///<  Radiator mixing valve position command (1 = radiator 1, 0 = radiator 2, 0.5 = even mix)
}B_RAD_MIX_t;

/**  IFHX_SET : Interloop heat exchanger outlet temperature setpoint command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 float PARAM_1_SETPOINT;      ///<  Temperature setpoint
}IFHX_SET_t;

/**  PUMP_1 : Pump 1 enable command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t PARAM_1_ENA;      ///<  Pump enable command (1 = enable, 0 = disable)
}PUMP_1_t;

/**  PUMP_2 : Pump 2 enable command**/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t PARAM_1_ENA;      ///<  Pump enable command (1 = enable, 0 = disable)
}PUMP_2_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _TCS_TYPES_H_
