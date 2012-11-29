// count_memcpy2.c
// $Id: count_memcpy2.c,v 1.2 2007/11/01 06:12:39 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "almemsys.h"

/* ----------- COUNT MEMCPY2 ------------- */
char * count_memcpy2(char * out, char * data, int start, int plus)
{
int stop, max, count, co;
char * swap;
max = (int)strlen(data);

if(start < 0 || plus < 0 || max < 0){
   out[0] = (char)0x00;
   return(out);
   }

stop = start + plus;

if(max < stop){
   out[0] = (char)0x00;
   return(out);
   }

swap = (char *)calloc(plus + 5, sizeof(char));

co = 0;
for(count = start; count <= stop; count ++){
   swap[co] = data[count];
   co++;
   }

swap[co] = (char)0x00;

out = safe_memcpy(out, swap, BUF_MAX);

free(swap);

return(out);
}



