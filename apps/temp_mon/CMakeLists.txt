cmake_minimum_required(VERSION 3.26)
project(TEMP_MON_APP C)

set(APP_SRC_FILES
    fsw/src/temp_mon_app.c
)

# Create the app module
add_cfe_app(temp_mon ${APP_SRC_FILES})

target_include_directories(temp_mon PUBLIC
    fsw/mission_inc
    fsw/platform_inc
)
