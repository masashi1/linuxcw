
#include<stdio.h>
#include<string.h>



/* ----------- SELF STRNCAT ------------- */
int self_strncat(char * pan, char * data, int buf_size)
{
static int ret;
int len1 = strlen(pan);
int len2 = strlen(data)+1;

ret = 0;
if((buf_size-1) >= (len1 + len2)){
   strncat(pan, data, len2);
   }
else {
   fprintf(stderr,"size err self_strncat() %d %d->%s %d->%s\n", buf_size, len1, pan, len2, data);
   }
return(ret);
}

