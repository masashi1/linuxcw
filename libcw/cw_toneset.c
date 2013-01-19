/* -*- mode: C; -*- */
#include <stdio.h>
#include "libcw.h"

int cw_toneset(cw_length * cw_len, int default_freq)
{

  if(default_freq < 400 || default_freq > 1500){
    default_freq = CW_DEF_FREQ;
  }

  cw_len->freq           = default_freq;           // 音程                           比率

  return 0;
}
