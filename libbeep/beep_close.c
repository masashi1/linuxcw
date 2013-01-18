/* -*- C -*- */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include "libbeep.h"

int beep_close(int console_fd)
{
  beep_off(console_fd);
  close(console_fd);
  return 0;
}
