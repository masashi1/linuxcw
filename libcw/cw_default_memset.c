/* -*- mode: C; -*- */
#include <stdio.h>
#include <string.h>
#include "libcw.h"

int cw_default_memset(cw_length * cw_len)
{

  // 欧文
  cw_default_memset_roman(cw_len);
  // 和文
  cw_default_memset_wabun(cw_len);

  return 0;
}
