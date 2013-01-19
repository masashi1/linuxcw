@SET_MAKE@
AUTOMAKE_OPTIONS = 1.10 no-dependencies

AM_CFLAGS = @MYCFLAGS@

bin_PROGRAMS = cwread

cwread_SOURCES = cwread.c cwread.h optin.c libcw.h libbeep.h almemsys.h
cwread_LDADD= -lcw -lbeep -lalmemsys
cwread_LDFLAGS = -L. -L../libbeep -L../libcw -L../almemsys
cwread_CFLAGS =  -I. -I../libbeep -I../libcw -I../almemsys


