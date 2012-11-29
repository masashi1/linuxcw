// socket_read.c
// $Id: socket_read.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<fcntl.h>
#include <errno.h>
#include <unistd.h>


int socket_read(int sk, char * readdata, int getlen, int interval){
struct timeval tv;
int retval;
int ret;
fd_set rfds;

fcntl(sk, F_SETFL, O_NONBLOCK);
tv.tv_sec = interval;
tv.tv_usec = 0;

#ifdef SOCKET_BUG
printf("SOCKET: socket_read(1): interval time set %d\n", interval);
#endif

ret = 0;

// ret = read(sk, readdata, getlen);

while(1){
   FD_ZERO(&rfds);
   FD_SET(sk, &rfds);
   retval = select(sk + 1, &rfds, NULL, NULL, &tv);
   if(retval < 0){
      #ifdef SOCKET_BUG
      printf("SOCKET: socket_read(2): NG select <%d> ERRNO: %d %s\n",
        retval, errno, strerror(errno));
      #endif
      ret = -1;
      break;
      }
   if(retval == 0){
      #ifdef SOCKET_BUG
      printf("SOCKET: socket_read(3): NG select <%d> ERRNO: %d %s\n",
        retval, errno, strerror(errno));
      #endif
      ret = -1;
      break;
      }
   if(retval >= 1){
      ret = read(sk, readdata, getlen);
      #ifdef SOCKET_BUG
      printf("SOCKET: socket_read(4): NG select <%d> ERRNO: %d %s\n",
        retval, errno, strerror(errno));
      #endif
      break;
      }
   } /* while */


fcntl(sk, F_SETFL, 0);

return(ret);
}



