/*=======================================================================================
** File Name:  temp_mon_platform_cfg.h
**
** Title:  Platform Configuration Header File for TEMP_MON Application
**
** $Author:    Nexsys
** $Revision: 1.1 $
** $Date:      2018-03-08
**
** Purpose:  This header file contains declartions and definitions of all TEMP_MON's 
**           platform-specific configurations.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-03-08 | Nexsys | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TEMP_MON_PLATFORM_CFG_H_
#define _TEMP_MON_PLATFORM_CFG_H_

/*
** temp_mon Platform Configuration Parameter Definitions
*/
#define TEMP_MON_SCH_PIPE_DEPTH  2
#define TEMP_MON_CMD_PIPE_DEPTH  10
#define TEMP_MON_TLM_PIPE_DEPTH  10
#define TEMP_MON_TVS_IO_PIPE_DEPTH 10

#define TEMP_MON_RCV_THREAD_STACK_SIZE 16384


#define TEMP_MON_FRAME_DATA_BUFFER_SIZE 81920 // 80 kB default - can be tuned up or down based on data rate per frame

#endif /* _TEMP_MON_PLATFORM_CFG_H_ */

/*=======================================================================================
** End of file temp_mon_platform_cfg.h
**=====================================================================================*/
    
