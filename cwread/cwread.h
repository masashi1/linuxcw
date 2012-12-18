/* -*- C -*- */

#ifndef _CWREAD_H_
#define _CWREAD_H_
/* global variables */

typedef struct {
  char *in;
  char *out;
  int   speed;
  int   tone;
  FILE *fp;
  int   beep;
} CWREAD_STAT;

/* prototype */
int optin (int argc, char * argv[], cw_length * cw_len, CWREAD_STAT *stat);
int cwread (cw_length *, CWREAD_STAT *);

#endif
