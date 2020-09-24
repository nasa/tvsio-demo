/*=======================================================================================
** File Name:  wheelbot_controller_private_types.h
**
** Title:  Type Header File for WHEELBOT_CONTROLLER Application
**
** $Author:    Nexsys
** $Revision: 
** $Date:     
**
** Purpose:  This header file contains declarations and definitions of all WHEELBOT_CONTROLLER's private
**           data structures and data types.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   
**
**=====================================================================================*/
    
#ifndef _WHEELBOT_CONTROLLER_PRIVATE_TYPES_H_
#define _WHEELBOT_CONTROLLER_PRIVATE_TYPES_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include "cfe.h"

/*
** Local Defines
*/

/*
** Local Structure Declarations
*/

typedef struct
{
    uint8  ucCmdHeader[CFE_SB_CMD_HDR_SIZE];
} WHEELBOT_CONTROLLER_NoArgCmd_t;


typedef struct
{
    uint32  counter;

    /* TODO:  Add input data to this application here, such as raw data read from I/O
    **        devices or data subscribed from other apps' output data.
    */

} WHEELBOT_CONTROLLER_InData_t;

typedef struct
{
    uint8   ucTlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint32  uiCounter;
} WHEELBOT_CONTROLLER_OutData_t;

/* TODO:  Add more private structure definitions here, if necessary. */

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

#endif /* _WHEELBOT_CONTROLLER_PRIVATE_TYPES_H_ */

/*=======================================================================================
** End of file wheelbot_controller_private_types.h
**=====================================================================================*/
    