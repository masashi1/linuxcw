// 固定長のデリミターカット
// dataはlen分の長さが保証されていること

#include<stdio.h>
#include<string.h>
#include <errno.h>
#include <stdlib.h>

#include "almemsys.h"


int self_delim_get(char * swap, char * data, char delim, int target, int len)
{
int sto, sta, count, ret;
sta =0;
sto =0;
count = 0;
ret = 0;

// delim の位置、データの大きさ
count  = delim_count(swap, delim, target, &sta, &sto);
#ifdef MAIL_DEBUG
printf("DELIM 1 %d -> %d %d\n", sta, sto, count);
#endif
if(count > 0 && sta <= sto && count < len){
   ret = memcount_cpm(data, swap, sta, sto, len);
   }
else{
   ret = -1;
   }
#ifdef MAIL_DEBUG
printf("data =%s\n", data);
#endif

return ret;
}





