

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int safe_pthread_mutex_lock(pthread_mutex_t * mu)
{
int ret, uint;
uint = 10000;

while(1){
   ret = pthread_mutex_trylock(mu);
   if(0 == ret){
      break;
      }
   else{
      #ifdef THREAD_LOCK_BUG
      fprintf(stderr,"pthread trylock err. <%d> <%d>\n", (int)mu, uint);
      #endif
      }
   if(uint > 500000){ uint = 500000; }
   usleep(uint);
   uint = uint + 10000;
   }

return ret;
}
