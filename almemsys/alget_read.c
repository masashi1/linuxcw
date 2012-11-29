// alget_read.c
// $Id: alget_read.c,v 1.4 2007/11/01 06:11:01 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>
#include<unistd.h>

#include"almemsys.h"


// char * alget_read(char *, int, int, int, int *, char, int, int);


// fdから得たデータをネゴしながら小分けで受け取りファイルに書き出す関数。
// mode 1 client -> server  最後にステータスを送る
// mode 0 server -> client  受け取って終わり

char * alget_read(char * filename,
                  char * rec,
                  int sk,
                  int interval,
                  int * stat,
                  char delim,
                  int file_len,
                  int mode)
{
FILE * fp;
int fd;
int count, fstat, co, onesize, allsize;

fp = NULL;
count = 0;
fstat = 0;
fd = 0;
co = 0;
onesize = 0;
allsize = 0;

while(1){
   rec = select_fdcat(sk, rec, stat, BUF_MAX, interval);  // データ受けとり
   onesize = (int)strlen(rec);
   allsize = allsize + onesize;

   if(* stat < 0){
      fprintf(stderr,"alget_read(1): stat < 0\n");
      break;
      }
   else if((file_len * 3) < (int)strlen(rec)){
      fprintf(stderr,"alget_read(2): file_len < rec\n");
      break;
      }
   else if(co > 5000){
      fprintf(stderr,"alget_read(3): get data len err\n");
      break;
      } 
   else if(allsize > BUF_MAX){
      fprintf(stderr,"alget_read(4): get data size err\n");
      * stat = -1; 
      break;
      }


   else if('\n' == (char)rec[0]){
      if(mode == 1){
         * stat = socket_send(sk, "200OK: stop data\n", interval); 
         }
      break;
      }
   else if(0 == memcmp(rec, "400", 3)){    // 400の場合は200を返して終了(client mode 1)
      if(mode == 1){
         * stat = socket_send(sk, "200OK: stop data\n", interval); 
         }
      break;
      }
   else if(0 == memcmp(rec, "500", 3)){ 
      if(mode == 1){
         * stat = socket_send(sk, "200OK: stop data\n", interval); 
         }
      break;
      }

   else{
     if(fstat == 0){
        if((fp = fopen(filename, "w+"))!=NULL){   // file をopen
           fd = fileno(fp);
           }
        else{
           * stat = -1;
           break;
           }
        fstat = 1;
        }
      swap_mem(rec, (char)delim, '\n');       // 0x05 を '\n'に戻す
      count = write(fd, rec, (int)strlen(rec));
      rec = safe_memcpy(rec, "\n", BUF_MAX);
      }

   if((* stat = socket_send(sk, "MORE\n", interval)) < 0){   // MORE の送信
      break;
      }
   }  // while

if(fstat == 1){
   fclose(fp);
   }

return rec;
}






