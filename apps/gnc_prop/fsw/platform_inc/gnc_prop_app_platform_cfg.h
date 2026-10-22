#ifndef GNC_PROP_APP_PLATFORM_CFG_H
#define GNC_PROP_APP_PLATFORM_CFG_H

/*
** GNC Propulsion Demo Application
** Platform Configuration Header
**
*/

/**************************************************************************
**  Pipe configuration
**************************************************************************/

/*
** Depth of the TVSIO pipe used to receive telemetry from SIM_SENSORS
** and SIM_THRUSTERS.
*/
#define GNC_PROP_TVSIO_PIPE_DEPTH      20

/*
** Maximum name length for pipes.
*/
#define GNC_PROP_PIPE_NAME_LENGTH      OS_MAX_API_NAME


#endif /* GNC_PROP_APP_PLATFORM_CFG_H */