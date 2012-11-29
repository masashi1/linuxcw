#include<stdio.h>
#include"libbeep.h"
#include"libcw.h"


int cw_sign_wabun(cw_length * cw_len, int fd, char * sign)
{
int no;
no = 0;

no = char_no_wabun(cw_len, sign);

#ifdef LIBCW_BUG
printf("LIBCW_BUG: cw_sign_wabun(): <%s> <%d> <%s>\n", sign, no, cw_len->wabun.note_sign[no]);
#endif

beep_bufout(cw_len, fd, cw_len->wabun.note_sign[no]);

return 0;
}



