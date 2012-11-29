#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"almemsys.h"

/* ujtoj komata mitsuyuki著　TCP_IP ネットワークプログラミング引用  */

#define iseuckanji(c) (0xa1<=(unsigned char)(c&0xff) && (unsigned char)(c&0xff)<=0xfe)
#define iseuckana(c) (0x8e==(unsigned char)(c&0xff))



char * mime_ujtoj(char * from)
{
int i, len, c, kanji_flag, flag;
char * head = "=?ISO-2022-jp?B?";
char * tail = "?=";
char ato[128];
char * to = ato;
char * data = (char *)calloc(2, sizeof(char));
char * swap = (char *)calloc(2, sizeof(char));

memset(to, 0x00, 128);

len = (int)strlen(from);
c = 0;
kanji_flag = 0;
flag = 0;

for(i = 0; i < len; i++){
   if(iseuckanji(from[i])){       // kanji
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

      #ifdef MIME_BASE64_BUG
      printf("MIME_BASE64_BUG: mime_base64.c: kanji %d\n", c);
      #endif

      if(c > (76 - 17 * 3 / 4)){ 

         to[c] = 0x1b;
         c++; 
         to[c] = 0x28;
         c++; 
         to[c] = 0x4a;
         c++;

         to[c] = 0x00;
         c = 0;
         swap = safe_memcpy(swap, to, BUF_MAX);

         #ifdef MIME_BASE64_BUG
         printf("MIME_BASE64_BUG: mime_base64.c: kanji <%x> %s \n",swap[0], swap);
         #endif

         swap = safe_base64(swap);
         if(flag == 0){
            data = safe_memcpy(data, head, BUF_MAX);
            }
         else{
            data = safe_strncat(data, "\t ", BUF_MAX);
            data = safe_strncat(data, head, BUF_MAX);
            }
         data = safe_strncat(data, swap, BUF_MAX);
         data = safe_strncat(data, tail, BUF_MAX);
         data = safe_strncat(data, "\r\n", BUF_MAX);
         memset(to, 0x00, 128);
         flag = 1;
         kanji_flag = 0;

         #ifdef MIME_BASE64_BUG
         printf("MIME_BASE64_BUG: mime_base64.c: kanji %s\n",data);
         #endif

         }

      }
   else{                    // not kanji
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

      #ifdef MIME_BASE64_BUG
      printf("MIME_BASE64_BUG: mime_base64.c: not kanji %d\n", c);
      #endif

      if(c > (76 - 17 * 3 / 4)){ 
         to[c] = 0x00;
         c =0;
         swap = safe_memcpy(swap, to, BUF_MAX);

         #ifdef MIME_BASE64_BUG
         printf("MIME_BASE64_BUG: mime_base64.c: not kanji <%x> %s \n",swap[0], swap);
         #endif

         swap = safe_base64(swap);
         if(flag == 0){
            data = safe_memcpy(data, head, BUF_MAX);
            }
         else{
            data = safe_strncat(data, "\t ", BUF_MAX);
            data = safe_strncat(data, head, BUF_MAX);
            }
         data = safe_strncat(data, swap, BUF_MAX);
         data = safe_strncat(data, tail, BUF_MAX);
         data = safe_strncat(data, "\r\n", BUF_MAX);
         memset(to, 0x00, 128);
         flag = 1;
         kanji_flag = 1;

         #ifdef MIME_BASE64_BUG
         printf("MIME_BASE64_BUG: mime_base64.c: not kanji %s\n",data);
         #endif

         }

      }
   }


to[c] = 0x1b;
c++; 
to[c] = 0x28;
c++; 
to[c] = 0x4a;
c++;

to[c] = '\0';
swap = safe_memcpy(swap, to, BUF_MAX);

#ifdef MIME_BASE64_BUG
printf("MIME_BASE64_BUG: mime_base64.c: owari <%x> %s \n",swap[0], swap);
#endif

swap = safe_base64(swap);

if(flag == 0){
   data = safe_memcpy(data, head, BUF_MAX);
   }
else{
   data = safe_strncat(data, "\t ", BUF_MAX);
   data = safe_strncat(data, head, BUF_MAX);
   }
data = safe_strncat(data, swap, BUF_MAX);
data = safe_strncat(data, tail, BUF_MAX);

#ifdef MIME_BASE64_BUG
printf("MIME_BASE64_BUG: mime_base64.c: owari %s\n",data);
#endif


from = safe_memcpy(from, data, BUF_MAX);
free(swap);
free(data);

return from;
}





