/* -*- C -*- */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include "libbeep.h"

int beep_sleep (int length)
{
  usleep(1000 * length);
  return 0;
}


