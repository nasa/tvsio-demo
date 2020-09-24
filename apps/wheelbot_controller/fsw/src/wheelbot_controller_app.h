/*=======================================================================================
** File Name:  wheelbot_controller_app.h
**
** Title:  Header File for WHEELBOT_CONTROLLER Application
**
** $Author:    Nexsys
** $Revision: 
** $Date:     
**
** Purpose:  To define WHEELBOT_CONTROLLER's internal macros, data types, global variables and
**           function prototypes
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   
**
**=====================================================================================*/
    
#ifndef _WHEELBOT_CONTROLLER_APP_H_
#define _WHEELBOT_CONTROLLER_APP_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "wheelbot_controller_platform_cfg.h"
#include "wheelbot_controller_mission_cfg.h"
#include "wheelbot_controller_private_ids.h"
#include "wheelbot_controller_private_types.h"
#include "wheelbot_controller_perfids.h"
#include "wheelbot_controller_msgids.h"
#include "wheelbot_controller_msg.h"



/*
** Local Defines
*/
#define WHEELBOT_CONTROLLER_TIMEOUT_MSEC    1000

/*
** Local Structure Declarations
*/
typedef struct
{
    /* CFE Event table */
    CFE_EVS_BinFilter_t  EventTbl[WHEELBOT_CONTROLLER_EVT_CNT];

    /* CFE scheduling pipe */
    CFE_SB_PipeId_t  SchPipeId; 
    uint16           usSchPipeDepth;
    char             cSchPipeName[OS_MAX_API_NAME];

    /* CFE command pipe */
    CFE_SB_PipeId_t  CmdPipeId;
    uint16           usCmdPipeDepth;
    char             cCmdPipeName[OS_MAX_API_NAME];
    
    /* CFE telemetry pipe */
    CFE_SB_PipeId_t  TlmPipeId;
    uint16           usTlmPipeDepth;
    char             cTlmPipeName[OS_MAX_API_NAME];

    /* Task-related */
    uint32  uiRunStatus;
    
    /* Input data - from I/O devices or subscribed from other apps' output data.
       Data structure should be defined in wheelbot_controller/fsw/src/wheelbot_controller_private_types.h */
    WHEELBOT_CONTROLLER_InData_t   InData;

    /* Output data - to be published at the end of a Wakeup cycle.
       Data structure should be defined in wheelbot_controller/fsw/src/wheelbot_controller_private_types.h */
    WHEELBOT_CONTROLLER_OutData_t  OutData;

    /* Housekeeping telemetry - for downlink only.
       Data structure should be defined in wheelbot_controller/fsw/src/wheelbot_controller_msg.h */
    WHEELBOT_CONTROLLER_HkTlm_t  HkTlm;

    /* TODO:  Add declarations for additional private data here */
} WHEELBOT_CONTROLLER_AppData_t;

/*
** External Global Variables
*/

/*
** Global Variables
*/

/*
** Local Variables
*/

/*
** Local Function Prototypes
*/
int32  WHEELBOT_CONTROLLER_InitApp(void);
int32  WHEELBOT_CONTROLLER_InitEvent(void);
int32  WHEELBOT_CONTROLLER_InitData(void);
int32  WHEELBOT_CONTROLLER_InitPipe(void);

void  WHEELBOT_CONTROLLER_AppMain(void);

void  WHEELBOT_CONTROLLER_CleanupCallback(void);

int32  WHEELBOT_CONTROLLER_RcvMsg(int32 iBlocking);

void  WHEELBOT_CONTROLLER_ProcessNewData(void);
void  WHEELBOT_CONTROLLER_ProcessNewCmds(void);
void  WHEELBOT_CONTROLLER_ProcessNewAppCmds(CFE_SB_Msg_t*);

void  WHEELBOT_CONTROLLER_ReportHousekeeping(void);
void  WHEELBOT_CONTROLLER_SendOutData(void);

boolean  WHEELBOT_CONTROLLER_VerifyCmdLength(CFE_SB_Msg_t*, uint16);

#endif /* _WHEELBOT_CONTROLLER_APP_H_ */

/*=======================================================================================
** End of file wheelbot_controller_app.h
**=====================================================================================*/
    