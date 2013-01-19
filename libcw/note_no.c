/* -*- mode: C; -*- */
#include <stdio.h>
#include <string.h>
#include "libbeep.h"
#include "libcw.h"

int note_no(cw_length * cw_len, char * note)
{
  int co, max;
  max = (int)strlen(note);

  if(max > BUFF_LENG){
    return 50;
  }

  for(co = 0; co < CHAR_LENG; co++){
    if(0 == (memcmp(cw_len->roman.note_sign[co], note, max))){
      return co;
    }
  }

  return 50;
}
