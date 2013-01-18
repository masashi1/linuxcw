/* -*- C -*- */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "libbeep.h"
#include "libcw.h"
#include "cwread.h"

#define  DEFAULT_SPEED  130
#define  DEFAULT_TONE   700
#define  MAX_BUF_SIZE   2048

/* beep file descripter */
int beepfd;

void intHandler (int signum)
{
  beep_close(beepfd);
  exit(EXIT_FAILURE);
}

int cwread (cw_length *cw_len, CWREAD_STAT *stat)
{
  char buf[MAX_BUF_SIZE];
  char *cp;

  while ((cp = fgets(buf, sizeof(buf), stat->fp)) != NULL){
    while (*cp != '\0'){
      switch (*cp){
      case '<':
	cw_len->cs = 0;
	break;
	
      case '>':
	cw_len->cs = cw_len->sp * 2;
	break;

      case ' ':
	if (*(cp-1) == ' '){
	  putchar('*');
	  cw_sign(cw_len, beepfd, '*');
	}
	else{
	  putchar(' ');
	  beep_sleep((cw_len->ws) - (cw_len->cs));
	}
	break;
	
      default:
	putchar(*cp);
	cw_sign(cw_len, beepfd, *cp);
	cw_sign(cw_len, beepfd, ' ');
	break;
      }
      cp++;
    }
  }
  return 0;
}

int main (int argc, char ** argv)
{
  CWREAD_STAT stat;
  cw_length cw_len;
  struct sigaction sa;

  stat.in    = (char *)calloc(2, sizeof(char));
  stat.tone  = DEFAULT_TONE;
  stat.speed = DEFAULT_SPEED;
  /* initialize cw code database */
  cw_default_memset(&cw_len);

  if (argc > 1)
    optin(argc, argv, &cw_len, &stat);
  cw_defaultset(&cw_len, stat.tone, stat.speed);

  /* open beep device(/dev/console) */
  beepfd = beep_fdopen(beepfd);

  /* init & regist sigaction */
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = intHandler;
  if (sigaction(SIGINT, &sa, NULL)){
    perror("sigaction");
  }
  
  if((stat.fp = fopen(stat.in, "r")) == NULL){
    stat.fp = stdin;
  }
  
  setbuf(stdout, NULL);
  cwread(&cw_len, &stat);

  beep_close(beepfd);
  fclose(stat.fp);
  return 0;
}

// 符号データベースの検索
// キャラから番号検索
// printf("char_no(): %d\n", char_no(&cw_len, 'a'));
// 符号列から番号検索
// printf("note_no(): %d\n", note_no(&cw_len, "-.-."));

// 指定された文字列からCWを鳴らす関数
// デフォの設定は。。。
// 短点          '.'
// 長点          '-'
// 文字間の空白  ' '
// 単語間の空白  '*'
// それ意外の文字は何も起こらないが電気とあなたの労働力の無駄。
// beep_bufout(&cw_len, fd, ".... .-.*.... .-.*.... .-.***.-,-.*. .***");

// 単純にローマ字を指定し、音を出してみる。
//   cw_sign(&cw_len, fd, 'c');

// さも返事ああったかのように、周波数とスピードを少々変えてみます。(笑い）
// cw_defaultset(&cw_len, 880, 70);
