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


/*--------------------- ACCEPT -------------------*/
int socket_accept(struct sockaddr_in * my_addr, int *ls, int *sk)
{
static int ret;

unsigned int my_addrlen = sizeof(* my_addr);

ret = -1;
if((*sk = accept(*ls, (struct sockaddr *) my_addr, &my_addrlen)) < 0){
   fprintf(stderr,"socket_accept(): not scception ERRNO: %d %s\n", errno, strerror(errno));
   close(*ls);
   ret = -1;
   return(ret);
   exit(1);
   }
else {
   ret = 0;
   return(ret);
   }
return(ret);
}





