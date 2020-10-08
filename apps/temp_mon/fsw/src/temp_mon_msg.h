/*******************************************************************************
**
**      GSC-18128-1, "Core Flight Executive Version 6.7"
**
**      Copyright (c) 2006-2019 United States Government as represented by
**      the Administrator of the National Aeronautics and Space Administration.
**      All Rights Reserved.
**
**      Licensed under the Apache License, Version 2.0 (the "License");
**      you may not use this file except in compliance with the License.
**      You may obtain a copy of the License at
**
**        http://www.apache.org/licenses/LICENSE-2.0
**
**      Unless required by applicable law or agreed to in writing, software
**      distributed under the License is distributed on an "AS IS" BASIS,
**      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**      See the License for the specific language governing permissions and
**      limitations under the License.
**
** File: temp_mon_msg.h
**
** Purpose:
**  Define Temperature Monitor App Messages and info
**
** Notes:
**
**
*******************************************************************************/
#ifndef _temp_mon_msg_h_
#define _temp_mon_msg_h_

/*
** TEMP_MON App command codes
*/
#define TEMP_MON_NOOP_CC                 0
#define TEMP_MON_RESET_COUNTERS_CC       1
#define TEMP_MON_PROCESS_CC              2

/*************************************************************************/

/*
** Type definition (generic "no arguments" command)
*/
typedef struct
{
   uint8    CmdHeader[CFE_SB_CMD_HDR_SIZE];

} TEMP_MON_NoArgsCmd_t;

/*
** The following commands all share the "NoArgs" format
**
** They are each given their own type name matching the command name, which_open_mode
** allows them to change independently in the future without changing the prototype
** of the handler function
*/
typedef TEMP_MON_NoArgsCmd_t      TEMP_MON_Noop_t;
typedef TEMP_MON_NoArgsCmd_t      TEMP_MON_ResetCounters_t;
typedef TEMP_MON_NoArgsCmd_t      TEMP_MON_Process_t;

/*************************************************************************/
/*
** Type definition (Temp Mon App housekeeping)
*/

typedef struct
{
    uint8              CommandErrorCounter;
    uint8              CommandCounter;
    uint8              spare[2];
} TEMP_MON_HkTlm_Payload_t;

typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    TEMP_MON_HkTlm_Payload_t  Payload;

} OS_PACK TEMP_MON_HkTlm_t;

#endif /* _temp_mon_msg_h_ */

/************************/
/*  End of File Comment */
/************************/
