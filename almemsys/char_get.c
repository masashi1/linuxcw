// char_get.c
// $Id: char_get.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura


#include<stdio.h>
#include<string.h>




/* ------------- CHAR GET ----------------------- */
int char_get(char * data, char * chData, char chA, int inCount)
{
static int count2;
int count, leng, Count;
leng = strlen(data);
count2 = 0;
Count = 0;

for(count = 0; count <= leng; count++){
   if(data[count] == chA){
      Count++;
      }
   if(inCount == Count){
      if(data[count] != chA){
         chData[count2] = data[count];
         count2++;
         }
      }
   }
chData[count2] = (char)0x00;
return(count2);
}




