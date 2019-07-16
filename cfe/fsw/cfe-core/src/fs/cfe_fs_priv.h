/******************************************************************************
** File: cfe_fs_priv.h
**
**      Copyright (c) 2004-2012, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA's Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used,
**      distributed and modified only pursuant to the terms of that agreement.
**
**
**
** Purpose:
**      This header file contains prototypes for private functions and type
**      definitions for FS internal use.
**
** Author:  A. Cudmore/NASA GSFC 
**
**
******************************************************************************/

#ifndef _cfe_fs_priv_
#define _cfe_fs_priv_

/*
** Includes
*/
#include "common_types.h"
#include "cfe_fs.h"
#include "cfe_es.h"

/*
** Macro Definitions
*/


/*
** Type Definitions
*/

/******************************************************************************
**  Typedef: CFE_FS_t 
**
**  Purpose:
**     This structure contains the FS global variables.
*/
typedef struct 
{
    uint32              SharedDataMutexId;

} CFE_FS_t;

/*
** FS Function Prototypes
*/

extern void CFE_FS_LockSharedData(const char *FunctionName );
extern void CFE_FS_UnlockSharedData(const char *FunctionName );
extern void CFE_FS_ByteSwapCFEHeader(CFE_FS_Header_t *Hdr);
extern void CFE_FS_ByteSwapUint32(uint32 *Uint32ToSwapPtr);


#endif /* _cfe_fs_priv_ */
/*****************************************************************************/
