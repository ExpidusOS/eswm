AM_CPPFLAGS = \
	-I${top_srcdir}

noinst_LTLIBRARIES = \
	libeswm-common.la

libeswm_common_la_SOURCES = \
	eswm-common.c \
	eswm-common.h

libeswm_common_la_CFLAGS = \
	$(GTK_CFLAGS) \
	$(PLATFORM_CFLAGS)

libeswm_common_la_LIBADD = \
	$(GTK_LIBS)

libeswm_common_la_LDFLAGS = \
	-no-undefined \
	$(PLATFORM_LDFLAGS)
