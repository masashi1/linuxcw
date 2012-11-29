
#include<stdio.h>
#include<fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "almemsys.h"

int socket_reada(int sk, char * readdata, int max){
int ret, stat, count;
char cha[64];

memset(cha, 0x00, 64);

ret = 0;
stat = 0;
count = 0;

while(1){

   stat = read(sk, cha, 63);

   if(stat <= 0){
      if(readdata[ret-1] == '\r' || readdata[ret-1] == '\n'){
         break;
         }
      else{
         if(count > 2){
            break;
            }
         count++;
         }
      }
   else{
      count = 0;
      strncat(readdata, cha, stat);

      memset(cha, 0x00, 64);
      ret = ret + stat;
      if(ret > max - 63){
         fprintf(stderr, "socket_reada(): read size err.\n");
         break;
         }
      }
   }

return(ret);
}



