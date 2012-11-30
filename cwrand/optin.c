#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libbeep.h"
#include "libcw.h"
#include "cwrand.h"
#include "almemsys.h"


int optin(int argc, char * argv[], cw_length * cw_len, int * moji, int * co, int * mode, int * exa_mode, int *start, int * stop, int * bb, int * kk)
{
  char i;
  int sp, to;
  extern char * optarg;
  const struct option cwrand_long_opt[]={
    {"help"	  , no_argument, NULL, NULL},
    {"print1"	  , no_argument, NULL, NULL},
    {"print2"	  , no_argument, NULL, NULL},
    {"examination", no_argument, NULL, NULL},
    {"figure"	  , no_argument, NULL, NULL},
    {"roman"	  , no_argument, NULL, NULL},
    {"sign"	  , no_argument, NULL, NULL},
    {0            , 0          , 0   , 0   },
  };

  i = 0x00;
  sp = 0;
  to = 0;
  * moji = 5;
  * co = 1;
  * mode = 0;
  * exa_mode = 0;

  while((i = (char)getopt(argc, argv, "v:s:b:k:c:m:t:-:"))!= EOF){
    switch(i){
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
    case '-':
      if(0 == memcmp(optarg, "help", 4)){
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

      else if(0 == memcmp(optarg, "examination", 11)){
#ifdef CWRAND_BUG
	printf("An unnecessary sign is deleted.\n");
#endif
	* exa_mode = 1;
      }

      else if(0 == memcmp(optarg, "print1", 6)){
#ifdef CWRAND_BUG
	printf("print mode setings. 1\n");
#endif
	* mode = 1;
      }

      else if(0 == memcmp(optarg, "print2", 6)){
#ifdef CWRAND_BUG
	printf("print mode setings. 1\n");
#endif
	* mode = 2;
      }

      else if(0 == memcmp(optarg, "figure", 6)){
#ifdef CWRAND_BUG
	printf("Figure mode. \n");
#endif
	* start = 0;
	* stop = 9;
      }

      else if(0 == memcmp(optarg, "roman", 5)){
#ifdef CWRAND_BUG
	printf("roman alphabet. \n");
#endif
	* start = 10;
	* stop = 35;
      }

      else if(0 == memcmp(optarg, "sign", 4)){
#ifdef CWRAND_BUG
	printf("sign mode. \n");
#endif
	* start = 36;
	* stop = 48;
      }

      else{
      }

      break; 


    default :
      printf("cwrand -c <count> -m <Number> -s <Speed> -t <tone>\n");
      break;
    }
  }

  return 0;
}
