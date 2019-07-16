cmake_minimum_required(VERSION 2.6.4)
project(SBN_APP C)

# workaround until these definitions are exposed by cfe_sb
include_directories(${CFECORE_SOURCE_DIR}/src/sb)
include_directories(fsw/public_inc)
include_directories(fsw/platform_inc)
include_directories(fsw/mission_inc)
include_directories(modules/udp/fsw/src)
include_directories(fsw/src)
include_directories(../inc)
include_directories(${MISSION_SOURCE_DIR})

#include the udp module CMakeLists - this is all that is needed to generate the sbn_udp.so file
include("./modules/udp/CMakeLists.txt")

execute_process(
    COMMAND grep CFE_SB_SubRprtMsg_Payload_t ${CFECORE_SOURCE_DIR}/src/inc/cfe_sb_msg.h
    RESULT_VARIABLE subrprtpayload
)

#if(NOT(${subrprtpayload}))
    add_definitions(-DSBN_PAYLOAD=Payload.PacketID.)
#else()
#    add_definitions(-DSBN_PAYLOAD=PacketID.)
#endif()

aux_source_directory(fsw/src APP_SRC_FILES)
aux_source_directory(fsw/tables APP_SRC_FILES)
aux_source_directory(modules/udp/fsw/src APP_SRC_FILES)



# Create the app module
add_cfe_app(sbn ${APP_SRC_FILES})

if (COMMAND add_cfe_tables)
    aux_source_directory(fsw/tables APP_TBL_FILES)
    add_cfe_tables(sbn ${APP_TBL_FILES})
    #add_cfe_tables(sbn fsw/tables/sbn_protobetter_tbl.c fsw/tables/sbn_remap_tbl.c)
    #add_cfe_tables(sbn fsw/tables/sbn_remap_tbl.c)
endif(COMMAND add_cfe_tables)
