
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in_systm.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netdb.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <errno.h>


// int socket_connect46(struct addrinfo * hints, char * ip, char * port, int * sk);


int socket_connect46(struct addrinfo * hints, char * ip, char * port, int * sk)
{

struct addrinfo *res, *res0;
int ret;
char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
int error;
ret = -1;

hints->ai_socktype = SOCK_STREAM;
// hints->ai_socktype = SOCK_DGRAM;   /* Datagram socket */
hints->ai_flags = AI_PASSIVE;         /* For wildcard IP address */
hints->ai_family = AF_UNSPEC;         /* Allow IPv4 or IPv6 */
hints->ai_protocol = 0;               /* Any protocol */
hints->ai_canonname = NULL;
hints->ai_addr = NULL;
hints->ai_next = NULL;

error = getaddrinfo(ip, port, hints, &res0);
if(error){
   fprintf(stderr, "ERR: %s %s: %s\n", ip, port, gai_strerror(error));
   exit(1);
   }

for(res = res0; res; res = res->ai_next){
   error = getnameinfo(res->ai_addr, res->ai_addrlen, hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV);
   if(error){
      fprintf(stderr,"ERR: %s %s: %s\n", ip, port, gai_strerror(error));
      continue;
      }

   fprintf(stderr,"trying %s port %s\n", hbuf, sbuf);

   * sk = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
   if(* sk < 0){
      fprintf(stderr,"ERR: %d\n", * sk);
      continue;
      }

   if((ret = connect(* sk, res->ai_addr, res->ai_addrlen)) < 0){
      close(* sk);
      * sk = -1;
      continue;
      }
   else{
      return ret;
      }
   }

fprintf(stderr,"ERR: test: no destination to connect to\n");
exit(1);

}




