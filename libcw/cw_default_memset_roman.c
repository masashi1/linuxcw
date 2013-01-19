/* -*- mode: C; -*- */
#include <stdio.h>
#include <string.h>
#include "libcw.h"

int cw_default_memset_roman(cw_length * cw_len)
{
  int co;

  for(co = 0; co < CHAR_LENG; co++){
    cw_len->roman.char_sign[co] = 0x00;
    memset(cw_len->roman.note_sign[co], 0x00, BUFF_LENG);
  }

  // 文字をセットしていきます
  // 数字
  memcpy(cw_len->roman.note_sign[0], "-----", 5); cw_len->roman.char_sign[0] = '0';
  memcpy(cw_len->roman.note_sign[1], ".----", 5); cw_len->roman.char_sign[1] = '1';
  memcpy(cw_len->roman.note_sign[2], "..---", 5); cw_len->roman.char_sign[2] = '2';
  memcpy(cw_len->roman.note_sign[3], "...--", 5); cw_len->roman.char_sign[3] = '3';
  memcpy(cw_len->roman.note_sign[4], "....-", 5); cw_len->roman.char_sign[4] = '4';
  memcpy(cw_len->roman.note_sign[5], ".....", 5); cw_len->roman.char_sign[5] = '5';
  memcpy(cw_len->roman.note_sign[6], "-....", 5); cw_len->roman.char_sign[6] = '6';
  memcpy(cw_len->roman.note_sign[7], "--...", 5); cw_len->roman.char_sign[7] = '7';
  memcpy(cw_len->roman.note_sign[8], "---..", 5); cw_len->roman.char_sign[8] = '8';
  memcpy(cw_len->roman.note_sign[9], "----.", 5); cw_len->roman.char_sign[9] = '9';
  // ローマ字（小）
  memcpy(cw_len->roman.note_sign[10], ".-", 2); cw_len->roman.char_sign[10] = 'a';
  memcpy(cw_len->roman.note_sign[11], "-...", 4); cw_len->roman.char_sign[11] = 'b';
  memcpy(cw_len->roman.note_sign[12], "-.-.", 4); cw_len->roman.char_sign[12] = 'c';
  memcpy(cw_len->roman.note_sign[13], "-..", 3); cw_len->roman.char_sign[13] = 'd';
  memcpy(cw_len->roman.note_sign[14], ".", 1); cw_len->roman.char_sign[14] = 'e';
  memcpy(cw_len->roman.note_sign[15], "..-.", 4); cw_len->roman.char_sign[15] = 'f';
  memcpy(cw_len->roman.note_sign[16], "--.", 3); cw_len->roman.char_sign[16] = 'g';
  memcpy(cw_len->roman.note_sign[17], "....", 4); cw_len->roman.char_sign[17] = 'h';
  memcpy(cw_len->roman.note_sign[18], "..", 2); cw_len->roman.char_sign[18] = 'i';
  memcpy(cw_len->roman.note_sign[19], ".---", 4); cw_len->roman.char_sign[19] = 'j';
  memcpy(cw_len->roman.note_sign[20], "-.-", 3); cw_len->roman.char_sign[20] = 'k';
  memcpy(cw_len->roman.note_sign[21], ".-..", 4); cw_len->roman.char_sign[21] = 'l';
  memcpy(cw_len->roman.note_sign[22], "--", 2); cw_len->roman.char_sign[22] = 'm';
  memcpy(cw_len->roman.note_sign[23], "-.", 2); cw_len->roman.char_sign[23] = 'n';
  memcpy(cw_len->roman.note_sign[24], "---", 3); cw_len->roman.char_sign[24] = 'o';
  memcpy(cw_len->roman.note_sign[25], ".--.", 4); cw_len->roman.char_sign[25] = 'p';
  memcpy(cw_len->roman.note_sign[26], "--.-", 4); cw_len->roman.char_sign[26] = 'q';
  memcpy(cw_len->roman.note_sign[27], ".-.", 3); cw_len->roman.char_sign[27] = 'r';
  memcpy(cw_len->roman.note_sign[28], "...", 3); cw_len->roman.char_sign[28] = 's';
  memcpy(cw_len->roman.note_sign[29], "-", 1); cw_len->roman.char_sign[29] = 't';
  memcpy(cw_len->roman.note_sign[30], "..-", 3); cw_len->roman.char_sign[30] = 'u';
  memcpy(cw_len->roman.note_sign[31], "...-", 4); cw_len->roman.char_sign[31] = 'v';
  memcpy(cw_len->roman.note_sign[32], ".--", 3); cw_len->roman.char_sign[32] = 'w';
  memcpy(cw_len->roman.note_sign[33], "-..-", 4); cw_len->roman.char_sign[33] = 'x';
  memcpy(cw_len->roman.note_sign[34], "-.--", 4); cw_len->roman.char_sign[34] = 'y';
  memcpy(cw_len->roman.note_sign[35], "--..", 4); cw_len->roman.char_sign[35] = 'z';
  // 記号
  memcpy(cw_len->roman.note_sign[36], "--..--", 6); cw_len->roman.char_sign[36] = ',';
  memcpy(cw_len->roman.note_sign[37], ".-.-.-", 6); cw_len->roman.char_sign[37] = '.';
  memcpy(cw_len->roman.note_sign[38], "---...", 6); cw_len->roman.char_sign[38] = ':';
  memcpy(cw_len->roman.note_sign[39], "..--..", 6); cw_len->roman.char_sign[39] = '?';
  memcpy(cw_len->roman.note_sign[40], ".----.", 6); cw_len->roman.char_sign[40] = '\'';
  memcpy(cw_len->roman.note_sign[41], "-....-", 6); cw_len->roman.char_sign[41] = '-';
  memcpy(cw_len->roman.note_sign[42], "-.--.", 5); cw_len->roman.char_sign[42] = '(';
  memcpy(cw_len->roman.note_sign[43], "-.--.-", 6); cw_len->roman.char_sign[43] = ')';
  memcpy(cw_len->roman.note_sign[44], "-...-", 5); cw_len->roman.char_sign[44] = '=';
  memcpy(cw_len->roman.note_sign[45], "-..-.", 5); cw_len->roman.char_sign[45] = '/';
  memcpy(cw_len->roman.note_sign[46], ".-.-.", 5); cw_len->roman.char_sign[46] = '+';
  memcpy(cw_len->roman.note_sign[47], ".-..-.", 6); cw_len->roman.char_sign[47] = '"';
  memcpy(cw_len->roman.note_sign[48], ".--.-.", 6); cw_len->roman.char_sign[48] = '@';
  // 操作記号
  memcpy(cw_len->roman.note_sign[49], " ", 1); cw_len->roman.char_sign[49] = ' ';  // 文字間の空白
  memcpy(cw_len->roman.note_sign[50], "*", 1); cw_len->roman.char_sign[50] = '*';  // ワード間の空白


  return 0;
}
