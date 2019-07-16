/*
 * sbn_protobetter_tbldefs.h
 *
 *  Created on: Jun 4, 2018
 *      Author: tbrain
 */

#ifndef CFS_APPS_SBN_FSW_SRC_SBN_PROTOBETTER_TBLDEFS_H_
#define CFS_APPS_SBN_FSW_SRC_SBN_PROTOBETTER_TBLDEFS_H_

#include "cfe.h"
#include "sbn_platform_cfg.h"

#define SBN_MAXIMUM_STRUCT_NAME 40

typedef struct
{
   CFE_SB_MsgId_t mid;
   char StructName[SBN_MAXIMUM_STRUCT_NAME];

} SBN_ProtoBetterEntry_t;

#endif /* CFS_APPS_SBN_FSW_SRC_SBN_PROTOBETTER_TBLDEFS_H_ */
