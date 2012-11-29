#include<stdio.h>
#include<time.h>

#include "almemsys.h"

char * message_id(char * backdata, char * name, char * domain)
{
time_t tt;
tt  = time(NULL);

backdata = safe_sprintf(backdata, BUF_MAX,"%d%d%d%d%d%d.%d.%s@%s",
   utime_getr(tt, 'y'),
   utime_getr(tt, 'm'),
   utime_getr(tt, 'd'),
   utime_getr(tt, 'h'),
   utime_getr(tt, 'i'),
   utime_getr(tt, 's'),
   randdata(100000, 999999),
   name,
   domain);

return backdata;
}
