
#ifndef _CWRAND_H_
  #define _CWRAND_H_

/* #define CWRAND_BUG */
/* #include "prototype.h" */

typedef struct {
  int mode;
  int exa_mode;
  int loop;
  int start;
  int stop;
} CWRAND_STAT;
    
int	optin (int argc, char * argv[], cw_length * cw_len, int * moji, CWRAND_STAT *stat, int * bb, int * kk);
int	anunnec (int char_no, int exa_mode);
int	calloptin (int argc, char * argv[], cw_length * cw_len, int * mo, int * no, int * bb, int * mode);
char	jpcall1c (void);

#endif
