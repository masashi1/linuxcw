
#include<stdio.h>
#include<stdlib.h>
#include"libbeep.h"
#include"libcw.h"
#include"cwread.h"

// char * filenames;


int main(int argc, char ** argv)
{
int fd;
FILE * fp;
char chA, chB;

fd = -1;
chA = 0x00;
chB = 0x00;
filenames = (char *)calloc(2, sizeof(char));

// cw用の構造体を定義します。
cw_length cw_len;

// デフォルトの符号データベースを初期化
cw_default_memset(&cw_len);

// デフォルトの信号の長さ(3)と周波数(2)を設定
cw_defaultset(&cw_len, 700, 130);

optin(argc, argv, &cw_len);

// beepデバイスファイルを開いてFDを得る
fd = beep_fdopen(fd);


if((fp = fopen(filenames, "r"))!=NULL){
   printf("open file name <%s>\n", filenames);
   while( chA != EOF ){
      chA=(char)fgetc(fp);

      printf("%c\n", chA);

      if(chA == '<'){
         cw_len.cs = 0;
         #ifdef CWREAD_BUG
         printf("CWREAD_BUG main(): up line set.\n");
         #endif
         }
      else if(chA == '>'){
         cw_len.cs = cw_len.sp * 2;
         #ifdef CWREAD_BUG
         printf("CWREAD_BUG main(): up line break.\n");
         #endif
         }
      else {
         if(chA == ' '){
            if(chB == ' '){ 
               cw_sign(&cw_len, fd, '*');
               #ifdef CWREAD_BUG
               printf("CWREAD_BUG main(): sleep1\n");
               #endif
               }
            else{
               beep_sleep(cw_len.ws - cw_len.cs);
               #ifdef CWREAD_BUG
               printf("CWREAD_BUG main(): sleep2\n");
               #endif
               }
            }
         else{
            cw_sign(&cw_len, fd, chA);
            cw_sign(&cw_len, fd, ' ');
            }
         chB = chA;
         }
      }
   fclose( fp );
   }

else {
   printf("file not open. stdin open.\n");
   while( chA != EOF ){
      chA=(char)fgetc(stdin);

      printf("%c\n", chA);

      if(chA == '<'){
         cw_len.cs = 0;     // 前の文字の後ろに1スペース入っているので0
         #ifdef CWREAD_BUG
         printf("CWREAD_BUG main(): up line set.\n");
         #endif
         }
      else if(chA == '>'){
         cw_len.cs = cw_len.sp * 2;  // 前の文字の後ろに1スペースあるので2
         #ifdef CWREAD_BUG
         printf("CWREAD_BUG main(): up line break.\n");
         #endif
         }
      else {
         if(chA == ' '){
            if(chB == ' '){ 
               cw_sign(&cw_len, fd, '*');
               #ifdef CWREAD_BUG
               printf("CWREAD_BUG main(): sleep1\n");
               #endif
               }
            else{
               beep_sleep(cw_len.ws - cw_len.cs);
               #ifdef CWREAD_BUG
               printf("CWREAD_BUG main(): sleep2\n");
               #endif
               }
            }
         else{
            cw_sign(&cw_len, fd, chA);
            cw_sign(&cw_len, fd, ' ');
            }
         chB = chA;
         }
      }
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


// beepのFDを開放し終了。
beep_close(fd);

return 0;
}




