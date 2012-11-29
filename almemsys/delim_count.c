// delim_count.c
// $Id: delim_count.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<string.h>

extern int char_count(char *, char);

/*------------------ DELIM_COUNT -------------------*/
int delim_count(char * data, char ca, int lim, int * sta, int *sto)
{
int co, max, maxlen, count, ret;
maxlen = (int)strlen(data);
max = char_count(data, ca);
count = 0;

for(co = 0; co < maxlen; co++){
   if(ca == data[co]){
      if(count == (lim - 1)){
         if(co == 0){
            * sta = co;
            }
         if(co > 0){
            * sta = co + 1;
            }
         }
      if(count == lim){
         * sto = co - 1;
         break;
         }
      count++;
      }
   }

if(co == maxlen){
   * sto = co - 1;
   }

if(max < lim || 0 > lim){
   * sta = 0;
   * sto = 0;
   ret = -1;
   }
else{
   ret = (*sto - *sta + 1);
   }

return ret;
}



