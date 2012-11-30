#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "libbeep.h"
#include "libcw.h"
#include "cwrand.h"
#include "almemsys.h"

static int usage (void)
{
  printf("cwrand は、欧文モールス信号の学習の為の道具です。\n");
  printf("       ランダムに文字を選択し、モールスを発信します。\n");
  printf("       cwrand は以下のオプションに対応しています。\n");
  printf("\n");
  printf("cwrand -c <Frequency> -m <Number> -s <Speed> -t <tone>\n");
  printf("\n");
  printf("-t <発信音>\n");
  printf("-s <速度>\n");
  printf("-m <暗分符号の数>\n");
  printf("-c <繰り返し>\n");
  printf("-b <記号間の時間x倍数>\n");
  printf("-k <同じ符号の繰り返し数>\n");
  printf("\n");
  printf("--help           ヘルプの表示\n");
  printf("--print1         一行ずつ表示します\n");
  printf("--print2         いち文字ずつ表示します\n");
  printf("--examination    国家試験に出ない符号をのぞきます\n");
  printf("--figure         数字のみを出力します\n");
  printf("--roman          ローマ字のみを出力します\n");
  printf("--sign           記号のみを出力します。\n");
  exit(1);
}

int optin(int argc, char * argv[], cw_length * cw_len, int * moji, int * co, CWRAND_STAT *stat, int * bb, int * kk)
{
  char i;
  int sp, to, long_opt, opt_index;
  extern char * optarg;
  struct option cwrand_long_opt[]={
    {"help"	  , no_argument, &long_opt, 'h'},
    {"print1"	  , no_argument, &long_opt, 'p'},
    {"print2"	  , no_argument, &long_opt, 'P'},
    {"examination", no_argument, &long_opt, 'e'},
    {"figure"	  , no_argument, &long_opt, 'f'},
    {"roman"	  , no_argument, &long_opt, 'r'},
    {"sign"	  , no_argument, &long_opt, 's'},
    {0            , 0          , 0   , 0   }
  };
  
  i = 0x00;
  sp = 0;
  to = 0;
  * moji = 5;
  * co = 1;
  stat -> mode = 0;
  stat -> exa_mode = 0;
  
  while ((i = (char)getopt_long(argc, argv, "v:s:b:k:c:m:t:-:hpPefrs", cwrand_long_opt, &opt_index))!= EOF) {
    switch (i) {
    case 0:
      switch (long_opt) {
      case 'h':
	usage();
	break;
	
      case 'p':
	stat->mode = 1;
	break;
	
      case 'P':
	stat->mode = 2;
	break;

      case 'e':
	stat->exa_mode = 1;
	break;

      case 'f':
	stat->start = 0;
	stat->stop  = 9;
	break;

      case 'r':
	stat->start = 10;
	stat->stop  = 35;
	break;
	
      case 's':
	stat->start = 10;
	stat->stop  = 48;
	break;

      default:

	break;
      }
    case 'c':
#ifdef CWRAND_BUG
      printf("Frequency of CW pattern. <%s>\n", optarg);
#endif
      * co = strtol(optarg, (char **)NULL, 10);
      break; 
    case 'm':
#ifdef CWRAND_BUG
      printf("number of charcters of random CW. <%s>\n", optarg);
#endif
      * moji = strtol(optarg, (char **)NULL, 10);
      break; 
    case 's':
#ifdef CWRAND_BUG
      printf("cw speed set. <%s>\n", optarg);
#endif
      sp = strtol(optarg, (char **)NULL, 10);
      cw_speedset(cw_len, sp);
      break; 
    case 't':
#ifdef CWRAND_BUG
      printf("cw tone set. <%s>\n", optarg);
#endif
      to = strtol(optarg, (char **)NULL, 10);
      cw_toneset(cw_len, to);
      break; 
    case 'b':
#ifdef CWRAND_BUG
      printf("cw break time set. <%s>\n", optarg);
#endif
      * bb = strtol(optarg, (char **)NULL, 10);
      break; 
    case 'k':
#ifdef CWRAND_BUG
      printf("cw return set. <%s>\n", optarg);
#endif
      * kk = strtol(optarg, (char **)NULL, 10);
      break; 
      
    default :
      printf("cwrand -c <count> -m <Number> -s <Speed> -t <tone>\n");
      break;
    }
  }

  return 0;
}
