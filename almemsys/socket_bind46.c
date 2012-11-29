
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
// int socket_bind46(struct addrinfo * hints, char * addr, char * port, int * ls, int maxsock);

int socket_bind46(struct addrinfo * hints, char * addr, char * port, int * ls, int maxsock)
{

struct addrinfo *res, *res0;
int error;
int smax;
int sockmax;
// int co;
char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];

#ifdef IPV6_V6ONLY
const int on = 1;
#endif

//for(co = 0; co < maxsock; co++){
//  ls[co] = 0;
//  }

hints->ai_socktype = SOCK_STREAM;
// hints->ai_socktype = SOCK_DGRAM;   /* Datagram socket */
hints->ai_flags = AI_PASSIVE;         /* For wildcard IP address */
hints->ai_family = AF_UNSPEC;         /* Allow IPv4 or IPv6 */
hints->ai_protocol = 0;               /* Any protocol */
hints->ai_canonname = NULL;
hints->ai_addr = NULL;
hints->ai_next = NULL;

error = getaddrinfo(addr, port, hints, &res0);
if(error){
   fprintf(stderr,"%s : %s: %s\n", addr, port, gai_strerror(error));
   return -1;
   }

smax = 0;
sockmax = -1;
for(res = res0; res && smax < maxsock; res = res->ai_next){
   ls[smax] = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
   if(ls[smax] < 0){
      continue;
      }
   if(ls[smax] >= FD_SETSIZE){
      close(ls[smax]);
      ls[smax] = -1;
      continue;
      }
#ifdef IPV6_V6ONLY
   if(res->ai_family == AF_INET6 && setsockopt(ls[smax], IPPROTO_IPV6, IPV6_V6ONLY, &on, sizeof(on)) < 0){
      perror("setsockopt");
      ls[smax] = -1;
      continue;
      }
#endif
   if(bind(ls[smax], res->ai_addr, res->ai_addrlen) < 0){
      close(ls[smax]);
      ls[smax] = -1;
      continue;
      }
   if(listen(ls[smax], 5) < 0){
      close(ls[smax]);
      ls[smax] = -1;
      continue;
      }
   error = getnameinfo(res->ai_addr, res->ai_addrlen, hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV);
   if(error){
      fprintf(stderr,"test: %s\n", gai_strerror(error));
      return -1;
      }
   fprintf(stderr,"listen to %s %s %d\n", hbuf, sbuf, ls[smax]);
   if(ls[smax] > sockmax){
      sockmax = ls[smax];
      smax++;
      }
   } /* */

return smax;
}



 
