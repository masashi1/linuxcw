#include<stdio.h>

char char_replace(char ch)
{
char ret;
ret = 0x00;

switch(ch){
   case 'A': ret = 'a'; break;
   case 'B': ret = 'b'; break;
   case 'C': ret = 'c'; break;
   case 'D': ret = 'd'; break;
   case 'E': ret = 'e'; break;
   case 'F': ret = 'f'; break;
   case 'G': ret = 'g'; break;
   case 'H': ret = 'h'; break;
   case 'I': ret = 'i'; break;
   case 'J': ret = 'j'; break;
   case 'K': ret = 'k'; break;
   case 'L': ret = 'l'; break;
   case 'M': ret = 'm'; break;
   case 'N': ret = 'n'; break;
   case 'O': ret = 'o'; break;
   case 'P': ret = 'p'; break;
   case 'Q': ret = 'q'; break;
   case 'R': ret = 'r'; break;
   case 'S': ret = 's'; break;
   case 'T': ret = 't'; break;
   case 'U': ret = 'u'; break;
   case 'V': ret = 'v'; break;
   case 'W': ret = 'w'; break;
   case 'X': ret = 'x'; break;
   case 'Y': ret = 'y'; break;
   case 'Z': ret = 'z'; break;

   default : ret = ch;
   break;
   }

return ret;
}




