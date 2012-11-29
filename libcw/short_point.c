#include<stdio.h>
#include"libbeep.h"
#include"libcw.h"


int short_point(cw_length * cw_len, int fd)
{
beep_on(fd, cw_len->sp, cw_len->freq); 
beep_sleep(cw_len->ps);
return 0;
}



