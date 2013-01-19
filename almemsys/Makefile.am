@SET_MAKE@
AUTOMAKE_OPTIONS = 1.10 no-dependencies

AM_CFLAGS = @MYCFLAGS@

noinst_LIBRARIES = libalmemsys.a

libalmemsys_a_SOURCES = \
		delim_get.c \
		safe_fdcat.c \
		safe_fdcpm.c \
		safe_filefdcat.c \
		safe_fpcat.c \
		safe_memcpy.c \
		safe_sprintf.c \
		safe_strncat.c \
		socket_reada.c \
		socket_readas.c \
		socket_reads.c \
		socket_sends.c \
		mlexit.c \
		self_memcpy.c \
		socket_send.c \
		select_fdcat.c \
		alget_read.c \
		alget_write.c \
		self_memcmp.c \
		count_memcpy.c \
		mem_count.c \
		mem_tcount.c \
		char_count.c \
		rm_char.c \
		char_point.c \
		char_get.c \
		clean_mem.c \
		set_mem.c \
		rm_crlf.c \
		delim_count.c \
		memcount_cpm.c \
		ch_int.c \
		ch_int2.c \
		ch_int3.c \
		ch_int_v4.c \
		ch_int_v6.c \
		swap_mem.c \
		chmem.c \
		swap_rn.c \
		alversion.c \
		file_copy.c \
		count_memcpy2.c \
		unlinkdir.c \
		ch_char.c \
		char_wday.c \
		char_mon.c \
		utime_getr.c \
		ctime_getr.c \
		time_minus.c \
		get_unixtime.c \
		day_minus.c \
		month_last.c \
		month_minus.c \
		time_getr.c \
		socket_bind.c \
		socket_accept.c \
		socket_connect.c \
                socket_accept46.c \
                socket_accept46rfd.c \
                socket_bind46.c \
                socket_connect46.c \
		base64.c \
		safe_base64.c \
		safe_ujtoj.c \
		ujtoj.c \
		randdata.c \
		mime_ujtoj.c \
		message_id.c \
		null_free.c \
		self_delim_get.c \
		self_strncat.c \
		safe_pthread_mutex_lock.c \
		bit.c


bin_PROGRAMS = almemsystest

almemsystest_SOURCES = test.c almemsys.h
almemsystest_LDADD= -lalmemsys
almemsystest_LDFLAGS = -L.

