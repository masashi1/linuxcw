// safe_fdcat.c
// $Id: safe_fdcat.c,v 1.3 2007/11/01 05:54:46 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

#include "almemsys.h"


char * safe_fdcat(int sk, char * all_data, int * stat, int max_len, int interval)
{
char buff[BUF_DEFLEN];
int indata, allcu;

allcu = 0;

if(all_data == NULL){
   all_data = (char *)calloc(BUF_DEFLEN, sizeof(char));
   }
else{
   all_data = null_free(all_data);
   }

while(1){
   if((indata = socket_reads(sk, buff, sizeof(buff), interval)) > 0){
      if(NULL != (strchr(buff, (int)'\n'))){
         allcu = allcu + indata;
         #ifdef SOCKET_BUG
         fprintf(stderr,"safe_fdcat(1): 改行読んだし　脱出！ 全部で %d バイト読んだよ！\n", allcu);
         #endif
         buff[indata] = (char)0x00;
         all_data = safe_strncat(all_data, buff, BUF_MAX);
         break;
         }
      else{
         allcu = allcu + indata;
         #ifdef SOCKET_BUG
         fprintf(stderr,"sfe_fdcat(2): %d バイト足して、いまんとこ %d バイト読んだよ！\n",
           indata, allcu);
         #endif
         buff[indata] = (char)0x00;
         all_data = safe_strncat(all_data, buff, BUF_MAX);
         if(allcu > max_len){
            #ifdef SOCKET_BUG
            fprintf(stderr,"safe_fdcat(3): たいへんだぁー！ %d も読んでるよ、おなかいっぱい\n", allcu);
            #endif
            all_data = safe_memcpy(all_data, "\n", BUF_MAX);
            allcu = -1;
            break;
            }
         }
      }
   else{
      #ifdef SOCKET_BUG
      fprintf(stderr,"safe_fdcat(4): recv失敗したし 脱出！ \n");
      #endif
      allcu = -1;
      all_data = safe_memcpy(all_data, "\n", BUF_MAX);
      break;
      }
   }  // while()


* stat = allcu;
return all_data;

}



