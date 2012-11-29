#include<stdio.h>
#include<string.h>



int mem_tcount(char * chData, char chA)
{
int buk;
int count;
int inMax = strlen(chData);

buk = 0;
for(count = 0; count < inMax; count++){
   if(chData[count] == chA){
      buk=count;
      return(buk);
      }
   }
return(buk);
}



