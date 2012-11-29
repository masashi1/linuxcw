#include<stdio.h>
#include"libbeep.h"
#include"libcw.h"


int long_point(cw_length * cw_len, int fd)
{
beep_on(fd, cw_len->lp, cw_len->freq); 
beep_sleep(cw_len->ps);
return 0;
}



