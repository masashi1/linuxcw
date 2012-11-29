
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

int utimesec()
{
struct timeval tv;
gettimeofday(&tv, NULL);
return (int)tv.tv_usec;
}

int randdata(int min, int max)
{
int a, in_max;
time_t t;

if(min >= max){
   min = 0;
   max = 1;
   }

in_max = (max - min) + 1;

t = utimesec();
srandom((unsigned int)t);
a = min + (int) ((double)in_max * random() / (RAND_MAX + 1.0));

#ifdef RANDDATA_BUG
printf("RANDDATA_BUG: randdata.c: utime=%d, randam=%d\n", t, a);
#endif

return a;
}


// int main(void)
// {
// int co;

// for(co = 0; co < 100; co++){
//   printf("%d\n", randdata(3, 7));
//   }

// return 0;
// }

