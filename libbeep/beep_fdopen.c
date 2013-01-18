/* -*- C -*- */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include "libbeep.h"

int beep_fdopen(int console_fd)
{
  console_fd = -1;

  if((console_fd = open(CONSOLE_DEVICE, O_WRONLY)) == -1) {
    fprintf(stderr, "Can't open %s.\n", CONSOLE_DEVICE);
    exit(1);
  }

  return console_fd;
}
