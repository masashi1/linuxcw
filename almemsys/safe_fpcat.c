// safe_fpcat.c
// $Id: safe_fpcat.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>

#include "almemsys.h"




char * safe_fpcat(FILE * fp, char * getdata, int * stat, int max_len)
{
char data[BUF_DEFLEN];
unsigned int chA;
int count = 0;
int fp_stat = 0;

if(getdata == NULL){
   getdata = (char *)calloc(BUF_LEN, sizeof(char));
   }
else{
   getdata = null_free(getdata);
   }

while(fp_stat == 0){
   chA = fgetc(fp);

   switch(chA){
      case '\n': data[count] = (char)0x00;
                 getdata = safe_strncat(getdata, data, max_len);
                 fp_stat = 1;
                 break;
      case EOF : data[count] = (char)0x00;
                 getdata = safe_strncat(getdata, data, max_len);
                 fp_stat = 1;
                 * stat = -1;
                 break;
      default  : data[count] = chA;
                 if(count < max_len){
                    count++;
                    }
                 if(count >= max_len){
                    data[count] = (char)0x00;
                    getdata = safe_strncat(getdata, data, max_len);
                    fp_stat = 1;
                    return getdata;
                    }
                 break; 
      } /* switch */

   if(count > (BUF_DEFLEN -2) && fp_stat != 1){
      data[count] = (char)0x00;
      getdata = safe_strncat(getdata, data, max_len);
      clean_mem(data, (char)0x00, (int)strlen(data));
      count = 0;
      }
   } /* while */
#ifdef AL_DEBUG
printf("GET DATA2 %s <%d>\n", getdata, (int)strlen(getdata));
#endif
return getdata;
} 





