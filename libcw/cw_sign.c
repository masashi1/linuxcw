#include<stdio.h>
#include"libbeep.h"
#include"libcw.h"


int cw_sign(cw_length * cw_len, int fd, char sign)
{
int no;
no = 0;

sign = char_replace(sign);
no = char_no(cw_len, sign);

#ifdef LIBCW_BUG
printf("LIBCW_BUG: cw_sign(): <%c> <%d> <%s>\n", sign, no, cw_len->roman.note_sign[no]);
#endif

beep_bufout(cw_len, fd, cw_len->roman.note_sign[no]);

return 0;
}



