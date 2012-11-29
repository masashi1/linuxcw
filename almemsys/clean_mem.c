// clean_mem.c
// $Id: clean_mem.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>

/* ---------------- CLEAN MEM ------------------ */
int clean_mem(char data[], char chA, int inlen)
{
int count, max;

max =  (int)strlen(data);
if(inlen < 1 && max < 1){
   return -1;
   }

for(count = inlen-1; 0 <= count; count = count-1){
   data[count] = chA;
   }
return(count);

}








