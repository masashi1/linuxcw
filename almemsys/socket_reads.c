// socket_read.c
// $Id: socket_reads.c,v 1.1 2007/10/17 10:57:56 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<fcntl.h>
#include <errno.h>
#include <unistd.h>


int socket_reads(int sk, char * readdata, int getlen, int interval){
struct timeval tv;
int retval;
int ret;
fd_set rfds;

tv.tv_sec = interval;
tv.tv_usec = 0;

#ifdef SOCKET_BUG
printf("SOCKET: socket_read(1): interval time set %d\n", interval);
#endif

ret = 0;

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

return(ret);
}



