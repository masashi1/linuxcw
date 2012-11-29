// tcp.c
// $Id: tcp.c,v 1.3 2007/11/01 05:57:06 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in_systm.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include <errno.h>



/*------------------ BIND ----------------------*/
int socket_bind(struct sockaddr_in * my_addr, int port, char ip_addr[], int *ls)
{
int ret;
ret = 0;

if((*ls = socket(AF_INET, SOCK_STREAM, 0))==-1){
   fprintf(stderr,"socket_bind(1): Not cleate socket\n");
   return ret;
   }

my_addr->sin_family = AF_INET;
my_addr->sin_port = htons(port);
/* my_addr->sin_addr.s_addr = inet_addr(ip_addr); */
if(0 == memcmp(ip_addr, "INADDR_ANY", 10)){
   my_addr->sin_addr.s_addr = INADDR_ANY;
   }
else{
   my_addr->sin_addr.s_addr = inet_addr(ip_addr);
   }

if(bind(*ls, (struct sockaddr *) my_addr, sizeof(* my_addr)) == -1){
   fprintf(stderr,"socket_bind(2): Not cleate bind\n");
   close(*ls);
   return ret;
   }

if((listen(*ls,0))==-1){
   fprintf(stderr,"socket_bind(3): Not listen port\n");
   close(*ls);
   return ret;
   }

return ret;
}





