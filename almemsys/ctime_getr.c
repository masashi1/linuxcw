#include<stdio.h>

#include<time.h>

#include "almemsys.h"



/* 現在時刻の指定文字の示す時間属性をかえす */
int ctime_getr(char ch)
{
time_t t;
struct tm tmbuf;

t = time(NULL);
localtime_r(&t, &tmbuf);

switch(ch){
  case 'y': return(tmbuf.tm_year + 1900);
  case 'm': return(tmbuf.tm_mon + 1);
  case 'd': return(tmbuf.tm_mday);
  case 'h': return(tmbuf.tm_hour);
  case 'i': return(tmbuf.tm_min);
  case 's': return(tmbuf.tm_sec);
  default : return(0); break;
  }

return -1;
}


