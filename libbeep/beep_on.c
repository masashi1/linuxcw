
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include "libbeep.h"



// int beep_on(int console_fd, int length, int freq);



int beep_on(int console_fd, int length, int freq)
{
int ret;

ret = 0;

if(freq <= 0){
   freq = DEF_FREQ;
   }
if(length <= 0){
   length = DEF_LENGTH;
   }

if(ioctl(console_fd, KIOCSOUND, (int)(CLOCK_RATE/freq)) < 0) {
   fprintf(stderr, "/dev/console のせっていができないみたいよ\n");
// ret = -1;
   exit(1);
   }
else{
   usleep(1000 * length);
   ioctl(console_fd, KIOCSOUND, 0);
   }

return ret;
}






