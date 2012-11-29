// safe_fdcpm.c
// $Id: safe_fdcpm.c,v 1.2 2007/10/17 10:57:56 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>

#include "almemsys.h"




char * safe_fdcpm(int sk, char * getdata, int * stat, int max_len, int interval)
{
int indata = 0;
int inlen = 0;
int count = 0;
int plen = 0;
char bf[BUF_DEFLEN];
char * buf = bf;

if(getdata == NULL){
   getdata = (char *)calloc(BUF_LEN, sizeof(char));
   }
else{
   getdata = null_free(getdata);
   }

while(1){
   if((indata = socket_reads(sk, buf, BUF_DEFLEN, interval)) < 1){
      fprintf(stderr, "safe_fdcpm(): farst read err indata=%d\n", indata);
      fprintf(stderr, "ERRNO: %s\n", strerror(errno));
      * stat = -1;
      return NULL;
      }

   buf[indata] = (char)0x00;
 
   if(indata <= BUF_DEFLEN && indata > 0){
      if(max_len >= (inlen + indata)){
         inlen = inlen + indata;
         if((getdata = (char *)realloc(getdata, sizeof(char) * (inlen + 1)))==NULL){
            fprintf(stderr,"The memory cannot be newly secured. \n");
            mlexit();
            }
         strncat(getdata, buf, (indata + 1));
         clean_mem(buf, '\0', BUF_DEFLEN);
         count = mem_count(getdata, (char)0x0a);
         if(getdata[count] == (char)0x0a && count >= 0){
            getdata[count+1] = (char)0x00;
            #ifdef AL_DEBUG 
            printf("(1nomall)COUNT=<%d>COUNTALL=<%d>RIALCOUNT=<%d>GETDATA=<%s>POINT<%p><%d>\n",
                  indata, inlen, (int)strlen(getdata), getdata, getdata, count);
            #endif
            * stat = 0;
            return getdata;
            }
         }

      if(max_len < (inlen + indata)){
         plen = indata - (inlen - max_len);
         inlen = max_len;
         fprintf(stderr,"memory max count err. %d\n", inlen);
         if((getdata = (char *)realloc(getdata, sizeof(char) * (inlen + 1)))==NULL){
            fprintf(stderr,"The memory cannot be newly secured. \n");
            mlexit();
            }
         strncat(getdata, buf, (plen + 1));
         clean_mem(buf, '\0', BUF_DEFLEN);
         getdata[inlen - 1] = (char)0x00;
         #ifdef AL_DEBUG
         printf("(1 nomall)COUNT=<%d>COUNTALL=<%d>RIALCOUNT=<%d>GETDATA=<%s>POINT<%p>P<%d>\n",
               indata, inlen, (int)strlen(getdata), getdata, getdata, plen);
         #endif
         * stat = 0;
         return getdata;
         } 
      }
   }

return NULL;
}





