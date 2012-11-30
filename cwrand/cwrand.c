
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almemsys.h"
#include "libbeep.h"
#include "libcw.h"
#include "cwrand.h"


int main(int argc, char ** argv)
{
  int fd;
  int moji, no, co, co2, co3, co4, inrand, mode, exa_mode, bb, kk;
  int start_rand, stop_rand;
  char cha;
  char sw[2];
  char * buf;
  char * swap = sw;

  moji = 0;
  co = 0;
  fd = -1;
  cha = 0x00;
  inrand = 0;
  mode = 0;
  exa_mode = 0;
  bb = 1;
  kk = 1;

  start_rand = 0;  // default の乱数の最小値
  stop_rand = 48;  // default の乱数の最大値


  buf = (char *)calloc(2, sizeof(char));
  memset(swap, 0x00, 2);

  buf = safe_memcpy(buf, "  ", BUF_MAX);

  // cw用の構造体を定義します。
  cw_length cw_len;

  // デフォルトの符号データベースを初期化
  cw_default_memset(&cw_len);

  // デフォルトの信号の長さ(3)と周波数(2)を設定
  cw_defaultset(&cw_len, 700, 80);

  optin(argc, argv, &cw_len, &moji, &no, &mode, &exa_mode, &start_rand, &stop_rand, &bb, &kk);

  // beepデバイスファイルを開いてFDを得る
  fd = beep_fdopen(fd);

#ifdef CWRAND_BUG
  printf("ブロックの文字数: %d  繰り返し数: %d\n", moji, no);
  printf("length_default:%d\n", cw_len.length_default);
  printf("exa_mode=%d mode=%d \n", exa_mode, mode);
  printf("rand start = %d rand stop = %d\n", start_rand, stop_rand);
#endif

  cw_len.ws = cw_len.sp * 4; // '*' の長さを短点の4倍に設定
  cw_len.cs = cw_len.sp * 2;  // 前の文字の後ろに1スペースあるので2

  // ワードの繰り返し
  for(co2 = 0; co2 < no; co2++){

    // ワード
    for(co = 0; co < moji; co++){
      inrand = (int)randdata(start_rand, stop_rand);
      cha = cw_len.roman.char_sign[inrand];

      if(0 == anunnec(inrand, exa_mode)){
	swap[0] = cha; 
	buf = safe_strncat(buf, swap, BUF_MAX);
	memset(swap, 0x00, 2);

	if(mode == 0 || mode == 2){
	  printf("%d  %c     %s\n", co2, cha, cw_len.roman.note_sign[inrand]);
	}
	for(co4 = 0; co4 < kk; co4++){
	  cw_sign(&cw_len, fd, cha);
	  cw_sign(&cw_len, fd, ' ');
	}
      }
      else {
	co = co - 1;
      }

    }
    // ワード間のスペース
    for(co3 = 0; co3 < bb; co3++){
      cw_sign(&cw_len, fd, '*');
    }

    if(mode == 1 || mode == 2){
      printf("%s\n", buf);
    }

    buf = safe_memcpy(buf, "  ", BUF_MAX);
  }

  // beepのFDを開放し終了。
  beep_close(fd);

  return 0;
}
