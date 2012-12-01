/* -*- mode: C; -*- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "libbeep.h"
#include "libcw.h"
#include "cwrand.h"
#include "almemsys.h"
#include "version.h"


static int usage (void)
{
  /* puts("\ncwrand は、欧文モールス信号の学習の為の道具です。\n");
   * puts("       ランダムに文字を選択し、モールスを発信します。\n");
   * puts("       cwrand は以下のオプションに対応しています。\n");
   * puts("\n");
   * puts("cwrand -c <Frequency> -m <Number> -s <Speed> -t <tone>\n");
   * puts("\n");
   * puts("-t <発信音>\n");
   * puts("-s <速度>\n");
   * puts("-m <暗分符号の数>\n");
   * puts("-c <繰り返し>\n");
   * puts("-b <記号間の時間x倍数>\n");
   * puts("-k <同じ符号の繰り返し数>\n");
   * puts("\n");
   * puts("--help           ヘルプの表示\n");
   * puts("--print1         一行ずつ表示します\n");
   * puts("--print2         いち文字ずつ表示します\n");
   * puts("--examination    国家試験に出ない符号をのぞきます\n");
   * puts("--figure         数字のみを出力します\n");
   * puts("--roman          ローマ字のみを出力します\n");
   * puts("--sign           記号のみを出力します。\n"); */

  char usage[] =
    "\ncwrand is a study tool for morse code.\n"
    "- generate random code.\n"
    "- using beep sound.\n\n"
    "cwrand [options]\n"
    "  --tone        , -t <value>  : tone of beep(Hz).\n"
    "  --sign        , -S          : show only sign.\n"
    "  --speed       , -s          : speed.\n"
    "  --roman       , -r          : show roman-code only.\n"
    "  --print2      , -P          : show per a figure.\n"
    "  --print1      , -p          : show per a line.\n"
    "  --number      , -n <value>  : unknown.\n"
    "  --loop        , -l <value>  : loop <value> times.\n"
    "  --kk          , -k          : unknown.\n"
    "  --figure      , -f          : show only numenic.\n"
    "  --bb          , -b <value>  : unknown.\n"
    "  --examination , -e          : examination mode.\n"
    "  --version     , -v          : show version.\n"
    "  --help        , -h          : this.\n";

  printf("\nVersion: %s\n", VERSION);
  puts(usage);
  exit(1);
}

int optin(int argc, char * argv[], cw_length * cw_len, int * moji, CWRAND_STAT *stat, int * bb, int * kk)
{
  int i, sp, to, opt_index;
  extern char * optarg;
  struct option cwrand_long_opt[] = {
    {"bb"         , required_argument, NULL, 'b'},
    {"examination", no_argument,       NULL, 'e'},
    {"figure"	  , no_argument,       NULL, 'f'},
    {"help"	  , no_argument,       NULL, 'h'},
    {"kk"         , required_argument, NULL, 'k'},
    {"loop"       , required_argument, NULL, 'l'},
    {"number"     , required_argument, NULL, 'n'},
    {"print1"	  , no_argument,       NULL, 'p'},
    {"print2"	  , no_argument,       NULL, 'P'},
    {"roman"	  , no_argument,       NULL, 'r'},
    {"speed"      , required_argument, NULL, 's'},
    {"sign"	  , no_argument,       NULL, 'S'},
    {"tone"       , required_argument, NULL, 't'},
    {"version"    , no_argument,       NULL, 'v'},
    {0            , 0          ,       0   ,  0 },
  };

  /* default setting */
  i		   = 0x00;
  sp		   = 0;
  to		   = 0;
  *	moji	   = 5;
  stat->loop	   = 1;
  stat->mode	   = 0;
  stat->exa_mode = 0;
  
  while ((i = getopt_long(argc, argv, "hpPefrSvl:n:s:t:b:k:", cwrand_long_opt, &opt_index)) != EOF) {
    switch (i) {
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
    case 'S':
      stat->start = 10;
      stat->stop  = 48;
      break;
    case 'l':
      stat->loop = strtol(optarg, (char **)NULL, 10);
      break; 
    case 'n':
      * moji = strtol(optarg, (char **)NULL, 10);
      break; 
    case 's':
      sp = strtol(optarg, (char **)NULL, 10);
      cw_speedset(cw_len, sp);
      break; 
    case 't':
      to = strtol(optarg, (char **)NULL, 10);
      cw_toneset(cw_len, to);
      break; 
    case 'b':
      * bb = strtol(optarg, (char **)NULL, 10);
      break; 
    case 'k':
      * kk = strtol(optarg, (char **)NULL, 10);
      break;
    case 'v':
      printf("Version: %s\n", VERSION);
      exit(EXIT_SUCCESS);
      break;
    case 'h':
      usage();
      break;
    default :
      usage();
      break;
    }
  }

  return 0;
}
