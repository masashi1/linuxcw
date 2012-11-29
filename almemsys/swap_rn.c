

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "almemsys.h"



// 文字列全体の中のすべてのchS(char)を、(\r\n)の改行に置き換える。 
char * swap_rn(char *data, char chS)
{
char * swap;
int max, count, count1, count2;
int nlen = 0;
count1 = 0;
max = strlen(data);

for(count2 = 0; count2 < max; count2++){
   if(data[count2] == chS){
      nlen++;
      }
   }

if((swap = (char *)calloc(BUF_DEFLEN, sizeof(char)))==NULL){exit(1);}

if(nlen > 0){
   if((swap = (char*)realloc(swap, sizeof(char) * (max + nlen + 1)))==NULL){
      fprintf(stderr,"swap_rn(): The memory cannot be newly secured. \n");
      exit(1);
      }

   for(count = 0; count < max; count++){
      if(data[count] == chS){
         swap[count1] = '\r';
         count1++;
         swap[count1] = '\n';
         count1++;
         }
      else {
         swap[count1] = data[count];
         count1++;
         }
      }
   swap[count1] = (char)0x00;
   clean_mem(data, '\0', (int)strlen(data));
   data = safe_memcpy(data, swap, BUF_MAX);

   }

free(swap);

return data;
}




