// safe_strncat.c
// $Id: safe_strncat.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdarg.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <errno.h>

#include "almemsys.h"




char * safe_strncat(char * buf, char * newdata, int max_len)
{
int plen = 0;
int newdata_count;
int buf_count;

if(newdata == NULL){
   return buf;
   }
else if(newdata[0] == (char)0x00){
   return buf;
   }

newdata_count = (int)strlen(newdata);

if(buf == NULL){
   buf = (char *)calloc(BUF_LEN, sizeof(char));
   }

buf_count = (int)strlen(buf);

if(buf_count < max_len){
   if(max_len <= (newdata_count + buf_count)){
      plen = max_len - buf_count;
      if((buf = (char *)realloc(buf, sizeof(char) * (max_len + 1)))==NULL){
         fprintf(stderr,"The memory cannot be newly secured. \n");
         mlexit();
         }
      strncat(buf, newdata, (plen + 1));
      fprintf(stderr,"data size err %s %d %d %d\n", buf, newdata_count, max_len, plen);
      return buf;
      }
   if(max_len > (newdata_count + buf_count)){
      if((buf = (char *)realloc(buf, sizeof(char) * (newdata_count + buf_count + 1)))==NULL){
         fprintf(stderr,"The memory cannot be newly secured. \n");
         mlexit();
         }
      strncat(buf, newdata, (newdata_count + 1));
      #ifdef AL_DEBUG
      printf("COUNT=<%d>GETDATA=<%s>\n", newdata_count, buf);
      #endif
      return buf;
      }
   }

return buf;
}

                                       

