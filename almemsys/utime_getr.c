#include<stdio.h>
#include<time.h>

#include "almemsys.h"

/* UNIX時間から時間日付等を返す (thread safe) */

int utime_getr(time_t tt, char ch)
{
time_t t;
struct tm tmbuf;

t = tt;
localtime_r(&t, &tmbuf);

switch(ch){
  case 'y': return(tmbuf.tm_year + 1900);
  case 'm': return(tmbuf.tm_mon + 1);
  case 'd': return(tmbuf.tm_mday);
  case 'w': return(tmbuf.tm_wday);
  case 'h': return(tmbuf.tm_hour);
  case 'i': return(tmbuf.tm_min);
  case 's': return(tmbuf.tm_sec);
  default : return(0); break;
  }

return -1;
}



