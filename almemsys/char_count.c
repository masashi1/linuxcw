// char_count.c
// $Id: char_count.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura


#include<stdio.h>
#include<string.h>



/* --------------- CHAR COUNT ------------------ */
int char_count(char * chData, char chA)
{
static int buk;
int count;
int inMax = (int)strlen(chData);

buk = 0;
for(count = 0; count < inMax; count++){
   if(chData[count] == chA){
      buk++;
      }
   }
return(buk);
}




