/* -*- mode: C; -*- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "almemsys.h"
#include "libbeep.h"
#include "libcw.h"
#include "cwrand.h"

/* Global Variables */
static int fd;

void intHandler(int signum)
{
  beep_off(fd);
  beep_close(fd);
  exit(EXIT_FAILURE);
}

int main(int argc, char ** argv)
{
  int moji, co, co2, co3, co4, inrand, bb, kk;
  char cha;
  char sw[2];
  char * buf;
  char * swap = sw;
  CWRAND_STAT stat;
  struct sigaction sa;
  
  moji	 = 0;
  co	 = 0;
  fd	 = -1;
  cha	 = 0x00;
  inrand = 0;
  bb	 = 1;
  kk	 = 1;

  stat.mode	= 0;
  stat.exa_mode = 0;
  stat.start	= 0;		// default の乱数の最小値
  stat.stop	= 48;		// default の乱数の最大値

  /* init & regist sigaction */
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = intHandler;
  if (sigaction(SIGINT, &sa, NULL)){
    perror("sigaction");
  }
  
  buf = (char *)calloc(2, sizeof(char));
  memset(swap, 0x00, 2);

  buf = safe_memcpy(buf, "  ", BUF_MAX);

  // cw用の構造体を定義します。
  cw_length cw_len;

  // デフォルトの符号データベースを初期化
  cw_default_memset(&cw_len);

  // デフォルトの信号の長さ(3)と周波数(2)を設定
  cw_defaultset(&cw_len, 700, 80);
  optin(argc, argv, &cw_len, &moji, &stat, &bb, &kk);

  // beepデバイスファイルを開いてFDを得る
  fd = beep_fdopen(fd);

#ifdef CWRAND_BUG
  printf("ブロックの文字数: %d  繰り返し数: %d\n", moji, stat.loop);
  printf("length_default:%d\n", cw_len.length_default);
  printf("exa_mode=%d mode=%d \n", exa_mode, mode);
  printf("rand start = %d rand stop = %d\n", start_rand, stop_rand);
#endif

  cw_len.ws = cw_len.sp * 4; // '*' の長さを短点の4倍に設定
  cw_len.cs = cw_len.sp * 2;  // 前の文字の後ろに1スペースあるので2

  // ワードの繰り返し
  for(co2 = 0; co2 < stat.loop; co2++){

    // ワード
    for(co = 0; co < moji; co++){
      inrand = (int)randdata(stat.start, stat.stop);
      cha = cw_len.roman.char_sign[inrand];

      if(0 == anunnec(inrand, stat.exa_mode)){
	swap[0] = cha; 
	buf = safe_strncat(buf, swap, BUF_MAX);
	memset(swap, 0x00, 2);

	if(stat.mode == 0 || stat.mode == 2){
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

    if(stat.mode == 1 || stat.mode == 2){
      printf("%s\n", buf);
    }

    buf = safe_memcpy(buf, "  ", BUF_MAX);
  }

  // beepのFDを開放し終了。
  beep_close(fd);

  return 0;
}
