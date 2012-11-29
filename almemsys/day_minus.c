#include "almemsys.h"

//  現在の年月で、一日前の日をかえす。(1 - 1 = 31)
int day_minus(int day_d)
{
int ret, day;
ret = -1;
day = 1;

if     (day_d <= 0){ day = 1; }
else if(day_d > 31){ day = 31; }
else               { day = day_d; }

if(day == 1){
   switch(ctime_getr('m')){
      case 1: ret = 31; break;
      case 2: ret = 31; break;
      case 3:
      switch(ctime_getr('y')){
         case 2008: ret = 29; break;
         case 2009: ret = 28; break;
         case 2010: ret = 28; break;
         case 2011: ret = 28; break;
         case 2012: ret = 29; break;
         case 2013: ret = 28; break;
         default: ret = 28; break;
         }
                        break;
      case 4: ret = 31; break;
      case 5: ret = 30; break;
      case 6: ret = 31; break;
      case 7: ret = 30; break;
      case 8: ret = 31; break;
      case 9: ret = 31; break;
      case 10: ret = 30; break;
      case 11: ret = 31; break;
      case 12: ret = 30; break;
      default: ret = 31; break;
      }
   }
else{ ret = day - 1; }

return ret;
}




