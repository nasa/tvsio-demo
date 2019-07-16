set(CMAKE_SHARED_LIBRARY_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_CXX_FLAGS "")
set(CMAKE_SHARED_MODULE_C_FLAGS "")
set(CMAKE_SHARED_MODULE_CXX_FLAGS "")
set(CMAKE_SHARED_MODULE_SUFFIX ".so")

set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

#Ensures no -fPIC option for shared libs
set(CMAKE_C_COMPILE_OPTIONS_PIC "")
set(CMAKE_CXX_COMPILE_OPTIONS_PIC "")
set(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS "-r")
set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "-r")

# This indicates where to install target binaries created during the build
set(INSTALL_SUBDIR "cf")

SET(WIND_BASE "$ENV{WIND_BASE}")
# Some upper-level code may be gated on _LINUX_OS_ being defined
set(OSAL_C_FLAGS "${OSAL_C_FLAGS} -DVOLTAB_PATH='\"/ram0/cf\"' -D_VXWORKS_OS_ -D_HAVE_STDINT_ -D_PPC_ -D__PPC__ -D_EMBED_ -DTOOL_FAMILY=gnu -DTOOL=e500v2gnu -D_WRS_KERNEL -DCPU=PPC85XX -DCPU_VARIANT=_ppc85xx_e500v2 \"-D_VSB_CONFIG_FILE=<../lib/h/config/vsbConfig.h>\" -D_EB -DENDIAN=_EB -DSOFTWARE_BIG_BIT_ORDER -mcpu=8548 -te500v2 -mstrict-align -fno-builtin -fvolatile -mhard-float -fno-implicit-fp -mfloat-gprs=double -mspe=yes -mabi=spe -mlongcall")

include_directories($ENV{WIND_BASE}/target/h)
include_directories($ENV{WIND_BASE}/target/h/wrn/coreip)
include_directories($ENV{WIND_BASE}/target/h/drv)
include_directories($ENV{WIND_BASE}/target/src/config)
include_directories($ENV{WIND_BASE}/target/src/drv)
include_directories($ENV{WIND_BASE}/target/config/comps/src)
include_directories($ENV{WIND_BASE}/target/config/comps/src/dosfs2)
