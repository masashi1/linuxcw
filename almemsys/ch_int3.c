// ch_int.c
// $Id: ch_int.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura


#include<stdio.h>
#include<string.h>
#include<ctype.h>



/* -------------- CH_INT -------------- */
int ch_int3(char * data, char cha)
{
int count;
int ret = 0;
int max = (int)strlen(data);

for(count = 0; count < max; count++){
   if(0 == isdigit((int)data[count])){
      if(data[count] == cha){
         ret = 0;
         }
      else{
         ret = -1;
         break;
         }
      }
   }

return ret;
}





