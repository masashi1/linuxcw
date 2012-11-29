// memcount_cpm.c
// $Id: memcount_cpm.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>


/* --------------- MEMCOUNT_CPM ---------------- */
int memcount_cpm(char * back, char * data, int sta, int sto, int len)
{
int max, count, count1;
max = (int)strlen(data);
count1 = 0;

if(max < 1 || sto < sta){
   return -1;
   }

for(count = sta; count <= sto && count < max; count++){
   back[count1] = data[count];
   count1++;
   if(count1 >= len){
      break;
      }
   }

back[count1] = (char)0x00;

return count;
}



