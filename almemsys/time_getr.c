#include<stdio.h>
#include<time.h>

#include "almemsys.h"


char * time_getr(char * buf)
{
time_t t;
struct tm tmbuf;

t = time(NULL);
localtime_r(&t, &tmbuf);

buf =  safe_sprintf(buf, BUF_MAX,"%04d:%02d:%02d:%02d:%02d:%02d",
      tmbuf.tm_year + 1900,
      tmbuf.tm_mon + 1,
      tmbuf.tm_mday,
      tmbuf.tm_hour,
      tmbuf.tm_min,
      tmbuf.tm_sec);

return buf;
}




