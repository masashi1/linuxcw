
#include<stdio.h>



int outchar(int * n, char ** ptr, char c);


/* base64 encode  */
int base64(char * data, int size, char * into)
{
char now[3];
char c;
int i, h, n;
char * ptr;
ptr = into;
n = 0;
for(i = 0; i < size; i += 3){
   if(i + 2 < size){
      now[0] = data[i];
      now[1] = data[i + 1];
      now[2] = data[i + 2];
      c=(now[0]>>2)&0x3f;
      outchar(&n, &ptr, c);
      c=((now[0]<<4)&0x30) + ((now[1]>>4)&0x0f);
      c&=0x3f;
      outchar(&n, &ptr, c);
      c=((now[1]<<2)&0x3c) + ((now[2]>>6)&0x03);
      c&=0x3f;
      outchar(&n, &ptr, c);
      c=now[2]&0x3f;
      c&=0x3f;
      outchar(&n, &ptr, c);
      }
   else if(i + 1 < size){
      now[0] = data[i];
      now[1] = data[i + 1];
      c=(now[0]>>2)&0x3f;
      outchar(&n, &ptr, c);
      c=((now[0]<<4)&0x30) + ((now[1]>>4)&0x0f);
      c&=0x3f;
      outchar(&n, &ptr, c);
      c=((now[1]<<2)&0x3c);
      c&=0x3f;
      outchar(&n, &ptr, c);
      }
   else{
      now[0] = data[i];
      c=(now[0]>>2)&0x3f;
      outchar(&n, &ptr, c);
      c=((now[0]<<4)&0x30);
      c&=0x3f;
      outchar(&n, &ptr, c);
      }
   }

h = 4 - (n%4);
if(h != 4){
   for(i = 0; i < h; i++){
      *ptr = '=';
      ptr++;
      }
   }

*ptr='\0';
return(0);
}







int outchar(int * n, char ** ptr, char c)
{

#ifdef BASE64_DEBUG
printf("%d ", c);
#endif

if(c <= 25){
   **ptr = c+'A';
   }
else if(c <= 51){
   **ptr = c-26+'a';
   }
else if(c <= 61){
   **ptr = c-52+'0';
   }

else if(c == 62){
   **ptr = '+';
   }

else if(c == 63){
   **ptr = '/';
   }
(*ptr)++;
(*n)++;

// if(cat > 0){
//   if((*n)%76 == 0){
//      **ptr = '\n';
//      (*ptr)++;
//      }
//   }

#ifdef BASE64_DEBUG
printf("%d ", **ptr);
printf("%c\n", **ptr);
#endif
return 0;
}              




