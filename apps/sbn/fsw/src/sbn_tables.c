#include "sbn_app.h"

int32 SBN_RemapTableValidation(void *TblPtr)
{
    SBN_RemapTable_t *r = (SBN_RemapTable_t *)TblPtr;
    int i = 0, j = 0;

    switch(r->RemapDefaultFlag)
    {
        /* all valid values */
        case SBN_REMAP_DEFAULT_IGNORE:
        case SBN_REMAP_DEFAULT_SEND:
            break;
        /* otherwise, unknown! */
        default:
            return 2;
    }/* end switch */

    // Perform insertion sort by processorID, then MsgID.
   for ( i = 0; i < SBN_REMAP_TABLE_SIZE; ++i )
   {
      if ( r->Entry[i].from == 0x0000 )
      {
         break;
      }
      SBN.RemapCache.EntryIdx[i] = i;
      if ( r->RemapDefaultFlag == SBN_REMAP_DEFAULT_IGNORE )
      {
         SBN.RemapCache.MapValue[i] = r->Entry[i].from;
      }
      else
      {
         SBN.RemapCache.MapValue[i] = r->Entry[i].ProcessorID;
         SBN.RemapCache.MapValue[i] = SBN.RemapCache.MapValue[i] << 40;
         SBN.RemapCache.MapValue[i] += r->Entry[i].from;
      }
   }
   SBN.RemapCache.numEntries = i;

    uint64 tmpHash;
    uint32 tmpIdx;
    for ( i = 1; i < SBN.RemapCache.numEntries; ++i )
    {
       j = i;
       tmpHash = SBN.RemapCache.MapValue[i];
       tmpIdx = SBN.RemapCache.EntryIdx[i];
       while ( ( j > 0 ) && ( SBN.RemapCache.MapValue[j - 1] > tmpHash ) )
       {
          SBN.RemapCache.MapValue[j] = SBN.RemapCache.MapValue[j - 1];
          SBN.RemapCache.EntryIdx[j] = SBN.RemapCache.EntryIdx[j - 1];
          --j;
       }
       SBN.RemapCache.MapValue[j] = tmpHash;
       SBN.RemapCache.EntryIdx[j] = tmpIdx;
    }

    /* Ensure the entries are sorted and unique,
     * we use a binary search per MID to find
     * the match. Note also this will catch any "from" values that are 0.
     */
    for(i = 0; i < SBN.RemapCache.numEntries; i++)
    {
        if(i > 0 && (SBN.RemapCache.MapValue[i -1 ] >= SBN.RemapCache.MapValue[i]))
        {
            /* entries are not sorted and/or not unique */
            return 4;
        }/* end if */
    }/* end for */

    return CFE_SUCCESS;
}/* end SBN_RemapTableValidation */

int32 SBN_ProtobetterTableValidation( void *TblPtr )
{
   SBN_ProtoBetterEntry_t * tbl = ( SBN_ProtoBetterEntry_t * ) TblPtr;
   size_t ii;

   SBN.ProtoCache.numEntries = 0;
   for ( ii = 0; ii < SBN_PROTOBETTER_TABLE_SIZE; ++ii, ++SBN.ProtoCache.numEntries )
   {
      size_t structNameLen = strlen( tbl[ii].StructName );
      if ( structNameLen == 0 )
      {
         break;
      }
      else
      {
         char funcName[SBN_MAXIMUM_STRUCT_NAME + 15];
         sprintf(funcName, "Pack%s", tbl[ii].StructName);
         int32 ret;
         ret = OS_SymbolLookup( (cpuaddr *)&SBN.ProtoCache.entries[ii].PackFuncPtr, funcName );
         if ( ret != OS_SUCCESS )
         {
            CFE_EVS_SendEvent( SBN_INIT_EID, CFE_EVS_ERROR, "Protobetter table error with symbol lookup, %s",
                               funcName );
            return ret;
         }
         sprintf(funcName, "Unpack%s", tbl[ii].StructName);
         ret = OS_SymbolLookup( (cpuaddr *)&SBN.ProtoCache.entries[ii].UnpackFuncPtr, funcName );
         if ( ret != OS_SUCCESS )
         {
            CFE_EVS_SendEvent( SBN_INIT_EID, CFE_EVS_ERROR, "Protobetter table error with symbol lookup, %s",
                               funcName );
            return ret;
         }
         SBN.ProtoCache.entries[ii].EntryIdx = ii;
      }
   }

   // Perform insertion sort by MsgID.
   SBN_ProtoBetterCache_Entry_t temp;
   for ( ii = 1; ii < SBN.ProtoCache.numEntries; ++ii )
   {
      int jj = ii;
      memcpy(&temp, &SBN.ProtoCache.entries[ii], sizeof(SBN_ProtoBetterCache_Entry_t));
      while ( ( jj > 0 ) && ( tbl[SBN.ProtoCache.entries[jj - 1].EntryIdx].mid > tbl[temp.EntryIdx].mid) )
      {
         memcpy(&SBN.ProtoCache.entries[jj], &SBN.ProtoCache.entries[jj-1], sizeof(SBN_ProtoBetterCache_Entry_t));
         --jj;
      }
      memcpy(&SBN.ProtoCache.entries[jj], &temp, sizeof(SBN_ProtoBetterCache_Entry_t));
   }

   for ( ii = 0; ii < SBN.ProtoCache.numEntries; ii++ )
   {
      if ( ii > 0
            && ( tbl[SBN.ProtoCache.entries[ii - 1].EntryIdx].mid
                  >= tbl[SBN.ProtoCache.entries[ii].EntryIdx].mid ) )
      {
         /* entries are not sorted and/or not unique */
         return 4;
      }/* end if */
   }/* end for */

   return CFE_SUCCESS;
}

int32 SBN_LoadTables()
{
    int32 Status = CFE_SUCCESS;
   SBN.RemapTableHandle = CFE_TBL_BAD_TABLE_HANDLE;
   SBN.RemapTable = 0x0;
   SBN.ProtobetterTableHandle = CFE_TBL_BAD_TABLE_HANDLE;
   SBN.ProtoBetterTable = 0x0;

    Status = CFE_TBL_Register(&SBN.RemapTableHandle, SBN_REMAP_TABLE_NAME,
        sizeof(SBN_RemapTable_t), CFE_TBL_OPT_DEFAULT,
        &SBN_RemapTableValidation);
    if(Status != CFE_SUCCESS)
    {
      CFE_EVS_SendEvent(SBN_INIT_EID, CFE_EVS_ERROR,
                "SBN failed to register remap table handle.");
        return Status;
    }/* end if */

    //Status = CFE_TBL_Register(&SBN.ProtobetterTableHandle, SBN_PROTOBETTER_TABLE_NAME,
    //    sizeof(SBN_ProtoBetterEntry_t)*SBN_PROTOBETTER_TABLE_SIZE, CFE_TBL_OPT_DEFAULT,
    //   &SBN_ProtobetterTableValidation);
    //if(Status != CFE_SUCCESS)
    //{
    //   CFE_EVS_SendEvent(SBN_INIT_EID, CFE_EVS_ERROR,
    //            "SBN failed to register Protobetter table handle.");
    //    return Status;
    //}/* end if */

    Status = CFE_TBL_Load(SBN.RemapTableHandle, CFE_TBL_SRC_FILE,
                          (const void *) SBN_REMAP_FILENAME);
    if(Status != CFE_SUCCESS)
    {
      CFE_EVS_SendEvent(SBN_INIT_EID, CFE_EVS_ERROR,
                "SBN failed to load Remap table handle.");
        return Status;
    }/* end if */

    //Status = CFE_TBL_Load(SBN.ProtobetterTableHandle, CFE_TBL_SRC_FILE,
    //                      (const void *) SBN_PROTOBETTER_FILENAME);
    //if(Status != CFE_SUCCESS)
    //{
    //  CFE_EVS_SendEvent(SBN_INIT_EID, CFE_EVS_ERROR,
    //            "SBN failed to load Protobetter table handle.");
    //    return Status;
    //}/* end if */


    CFE_TBL_Manage(SBN.RemapTableHandle);
    //CFE_TBL_Manage(SBN.ProtobetterTableHandle);

    Status = CFE_TBL_GetAddress((void **)&SBN.RemapTable, SBN.RemapTableHandle);

    if (Status > CFE_SUCCESS)
    {
        /*
        ** Change warning results to indicate "success"
        */
       Status = CFE_SUCCESS;
    }

    /*
    ** Repeat the process for the message table
    */
    //if (Status == CFE_SUCCESS)
    //{
    //   Status = CFE_TBL_GetAddress((void *)&SBN.ProtoBetterTable,
    //                               SBN.ProtobetterTableHandle);
    //    if (Status > CFE_SUCCESS)
    //    {
    //       Status = CFE_SUCCESS;
    //    }
    //}

    return Status;

}/* end SBN_RegisterTables */
