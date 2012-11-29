
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"libbeep.h"
#include"libcw.h"
#include"cwrand.h"
#include"almemsys.h"


int calloptin(int argc, char * argv[], cw_length * cw_len, int * mo, int * no, int * bb, int * mode)
{
char i;
int sp, to;
extern char * optarg;
i = 0x00;
sp = 0;
to = 0;
* bb = 1;
* mo = 1;
* no = 1;
* mode = 0;

while((i = (char)getopt(argc, argv, "v:s:b:c:m:t:-:"))!= EOF){
   switch(i){
      case 'c':
                #ifdef CWRAND_BUG
                printf("コールサインの生成回数. <%s>\n", optarg);
                #endif
                * no = strtol(optarg, (char **)NULL, 10);
                break; 
      case 'm':
                #ifdef CWRAND_BUG
                printf("同じコールサインの繰り返し数. <%s>\n", optarg);
                #endif
                * mo = strtol(optarg, (char **)NULL, 10);
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
      case '-':
                if(0 == memcmp(optarg, "help", 4)){
                    printf("cwcallrand は、欧文モールス信号の学習の為の道具です。\n");
                    printf("       ランダムに文字を選択し、モールスを発信します。\n");
                    printf("       cwcallrand は以下のオプションに対応しています。\n");
                    printf("\n");
                    printf("cwcallrand -c <繰り返し> -m <数> -s <速度> -t <周波数>\n");
                    printf("\n");
                    printf("-t <発信音>\n");
                    printf("-s <速度>\n");
                    printf("-c <生成するコールサインの数>\n");
                    printf("-m <同じコールサインの繰り返し数>\n");
                    printf("-b <コールサイン間に開けるスペースの数>\n");
                    printf("\n");
                    printf("--help           ヘルプの表示\n");
                    printf("--default         一行ずつ表示します\n");
                    printf("--japan           いち文字ずつ表示します\n");
                    exit(1);
                    }

                else if(0 == memcmp(optarg, "default", 7)){
                    #ifdef CWRAND_BUG
                    printf("all randam call sign.\n");
                    #endif
                    * mode = 1;
                    }

                else if(0 == memcmp(optarg, "japan", 5)){
                    #ifdef CWRAND_BUG
                    printf("japan call sign.\n");
                    #endif
                    * mode = 2;
                    }

                else{
                    }

                break; 


      default :
                printf("cwcallrand -c <繰り返し> -m <数> -s <速度> -t <周波数>\n");
                break;
      }
   }

return 0;
}





