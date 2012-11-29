// socket_sends.c
// $Id: socket_sends.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>


int socket_sends(int sk, char * senddata, int interval, char mode){
static int ret;
struct timeval tv;
int retval;
fd_set rfds;

fcntl(sk, F_SETFL, O_NONBLOCK);
tv.tv_sec = interval;
tv.tv_usec = 0;

if(mode > 1 || mode < 0){
   mode = 0;
   }

#ifdef SOCKET_SENDBUG
printf("SOCKET: socket_send(1): interval time set %d \n", interval);
#endif

ret = 0;

ret = send(sk, senddata, (int)strlen(senddata), 0);

while(1){
   FD_ZERO(&rfds);
   FD_SET(sk, &rfds);
   retval = select(sk + 1, &rfds, NULL, NULL, &tv);
   if(retval < 0){
      #ifdef SOCKET_SENDBUG
      printf("SOCKET: socket_send(2): NG select <%d> ERRNO: %d %s\n",
        retval, errno, strerror(errno));
      #endif
      ret = -1;
      break;      }
   if(retval == 0){
      #ifdef SOCKET_SENDBUG
      printf("SOCKET: socket_send(3): NG select <%d> ERRNO: %d %s ret=%d\n",
        retval, errno, strerror(errno), ret);
      #endif
      if(mode == 0){
         ret = -1; 
         }
      break;
      }
   if(retval >= 1){
      #ifdef SOCKET_SENDBUG
      printf("SOCKET: socket_send(4): NG select <%d> ERRNO: %d %s ret=%d\n",
        retval, errno, strerror(errno), ret);
      #endif
      break;
      }
   } /* while */


fcntl(sk, F_SETFL, 0);

return(ret);
}




