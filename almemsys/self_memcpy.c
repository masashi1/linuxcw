// self_memcpy.c
// $Id: self_memcpy.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>


extern int count_memcpy(char *, char *, int);


/* ----------- SELF MEMCPY ------------- */
int self_memcpy(char * pan, char * data, int buf_size)
{
int ret;
int data_len = strlen(data) - 1;

ret = 0;
memset(pan, 0x00, buf_size-1);

if((buf_size -1) <= data_len ){
   count_memcpy(pan, data, buf_size -1);
// fprintf(stderr,"self_memcpy() %d %d->%s\n", buf_size, data_len, data);
   ret = 0;
   }
else {
   count_memcpy(pan, data, strlen(data)+1);
   ret = 0;
   }
return(ret);
}



