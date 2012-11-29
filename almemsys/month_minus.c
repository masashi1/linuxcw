


// 指定月から一ヶ月引いた月をかえす。単純。。。
int month_minus(int month)
{
int ret;
ret = -1;

switch(month){
   case 1: ret = 12;  break;
   case 2: ret = 1;   break;
   case 3: ret = 2;   break;
   case 4: ret = 3;   break;
   case 5: ret = 4;   break;
   case 6: ret = 5;   break;
   case 7: ret = 6;   break;
   case 8: ret = 7;   break;
   case 9: ret = 8;   break;
   case 10: ret = 9;  break;
   case 11: ret = 10; break;
   case 12: ret = 11; break;
   default: ret = 0; break;
   }

return ret;
}


