// count_memcpy.c
// $Id: count_memcpy.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>

/* ----------- COUNT MEMCPY ------------- */
int count_memcpy(char * out, char * data, int max)
{
int count;

for(count = 0; count < max; count ++){
   out[count] = data[count];
   }

out[count] = (char)0x00;

return(count);
}



