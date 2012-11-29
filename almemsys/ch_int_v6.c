
#include<stdio.h>
#include<string.h>
#include<ctype.h>



/* -------------- CH_INT -------------- */
int ch_int_v6(char * data)
{
int count;
int ret = 0;
int max = (int)strlen(data);

for(count = 0; count < max; count++){
   switch((int)data[count]){
      case '0': ret = 0; break;
      case '1': ret = 0; break;
      case '2': ret = 0; break;
      case '3': ret = 0; break;
      case '4': ret = 0; break;
      case '5': ret = 0; break;
      case '6': ret = 0; break;
      case '7': ret = 0; break;
      case '8': ret = 0; break;
      case '9': ret = 0; break;
      case 'a': ret = 0; break;
      case 'b': ret = 0; break;
      case 'c': ret = 0; break;
      case 'd': ret = 0; break;
      case 'e': ret = 0; break;
      case 'f': ret = 0; break;
      case 'A': ret = 0; break;
      case 'B': ret = 0; break;
      case 'C': ret = 0; break;
      case 'D': ret = 0; break;
      case 'E': ret = 0; break;
      case 'F': ret = 0; break;
      case ':': ret = 0; break;
      default : ret = -1; break;
      }
   if(ret == -1){
      return ret;
      }
   }

return ret;
}





