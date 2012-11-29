#include<stdio.h>
#include"libbeep.h"


int main(void)
{
int fd = -1;
fd = beep_fdopen(fd);

beep_on(fd, 300, 523);  // ど
beep_sleep(300);
beep_on(fd, 300, 587);  // れ
beep_sleep(300);
beep_on(fd, 300, 659);  // み
beep_sleep(300);
beep_on(fd, 300, 698);  // ふぁ
beep_sleep(300);
beep_on(fd, 300, 784);  // そ
beep_sleep(300);
beep_on(fd, 300, 880);  // ら
beep_sleep(300);
beep_on(fd, 300, 988);  // し
beep_sleep(300);
beep_on(fd, 300, 1047); // ど

beep_close(fd);

return 0;
}


