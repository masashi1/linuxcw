
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>

#include"almemsys.h"

// proto type
// int socket_accept46(struct sockaddr_storage * from, fd_set rfd0, int * s, int smax, int sockmax);


char * socket_accept46(char * ipdata, fd_set rfd, int * s, int smax, int sockmax, int * sk, int * net)
{
struct sockaddr_storage from;
struct sockaddr_in * sin;
struct sockaddr_in6 * sin6;
char bu[256];
char * buf = bu;

int loopcount, n, i;
// fd_set rfd;
socklen_t fromlen;
* net = 0;
loopcount = 24;

memset(&from, 0, sizeof(from));

// rfd = * rfd0;

n = select(sockmax + 1, &rfd, NULL, NULL, NULL);


if(n < 0){
   perror("select");
   return ipdata;
   }
for(i = 0; i < smax; i++){
   if(FD_ISSET(s[i], &rfd)){

      fromlen = sizeof(from);
      * sk = accept(s[i], (struct sockaddr *)&from, &fromlen);

      if(from.ss_family == AF_INET){
         sin = (struct sockaddr_in *)&from;
         * net = 4;
         ipdata = safe_memcpy(ipdata, (char *)inet_ntop(AF_INET, &(sin->sin_addr), buf, 256), BUF_LEN);
         }
      else if(from.ss_family == AF_INET6){
         sin6 = (struct sockaddr_in6 *)&from;
         * net = 6;
         ipdata = safe_memcpy(ipdata, (char *)inet_ntop(AF_INET6, &(sin6->sin6_addr), buf, 256), BUF_LEN);
         }
      else{
         * net = 0;
         printf("not accepted connection fer v6 or v4\n");
         }

      fprintf(stderr,"accept to %d , %d\n", * sk,  s[i]);

      if(* sk < 0){
         loopcount= loopcount - 1;
         if(loopcount == 0){
            exit(1);
            }
         continue;
         }
      else{
         loopcount = 24;
         }
      }
   }

return ipdata;
}



 
