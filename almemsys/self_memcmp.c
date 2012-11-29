// self_memcmp.c
// $Id: self_memcmp.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>



/* ----------- SELF MEMCMP ------------- */
int self_memcmp(char * dataa, char * datab)
{
int ret, maxa, maxb;

maxa = (int)strlen(dataa);
maxb = (int)strlen(datab);

if(maxa != maxb){
   ret = -1;
   return ret;
   }
else{
   ret = memcmp(dataa, datab, maxa);
   }

// printf("SELF_MEMCMP ret<%d> <%s> <%s>\n", ret, dataa, datab);

return ret;
}



