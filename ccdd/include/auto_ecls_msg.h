/* Created : Mon Jul 22 09:47:38 CDT 2019
   User    : pchapate
   Project : fcc_cfs
   Script  : /users/pchapate/fcc_sbn/fcc_fsw/ccdd/scripts/CCSDS_V2_Msgs.js
   Group(s): ecls_msg
*/

#ifndef _auto_ecls_msg_h_
#define _auto_ecls_msg_h_

#include "cfe.h"

#include "ecls_mission_cfg.h"
#include "ecls_platform_cfg.h"
#include "ecls_msgdefs.h"

/*! Structure: UM_ECLSS_CAL_VPA_TLM (2 bytes total)
   Description: Trick simulation provided definitions for "UM" module ECLSS message and child structures */
typedef struct
{
   uint8 VENT_VLV_POS;   /*!< [    0] (1 bytes)  VPA vent valve position (1 = open) */
   uint8 PRESS_VLV_POS;  /*!< [    1] (1 bytes)  VPA pressurization valve position (1 = open) */
} UM_ECLSS_CAL_VPA_TLM;  /*< Total size of 2 bytes */

/*! Structure: UM_ECLSS_FAN_TLM (8 bytes total)
   Description: Trick simulation provided definitions for "UM" module ECLSS message and child structures */
typedef struct
{
   float TEMPERATURE;  /*!< [    0] (4 bytes)  Motor temperature */
   float SPEED;        /*!< [    4] (4 bytes)  Motor speed */
} UM_ECLSS_FAN_TLM;    /*< Total size of 8 bytes */

/*! Structure: UM_ECLSS_CAL_ENV_MON_TLM (28 bytes total)
   Description: Trick simulation provided definitions for "UM" module ECLSS message and child structures */
typedef struct
{
   float PPO2;               /*!< [   12] (4 bytes)  Partial pressure of O2 */
   float PPCO2;              /*!< [   16] (4 bytes)  Partial pressure of CO2 */
   float RH;                 /*!< [   20] (4 bytes)  Percent (0-100) relative humidity */
   uint8 SMOKE;              /*!< [   24] (1 bytes)  Smoke detection (1 = smoke) */
   char pad0__[3];           /*!< [   25] (3x1=3 bytes) */
} UM_ECLSS_CAL_ENV_MON_TLM;  /*< Total size of 28 bytes */

/*! Structure: UM_ECLSS_PCA_CNTLR_TLM (12 bytes total)
   Description: Trick simulation provided definitions for "UM" module ECLSS message and child structures */
typedef struct
{
   int32 STATE;            /*!< [    0] (4 bytes)  Active state enumeration: (-1 = DEPRESS; 0 = SETPOINT; 1 = REPRESS; 99 = HOLD; 100 = FEED THE LEAK; 101 = FEED THE LEAK HOLD) */
   float O2_SETPOINT;      /*!< [    4] (4 bytes)  Cabin O2 partial pressure percent (0-100) setpoint */
   float P_SETPOINT;       /*!< [    8] (4 bytes)  Cabin pressure setpoint */
} UM_ECLSS_PCA_CNTLR_TLM;  /*< Total size of 12 bytes */

/*! Structure: UM_ECLSS_PCA_TLM (56 bytes total)
   Description: Trick simulation provided definitions for "UM" module ECLSS message and child structures */
typedef struct
{
   UM_ECLSS_PCA_CNTLR_TLM CNTLR;  /*!< [    0] (12 bytes)  PCA Controller */
   uint8 VENT_POS;                /*!< [   12] (1 bytes)  Cabin vent valve position (1 = open) */
   char pad0__[3];                /*!< [   13] (3x1=3 bytes) */
   float N2_REG_P;                /*!< [   16] (4 bytes)  N2 Pressure regulator regulated pressure */
   float N2_EXIT_T;               /*!< [   20] (4 bytes)  N2 Temperature to cabin */
   uint8 N2_SOL_HIGH_POS;         /*!< [   24] (1 bytes)  N2 High-flow solenoid valve position (1 = open) */
   uint8 N2_SOL_LOW_POS;          /*!< [   25] (1 bytes)  N2 Low-flow solenoid valve position (1 = open) */
   char pad1__[2];                /*!< [   26] (2x1=2 bytes) */
   float N2_TANK_P;               /*!< [   28] (4 bytes)  N2 Tank pressure */
   float N2_TANK_QTY;             /*!< [   32] (4 bytes)  N2 Tank quantity fraction (0-1) of full */
   float O2_REG_P;                /*!< [   36] (4 bytes)  O2 Pressure regulator regulated pressure */
   float O2_EXIT_T;               /*!< [   40] (4 bytes)  O2 Temperature to cabin */
   uint8 O2_SOL_HIGH_POS;         /*!< [   44] (1 bytes)  O2 High-flow solenoid valve position (1 = open) */
   uint8 O2_SOL_LOW_POS;          /*!< [   45] (1 bytes)  O2 Low-flow solenoid valve position (1 = open) */
   char pad2__[2];                /*!< [   46] (2x1=2 bytes) */
   float O2_TANK_P;               /*!< [   48] (4 bytes)  O2 Tank pressure */
   float O2_TANK_QTY;             /*!< [   52] (4 bytes)  O2 Tank quantity fraction (0-1) of full */
} UM_ECLSS_PCA_TLM;               /*< Total size of 56 bytes */

/*! Structure: UM_ECLSS_CAL_TLM (58 bytes total)
   Description: Trick simulation provided definitions for "UM" module ECLSS message and child structures */
typedef struct
{
   UM_ECLSS_CAL_ENV_MON_TLM ENV_MON;  /*!< [    0] (16 bytes)  Environment Monitor */
   UM_ECLSS_FAN_TLM CABIN_FAN;        /*!< [   16] (8 bytes)  Cabin fan */
   UM_ECLSS_FAN_TLM VV_IMV_FAN;       /*!< [   24] (8 bytes)  Visiting Vehicle (VV) Inter-Module Ventilation (IMV) fan */
   UM_ECLSS_CAL_VPA_TLM VPA;          /*!< [   32] (2 bytes)  Vestibule Pressurization Assembly (VPA) */
   uint8 PPRV1_ISO_POS;               /*!< [   34] (1 bytes)  Positive Pressure Relief Valve (PPRV) 1 position (1 = open) */
   uint8 PPRV2_ISO_POS;               /*!< [   35] (1 bytes)  Positive Pressure Relief Valve (PPRV) 2 position (1 = open) */
   uint8 PCVA1_POS;                   /*!< [   36] (1 bytes)  Pressure Control Vent Assembly (PCVA) vent valve 1 position (1 = open) */
   uint8 PCVA2_POS;                   /*!< [   37] (1 bytes)  Pressure Control Vent Assembly (PCVA) vent valve 2 position (1 = open) */
   uint8 PCVA1_ISO_POS;               /*!< [   38] (1 bytes)  Pressure Control Vent Assembly (PCVA) isolation valve 1 position (1 = open) */
   uint8 PCVA2_ISO_POS;               /*!< [   39] (1 bytes)  Pressure Control Vent Assembly (PCVA) isolation valve 2 position (1 = open) */
   float CABIN_P;                     /*!< [   42] (4 bytes)  Cabin pressure */
   float CABIN_T;                     /*!< [   46] (4 bytes)  Cabin temperature */
   float SCI_AL_P;                    /*!< [   50] (4 bytes)  Science airlock pressure */
   float SCI_AL_T;                    /*!< [   54] (4 bytes)  Science airlock temperature */
} UM_ECLSS_CAL_TLM;                   /*< Total size of 58 bytes */

/*! Structure: UM_ECLSS_VALVE_CMD_T (13 bytes total)
   Description: UM ECLSS Valve Position override command. */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /*!< [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes)  CCSDS command message header */
   uint8 PARAM_1_POSITION;  /*!< [   12] (1 bytes)  Valve position command (1 = OPEN, 0 = CLOSE) */
} UM_ECLSS_VALVE_CMD_T;     /*< Total size of 13 bytes */

/*! Structure: UM_ECLSS_PCA_SETP_CMD_T (16 bytes total)
   Description: UM ECLSS PCA Setpoint Override Command. Used to override PCA Setpoints. */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /*!< [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes)  CCSDS command message header */
   float PARAM_1_SETPOINT;  /*!< [   12] (4 bytes)  Fan speed value (rpm) */
} UM_ECLSS_PCA_SETP_CMD_T;  /*< Total size of 16 bytes */

/*! Structure: UM_ECLSS_PCA_PRESS_CMD_T (13 bytes total)
   Description: Repressurization / Depressurization Start / Stop command. This command structure is used for starting and stopping repressurization or depressurization events */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /*!< [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes)  CCSDS command message header */
   uint8 PARAM_1_START;      /*!< [   12] (1 bytes)  Start Event (1 = start) */
} UM_ECLSS_PCA_PRESS_CMD_T;  /*< Total size of 13 bytes */

/*! Structure: UM_ECLSS_FAN_CMD_T (20 bytes total)
   Description: UM ECLSS Fan Command. Used to enable/disable ECLSS fan and set fan speed. */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /*!< [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes)  CCSDS command message header */
   uint8 PARAM_1_ENABLE;   /*!< [   12] (1 bytes)  Fan run enable flag (1=ENABLE, 0=DISABLE) */
   char pad0__[3];         /*!< [   13] (3x1=3 bytes) */
   float PARAM_2_SPEED;    /*!< [   16] (4 bytes)  Fan speed value (rpm) */
} UM_ECLSS_FAN_CMD_T;      /*< Total size of 20 bytes */

/*! Structure: ECLS_HKTLM_T (24 bytes total) */
typedef struct
{
   uint8 ucTlmHeader[CFE_SB_TLM_HDR_SIZE]; /*!< [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes) */
   uint8 usCmdCntr;        /*!< [   16] (1 bytes)  Command Counter of valid commands received */
   uint8 usCmdErrCntr;     /*!< [   17] (1 bytes)  Command Error Counter of invalid commands received */
   char pad0__[2];         /*!< [   18] (2x1=2 bytes) */
   uint32 uiExecCntr;      /*!< [   20] (4 bytes)  Execution Counter of execution cycles performed so far */
} ECLS_HKTLM_T;            /*< Total size of 24 bytes */

/*! Structure: ECLS_NOARGCMD_T (12 bytes total) */
typedef struct
{
   uint8 ucCmdHeader[CFE_SB_CMD_HDR_SIZE]; /*!< [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes) */
} ECLS_NOARGCMD_T;         /*< Total size of 12 bytes */

/*! Structure: ECLS_OUTDATA_T (44 bytes total) */
typedef struct
{
   uint8 ucTlmHeader[CFE_SB_TLM_HDR_SIZE]; /*!< [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes) */
   float PPO2;             /*!< [   16] (4 bytes)  Partial pressure of O2 (kPa) */
   float pFilt;            /*!< [   20] (4 bytes)  Filtered Total Cabin Pressure (kPa) */
   float dPdt;             /*!< [   24] (4 bytes)  Filtered Pressure Rate of Change */
   uint8 leakActive;       /*!< [   28] (1 bytes)  Leak Fault Detected Flag */
   uint8 pprv1CmdPos;      /*!< [   29] (1 bytes)  PPRV1 Commanded Position */
   uint8 pprv2CmdPos;      /*!< [   30] (1 bytes)  PPRV2 Commanded Position */
   uint8 ventVlvCmdPos;    /*!< [   31] (1 bytes)  VPA Vent Valve Commanded Position */
   uint8 pressVlvCmdPos;   /*!< [   32] (1 bytes)  VPA Pressurization Valve Commanded Position */
   char pad0__[3];         /*!< [   33] (3x1=3 bytes) */
   float PPO2CmdVal;       /*!< [   36] (4 bytes)  Commanded Partial Pressure Percentage of Oxygen */
   float pcaPCmdVal;       /*!< [   40] (4 bytes)  Pressure Control Assembly Commanded Pressure Value */
} ECLS_OUTDATA_T;          /*< Total size of 44 bytes */

/*! Structure: UM_ECLSS_TLM (142 bytes total)
   Description: Trick simulation provided definitions for "UM" module ECLSS message and child structures */
typedef struct
{
   uint8 cfsHeader[CFE_SB_TLM_HDR_SIZE]; /*!< [   12] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes)  Extended CFS SB message Header */
   UM_ECLSS_CAL_TLM CAL;  /*!< [   28] (58 bytes)  Cabin Air Loop (CAL) */
   UM_ECLSS_PCA_TLM PCA;  /*!< [   86] (56 bytes)  Pressure Control Assembly (PCA) */
} UM_ECLSS_TLM;           /*< Total size of 142 bytes */

#endif /* #ifndef _auto_ecls_msg_h_ */

