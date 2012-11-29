// ch_int2.c
// $Id: $
// masashi shimakura


#include<stdio.h>
#include<string.h>
#include<ctype.h>



/* -------------- CH_INT -------------- */
int ch_int2(char * data)
{
int count;
int ret = 0;
int max = (int)strlen(data);

for(count = 0; count < max; count++){
   if(0 == isdigit((int)data[count])){
      ret = -1;
      break;
      }
   }

return ret;
}





