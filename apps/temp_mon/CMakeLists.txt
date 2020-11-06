cmake_minimum_required(VERSION 2.6.4)
project(TEMP_MON_APP C)

include_directories(fsw/mission_inc)
include_directories(fsw/platform_inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc) # global 'apps/inc/' directory for CFS mission

aux_source_directory(fsw/src APP_SRC_FILES)

# Create the app module
add_cfe_app(temp_mon ${APP_SRC_FILES})
