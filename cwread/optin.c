
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"libbeep.h"
#include"libcw.h"
#include"cwread.h"
#include"almemsys.h"


// extern char * filenames;

int optin(int argc, char * argv[], cw_length * cw_len)
{
char i;
int sp, to;
extern char * optarg;
i = 0x00;
sp = 0;
to = 0;

while((i = (char)getopt(argc, argv, "v:s:f:t:"))!= EOF){
   switch(i){
      case 'f':
                printf("open file name <%s>\n", optarg);
                filenames = safe_memcpy(filenames, optarg, BUF_LEN);
                break; 
      case 's':
                printf("cw speed set. <%s>\n", optarg);
                sp = strtol(optarg, (char **)NULL, 10);
                cw_speedset(cw_len, sp);
                break; 
      case 't':
                printf("cw tone set. <%s>\n", optarg);
                to = strtol(optarg, (char **)NULL, 10);
                cw_toneset(cw_len, to);
                break; 
      default :
                filenames = safe_memcpy(filenames, "/mmp/taro", BUF_LEN);
                printf("file not open.\n");
                break;
      }
   }

return 0;
}



