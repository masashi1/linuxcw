/* -*- mode: C; -*- */
#include <stdio.h>
#include <string.h>
#include "libbeep.h"
#include "libcw.h"

int beep_bufout(cw_length * cw_len, int fd, char * buf)
{
  int len, co;
  len = (int)strlen(buf);

  for(co = 0; co < len; co++){
    if(buf[co] == cw_len->short_p){
      beep_on(fd, cw_len->sp, cw_len->freq); 
      beep_sleep(cw_len->ps);
    }
    else if(buf[co] == cw_len->long_p){
      beep_on(fd, cw_len->lp, cw_len->freq); 
      beep_sleep(cw_len->ps);
    }
    else if(buf[co] == cw_len->break_p){
      beep_sleep(cw_len->cs);
#ifdef LIBCW_BUG
      printf("LIBCW_BUG: beep_bufout(): break time %d\n", cw_len->cs);
#endif
    }
    else if(buf[co] == cw_len->wbreak_p){
      beep_sleep(cw_len->ws);
#ifdef LIBCW_BUG
      printf("LIBCW_BUG: beep_bufout(): wbreak time %d\n", cw_len->ws);
#endif
    }
    else{
    }
  }
  return len;
}
