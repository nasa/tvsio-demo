cmake_minimum_required(VERSION 2.6.4)
project(CFS_CI C)

include_directories(fsw/mission_inc)
include_directories(fsw/platform_inc)
include_directories(fsw/src)
include_directories(${io_lib_MISSION_DIR}/fsw/public_inc)
include_directories(${to_MISSION_DIR}/fsw/platform_inc)
include_directories(${to_MISSION_DIR}/fsw/src)

set(CI_TRANSPORT udp)

aux_source_directory(fsw/src APP_SRC_FILES)

# Create the app module
add_cfe_app(ci ${APP_SRC_FILES})
