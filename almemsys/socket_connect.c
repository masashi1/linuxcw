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



/*----------------------- CONNECT --------------------*/
int socket_connect(struct sockaddr_in * my_addr, int port, char ip_addr[], int *sk)
{
int ret;

ret = 0;
if((* sk = socket(AF_INET, SOCK_STREAM, 0))==-1){
   fprintf(stderr,"socket_connect(): Not cleate socket\n");
   ret = -1;
   return(ret);
   }

my_addr->sin_family = AF_INET;
my_addr->sin_port = htons(port);
my_addr->sin_addr.s_addr = inet_addr(ip_addr);

if(connect(*sk, (struct sockaddr *) my_addr, sizeof(* my_addr)) == -1){
   fprintf(stderr,"socket_connect(): Not connection\n");
   close(*sk);
   ret = -1;
   return(ret);
   }

return(ret);
}







