/* -*- C -*- */
#include<stdio.h>
#include"libbeep.h"

int main(void)
{
  int fd = -1;
  fd = beep_fdopen(fd);

  beep_on(fd, 300, 523);  // ど
  beep_sleep(300);

  beep_close(fd);

  return 0;
}
