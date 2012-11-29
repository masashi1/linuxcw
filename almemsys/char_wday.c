#include <stdio.h>

#include "almemsys.h"


// 数字の順番で英語曜日の頭3文字をかえす
char * char_wday(int wday)
{
char * ret;
switch(wday){
   case 0 : ret = "Sun"; break;
   case 1 : ret = "Mon"; break;
   case 2 : ret = "Tue"; break;
   case 3 : ret = "Wed"; break;
   case 4 : ret = "Thu"; break;
   case 5 : ret = "Fri"; break;
   case 6 : ret = "Sat"; break;
   default : ret = "Not!"; break;
   }
return(ret);
}



