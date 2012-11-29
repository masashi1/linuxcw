
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "almemsys.h"



char * safe_ujtoj(char * data)
{
char * swap;
int max;
// int count;

max = (int)strlen(data);

if(max > 0){
   swap = (char *)calloc((max * 2), sizeof(char));
   ujtoj((unsigned char *)swap, (unsigned char *)data);
   data = safe_memcpy(data, swap, BUF_MAX);

//   for(count = 0; count < strlen(data); count++){
//      printf("data char[%c] data hex<0x%x>\n", data[count], data[count]);
//      }


   free(swap);
   }
else{
   fprintf(stderr,"safe_ujtoj(): data size err.\n");
   }

return data;
}


