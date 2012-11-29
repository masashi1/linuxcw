
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include"almemsys.h"


// char * safe_base64(char *, int, int);
 

char * safe_base64(char * data)
{
char * swap;
int max;

max = (int)strlen(data);

if(max > 0){
   swap = (char *)calloc((max * 2), (int)sizeof(char));
   base64(data, max, swap);
   data = safe_memcpy(data, swap, BUF_MAX);
   free(swap);
   }
else{
   fprintf(stderr,"safe_base64(): not 64 encode.\n");
   }

return data;
}



