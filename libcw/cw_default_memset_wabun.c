/* -*- mode: C; -*- */
#include <stdio.h>
#include <string.h>
#include "libcw.h"

int cw_default_memset_wabun(cw_length * cw_len)
{
  int co;

  for(co = 0; co < WCHAR_LENG; co++){
    memset(cw_len->wabun.char_sign[co], 0x00, BUFF_LENG);
    memset(cw_len->wabun.note_sign[co], 0x00, BUFF_LENG);
  }

  // 数字（基本的ニ全角デアルコト）
  memcpy(cw_len->wabun.note_sign[0], "-----", 5); memcpy(cw_len->wabun.char_sign[0], "零", (int)strlen("零"));
  memcpy(cw_len->wabun.note_sign[1], ".----", 5); memcpy(cw_len->wabun.char_sign[1], "一", (int)strlen("一"));
  memcpy(cw_len->wabun.note_sign[2], "..---", 5); memcpy(cw_len->wabun.char_sign[2], "二", (int)strlen("二")); 
  memcpy(cw_len->wabun.note_sign[3], "...--", 5); memcpy(cw_len->wabun.char_sign[3], "三", (int)strlen("三"));
  memcpy(cw_len->wabun.note_sign[4], "....-", 5); memcpy(cw_len->wabun.char_sign[4], "四", (int)strlen("四"));
  memcpy(cw_len->wabun.note_sign[5], ".....", 5); memcpy(cw_len->wabun.char_sign[5], "五", (int)strlen("五")); 
  memcpy(cw_len->wabun.note_sign[6], "-....", 5); memcpy(cw_len->wabun.char_sign[6], "六", (int)strlen("六"));
  memcpy(cw_len->wabun.note_sign[7], "--...", 5); memcpy(cw_len->wabun.char_sign[7], "七", (int)strlen("七"));
  memcpy(cw_len->wabun.note_sign[8], "---..", 5); memcpy(cw_len->wabun.char_sign[8], "八", (int)strlen("八"));
  memcpy(cw_len->wabun.note_sign[9], "----.", 5); memcpy(cw_len->wabun.char_sign[9], "九", (int)strlen("九"));
  // 全角カタカナ
  memcpy(cw_len->wabun.note_sign[10], ".-", 2); memcpy(cw_len->wabun.char_sign[10], "イ", (int)strlen("イ"));
  memcpy(cw_len->wabun.note_sign[11], ".-.-", 4); memcpy(cw_len->wabun.char_sign[11], "ロ", (int)strlen("ロ"));
  memcpy(cw_len->wabun.note_sign[12], "-...", 4); memcpy(cw_len->wabun.char_sign[12], "ハ", (int)strlen("ハ"));
  memcpy(cw_len->wabun.note_sign[13], "-.-.", 4); memcpy(cw_len->wabun.char_sign[13], "ニ", (int)strlen("ニ"));
  memcpy(cw_len->wabun.note_sign[14], "-..", 3); memcpy(cw_len->wabun.char_sign[14], "ホ", (int)strlen("ホ"));
  memcpy(cw_len->wabun.note_sign[15], ".", 1); memcpy(cw_len->wabun.char_sign[15], "ヘ", (int)strlen("ヘ"));
  memcpy(cw_len->wabun.note_sign[16], "..-..", 5); memcpy(cw_len->wabun.char_sign[16], "ト", (int)strlen("ト"));
  memcpy(cw_len->wabun.note_sign[17], "..-.", 4); memcpy(cw_len->wabun.char_sign[17], "チ", (int)strlen("チ"));
  memcpy(cw_len->wabun.note_sign[18], "--.", 3); memcpy(cw_len->wabun.char_sign[18], "リ", (int)strlen("リ"));
  memcpy(cw_len->wabun.note_sign[19], "....", 4); memcpy(cw_len->wabun.char_sign[19], "ヌ", (int)strlen("ヌ"));
  memcpy(cw_len->wabun.note_sign[20], "-.--.", 5); memcpy(cw_len->wabun.char_sign[20], "ル", (int)strlen("ル"));
  memcpy(cw_len->wabun.note_sign[21], ".---", 4); memcpy(cw_len->wabun.char_sign[21], "ヲ", (int)strlen("ヲ")); 
  memcpy(cw_len->wabun.note_sign[22], "-.-", 3); memcpy(cw_len->wabun.char_sign[22], "ワ", (int)strlen("ワ"));
  memcpy(cw_len->wabun.note_sign[23], ".-..", 4); memcpy(cw_len->wabun.char_sign[23], "カ", (int)strlen("カ"));
  memcpy(cw_len->wabun.note_sign[24], "--", 2); memcpy(cw_len->wabun.char_sign[24], "ヨ", (int)strlen("ヨ")); 
  memcpy(cw_len->wabun.note_sign[25], "-.", 2); memcpy(cw_len->wabun.char_sign[25], "タ", (int)strlen("タ"));
  memcpy(cw_len->wabun.note_sign[26], "---", 3); memcpy(cw_len->wabun.char_sign[26], "レ", (int)strlen("レ"));
  memcpy(cw_len->wabun.note_sign[27], "---.", 4); memcpy(cw_len->wabun.char_sign[27], "ソ", (int)strlen("ソ"));
  memcpy(cw_len->wabun.note_sign[28], ".--.", 4); memcpy(cw_len->wabun.char_sign[28], "ツ", (int)strlen("ツ"));
  memcpy(cw_len->wabun.note_sign[29], "--.-", 4); memcpy(cw_len->wabun.char_sign[29], "ネ", (int)strlen("ネ"));
  memcpy(cw_len->wabun.note_sign[30], ".-.", 3); memcpy(cw_len->wabun.char_sign[30], "ナ", (int)strlen("ナ")); 
  memcpy(cw_len->wabun.note_sign[31], "...", 3); memcpy(cw_len->wabun.char_sign[31], "ラ", (int)strlen("ラ"));
  memcpy(cw_len->wabun.note_sign[32], "-", 1); memcpy(cw_len->wabun.char_sign[32], "ム", (int)strlen("ム"));
  memcpy(cw_len->wabun.note_sign[33], "..-", 3); memcpy(cw_len->wabun.char_sign[33], "ウ", (int)strlen("ウ"));
  memcpy(cw_len->wabun.note_sign[34], ".-..-", 5); memcpy(cw_len->wabun.char_sign[34], "ヱ", (int)strlen("ヱ")); 
  memcpy(cw_len->wabun.note_sign[35], "..--", 4); memcpy(cw_len->wabun.char_sign[35], "ノ", (int)strlen("ノ"));
  memcpy(cw_len->wabun.note_sign[36], ".-...", 5); memcpy(cw_len->wabun.char_sign[36], "オ", (int)strlen("オ"));
  memcpy(cw_len->wabun.note_sign[37], "...-", 4); memcpy(cw_len->wabun.char_sign[37], "ク", (int)strlen("ク")); 
  memcpy(cw_len->wabun.note_sign[38], ".--", 3); memcpy(cw_len->wabun.char_sign[38], "ヤ", (int)strlen("ヤ"));
  memcpy(cw_len->wabun.note_sign[39], "-..-", 4); memcpy(cw_len->wabun.char_sign[39], "マ", (int)strlen("マ"));
  memcpy(cw_len->wabun.note_sign[40], "-.--", 4); memcpy(cw_len->wabun.char_sign[40], "ケ", (int)strlen("ケ"));
  memcpy(cw_len->wabun.note_sign[41], "--..", 4); memcpy(cw_len->wabun.char_sign[41], "フ", (int)strlen("フ"));
  memcpy(cw_len->wabun.note_sign[42], "----", 4); memcpy(cw_len->wabun.char_sign[42], "コ", (int)strlen("コ"));
  memcpy(cw_len->wabun.note_sign[43], "-.---", 5); memcpy(cw_len->wabun.char_sign[43], "エ", (int)strlen("エ"));
  memcpy(cw_len->wabun.note_sign[44], ".-.--", 5); memcpy(cw_len->wabun.char_sign[44], "テ", (int)strlen("テ")); 
  memcpy(cw_len->wabun.note_sign[45], "--.--", 5); memcpy(cw_len->wabun.char_sign[45], "ア", (int)strlen("ア"));
  memcpy(cw_len->wabun.note_sign[46], "-.-.-", 5); memcpy(cw_len->wabun.char_sign[46], "サ", (int)strlen("サ"));
  memcpy(cw_len->wabun.note_sign[47], "-.-..", 5); memcpy(cw_len->wabun.char_sign[47], "キ", (int)strlen("キ"));
  memcpy(cw_len->wabun.note_sign[48], "-..--", 5); memcpy(cw_len->wabun.char_sign[48], "ユ", (int)strlen("ユ"));
  memcpy(cw_len->wabun.note_sign[49], "-...-", 5); memcpy(cw_len->wabun.char_sign[49], "メ", (int)strlen("メ"));
  memcpy(cw_len->wabun.note_sign[50], "..-.-", 5); memcpy(cw_len->wabun.char_sign[50], "ミ", (int)strlen("ミ"));
  memcpy(cw_len->wabun.note_sign[51], "--.-.", 5); memcpy(cw_len->wabun.char_sign[51], "シ", (int)strlen("シ"));
  memcpy(cw_len->wabun.note_sign[52], ".--..", 5); memcpy(cw_len->wabun.char_sign[52], "エ", (int)strlen("エ"));
  memcpy(cw_len->wabun.note_sign[53], "--..-", 5); memcpy(cw_len->wabun.char_sign[53], "ヒ", (int)strlen("ヒ"));
  memcpy(cw_len->wabun.note_sign[54], "-..-.", 5); memcpy(cw_len->wabun.char_sign[54], "モ", (int)strlen("モ"));
  memcpy(cw_len->wabun.note_sign[55], ".---.", 5); memcpy(cw_len->wabun.char_sign[55], "セ", (int)strlen("セ"));
  memcpy(cw_len->wabun.note_sign[56], "---.-", 5); memcpy(cw_len->wabun.char_sign[56], "ス", (int)strlen("ス"));
  memcpy(cw_len->wabun.note_sign[57], ".-.-.", 5); memcpy(cw_len->wabun.char_sign[57], "ソ", (int)strlen("ソ"));
  // 全角記号
  memcpy(cw_len->wabun.note_sign[58], ".--.-", 5); memcpy(cw_len->wabun.char_sign[58], "ー", (int)strlen("ー"));
  memcpy(cw_len->wabun.note_sign[59], ".-.-.-", 6); memcpy(cw_len->wabun.char_sign[59], "、", (int)strlen("、"));
  memcpy(cw_len->wabun.note_sign[60], "-.--.-", 6); memcpy(cw_len->wabun.char_sign[60], "（", (int)strlen("（"));
  memcpy(cw_len->wabun.note_sign[61], ".-..-.", 6); memcpy(cw_len->wabun.char_sign[61], "）", (int)strlen("）"));
  memcpy(cw_len->wabun.note_sign[62], ".-.-..", 6); memcpy(cw_len->wabun.char_sign[62], "」", (int)strlen("」"));

  // 全角操作記号
  memcpy(cw_len->wabun.note_sign[63], " ", 1); memcpy(cw_len->wabun.char_sign[63], "　", (int)strlen("　"));
  memcpy(cw_len->wabun.note_sign[64], "*", 1); memcpy(cw_len->wabun.char_sign[64], "＊", (int)strlen("＊"));

  return 0;
}
