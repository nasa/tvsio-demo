#ifndef _sbn_tte_if_struct_h_
#define _sbn_tte_if_struct_h_

#include "sbn_constants.h"
#include "sbn_interfaces.h"
#include "sbn_platform_cfg.h"
#include "cfe.h"
#include "tte_api.h"

#define SBN_TTE_ITEMS_PER_FILE_LINE 1

/* Max length of a TTE port name */
#define SBN_TTE_MAX_PORTNAME_LEN 64

/* Max ports per CPU */
#define SBN_TTE_MAX_PORTS 32

/* Max TTE networks */
#define SBN_TTE_MAX_NETWORKS 1

/* Max MIDs per port */
#define SBN_TTE_MAX_PORT_MSGIDS 8

typedef enum 
{
    SBN_TTE_DIRECTION_RECEIVE = 0,
    SBN_TTE_DIRECTION_SEND = 1,
    SBN_TTE_DIRECTION_MIN = 0,
    SBN_TTE_DIRECTION_MAX = 1
} SBN_TTE_Direction_t;

typedef struct
{
    TTE_PortHdl_t PortHandle;                       /* Handle identifying this port, returned by the TTE API */
    SBN_TTE_Direction_t Direction;                  /* Whether this is a send or a receive port */
    CFE_SB_MsgId_t MsgIds[SBN_TTE_MAX_PORT_MSGIDS]; /* MIDs sent on this port (for send ports only) */
    uint8 MsgIdCount;                               /* How many MIDs are sent on this port */
} SBN_TTE_Port_t;

#endif /* _sbn_TTE_if_struct_h_ */
