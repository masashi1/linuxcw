// alget_write.c
// $Id: alget_write.c,v 1.2 2007/11/01 06:11:01 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"almemsys.h"


// int alget_write(int, FILE *, int, char, int, int);


// FPから一行ずつ読み出したデータをネゴしながら一定量小分けでsendする関数
// mode 1 client -> server でデータを送る場合、最後はserverから受け取って終了 400
// mode 0 server -> client の場合、自分からの送信を最後に終了 300

int alget_write(int sock_fd, FILE * fp, int interval, char delim, int file_len, int mode)
{
char * swap;
char * data;
int ch, counts, stat;

ch = 0;
counts = 0;
stat = 0;
swap = (char *)calloc(BUF_DEFLEN, sizeof(char));
data = (char *)calloc(BUF_DEFLEN, sizeof(char));

while(1){

   if(ch >=0){

      // 行単位で一定量のBUFを作る
      while(1){
         swap = safe_fpcat(fp, swap, &ch, BUF_MAX);      // file から一行swapに読む
         swap = safe_strncat(swap, "\n", BUF_MAX);       // 最後に改行追加
         data = safe_strncat(data, swap, BUF_MAX);       // data の後ろにつなぐ
         if( file_len < (int)strlen(data) || ch < 0){    // 4K越えるか、読めない場合
            break;
            }
         }   // while

      swap_mem(data, '\n', (char)delim);  // '\n'を'0x05'に置き換え
      counts = mem_count(data, (char)delim);            // 最後に0x05がある位置
      data[counts] = '\n';                              // 最後の0x05を改行に
      }

   if(1 < (int)strlen(data)){                           // data が1以上なのでdata送信
      stat = socket_send(sock_fd, data, interval);
      data[0] = (char)0x00;
      }
   else if(ch < 0){                                     // data 1以下なので終了送信
      if(mode == 1){
         stat = socket_send(sock_fd, "400OK: stop send data\n", interval);
         swap = select_fdcat(sock_fd, swap, &stat, BUF_MAX, interval);
         }
      else{
         stat = socket_send(sock_fd, "400OK: stop send data\n", interval);
         }
      break;
      }

   // more を受け取る
   swap = select_fdcat(sock_fd, swap, &stat, BUF_MAX, interval);
   if(stat < 0 || 0 != memcmp(swap, "MORE", 4)){
      stat = socket_send(sock_fd, "500 NG file_send2(): not stat.\n", interval);
      break;
      }

   }  // while

free(swap);
free(data);

return stat;
}










