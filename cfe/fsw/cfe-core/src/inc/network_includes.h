/******************************************************************************
** File: network_includes.h
** $Id: network_includes.h 1.3 2009/07/31 10:20:30GMT-05:00 acudmore Exp  $
**
** Purpose:
**   This header file contains the correct set of network include
**   files, which are dependant on the operating system.
**
** Author:   R.McGraw/SSI
**
** Notes:
**
******************************************************************************/

#ifndef _network_includes_
#define _network_includes_

#ifdef _VXWORKS_OS_
    #include <vxWorks.h>
    #include <selectLib.h>
    #include <sockLib.h>
    #include <inetLib.h>
    #include <arpLib.h>
    #include <netinet/in.h>
    #include <netinet/tcp.h>

#elif  _RTEMS_OS_
    #define _USING_RTEMS_INCLUDES_
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <netinet/tcp.h>
    #include <fcntl.h>
    #define _HAVE_FCNTL_
    #ifndef MSG_DONTWAIT
      #define MSG_DONTWAIT 0
    #endif
#elif  _MAC_OS_
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <netinet/tcp.h>
    #include <fcntl.h>
    #define _HAVE_FCNTL_

#elif  _LINUX_OS_
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <netinet/tcp.h>
    #include <fcntl.h>
    #define _HAVE_FCNTL_
    #ifndef MSG_DONTWAIT
      #define MSG_DONTWAIT 0
    #endif

#else
    #error "No OS defined!"
#endif

#endif /* _network_includes_ */
