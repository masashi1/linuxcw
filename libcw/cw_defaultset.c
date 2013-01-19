/* -*- mode: C; -*- */
#include <stdio.h>
#include "libcw.h"

int cw_defaultset(cw_length * cw_len, int default_freq, int default_length)
{

  //  #define CW_DEF_FREQ    800       // おとのたかさ KHzていどのつもりん
  //  #define CW_DEF_LENGTH   50       // おとのながさ

  if(default_freq < 400 || default_freq > 1500){
    default_freq = CW_DEF_FREQ;
  }
  if(default_length < 5 || default_length > 1000){
    default_length = CW_DEF_LENGTH;
  }

  cw_len->mode           = 0;                      // Default 0 欧文、和文ハ1
  cw_len->freq           = default_freq;           // 音程                           比率
  cw_len->length_default = default_length;         // 長点短点のベースになる長さ。    1(CW_DEF_LENGTH)
  cw_len->sp             = cw_len->length_default; // 短点の長さ。                    1
  cw_len->lp             = cw_len->sp * 3;         // 長点の長さ。                    3
  cw_len->ps             = cw_len->sp;             // 二点間のスペースの長さ。        1
  cw_len->cs             = cw_len->sp * 3;         // 二キャラクタ間のスペースの長さ。3
  cw_len->ws             = cw_len->sp * 7;         // 二ワード間のスペースの長さ。    7

  cw_len->short_p        = '.';                    // 短点を判断する場合の記号
  cw_len->long_p         = '-';                    // 長点を判断する場合の記号
  cw_len->break_p        = ' ';                    // 文字間の空白を判断する場合の記号
  cw_len->wbreak_p       = '*';                    // 単語間の空白を判断する場合の記号

  // cw_default_memset(cw_len);

  return 0;
}
