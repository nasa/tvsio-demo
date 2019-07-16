/* Created : Tue Jul 17 07:08:41 CDT 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): HERA_CW_DATA, CCSDS_TLM_HDR, CCSDS_Primary, THERAHEADER */

#ifndef _HERA_TYPES_H_
#define _HERA_TYPES_H_

#include "shared_types.h"
///* @file */
#define MAX_SENSORS 4 ///< Max Number of Timepix sensors in a HERA system
   
//! HERA Subsystem Status Enumeration
typedef enum
{
   UNKNOWN_STATUS = 0, ///< Unknown
   FAILED_STATUS, ///< System not operational
   OFF_STATUS, ///< System has been commanded OFF
   MAINTENANCE_STATUS, ///< System in maintanence mode
   DEGRADED_STATUS, ///< System running, but data is suspect
   NOMINAL_STATUS, ///< System running normally
   SELF_TEST_STATUS ///< System is executing a self test.
} ESUBSYSSTATUS;

//! HERA state/modes
typedef enum
{
   MODE_UNKNOWN = 0, ///< [0x00] UNKNOWN
   MODE_SELF_INIT = 1, ///< [0x01] CHaTS Internal Initialization
   MODE_INIT = 2, ///< [0x02] HERA is initializing
   MODE_STANDBY = 3, ///< [0x03][CMD] HERA in standby
   MODE_ACQUIRE = 4, ///< [0x04][CMD] HERA in acquisition
   MODE_RESTART = 5, ///< [0x05] HERA will close down and then reboot
   MODE_SHUTDOWN = 6, ///< [0x06][CMD] HERA shutting down
   MODE_SHUTDOWN_AND_LOCK = 7, ///< [0x07][CMD] HERA shutting down after locking filesystem
   MODE_LOCK = 8, ///< [0x08] HERA filesystem is locked (presumably at end of mission). Cannot leave mode unless #UNLOCK_FILESYSTEM is sent
   MODE_FAULT = 9, ///< [0X09] A "safe" mode to which HERA, or a subsystem, will transition if certain extreme fault conditions are detected.
   MODE_SELF_TEST = 10 ///< [0X0A] SELF TEST Mode
} EMODE;

//! ORION display flag data. The flag flag represents the logical "OR" of all the flags that are desired.
typedef enum
{
   NO_FLAGS = 0, ///< Standard Display
   CAUTION_LOW = 1, ///< Yellow with Down arrow
   CAUTION_HIGH = 2, ///< Yellow with Up arrow
   WARNING_LOW = 4, ///< Red with Down arrow
   WARNING_HIGH = 8, ///< Red with Up arrow
   RED_X = 16, ///< single "x" in red text
   MISSING = 32, ///< cyan "m" in place of data
   BLANK = 64, ///< print "spaces" in field (no characters)
   SUSPECT = 128 ///< suspect data, take reading with grain of salt
} MSID_FLAG_MAPPING;



#ifdef __cplusplus
extern "C" {
#endif
/** Structure THERAHEADER (24 bytes in size)  *
* This structure is used for all ORION<-->HERA, GSE<-->CHaTS, GSE<-->SUS, and CHaTS<-->SUS communication, as described in the HERA ICD. The header structure contains 24 bytes, is followed by an optional payload, and then a 16-bit checksum.
*/
typedef struct
{
  uint32_t uSync;                                     ///< [    0] (4 bytes)  Sync value is 0x1ACFFC1D
  uint16_t usSource;                                  ///< [    4] (2 bytes)  ID number for the source of the command (i.e. the sender) Enumerated values are MPCV_ID(1)/0x01, LSU_ID(100)/0x64, HSU1_ID(101)/0x65, HSU2_ID(102)/0x66, HSU3_ID(103)/0x67, or HPU_ID(220)/0xDC
  uint16_t usDestination;                             ///< [    6] (2 bytes)  ID number for the destination of the command (i.e. the sender) Enumerated values are MPCV_ID(1)/0x01, LSU_ID(100)/0x64, HSU1_ID(101)/0x65, HSU2_ID(102)/0x66, HSU3_ID(103)/0x67, or HPU_ID(220)/0xDC
  uint16_t usSQUID;                                   ///< [    8] (2 bytes)  Sequence ID. Command counter for this cmd source, starts from 0
  uint16_t eCmd;                                      ///< [   10] (2 bytes)  Unique command number to execute (an "ECMD" item)
  uint32_t uPlSize;                                   ///< [   12] (4 bytes)  payload byte count, does not count the header bytes
  uint64_t ullOrionTime;                              ///< [   16] (8 bytes)  Timestamp as number of nano-seconds since GPS epoch(Jan6, 1980)
} THERAHEADER;     ///<  Total size of 24 bytes

/** Structure HERA_CW_DATA (72 bytes in size)  *
* A small structure holding just the Orion Status/C+W data (sent to ORION from HERA)
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                            ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  THERAHEADER hdr;                                    ///< [   16] (24 bytes)  24-byte HERA Header
  uint8_t ucHSUPwrSwitchStatus;                       ///< [   40] (1 bytes)  Power status on HSU's, 1 bit each. (1 byte)
  uint8_t ucHERASystemMode;                           ///< [   41] (1 bytes)  HERA operating mode (#EMODE)
  uint8_t ucHERASystemAlarm;                          ///< [   42] (1 bytes)  HERA Alarm status
  uint8_t ucHERAExecutionInd;                         ///< [   43] (1 bytes)  Overall HERA system status (#ESUBSYSSTATUS)
  uint32_t uiBuiltInTestStatus;                       ///< [   44] (4 bytes)  BIT status bits
  uint8_t ucSensorExecutionInd[MAX_SENSORS];          ///< [   48] (MAX_SENSORS x 1=4 bytes)  Sensor Execution Status (#ESUBSYSSTATUS). Array of #MAX_SENSORS
  uint8_t ucSensorExecutionIndFlag[MAX_SENSORS];      ///< [   52] (MAX_SENSORS x 1=4 bytes)  Sensor ExecIND Flags (#MSID_FLAG_MAPPING)
  uint8_t ucAbsDoseRateAlarm[MAX_SENSORS];            ///< [   56] (MAX_SENSORS x 1=4 bytes)  Flag for 3-in-a-row DoseRate readings over limit (1 for each sensor)
  uint8_t ucHERAExecutionIndFlag;                     ///< [   60] (1 bytes)  Display Flags for HERAExecutionIND status. (#MSID_FLAG_MAPPING)
  uint8_t ucBITFlag;                                  ///< [   61] (1 bytes)  Display Flags for uiBuiltInTestStatus (#MSID_FLAG_MAPPING)
  uint16_t usNumCmdRecv;                              ///< [   62] (2 bytes)  Number of commands received by HERA
  uint8_t ucCmdFlag;                                  ///< [   64] (1 bytes)  Display Flags for numCommandRecieved (#MSID_FLAG_MAPPING)
  char UNUSED[5];                                     ///< [   65] (5x1=5 bytes)  Reserved for future work...
  uint16_t usChecksum;                                ///< [   70] (2 bytes)  Checksum for #HERA_CW_DATA structure
} HERA_CW_DATA;     ///<  Total size of 72 bytes

void byteswap_HERA_CW_DATA(HERA_CW_DATA *inPtr, HERA_CW_DATA *outPtr, int direction);
void bitswap_HERA_CW_DATA(HERA_CW_DATA *inPtr, HERA_CW_DATA *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void byteswap_THERAHEADER(THERAHEADER *inPtr, THERAHEADER *outPtr, int direction);
void bitswap_THERAHEADER(THERAHEADER *inPtr, THERAHEADER *outPtr, int direction);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _HERA_TYPES_H_
