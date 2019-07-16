/* Created : Tue Nov 13 07:47:47 CST 2018
   User    : rmcclune
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): HAB_Power_Source1, CCSDS_TLM_HDR, CCSDS_Primary, sim_power_source, HAB_Power_Source2 */

#ifndef _HAB_TYPES_H_
#define _HAB_TYPES_H_

#include "shared_types.h"
///* @file */


#ifdef __cplusplus
extern "C" {
#endif
/** Structure HAB_Power_Source1 (77 bytes in size)  *
* "power source" system generated by the Trick simulation, they only exist virtually (combination of solar array and battery); there are two per element
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  sim_power_source hab_power_source1;         ///< [   16] (61 bytes)  
} HAB_Power_Source1;     ///<  Total size of 77 bytes

/** Structure HAB_Power_Source2 (77 bytes in size)  *
* "power source" system generated by the Trick simulation, they only exist virtually (combination of solar array and battery); there are two per element
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                    ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  sim_power_source hab_power_source2;         ///< [   16] (61 bytes)  
} HAB_Power_Source2;     ///<  Total size of 77 bytes

void byteswap_HAB_Power_Source2(HAB_Power_Source2 *inPtr, HAB_Power_Source2 *outPtr, int direction);
void bitswap_HAB_Power_Source2(HAB_Power_Source2 *inPtr, HAB_Power_Source2 *outPtr, int direction);
void byteswap_HAB_Power_Source1(HAB_Power_Source1 *inPtr, HAB_Power_Source1 *outPtr, int direction);
void bitswap_HAB_Power_Source1(HAB_Power_Source1 *inPtr, HAB_Power_Source1 *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void byteswap_sim_power_source(sim_power_source *inPtr, sim_power_source *outPtr, int direction);
void bitswap_sim_power_source(sim_power_source *inPtr, sim_power_source *outPtr, int direction);


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define SET_HAB_PS1_OUTPUT_CHANNEL_STATE  0x0
#define SET_HAB_PS1_SAR_STATE             0x1
#define SET_HAB_PS2_OUTPUT_CHANNEL_STATE  0x0
#define SET_HAB_PS2_SAR_STATE             0x1

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  SET_HAB_PS1_OUTPUT_CHANNEL_STATE : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t outSTATE;      ///<  Commanded positions for selected channels (outCHANNEL)
 int8_t outCHANNEL;      ///<  Selected Channels for the command (outSTATE); bit 1 = SAR switch; bit 2 = BATT switch; bit 3 = Cross connect switch
}SET_HAB_PS1_OUTPUT_CHANNEL_STATE_t;

/**  SET_HAB_PS1_SAR_STATE : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t sarSTATE;      ///<  Command for SAR (true = ON; false = OFF)
}SET_HAB_PS1_SAR_STATE_t;

/**  SET_HAB_PS2_OUTPUT_CHANNEL_STATE : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t outSTATE;      ///<  Commanded positions for selected channels (outCHANNEL)
 int8_t outCHANNEL;      ///<  Selected Channels for the command (outSTATE); bit 1 = SAR switch; bit 2 = BATT switch; bit 3 = Cross connect switch
}SET_HAB_PS2_OUTPUT_CHANNEL_STATE_t;

/**  SET_HAB_PS2_SAR_STATE : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
 uint8_t sarSTATE;      ///<  Command for SAR (true = ON; false = OFF)
}SET_HAB_PS2_SAR_STATE_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _HAB_TYPES_H_
