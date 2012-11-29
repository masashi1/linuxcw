// socket_send.c
// $Id: socket_send.c,v 1.3 2007/11/01 06:11:01 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
// #include <sys/types.h>
#include <sys/socket.h>

#include"almemsys.h"


// int socket_send(int, char *, int);


/*--------------------- SEND ------------------------- */
int socket_send(int sk, char * senddata, int interval){
int ret;
struct timeval tv;
int retval, flag;
fd_set rfds;

// 非同期開始
flag=fcntl(sk, F_GETFL, 0);
fcntl(sk, F_SETFL, flag|O_NONBLOCK);

tv.tv_sec = interval;
tv.tv_usec = 0;

#ifdef SOCKET_SENDBUG
printf("SOCKET_SENDBUG: socket_send(1): interval time set %d \n", interval);
#endif

ret = 0;

ret = send(sk, senddata, (int)strlen(senddata), 0);

FD_ZERO(&rfds);
FD_SET(sk, &rfds);
retval = select(sk + 1, &rfds, NULL, NULL, &tv);
switch(retval){
   case -1:
            #ifdef SOCKET_SENDBUG
            printf("SOCKET: socket_send(2): NG select <%d> ERRNO: %d %s\n",
              retval, errno, strerror(errno));
            #endif
            ret = -1;
            break;
   case 0:
            #ifdef SOCKET_SENDBUG
            printf("SOCKET: socket_send(3): NG select <%d> ERRNO: %d %s\n",
              retval, errno, strerror(errno));
            #endif
            ret = -1;
            break;
   default:
            #ifdef SOCKET_SENDBUG
            printf("SOCKET: socket_send(4): NG select <%d> ERRNO: %d %s\n",
              retval, errno, strerror(errno));
            #endif
            #ifdef SEND_RECV_BUG
            printf("SEND <<%s", senddata);
            #endif
            break;
   } // switch

fcntl(sk, F_SETFL, flag);

#ifdef SOCKET_SENDBUG
printf("SOCKET_SENDBUG: socket_send(5L): SEND DATA SIZE=%d DATA=<%s>\n",(int)strlen(senddata),senddata);
#endif

return(ret);
}





