/*=======================================================================================
**
** File:  ecls_mission_cfg.h
**
** Purpose:
**    This file defines mission-specific configurations for ECLS application.
**
** Modification History:
**    Date       | Author          | Description
**    ---------- | --------------- | ----------------------------------------------------
**    2019-06-11 | Jia Lin      | Initial revision
**
**=======================================================================================*/
 
#ifndef _ecls_mission_cfg_h_
#define _ecls_mission_cfg_h_

/*=======================================================================================
** Includes
**=======================================================================================*/

#include "cfe.h"

/*=======================================================================================
** Macro Definitions
**=======================================================================================*/

/** \eclsmissioncfg Mission-specific version number for ECLS application
**  
**  \par Description:
**       An application version number consists of four parts:
**       major version number, minor version number, revision
**       number and mission-specific revision number. The mission
**       specific revision number is defined here and the other
**       parts are defined in "ecls_version.h".
**
**  \par Limits:
**       Must be defined as a numeric value that is greater than
**       or equal to zero.
*/
#define ECLS_MISSION_REVISION  0

/**
** \eclsmissioncfg Execution rate in Hertz (Hz)
**
** \par Description:
**      The rate at which ECLS can run per second, which should equals the publishing
**      rate of its WakeUp message.
**
** \par Limits:
**      Must be defined as a numeric value between 1 and the maximum allowable rate 
**      spcified for the mission.
*/
#define ECLS_EXECUTION_RATE_IN_HZ  1

/** \eclsmissioncfg Time to wait for all applications to be started
**  
**  \par Description:
**       Wait time, in milliseconds, for system startup synchronization.
**
**  \par Limits:
**       Must be defined as a numeric value that is equal to or greater than 0.
*/
#define ECLS_STARTUP_WAIT_IN_MILLISECS  100


/*
** TODO: Add definitions for mission-specific parameters here, if needed.
*/

#endif /* _ecls_mission_cfg_h_ */

/*=======================================================================================
** End of file ecls_mission_cfg.h
**=======================================================================================*/

