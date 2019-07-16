#ifndef _sbn_msg_h_
#define _sbn_msg_h_

#include "sbn_msgdefs.h"
#include "sbn_platform_cfg.h"
#include "sbn_constants.h"
#include "cfe.h"

/**
 * \brief No Arguments Command
 * For command details see #SBN_NOOP_CC, #SBN_RESET_CC
 * Also see #SBN_SEND_HK_CC
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} SBN_NoArgsCmd_t;

typedef struct
{
    uint8  ucCmdHeader[CFE_SB_CMD_HDR_SIZE];  /**< \brief CCSDS command message header */
    double Temperature;                     /**< \brief Motor temperature (degrees K)*/
    double Speed;   
} UM_ECLSS_FAN_CMD_T;

/**
 * \brief Net Command
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    uint8 NetIdx;
} SBN_NetCmd_t;

/**
 * \brief Peer Command
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    uint8 NetIdx;
    uint8 PeerIdx;
} SBN_PeerCmd_t;

/**
 * \brief Housekeeping packet structure
 */
typedef struct {
    uint8  TlmHeader[CFE_SB_TLM_HDR_SIZE];

    /** SBN sends all HK responses with the same MID, the CC of the request
     * is copied to the struct of the response to disambiguate what type
     * of response it is.
     */
    uint8 CC; // 1 byte

    uint8 CmdCount; // 1 + 1 = 2 bytes

    uint8 CmdErrCount; // 2 + 1 = 3 bytes

    uint8 Padding; // 3 + 1 = 4 bytes // 16-bit align below

    uint16 SubCount; // 4 + 2 = 6 bytes

    uint16 NetCount; // 6 + 2 = 8 bytes
} SBN_HkPacket_t;

typedef struct {
    uint8  TlmHeader[CFE_SB_TLM_HDR_SIZE];

    /** SBN sends all HK responses with the same MID, the CC of the request
     * is copied to the struct of the response to disambiguate what type
     * of response it is.
     */
    uint8 CC; // 1 byte

    uint8 NetIdx; // 1 + 1 = 2 bytes

    uint8 PeerIdx; // 2 + 1 = 3 bytes

    uint8 Padding; // 3 + 1 = 4 bytes

    uint16 SubCount; // 4 + 2 = 6 bytes

    uint16 Padding2[2]; // 6 + 2 = 8 bytes

    CFE_SB_MsgId_t Subs[SBN_MAX_SUBS_PER_PEER];
    uint32 Dword; /* Force 32-bit alignment for this structure */
} SBN_HkSubsPkt_t;

#endif /* _sbn_msg_h_ */
