PROC $SC_$CPU_sb_64ksend
;**********************************************************************
;  Test Name:  sb_64ksend
;  Test Level: Build Verification
;  Test Type:  Functional
;
;  Test Description
;	This scenario verifies that the flight software will handle messages
;       up to 64K bytes.
;
;  Requirements Tested
;
;  Prerequisite Conditions
;	Open event log and telemetry archive files.
;
;  Assumptions and Constraints
;	The CFE_MISSION_SB_MAX_SB_MSG_SIZE macro is set to 64K.
;
;  Change History
;
;	Date		   Name		Description
;	01/05/10	Walt Moleski	Original procedure
;	10/26/17	Walt Moleski	Updated for cFE 6.6
;
;  Arguments
;
;	Name			Description
;	None	
;
;  Procedures Called
;
;	Name			Description
;       ut_tlmwait      Wait for a specified telemetry point to update to
;                       a specified value. 
;       ut_sendcmd      Send commands to the spacecraft. Verifies command
;                       processed and command error counters.
;       ut_sendrawcmd   Send raw commands to the spacecraft. Verifies command
;                       processed and command error counters.
;       ut_pfindicate   Print the pass fail status of a particular requirement
;                       number.
;       ut_setupevt     Performs setup to verify that a particular event
;                       message was received by ASIST.
;
;  Expected Test Results and Analysis
;	This proc should run to completion with no unexpected errors.
;       There is no stopping for manual inputs.
;       The proc is straight-forward. Manual analysis is not needed.
;
;**********************************************************************
;  Define variables
;**********************************************************************

#include "ut_statusdefs.h"
#include "ut_cfe_info.h"
#include "cfe_mission_cfg.h"
#include "cfe_sb_events.h"

;**********************************************************************
; Set the local values
;**********************************************************************
LOCAL rawcmd
LOCAL i
LOCAL cmdSize

write ";**********************************************************************"
write ";  Step 1.0: Send a raw command with a too big packet size of "
write ";  CFE_MISSION_SB_MAX_SB_MSG_SIZE bytes + 1 (= 65537 bytes). "
write ";  65537 bytes - 7 bytes =  65530 bytes = x'FFFA' "
write ";**********************************************************************"
ut_setupevt "$SC", "$CPU", "CFE_SB", CFE_SB_MSG_TOO_BIG_EID, "ERROR"

cmdSize = CFE_MISSION_SB_MAX_SB_MSG_SIZE - 6
write "Setting cmdSize to ", cmdSize
rawcmd = "18"&%hex($CPU_CMDAPID_BASE + SB_CMDAPID_OFF, 2)&"C000"&%hex(cmdSize,4) 
rawcmd = rawcmd & "05000000"    ; 4 bytes

Ut_sendrawcmd "$SC_$CPU_SB", {rawcmd}

;  Look for the event message
if ($SC_$CPU_num_found_messages > 0) then
   write "<*> Passed - Event Msg ",$SC_$CPU_find_event[1].eventid," rcv'd!!!" 
else
   write "<!> Failed - Event Message not received for Too large packet size command."
   write "<!> Too large packet size test failed."
endif

wait 5

write ";**********************************************************************"
write ";  Step 2.0: Send a raw command with a packet size of "
write ";  CFE_MISSION_SB_MAX_SB_MSG_SIZE bytes (= 65536 bytes). "
write ";  65536 bytes - 7 bytes = 65529 bytes = x'FFF9' "
write ";  This step should pass since the MAX size is a valid length "
write ";**********************************************************************"

cmdSize = CFE_MISSION_SB_MAX_SB_MSG_SIZE - 7
write "Setting cmdSize to ", cmdSize
rawcmd = "18"&%hex($CPU_CMDAPID_BASE + SB_CMDAPID_OFF, 2)&"C000"&%hex(cmdSize,4) 
rawcmd = rawcmd & "00010005"    ; 4 bytes

Ut_sendrawcmd "$SC_$CPU_SB", {rawcmd}

;  Look for the event message
if (ut_rcs_status = UT_RCS_Success) then
   Write "<*> Passed (4701) - Command with ",cmdSize," sent successfully" 
else
   Write "<!> Failed (4701) - Max packet size command test failed."
endif

wait 10

write ";**********************************************************************"
write ";  End procedure $SC_$CPU_sb_64ksend                                  "
write ";**********************************************************************"
ENDPROC
