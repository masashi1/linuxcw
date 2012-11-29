// rm_crlf.c
// $Id: rm_crlf.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>

/*------------------ RM CRLF -------------------*/
int rm_crlf( char data[], int count )
{
static int inA;
inA = 0;
for(; inA < count; ){
   if( data[inA] == (char)0x0a || data[inA] == (char)0x0d ){
      data[inA] = (char)0x00;
      }
   inA++;
   }
return(inA);
}



