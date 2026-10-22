cmake_minimum_required(VERSION 3.26)
project(GNC_PROP_APP C)

set(APP_SRC_FILES
    fsw/src/gnc_prop_app.c
)

# Create the app module
add_cfe_app(gnc_prop ${APP_SRC_FILES})

target_include_directories(gnc_prop PUBLIC
    fsw/mission_inc
    fsw/platform_inc
)
