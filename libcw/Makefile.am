@SET_MAKE@
AUTOMAKE_OPTIONS = 1.10 no-dependencies

CFLAGS = @MYCFLAGS@

noinst_LIBRARIES = libcw.a

libcw_a_CFLAGS = -I../libbeep
libcw_a_SOURCES = \
	cw_defaultset.c \
	cw_speedset.c \
	cw_toneset.c \
	long_point.c \
	short_point.c \
	beep_bufout.c \
	cw_default_memset.c \
	cw_default_memset_roman.c \
	cw_default_memset_wabun.c \
	char_no.c \
	char_no_wabun.c \
	note_no.c \
	char_replace.c \
	cw_sign.c \
	cw_sign_wabun.c

bin_PROGRAMS = libcw_test

libcw_test_SOURCES = libcw_test.c libcw.h libbeep.h prototype.h 
libcw_test_LDADD= -lcw -lbeep
libcw_test_LDFLAGS = -L. -L../libbeep
libcw_test_CFLAGS =  -I../libbeep


