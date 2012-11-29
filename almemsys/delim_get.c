// delim_get.c
// $Id: delim_get.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>
#include <errno.h>
#include <stdlib.h>

#include "almemsys.h"


char * delim_get(char * swap, char * data, char delim, int * ret, int target)
{
int sto, sta, count;
sta =0;
sto =0;
count = 0;
* ret = 0;

if(data == NULL){
   data = (char *)calloc(BUF_LEN, sizeof(char));
   }
else{
   data = null_free(data);
   }

if(swap == NULL){
   return data;
   }


count  = delim_count(swap, delim, target, &sta, &sto);
#ifdef MAIL_DEBUG
printf("DELIM 1 %d -> %d %d\n", sta, sto, count);
#endif
if(count > 0 && sta <= sto){
   data = (char *)realloc(data, (count + 2) * (sizeof(char)));
   memcount_cpm(data, swap, sta, sto, count);
   }
else{
   data = (char *)realloc(data, 5 * (sizeof(char)));
   memcpy(data, "NOT", 3);
   data[3] = (char)0x00;
   * ret = -1;
   }
#ifdef MAIL_DEBUG
printf("data =%s\n", data);
#endif

return data;
}





