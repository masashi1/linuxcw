#include<stdio.h>
#include<string.h>
#include"libbeep.h"
#include"libcw.h"


int char_no_wabun(cw_length * cw_len, char * sign)
{
int co;

for(co = 0; co < CHAR_LENG; co++){
   if(0 == (memcmp(cw_len->wabun.char_sign[co], sign, (int)strlen(sign)))){
      return co;
      }
   }

return 58;
}



