/*=======================================================================================
**
** File:  ecls_msgdefs.h
**
** Purpose:
**    This file defines constants used in ECLS application's command & telemetry 
**    messages.
**
** Modification History:
**    Date       | Author          | Description
**    ---------- | --------------- | ----------------------------------------------------
**    2019-06-11 | Jia Lin      | Initial revision
**
**=======================================================================================*/

#ifndef _ecls_msgdefs_h_
#define _ecls_msgdefs_h_

/**************************************
** Command Codes for Command Messages
***************************************/

/** \name ECLS Command Codes */
/** \{ */

/** \eclscmd ECLS No-Op Command
**
**  \par Description:
**       This command increments the ECLS application's #ECLS_HKTLM_T.usCmdCntr telemetry.
**
**  \par Command Structure:
**       #ECLS_NOARGCMD_T
**
**  \par Command Arguments:
**       None
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**       - #ECLS_HKTLM_T.usCmdCntr telemetry will increment.
**       - The #ECLS_CMD_INF_EID informational event message will be issued acknowledging 
**         No-Op command has been received.
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**
**       Evidence of an unexpected command length error may be found in the following telemetry:
**       - #ECLS_HKTLM_T.usCmdErrCntr telemetry will increment.
**       - The #ECLS_CMDMSG_LEN_ERR_EID error event message will be issued.
**
**  \par Criticality
**       None
*/
#define ECLS_NOOP_CC         0    

/** \eclscmd ECLS Reset-Counters Command
**
**  \par Description:
**       This command resets the following telemetry:
**       - #ECLS_HKTLM_T.usCmdCntr
**       - #ECLS_HKTLM_T.usCmdErrCntr
**       - #ECLS_HKTLM_T.uiExecCntr
**
**  \par Command Structure:
**       #ECLS_NOARGCMD_T
**
**  \par Command Arguments:
**       None
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**       - #ECLS_HKTLM_T.usCmdCntr telemetry will be set to zero.
**       - #ECLS_HKTLM_T.usCmdErrCntr telemetry will be set to zero.
**       - #ECLS_HKTLM_T.uiExecCntr telemetry will be set to zero.
**       - The #ECLS_CMD_INF_EID informational event message will be issued acknowledging 
**         Reset-Counters command has been received.
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**
**       Evidence of an unexpected command length error may be found in the following telemetry:
**       - #ECLS_HKTLM_T.usCmdErrCntr telemetry will increment.
**       - The #ECLS_CMDMSG_LEN_ERR_EID error event message will be issued.
**
**  \par Criticality:
**       This command is not inherently dangerous.
**       However, it is possible for ground systems and on-board safing procedures to be designed 
**       such that they react to changes in the counter values that are reset by this command.
*/
#define ECLS_RESET_CNTRS_CC  1

/** \eclscmd ECLS PPRV 1 Isolation Command Code
**
**  \par Description:
**       This command generates a hardware effector command
**       to modify the PPRV 1 Isolation Valve Position
**
**  \par Command Structure:
**       #UM_ECLSS_VALVE_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_POSITION
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range commanded valve position (> 1 or < 0)
**
**  \par Criticality:
**       This command can isolate the PPRV and prevent correct cabin venting in the event of an 
**       overpressure event. 
*/
#define ECLS_PPRV_1_ISO_CC 0

/** \eclscmd ECLS PPRV 2 Isolation Command Code
**
**  \par Description:
**       This command generates a hardware effector command
**       to modify the PPRV 2 Isolation Valve Position
**
**  \par Command Structure:
**       #UM_ECLSS_VALVE_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_POSITION
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range commanded valve position (> 1 or < 0)
**
**  \par Criticality:
**       This command can isolate the PPRV and prevent correct cabin venting in the event of an 
**       overpressure event. 
*/

#define ECLS_PPRV_2_ISO_CC 1

/** \eclscmd ECLS Cabin Fan Enable and Speed Override Command Code
**
**  \par Description:
**       This command generates a hardware effector command
**       to modify the ECLS Cabin Fan Speed and Enable status
**
**  \par Command Structure:
**       #UM_ECLSS_FAN_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_ENABLE
**       PARAM_2_SPEED
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range commanded enable status (> 1 or < 0)
**       - Out of range commanded speed
**
**  \par Criticality:
**       This command is not inherently dangerous.
**       However, it is possible for ground systems and on-board safing procedures to be designed 
**       such that they react to changes in the counter values that are reset by this command.       
*/
#define ECLS_CABIN_FAN_CC 2

/** \eclscmd ECLS Visiting Vehicle Fan Enable and Speed Override Command Code
**
**  \par Description:
**       This command generates a hardware effector command
**       to modify the ECLS Visiting Vehicle Fan Speed and Enable status
**
**  \par Command Structure:
**       #UM_ECLSS_FAN_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_ENABLE
**       PARAM_2_SPEED
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range commanded enable status (> 1 or < 0)
**       - Out of range commanded speed
**
**  \par Criticality:
**       This command is not inherently dangerous.
**       However, it is possible for ground systems and on-board safing procedures to be designed 
**       such that they react to changes in the counter values that are reset by this command.
*/

#define ECLS_VV_IMV_FAN_CC 3

/** \eclscmd ECLS VPA Vent Valve Position Override Command Code
**
**  \par Description:
**       This command generates a hardware effector command
**       to modify the VPA Vent Valve Position
**
**  \par Command Structure:
**       #UM_ECLSS_VALVE_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_POSITION
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range commanded valve position (> 1 or < 0)
**
**  \par Criticality:
**       
*/
#define ECLS_VENT_VLV_CC 0

/** \eclscmd ECLS VPA Pressurization Valve Position Override Command Code
**
**  \par Description:
**       This command generates a hardware effector command
**       to modify the VPA Pressurization Valve Position
**
**  \par Command Structure:
**       #UM_ECLSS_VALVE_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_POSITION
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range commanded valve position (> 1 or < 0)
**
**  \par Criticality:
**       
*/
#define ECLS_PRESS_VLV_CC 1

/** \eclscmd ECLS Start PCA Depressurization Command Code
**
**  \par Description:
**       This command initiated a PCA Depressuization Event
**
**  \par Command Structure:
**       #UM_ECLSS_PCA_PRESS_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_START
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range event start command (!= 1)
**
**  \par Criticality:
**       
*/
#define ECLS_DEPRESS_CC 0

/** \eclscmd ECLS O2 Setpoint Override Command Code
**
**  \par Description:
**       This command generates a hardware effector command
**       to modify the ECLS O2 Setpoint Value
**
**  \par Command Structure:
**       #UM_ECLSS_PCA_SETP_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_SETPOINT
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range setpoint value
**
**  \par Criticality:
**       
*/
#define ECLS_O2_SET_CC 1

/** \eclscmd ECLS P Setpoint Override Command Code
**
**  \par Description:
**       This command generates a hardware effector command
**       to modify the ECLS Total Pressure Setpoint Value
**
**  \par Command Structure:
**       #UM_ECLSS_PCA_SETP_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_SETPOINT
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range setpoint value
**
**  \par Criticality:
**       
*/
#define ECLS_P_SET_CC 2

/** \eclscmd ECLS Start PCA Repressurization Command Code
**
**  \par Description:
**       This command initiated a PCA Repressuization Event
**
**  \par Command Structure:
**       #UM_ECLSS_PCA_PRESS_CMD_T
**
**  \par Command Arguments:
**       PARAM_1_START
**
**  \par Command Verifications:
**       Successful execution of this command may be verified with the following telemetry:
**
**
**  \par Error Conditions:
**       This command may fail for the following reason(s):
**       - Unexpected command length.
**       - Out of range event start command (!= 1)
**
**  \par Criticality:
**       
*/
#define ECLS_REPRESS_CC 3

#endif /* _ecls_msgdefs_h_ */

/*=======================================================================================
** End of file ecls_msgdefs.h
**=====================================================================================*/
    
