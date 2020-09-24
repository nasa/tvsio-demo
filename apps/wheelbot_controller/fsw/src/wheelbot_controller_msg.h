/*=======================================================================================
** File Name:  wheelbot_controller_msg.h
**
** Title:  Message Definition Header File for WHEELBOT_CONTROLLER Application
**
** $Author:    Nexsys
** $Revision: 
** $Date:     
**
** Purpose:  To define WHEELBOT_CONTROLLER's command and telemetry message defintions 
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   
**
**=====================================================================================*/
    
#ifndef _WHEELBOT_CONTROLLER_MSG_H_
#define _WHEELBOT_CONTROLLER_MSG_H_

/*
** Pragmas
*/

/*
** Include Files
*/



/*
** Local Defines
*/

/*
** WHEELBOT_CONTROLLER command codes
*/
#define WHEELBOT_CONTROLLER_NOOP_CC                 0
#define WHEELBOT_CONTROLLER_RESET_CC                1

/*
** Local Structure Declarations
*/
typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint8              usCmdCnt;
    uint8              usCmdErrCnt;

    /* TODO:  Add declarations for additional housekeeping data here */

} WHEELBOT_CONTROLLER_HkTlm_t;


#endif /* _WHEELBOT_CONTROLLER_MSG_H_ */

/*=======================================================================================
** End of file wheelbot_controller_msg.h
**=====================================================================================*/
    