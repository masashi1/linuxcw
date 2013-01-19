/* -*- mode: C; -*- */
#include <stdio.h>
#include "libbeep.h"
#include "libcw.h"

int char_no(cw_length * cw_len, char sign)
{
  int co;

  for(co = 0; co < CHAR_LENG; co++){
    if(cw_len->roman.char_sign[co] == sign){
      return co;
    }
  }

  return 58;
}
