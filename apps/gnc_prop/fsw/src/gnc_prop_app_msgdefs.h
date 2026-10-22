#ifndef GNC_PROP_APP_MSGDEFS_H
#define GNC_PROP_APP_MSGDEFS_H

/* Command codes */
#define GNC_PROP_NOOP_CC     0
#define GNC_PROP_RESET_CC    1

/* ---------------------------------------------
** Generic NOOP command
** --------------------------------------------- */
typedef struct
{
    CFE_MSG_CommandHeader_t CmdHeader;
} GNC_PROP_Noop_t;

/* ---------------------------------------------
** Generic RESET command
** --------------------------------------------- */
typedef struct
{
    CFE_MSG_CommandHeader_t CmdHeader;
} GNC_PROP_Reset_t;

#endif