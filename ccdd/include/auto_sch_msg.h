/* Created : Tue May 07 14:50:19 CDT 2019
   User    : aes
   Project : cert_cfs_restored
   Script  : /home/tngo/AES_workspace/js-er-code/aes_ccdd/scripts/CCSDS_V2_Msgs.js
   Group(s): sch_msg
*/

#ifndef _auto_sch_msg_h_
#define _auto_sch_msg_h_


/* Structure: SCH_DiagPacket_t (342 bytes total) */
typedef struct
{
   uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE]; /* [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes)  cFE Software Bus Telemetry Message Header */
   uint16 EntryStates[SCH_NUM_STATUS_BYTES_REQD / 2]; /* [   16] (##SCH_NUM_STATUS_BYTES_REQD## / 2x2=NaN bytes)  States of each Schedule Entry Each two bits represents the state for a single entry in Schedule Definition Table. Unused=0, Enabled=1, Disabled=2 MSBs are the lowest numbered entry */
   CFE_SB_Qos_t MsgIDs[SCH_TABLE_ENTRIES]; /* [  142] (##SCH_TABLE_ENTRIES##x2=NaN bytes)  Message ID of msg associated with each entry */
} SCH_DiagPacket_t;           /* Total size of 342 bytes */

/* Structure: SCH_EntryCmd_t (16 bytes total) */
typedef struct
{
   uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes)  cFE Software Bus Command Message Header */
   uint16 SlotNumber;    /* [   12] (2 bytes)  Slot Number of Activity whose state is to changeValid Range is zero to (#SCH_TOTAL_SLOTS - 1) */
   uint16 EntryNumber;   /* [   14] (2 bytes)  Entry Number of Activity whose state is to change Valid Range is zero to (#SCH_ENTRIES_PER_SLOT - 1) */
} SCH_EntryCmd_t;        /* Total size of 16 bytes */

/* Structure: SCH_GroupCmd_t (16 bytes total) */
typedef struct
{
   uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes)  cFE Software Bus Command Message Header */
   uint32 GroupData;     /* [   12] (4 bytes)  Group and Multi-Group Identifiers Most Significant Byte contains a Group ID of 1 to 255, remaining 24 bits identify 24 Multi-Group Identifiers */
} SCH_GroupCmd_t;        /* Total size of 16 bytes */

/* Structure: SCH_HkPacket_t (68 bytes total) */
typedef struct
{
   uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE]; /* [    0] (##CFE_SB_TLM_HDR_SIZE##x1=NaN bytes)  cFE Software Bus Telemetry Message Header ** Command execution counters (ground commands) */
   uint8 CmdCounter;                     /* [   16] (1 bytes)  Command Counter SCHHK_CmdCounter "Click for more" */
   uint8 ErrCounter;                     /* [   17] (1 bytes)  Command Error Counter SCHHK_ErrCounter "Click for more" */
   uint8 SyncToMET;                      /* [   18] (1 bytes)  Status indicating whether slots are synched to MET SCHHK_SyncToMET "Click for more" */
   uint8 MajorFrameSource;               /* [   19] (1 bytes)  Major Frame Signal source identifier SCHHK_MajorFrameSource "Click for more" ** Messages sent by schedule table processor */
   uint32 ScheduleActivitySuccessCount;  /* [   20] (4 bytes)  Number of successfully performed activities SCHHK_ScheduleActivitySuccessCount "Click for more" */
   uint32 ScheduleActivityFailureCount;  /* [   24] (4 bytes)  Number of unsuccessful activities attempted SCHHK_ScheduleActivityFailureCount "Click for more" ** Total schedule table slots processed */
   uint32 SlotsProcessedCount;           /* [   28] (4 bytes)  Total # of Schedule Slots (Minor Frames) Processed SCHHK_SlotsProcessedCount "Click for more" ** The number of times that slots were skipped ** (not the number of slots that were skipped) */
   uint16 SkippedSlotsCount;             /* [   32] (2 bytes)  Number of times that slots were skipped The number of times that a slot (minor frame) was skipped. SCHHK_SkippedSlotsCount "Click for more" Note: This is NOT the number of slots that were skipped ** The number of times that multiple slots were processed ** (not the number of slots that were processed) */
   uint16 MultipleSlotsCount;            /* [   34] (2 bytes)  Number of times that multiple slots processed The number of times that multiple slots (minor frames) were processed in the same minor frame. SCHHK_MultipleSlotsCount "Click for more" Note: This is NOT the number of slots that were processed ** The number of times that SH woke up in the same slot as last time */
   uint16 SameSlotCount;                 /* [   36] (2 bytes)  # of times SCH woke up in the same slot as last time SCHHK_SameSlotCount "Click for more" ** The number of times that a table entry with bad data was processed ** (the entry previously passed validation but then somehow went bad) */
   uint16 BadTableDataCount;             /* [   38] (2 bytes)  # of times corrupted table entries were processed SCHHK_BadTableDataCount "Click for more" ** The number of tables verified prior to table load */
   uint16 TableVerifySuccessCount;       /* [   40] (2 bytes)  # of times table loads successfully verified SCHHK_TableVerifySuccessCount "Click for more" */
   uint16 TableVerifyFailureCount;       /* [   42] (2 bytes)  # of times table loads unsuccessfully verified SCHHK_TableVerifyFailureCount "Click for more" */
   uint32 TablePassCount;                /* [   44] (4 bytes)  # of times Schedule Table has been processed SCHHK_TablePassCount "Click for more" */
   uint32 ValidMajorFrameCount;          /* [   48] (4 bytes)  # of valid Major Frame tones received SCHHK_ValidMajorFrameCount "Click for more" */
   uint32 MissedMajorFrameCount;         /* [   52] (4 bytes)  # of missing Major Frame tones SCHHK_MissedMajorFrameCount "Click for more" */
   uint32 UnexpectedMajorFrameCount;     /* [   56] (4 bytes)  # of unexpected Major Frame tones SCHHK_UnexpectedMajorFrameCount "Click for more" */
   uint16 MinorFramesSinceTone;          /* [   60] (2 bytes)  # of Minor Frames since last Major Frame tone SCHHK_MinorFramesSinceTone "Click for more" */
   uint16 NextSlotNumber;                /* [   62] (2 bytes)  Next Minor Frame to be processed SCHHK_NextSlotNumber "Click for more" */
   uint16 LastSyncMETSlot;               /* [   64] (2 bytes)  Slot number where Time Sync last occurred SCHHK_LastSyncMETSlot "Click for more" */
   boolean IgnoreMajorFrame;             /* [   66] (1 bytes)  Major Frame too noisy to trust SCHHK_IgnoreMajorFrame "Click for more" */
   boolean UnexpectedMajorFrame;         /* [   67] (1 bytes)  Most Recent Major Frame signal was unexpected SCHHK_UnexpectedMajorFrame "Click for more" */
} SCH_HkPacket_t;                        /* Total size of 68 bytes */

/* Structure: SCH_NoArgsCmd_t (12 bytes total) */
typedef struct
{
   uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE]; /* [    0] (##CFE_SB_CMD_HDR_SIZE##x1=NaN bytes)  cFE Software Bus Command Message Header */
} SCH_NoArgsCmd_t;       /* Total size of 12 bytes */

#endif /* #ifndef _auto_sch_msg_h_ */

