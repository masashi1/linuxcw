// safe_sprintf.c
// $Id: safe_sprintf.c,v 1.2 2007/11/01 06:08:31 sendan Exp $
// masashi shimakura


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include <errno.h>

#include "almemsys.h"



__attribute__((__format__(__printf__, 3, 4))) char * safe_sprintf(char * data, long int max_len, const char * fmt,...)
{
FILE * fp;
va_list args;
long int len;

if(data == NULL){
   data = (char *)calloc(BUF_LEN, sizeof(char));
   }
else{
   data = null_free(data);
   }

va_start(args, fmt);
if((fp = fopen("/dev/null", "w+"))!=NULL){
   len = vfprintf(fp, fmt, args);
   fclose(fp);
   }
else{
   len = vfprintf(stderr, fmt, args);
   }
va_end(args);

va_start(args, fmt);
if(len > 0){
   if(len > max_len){
      len = max_len;
      }
   if((data = (char *)realloc(data, (len + 2) * sizeof(char)))==NULL){
      fprintf(stderr,"The memory cannot be newly secured. \n");
      mlexit();
      }
   vsnprintf(data, (len + 1), fmt, args);
   }
va_end(args);

return data;
}



