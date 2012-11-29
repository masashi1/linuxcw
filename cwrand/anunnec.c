
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"libbeep.h"
#include"libcw.h"
#include"cwrand.h"
#include"almemsys.h"


int anunnec(int char_no, int exa_mode)
{
int co;
int list[17] = { 40, 42, 43, 44, 46, 47 };

for(co = 0; co < 17; co++){
   if(char_no == list[co]){
      if(exa_mode == 1){
         return 1;
         }
      }
   }

return 0;
}



