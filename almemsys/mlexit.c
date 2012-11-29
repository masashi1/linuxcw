// mlexit.c
// $Id: mlexit.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<stdlib.h>

int mlexit(void);

int mlexit(void)
{
fprintf(stderr, "malloc() Not set buffer. exit\n");
exit(1);
return 0;
}



