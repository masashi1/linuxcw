#include <stdio.h>

#include "almemsys.h"


// 数字月を英語月頭3文字でかえす
char * char_mon(int mon)
{
char * ret;
switch(mon){
   case 0 : ret = "Jan"; break;
   case 1 : ret = "Feb"; break;
   case 2 : ret = "Mar"; break;
   case 3 : ret = "Apr"; break;
   case 4 : ret = "May"; break;
   case 5 : ret = "Jun"; break;
   case 6 : ret = "Jul"; break;
   case 7 : ret = "Aug"; break;
   case 8 : ret = "Sep"; break;
   case 9 : ret = "Oct"; break;
   case 10 : ret = "Nov"; break;
   case 11 : ret = "Dec"; break;
   default : ret = "Not!"; break;
   }
return(ret);
}



