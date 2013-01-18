/* -*- C -*- */

#ifndef _LIBBEEP_H_
#define _LIBBEEP_H_

#define CLOCK_RATE  1193180   /* clock rate */
#define DEF_FREQ    440       /* beep frequency(Hz) */
#define DEF_LENGTH  100       /* beep length */

#define CONSOLE_DEVICE  "/dev/console"

int beep_close (int console_fd);
int beep_fdopen (int console_fd);
int beep_on (int console_fd, int length, int freq);
int beep_off (int fd);
int beep_sleep (int length);

#endif
