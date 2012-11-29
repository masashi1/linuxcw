
#include<stdio.h>
#include"libcw.h"


int cw_speedset(cw_length * cw_len, int default_length)
{

if(default_length < 5 || default_length > 1000){
   default_length = CW_DEF_LENGTH;
   }

cw_len->length_default = default_length;         // 長点短点のベースになる長さ。    1(CW_DEF_LENGTH)
cw_len->sp             = cw_len->length_default; // 短点の長さ。                    1
cw_len->lp             = cw_len->sp * 3;         // 長点の長さ。                    3
cw_len->ps             = cw_len->sp;             // 二点間のスペースの長さ。        1
cw_len->cs             = cw_len->sp * 3;         // 二キャラクタ間のスペースの長さ。3
cw_len->ws             = cw_len->sp * 7;         // 二ワード間のスペースの長さ。    7

return 0;
}


