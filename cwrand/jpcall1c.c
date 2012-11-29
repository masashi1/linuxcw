
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"almemsys.h"


char jpcall1c(void)
{
char an;
int rand;

rand = (int)randdata(0, 9);

switch(rand){
   case 0: an = 'J'; break;
   case 1: an = 'J'; break;
   case 2: an = 'J'; break;
   case 3: an = 'J'; break;
   case 4: an = 'J'; break;
   case 5: an = 'J'; break;
   case 6: an = '7'; break;
   case 7: an = '7'; break;
   case 8: an = '8'; break;
   case 9: an = '8'; break;
   default : an = 'J'; break;
   }

return an;
}




