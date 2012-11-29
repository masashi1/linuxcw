// Bit 演算の道具

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

// #define INBIT_BUG


// char * out_bit(unsigned int ina, char * bit, int bx)
// unsigned long in_bit(char * bit, char bx)



// BIT表現の文字列 "01010101" を数字として変数に入れる
// 1: 1,0を使ったBIT表現の文字列ポインター 2: BIT数
unsigned long in_bit(char * bit, char bx)
{
unsigned long uca;
int max, co;

max = (int)strlen(bit);

if(bx < 8){ bx = 9; }
if(bx > 8 && bx < 16){ bx = 16; }
if(bx > 16 && bx < 32){ bx = 32; }
if(bx > 32){ bx = 32; }

if(max < bx || max > bx){
   uca = -1;
   #ifdef INBIT_BUG
   printf("err not data size\n");
   #endif
   return uca;
   }

for(co = 0; co < bx; co++){
   if(bit[co] != '1' && bit[co] != '0'){
      uca = -2;
      #ifdef INBIT_BUG
      printf("err not 0 or 1\n");
      #endif
      return uca;
      }
   }

uca = (unsigned long)strtoul(bit, (char **)NULL, 2);

#ifdef INBIT_BUG
printf("<%s> %d, %d, %d, %x\n", bit, max, bx, uca, uca);
#endif

return uca;
}





// 数字をBIT表現する
// 1: 表示したい変数 2: 予め32オクテット確保したポインター 3: 表示したいビット数
char * out_bit(unsigned int ina, char * bit, int bx)
{
char tib[34];
char co, con;
co = 0;
con = 0;

memset(tib, 0x00, 34);

if(bx < 8){ bx = 9; }
if(bx > 8 && bx < 16){ bx = 16; }
if(bx > 16 && bx < 32){ bx = 32; }
if(bx > 32){ bx = 32; }

while(ina){
   tib[co++] = ina % 2 + '0';
   ina = ina / 2;
   if(co >= bx){
      break;
      }
   }

if(co < bx){
   while(1){
      tib[co++] = '0';
      if(co >= bx){
         break;
         }
      }
   }

for(co = (bx - 1); co >= 0; co--){
   bit[con] = tib[co];
   con++;
   }

return bit;
}




/* お試しmain() 

int main(void)
{
char bit[34];

// 関数使用
unsigned char         ua8   = in_bit("10101010", 8);
unsigned short int    usi16 = in_bit("1010101001010101", 16);
unsigned long         ul32  = in_bit("00101010010101011111111100000000", 32);

memset(bit, 0x00, 34);

printf( "<%s><%02lx>\n", out_bit(ua8, bit, 8), ua8 ); 
printf( "<%s><%04lx>\n", out_bit(usi16, bit, 16), usi16 );
printf( "<%s><%08lx>\n", out_bit(ul32, bit, 32), ul32 );

memset(bit, 0x00, 34);

ua8 = in_bit("11111111", 8);
printf("-(1)-全部BITを立てた元データ-----------------------<%s><%d><0x%02lx>\n",
  out_bit(ua8, bit, 8), ua8, ua8);

printf("-(2)-1の下位4BITをマスク(bit単位の論理and演算 &)---<%s><%d><0x%02lx>\n",
  out_bit(ua8 & in_bit("11110000", 8), bit, 8), ua8 & in_bit("11110000", 8), ua8 & in_bit("11110000", 8));

ua8 = in_bit("00000000", 8);
printf("-(3)-全部BITをマスクした元データ-------------------<%s><%d><0x%02lx>\n",
  out_bit(ua8, bit, 8), ua8, ua8);

printf("-(4)-3の上位4BITをON(bit単位の論理or演算 |)--------<%s><%d><0x%02lx>\n",
  out_bit(ua8 | in_bit("11110000", 8), bit, 8), ua8 | in_bit("11110000", 8), ua8 | in_bit("11110000", 8));

ua8 = in_bit("01010101", 8);
printf("-(5)-交互にビットを立てた元データ------------------<%s><%d><0x%02lx>\n",
  out_bit(ua8, bit, 8), ua8, ua8);

printf("-(6)-5の下位4BITを反転(bit単位の排他論理or演算 ^)--<%s><%d><0x%02lx>\n",
  out_bit(ua8 ^ in_bit("00001111", 8), bit, 8), ua8 ^ in_bit("00001111", 8), ua8 ^ in_bit("00001111", 8));

printf("-(7)-5の全てのBITを無条件で反転(補数演算 ~)--------<%s><0x%02lx>\n",
  out_bit(~ua8, bit, 8), ~ua8);

printf("-(8)-5を左に3BITシフト(左シフト演算 <<)------------<%s><0x%02lx>\n",
  out_bit(ua8 << 3, bit, 8), ua8 << 3);

printf("-(9)-5を右に3BITシフト(右シフト演算 >>)------------<%s><0x%02lx>\n",
  out_bit(ua8 >> 3, bit, 8), ua8 >> 3);

usi16 = in_bit("1010101010101010", 16);
printf("-(10)-交互にビットを立てた元データ(16Bit)----------<%s><0x%04lx>\n",
   out_bit(usi16, bit, 16), usi16);

ul32 = in_bit("10101010101010110101010101010101", 32);
printf("-(11)-交互にビットを立てた元データ(32Bit)----------<%s><0x%08lx>\n",
  out_bit(ul32, bit, 32), ul32);

printf("-(12)-11を補数で反転(32Bit補数演算)----------------<%s><0x%08lx>\n",
  out_bit(~ul32, bit, 32), ~ul32);

printf("-(12)-11を左に16シフト(32Bit)----------------------<%s><0x%08lx>\n",
  out_bit(ul32 << 16, bit, 32), ul32 << 16);

printf("-(12)-11を右に16シフト(32Bit)----------------------<%s><0x%08lx>\n",
  out_bit(ul32 >> 16, bit, 32), ul32 << 16);

return 0;
}

*/





