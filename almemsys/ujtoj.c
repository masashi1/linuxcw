
#include<stdio.h>
#include<string.h>



/* ujtoj komata mitsuyuki著　TCP_IP ネットワークプログラミング引用  */

#define iseuckanji(c) (0xa1<=(unsigned char)(c&0xff) && (unsigned char)(c&0xff)<=0xfe)
#define iseuckana(c) (0x8e==(unsigned char)(c&0xff))


/* ---- for test ---
int chcode(char * data)
{
int count, max;
count = 0;
max = strlen(data);
for(count = 0; count < max; count++){
   printf("0x0%x,", data[count]);
   }
return max;
}


int main(int argc, char ** argv)
{
char Out[1024];
char * out = Out;
char * in = "これこれしかじか";

ujtoj((unsigned char *)out, (unsigned char *)in);

printf("in data  <%s>\n", in);
chcode(in);
printf("out data <%s>\n", out);
chcode(out);

return 0;
}
*/


/* EUC -> JIS */
int ujtoj(unsigned char *to, unsigned char *from)
{
register int i, len, c;
int kanji_flag;

len = (int)strlen((char *)from);
c = 0;
kanji_flag = 0;

for(i = 0; i < len; i++){
   if(iseuckanji(from[i])){
      if(kanji_flag == 0){
         to[c] = 0x1b;
         c++;
         to[c] = 0x24;
         c++;
         to[c] = 0x42;
         c++;
         kanji_flag = 1;
         }
      to[c] = (from[i]&0x7f);
      c++; 
      to[c] = (from[i+1]&0x7f);
      c++;
      i++;
      }
   else{
      if(kanji_flag == 1){
         to[c] = 0x1b;
         c++; 
         to[c] = 0x28;
         c++; 
         to[c] = 0x4a;
         c++; 
         kanji_flag = 0;
         }
      to[c] = from[i];
      c++;
      }
   }

if(kanji_flag == 1){
   to[c] = 0x1b;
   c++; 
   to[c] = 0x28;
   c++; 
   to[c] = 0x4a;
   c++;
   kanji_flag = 0;
   }

to[c] = '\0';

return 0;
}





