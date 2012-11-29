// mem_count.c
// $Id: mem_count.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>



/* --------------- MEM COUNT ------------------ */
int mem_count(char * chData, char chA)
{
int buk;
int count;
int inMax = strlen(chData);

buk = 0;
for(count = 0; count < inMax; count++){
   if(chData[count] == chA){
      buk=count;
      }
   }
return(buk);
}



