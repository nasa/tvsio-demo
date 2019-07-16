/*
**  File: 
**    cfe_es_version.h
**  $Id: cfe_version.h 1.8.2.5 2014/12/02 19:26:21GMT-05:00 sstrege Exp  $
**
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.
**
**  Purpose:
**     Provide version identifiers for the cFE core.
**
**     Version Number Semantics:
**
**     The version number is a sequence of four numbers, generally separated by dots when written. These are, in order,
**     the Major number, the Minor number, the Implementation Revision number, and the Mission Revision number. At
**     their option, Missions may modify the Mission Revision information as needed to suit their needs.
**
**     The Major number shall be incremented to indicate when there is a change to an API. Specifically when the API
**     changes in ways that will cause existing correctly-written cFS components to stop working. It may also be
**     incremented for a release that contains changes deemed to be of similar impact, even if there are no actual
**     changes to the API.  The Major number may increment when there is no breaking change to the API, if the changes
**     are significant enough to warrant the same level of attention as a breaking API change.  The Major number is
**     provided as a simple macro defined in this header file as part of the API definition; this macro must expand
**     to a simple integer value, so that it can be used in simple #if directives by the macro preprocessor.
**
**     The Minor number shall be incremented to indicate the addition of features to the API, which do not break
**     existing code. It may also be incremented for a release that contains changes deemed to be of similar impact,
**     even if there are no actual updates to the API.  The Minor number may increment  when there have been no
**     augmentations to the API, if changes are as significant as additions to the public API.  The Minor number is
**     provided as a simple macro defined in this header file as part of the API definition; this macro must expand
**     to a simple integer value, so that it can be used in simple #if directives by the macro preprocessor.
**
**     The Implementation Revision Version number shall be incremented when updates are made to an implementation that
**     do not have consequences visible to external components. It may also be updated if there are other changes
**     contained within a release that make it desirable for applications to distinguish one release from another.  The
**     Revision number may update in implementations where no actual implementation-specific code has changed, if
**     there are other changes within the release with similar significance.  The Revision number is provided as a
**     simple macro defined in this header file as part of the API definition; this macro must expand to a simple
**     integer value, so that it can be used in simple #if directives by the macro preprocessor.
**
**     The Mission Version number shall be set to zero in all officially released packages, and is entirely reserved
**     for the use of the mission.  The Mission Version is provided as a simple macro defined in the cfe_platform_cfg.h
**     header file.
**
**  References:
**     Flight Software Branch C Coding Standard Version 1.0a
**     cFE Flight Software Application Developers Guide
**
**  Notes:
**
*/

#ifndef _cfe_version_
#define _cfe_version_

/*
 * The "enhanced build" (cmake-driven) instantiates a configuration
 * object that contains extended version information within it.
 *
 * This information is generated automatically by the build using
 * git to determine the most recent tag and commitid.
 *
 * This is only available when compiling with the cmake scripts which
 * is why it is conditionally included.
 */
#ifdef _ENHANCED_BUILD_
#include <target_config.h>
#endif


/*
** Macro Definitions
*/
#define CFE_MAJOR_VERSION         6
#define CFE_MINOR_VERSION         6
#define CFE_REVISION              0


#endif  /* _cfe_version_ */

