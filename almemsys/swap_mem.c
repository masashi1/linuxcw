// swap_mem.c
// $Id: swap_mem.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>


/*------------------ SWAP MEM -------------------*/
int swap_mem( char data[], char chA, char chB )
{
int inA, ret, count;
inA = 0;
ret = 0;

count = (int)strlen(data);

if(0 < count){
   for(; inA < count; ){
      if( data[inA] == chA ){
         data[inA] = chB;
         ret++;
         }
      inA++;
      }
   }

return(ret);
}


