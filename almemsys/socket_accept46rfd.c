
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


// proto type
// int socket_accept46rfd(fd_set * rfd, int * s, int smax);

int socket_accept46rfd(fd_set * rfd, int * s, int smax)
{
int i;

FD_ZERO(rfd);
for(i = 0; i < smax; i++){
   FD_SET(s[i], rfd);
   }

return 0;
}




 
