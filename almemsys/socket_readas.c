
#include<stdio.h>
#include<fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "almemsys.h"

// #define SOCKET_READBUG

int socket_readas(int sk, char * readdata, int max, int interval, int mode){
int ret, stat;
char cha[64];

struct timeval tv;
int retval;
fd_set rfds;

tv.tv_sec = interval;
tv.tv_usec = 0;


memset(cha, 0x00, 64);

ret = 0;
stat = 0;

while(1){
   FD_ZERO(&rfds);
   FD_SET(sk, &rfds);

   retval = select(sk + 1, &rfds, NULL, NULL, &tv);

   if(retval < 0){
      #ifdef SOCKET_READBUG
      printf("SOCKET: socket_read(2): NG select <%d> ERRNO: %d %s\n",
        retval, errno, strerror(errno));
      #endif
      ret = -1;
      break;
      }
   if(retval == 0){
      #ifdef SOCKET_READBUG
      printf("SOCKET: socket_read(3): NG select. time out break <%d> ERRNO: %d %s\n",
        retval, errno, strerror(errno));
      #endif
      ret = -1;
      break;
      }
   if(retval >= 1){

      stat = read(sk, cha, 32);

      #ifdef SOCKET_READBUG
      printf("stat = %d string = %s front_char = %02x %02x %02x %02x\n", stat, cha, cha[0], cha[1], cha[2], cha[3]);
      printf("rear_char = %02x %02x %02x\n",cha[stat -2], cha[stat -1], cha[stat]);
      #endif

      if(stat < 0){
         #ifdef SOCKET_READBUG
         printf("BREAK stat==0\n");
         #endif
         break;
         }

      if(stat == 0 && cha[0] == 0x00 && cha[1] == 0x00){
         #ifdef SOCKET_READBUG
         printf("BREAK stat==0 cha0=00 cha1=00\n");
         #endif
         break;
         }

      if(stat == 1 && cha[0] == 0x0a && cha[1] == 0x00){
         #ifdef SOCKET_READBUG
         printf("BREAK stat==1 cha0=0a cha1=00\n");
         #endif
         break;
         }

      if(stat >= 2){
         if(mode == 1){
            if(cha[stat - 1] == 0x0a){
               #ifdef SOCKET_READBUG
               printf("BREAK stat>1 0d [mode 1]\n");
               #endif
               strncat(readdata, cha, stat);
               memset(cha, 0x00, 33);
               ret = ret + stat;
               break;
               }
            }
         if(cha[stat - 2] == 0x0d && cha[stat - 1] == 0x0a){
            #ifdef SOCKET_READBUG
            printf("BREAK stat>1 0d 0a\n");
            #endif
            strncat(readdata, cha, stat);
            memset(cha, 0x00, 33);
            ret = ret + stat;
            break;
            }
         else{
            strncat(readdata, cha, stat);
            memset(cha, 0x00, 33);
            ret = ret + stat;
            if(ret > max - 32){
               fprintf(stderr, "socket_reada(): read size err.\n");
               break;
               }
            }

         }
      }
   } // while()

return(ret);
}



