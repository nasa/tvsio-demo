cmake_minimum_required(VERSION 2.6.4)
project(CFS_TO C)

include_directories(fsw/mission_inc)
include_directories(fsw/platform_inc)
include_directories(fsw/src)
include_directories(${io_lib_MISSION_DIR}/fsw/public_inc)

set(TO_TRANSPORT udp)

aux_source_directory(fsw/src APP_SRC_FILES)

# Create the app module
add_cfe_app(to ${APP_SRC_FILES})

# Create the table object files
include_directories(fsw/tables)

# Add the tables
add_cfe_tables(to fsw/tables/to_config.c)
