// ch_char.c
// $Id: $
// masashi shimakura


#include<stdio.h>
#include<string.h>
#include<ctype.h>



/* -------------- CH_CHAR -------------- */
int ch_char(char * data, char * backdata)
{
int count;
int ret = 0;
int max = (int)strlen(data);

for(count = 0; count < max; count++){
   if(0 != isdigit((int)data[count])){
      backdata[ret] = data[count];
      ret++;
      }
   else if(0 != isprint((int)data[count])){
      backdata[ret] = data[count];
      ret++;
      }
   else {
      }
   }

backdata[ret] = (char)0x00;

return ret;
}





