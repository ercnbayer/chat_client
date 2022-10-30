#ifndef MD_BASE_H
#define MD_BASE_H

#pragma pack(1) //Calculate struct sizeof aligment settings

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>  /* ipv6 */
    #include <mswsock.h>
    #include <shellapi.h>
    #include <stddef.h>    /* offsetof() */
#endif

#include <sys/types.h>
#include <sys/socket.h>
       #include <netinet/in.h>
       #include <netinet/ip.h>
#include <sys/stat.h>
#include <stdio.h>
#include <curses.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <map>
#include <errno.h>
#include <inttypes.h>
#include <time.h>
#include <linux/socket.h>
#include <linux/if.h>

#include <arpa/inet.h>








/*types base structures*/






#endif


