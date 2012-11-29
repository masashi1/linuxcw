#include<stdio.h>


int chmem(char * data, int in)
{
int ret,count;

ret = 0;

if(in < 0){
   ret = -1;
   }
else{
   for(count = 0; count < in; count++){
      data[count] = (char)0x00;
      }
   }

return ret;
}
