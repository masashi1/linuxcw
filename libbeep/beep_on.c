/* -*- C -*- */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include "libbeep.h"

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
    fprintf(stderr, "initialize error (%s)\n", CONSOLE_DEVICE);
    // ret = -1;
    exit(1);
  }
  else{
    usleep(1000 * length);
    ioctl(console_fd, KIOCSOUND, 0);
  }

  return ret;
}

int beep_off(int fd)
{
  if (ioctl(fd, KIOCSOUND, 0) < 0){
    perror("beep_off");
  }
  else {
    return 0;
  }
  return 0;
}
