# This indicates where to install target binaries created during the build
set(INSTALL_SUBDIR "cf")

message("WIND_BASE IS $ENV{WIND_BASE}")

SET(WIND_BASE "$ENV{WIND_BASE}")
include_directories(${WIND_BASE}/target/h)
include_directories(${WIND_BASE}/target/h/wrn/coreip)
include_directories(${WIND_BASE}/target/h/drv)
include_directories(${WIND_BASE}/target/src/config)
include_directories(${WIND_BASE}/target/src/drv)
include_directories(${WIND_BASE}/target/config/comps/src)
include_directories(${WIND_BASE}/target/config/comps/src/dosfs2)
include_directories(${WIND_BASE}/target/lib/h/config)

set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
  
set(ENDIAN_DEFS "-D_EB -DENDIAN=_EB -DSOFTWARE_BIG_BIT_ORDER")
set(TARGET_DEFS "-D_VXWORKS_OS_ -D_PPC_ -D__PPC__ -DMCP750 -D_EMBED_ -D_HAVE_STDINT_ -DTOOL_FAMILY=gnu -DTOOL=gnu -DCPU=PPC604 -D_WRS_KERNEL")
set(COMPILE_FLAGS "-m32 -mcpu=604 -mstrict-align -fno-builtin")
set(LINK_FLAGS "-nostdlib")
set(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS "-r")
set(CMAKE_C_COMPILE_OPTIONS_PIC "")
set(CMAKE_CXX_COMPILE_OPTIONS_PIC "")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "-rdynamic")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "-rdynamic")

set(OSAL_C_FLAGS "${OSAL_C_FLAGS} ${COMPILE_FLAGS} ${ENDIAN_DEFS} ${ARCH_OPTS} ${TARGET_DEFS}")
