
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"almemsys.h"
#include"libbeep.h"
#include"libcw.h"
#include"cwrand.h"


int main(int argc, char ** argv)
{
int fd;
int mo, no, co, co2, co3, inrand, mode, bb;
char sw[6];
char * swap = sw;

no = 1;
mo = 1;
fd = -1;
inrand = 0;
mode = 0;
bb = 1;


memset(swap, 0x00, 6);


// cw用の構造体を定義します。
cw_length cw_len;

// デフォルトの符号データベースを初期化
cw_default_memset(&cw_len);

// デフォルトの信号の長さ(3)と周波数(2)を設定
cw_defaultset(&cw_len, 700, 80);

calloptin(argc, argv, &cw_len, &mo, &no, &bb, &mode);

printf("生成数    -c        : %d\n", no);
printf("2繰り返し -m        : %d\n", mo);
printf("ワードのスペース -b : %d\n", bb);
printf("コールサインの種類  : %d\n", mode);


// beepデバイスファイルを開いてFDを得る
fd = beep_fdopen(fd);

cw_len.ws = cw_len.sp * 4; // '*' の長さを短点の4倍に設定
cw_len.cs = cw_len.sp * 2;  // 前の文字の後ろに1スペースあるので2

// ワードの繰り返し
for(co2 = 0; co2 < no; co2++){

   memset(swap, 0x00, 6);

   // なんでもありのモード
   if(mode <= 1){
      // call sign 1文字目
      inrand = (int)randdata(10, 35);
      swap[0] = cw_len.roman.char_sign[inrand];
      // call sign 2文字目
      inrand = (int)randdata(10, 35);
      swap[1] = cw_len.roman.char_sign[inrand];
      // call sign 3文字目
      inrand = (int)randdata(0, 9);
      swap[2] = cw_len.roman.char_sign[inrand];
      // call sign 4文字目
      inrand = (int)randdata(10, 35);
      swap[3] = cw_len.roman.char_sign[inrand];
      // call sign 5文字目
      inrand = (int)randdata(10, 35);
      swap[4] = cw_len.roman.char_sign[inrand];
      // call sign 6文字目
      inrand = (int)randdata(10, 35);
      swap[5] = cw_len.roman.char_sign[inrand];
      }

   // なんでもありのモード
   else if(mode == 2){
      // call sign 1文字目
      swap[0] = jpcall1c();                    // j,7,8,
      // call sign 2文字目
      if(swap[0] == 'J' || swap[0] == 'j'){
         inrand = (int)randdata(10, 28);           // a - j
         swap[1] = cw_len.roman.char_sign[inrand];
         }
      else{
         inrand = (int)randdata(19, 23);           // j - n
         swap[1] = cw_len.roman.char_sign[inrand];
         }
      // call sign 3文字目
      inrand = (int)randdata(0, 9);
      swap[2] = cw_len.roman.char_sign[inrand];
      // call sign 4文字目
      inrand = (int)randdata(10, 35);
      swap[3] = cw_len.roman.char_sign[inrand];
      // call sign 5文字目
      inrand = (int)randdata(10, 35);
      swap[4] = cw_len.roman.char_sign[inrand];
      // call sign 6文字目
      inrand = (int)randdata(10, 35);
      swap[5] = cw_len.roman.char_sign[inrand];
      }


   for(co = 0; co < mo; co++){
      for(co3 = 0; co3 < 6; co3++){
         cw_sign(&cw_len, fd, swap[co3]);
         cw_sign(&cw_len, fd, ' ');
         printf("%c\n", swap[co3]);
         }

      // ワード間のスペース
      for(co3 = 0; co3 < bb; co3++){
         cw_sign(&cw_len, fd, '*');
         printf("\n");
         }
      }

   printf("CALL SIGN = %s\n", swap);
   }

// beepのFDを開放し終了。
beep_close(fd);

return 0;
}




