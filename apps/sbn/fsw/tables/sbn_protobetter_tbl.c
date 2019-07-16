/*
 * sbn_protobetter_tbl.c
 *
 *  Created on: Jun 5, 2018
 *      Author: tbrain
 */

#include "cfe_tbl_filedef.h"
#include "sbn_protobetter_tbldefs.h"

SBN_ProtoBetterEntry_t SBN_ProtoBetterTable[SBN_PROTOBETTER_TABLE_SIZE] =
{
      // Table entry should be Message ID value followed by message structure name.
      // The pack/unpack function names will prepend the structure name with "Pack" and "Unpack"
      // i.e "Foo" will be "PackFoo" and "UnpackFoo"
      // {0x187C, "Foo"},
      {0, ""}
};/* end SBN_RemapTable */

CFE_TBL_FILEDEF(SBN_ProtoBetterTable, SBN.PROTOBETTER_TBL, SBN Protobetter Table,sbn_protobetter_tbl.tbl)


