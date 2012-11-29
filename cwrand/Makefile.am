@SET_MAKE@
AUTOMAKE_OPTIONS = 1.10 no-dependencies

CFLAGS = @MYCFLAGS@

bin_PROGRAMS = cwrand cwcallrand

cwrand_SOURCES = cwrand.c cwrand.h optin.c anunnec.c libcw.h libbeep.h almemsys.h
cwrand_LDADD= -lcw -lbeep -lalmemsys
cwrand_LDFLAGS = -L. -L../libbeep -L../libcw -L../almemsys
cwrand_CFLAGS =  -I. -I../libbeep -I../libcw -I../almemsys

cwcallrand_SOURCES = cwcallrand.c cwrand.h calloptin.c jpcall1c.c libcw.h libbeep.h almemsys.h
cwcallrand_LDADD= -lcw -lbeep -lalmemsys
cwcallrand_LDFLAGS = -L. -L../libbeep -L../libcw -L../almemsys
cwcallrand_CFLAGS =  -I. -I../libbeep -I../libcw -I../almemsys

