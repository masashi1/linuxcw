// safe_memcpy.c
// $Id: safe_memcpy.c,v 1.2 2007/10/17 10:57:56 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>

#include "almemsys.h"



char * safe_memcpy(char * buf, char * newdata, int max_len)
{
int data_count;

if(newdata == NULL){
   fprintf(stderr,"safe_memcpy(0): insert data is NULL.\n");
   buf = null_free(buf);
   return buf;
   }
else if(newdata[0] == (char)0x00){
   buf = null_free(buf);
   return buf;
   }

data_count = (int)strlen(newdata);

if(buf == NULL){
   buf = (char *)calloc(BUF_LEN, sizeof(char));
   }
else{
   buf = null_free(buf);
   }

if(max_len < data_count){
   if((buf = (char *)realloc(buf, (max_len + 1)))==NULL){
      fprintf(stderr,"The memory cannot be newly secured. \n");
      mlexit();
      }
   memset(buf, (char)0x00, max_len);
   count_memcpy(buf, newdata, max_len);
   fprintf(stderr,"data size err %s %d %d\n", buf, data_count, max_len);
   return buf;
   }
else {
   if((buf = (char *)realloc(buf, (data_count + 2)))==NULL){
      fprintf(stderr,"The memory cannot be newly secured. \n");
      mlexit();
      }
   memset(buf, (char)0x00, data_count + 1);
   count_memcpy(buf, newdata, data_count);
   #ifdef AL_DEBUG 
   printf("COUNT = <%d> GET DATA = <%s>\n", data_count, buf);
   #endif
   return buf;
   }

return NULL;
}




