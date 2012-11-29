@SET_MAKE@
AUTOMAKE_OPTIONS = 1.10 no-dependencies

CFLAGS = @MYCFLAGS@

noinst_LIBRARIES = libbeep.a

libbeep_a_CFLAGS = -I
libbeep_a_SOURCES = \
		beep_fdopen.c \
		beep_close.c \
		beep_on.c \
		beep_sleep.c

bin_PROGRAMS = libbeep_test beep_off

libbeep_test_SOURCES = libbeep_test.c libbeep.h prototype.h 
libbeep_test_LDADD= -lbeep
libbeep_test_LDFLAGS = -L. 
libbeep_test_CFLAGS = 

beep_off_SOURCES = beep_off.c libbeep.h prototype.h 
beep_off_LDADD= -lbeep
beep_off_LDFLAGS = -L. 
beep_off_CFLAGS = 

