// char_point.c
// $Id: char_point.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>


/* --------------- CHAR POINT ------------------ */
int char_point(char * chData, char chA, int po)
{
static int buk;
int count;
int inMax = (int)strlen(chData);

buk = 0;
for(count = 0; count < inMax; count++){
   if(chData[count] == chA){
      buk++;
      if(buk == po){
         return count;
         }
      }
   }
return 0;
}





