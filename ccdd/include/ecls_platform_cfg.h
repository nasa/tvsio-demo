/*=======================================================================================
**
** File  ecls_platform_cfg.h
**
** Purpose:
**    This file defines platform-specific configurations for ECLS application.
**
** Modification History:
**    Date       | Author          | Description
**    ---------- | --------------- | ----------------------------------------------------
**    2019-06-11 | Jia Lin      | Initial revision
**
**=======================================================================================*/

#ifndef _ecls_platform_cfg_h_
#define _ecls_platform_cfg_h_

/*=======================================================================================
** Macro Definitions
**=======================================================================================*/

/**
** \eclsplatformcfg Unique name for ECLS Scheduling pipe
**
** \par Description:
**      This pipe receives messages sent by the SCH application, typically the
**      WakeUp and SendHk messages.
*/
#define ECLS_SCH_PIPE_NAME  "ECLS_SCH_PIPE"

/**
** \eclsplatformcfg Maximum number of messages in the Scheduling pipe
**
** \par Description:
**      When this number is reached, incoming messages will get dropped
**      until there is room in the pipe again.
*/
#define ECLS_SCH_PIPE_DEPTH  3

/**
** \eclsplatformcfg Unique name for ECLS Command pipe
**
** \par Description:
**      This pipe receives command messages sent by any source.
*/
#define ECLS_CMD_PIPE_NAME  "ECLS_CMD_PIPE"

/**
** \eclsplatformcfg Maximum number of messages in the Command pipe
**
** \par Description:
**      When this number is reached, incoming messages will get dropped
**      until there is room in the pipe again.
*/
#define ECLS_CMD_PIPE_DEPTH  5

/**
** \eclsplatformcfg Unique name for ECLS Telemetry pipe
**
** \par Description:
**      This pipe receives telemetry messages that it subscribes to.
*/
#define ECLS_TLM_PIPE_NAME  "ECLS_TLM_PIPE"

/**
** \eclsplatformcfg Maximum number of messages in the Telemetry pipe
**
** \par Description:
**      When this number is reached, incoming messages will get dropped
**      until there is room in the pipe again.
*/
#define ECLS_TLM_PIPE_DEPTH  5


/*
** TODO: Add more definitions for platform-specific parameters here, if needed.
*/

#endif /* _ecls_platform_cfg_h_ */

/*=======================================================================================
** End of file ecls_platform_cfg.h
**=======================================================================================*/

