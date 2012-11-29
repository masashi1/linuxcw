#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * null_free(char * data)
{
int len;
len = (int)strlen(data);

if(0 < len){

   #ifdef NULL_FREEBUG
   printf("null_free(%d) %s\n", len, data);
   #endif

   memset(data, 0x00, len);
   }

return data;
}


