cmake_minimum_required(VERSION 2.6.4)
project(SBN_TTE C)

if(NOT(IS_DIRECTORY ${SBN_APP_SOURCE_DIR}))
    message(FATAL_ERROR "SBN_APP_SOURCE_DIR not defined, is sbn in the target list before this module?")
endif()

include_directories(${SBN_APP_SOURCE_DIR}/../inc)

include_directories(${SBN_APP_SOURCE_DIR}/fsw/platform_inc)
include_directories(${SBN_APP_SOURCE_DIR}/fsw/public_inc)
include_directories(${SBN_APP_SOURCE_DIR}/fsw/mission_inc)
include_directories(${SBN_APP_SOURCE_DIR}/fsw/src)
include_directories(${tte_MISSION_DIR}/fsw/public_inc)

aux_source_directory(fsw/src LIB_SRC_FILES)

# Create the app module
add_cfe_app(sbn_tte ${LIB_SRC_FILES})
