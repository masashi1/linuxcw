// set_mem.c
// $Id: set_mem.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>



/*------------------ SET MEM -------------------*/
int set_mem( char data[], char chA, int count )
{
int inA=0;
for(; inA < count; ){
   if( data[inA] == chA ){
      data[inA] = (char)0x00;
      }
   inA++;
   }
return inA;
}



