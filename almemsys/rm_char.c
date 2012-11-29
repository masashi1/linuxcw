#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "almemsys.h"

// int rm_char(char * data, char ch, int max);

int rm_char(char * data, char ch)
{
int max, comax, ret, co, po, pp;

ret = 0;

max = strlen(data);
comax = char_count(data, ch);

if(comax > 0){
   ret = comax;
   for(co = comax; co > 0; co--){
      pp = mem_count(data, ch); 
      for(po = pp; po < max; po++){
         data[po] = data[po + 1];
         }
      data[po] = (char)0x00;
      }
   }
else{
   return ret;
   }

return ret;
}


