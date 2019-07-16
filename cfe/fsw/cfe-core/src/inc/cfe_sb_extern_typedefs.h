/*
 *      Copyright (c) 2004-2017, United States government as represented by the 
 *      administrator of the National Aeronautics Space Administration.  
 *      All rights reserved. This software(cFE) was created at NASA's Goddard 
 *      Space Flight Center pursuant to government contracts.
 *
 *      This is governed by the NASA Open Source Agreement and may be used,
 *      distributed and modified only pursuant to the terms of that agreement. 
 */

#ifndef _CFE_SB_EXTERN_TYPEDEFS_H_
#define _CFE_SB_EXTERN_TYPEDEFS_H_

/* This header may be generated from an EDS file, 
 * tools are available and the feature is enabled */
#ifdef CFE_EDS_ENABLED_BUILD

/* Use the EDS generated version of these types */
#include "cfe_sb_eds_typedefs.h"

#else
/* Use the local definitions of these types */

#include "common_types.h"
#include "cfe_mission_cfg.h"

/**
 * @brief Label definitions associated with CFE_SB_QosPriority_Enum_t
 */
enum CFE_SB_QosPriority
{

   /**
    * @brief Normal priority level
    */
   CFE_SB_QosPriority_LOW                             = 0,

   /**
    * @brief High priority
    */
   CFE_SB_QosPriority_HIGH                            = 1
};

/**
 * @brief Selects the priorty level for message routing
 *
 *
 * @sa enum CFE_SB_QosPriority
 */
typedef uint8                                            CFE_SB_QosPriority_Enum_t;


/**
 * @brief Label definitions associated with CFE_SB_QosReliability_Enum_t
 */
enum CFE_SB_QosReliability
{

   /**
    * @brief Normal (best-effort) reliability
    */
   CFE_SB_QosReliability_LOW                          = 0,

   /**
    * @brief High reliability
    */
   CFE_SB_QosReliability_HIGH                         = 1
};

/**
 * @brief Selects the reliability level for message routing
 *
 *
 * @sa enum CFE_SB_QosReliability
 */
typedef uint8                                            CFE_SB_QosReliability_Enum_t;

/**
 * @brief An integer type that should be used for indexing into the Routing Table
 */
typedef uint16  CFE_SB_MsgRouteIdx_Atom_t;

/**
 * @brief  CFE_SB_MsgId_Atom_t primitive type definition
 *
 * This is an integer type capable of holding any Message ID value
 */
#ifdef MESSAGE_FORMAT_IS_CCSDS_VER_2
typedef uint32 CFE_SB_MsgId_Atom_t;
#else
typedef uint16 CFE_SB_MsgId_Atom_t;
#endif

/**
 * @brief  CFE_SB_MsgId_t type definition
 *
 * Software Bus message identifier used in many SB APIs
 *
 * Currently this is directly mapped to the underlying holding type (not wrapped) for
 * compatibility with existing usage semantics in apps (mainly switch/case statements)
 *
 * @note In a future version it could become a type-safe wrapper similar to the route index,
 * to avoid message IDs getting mixed between other integer values.
 */
typedef CFE_SB_MsgId_Atom_t CFE_SB_MsgId_t;

#endif /* CFE_EDS_ENABLED_BUILD */

#endif /* _CFE_SB_EXTERN_TYPEDEFS_H_ */

