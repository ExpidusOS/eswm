bin_PROGRAMS = eswm1

eswm1_SOURCES =								\
	client.c							\
	client.h							\
	compositor.c							\
	compositor.h							\
	cycle.c								\
	cycle.h								\
	device.c							\
	device.h							\
	display.c							\
	display.h							\
	event_filter.c							\
	event_filter.h							\
	events.c							\
	events.h							\
	focus.c								\
	focus.h								\
	frame.c								\
	frame.h								\
	hints.c								\
	hints.h								\
	icons.c								\
	icons.h								\
	keyboard.c							\
	keyboard.h							\
	main.c								\
	menu.c								\
	menu.h								\
	misc.c								\
	misc.h								\
	moveresize.c							\
	moveresize.h							\
	mypixmap.c							\
	mypixmap.h							\
	mywindow.c							\
	mywindow.h							\
	netwm.c								\
	netwm.h								\
	parserc.c							\
	parserc.h							\
	placement.c							\
	placement.h							\
	poswin.c							\
	poswin.h							\
	screen.c							\
	screen.h							\
	session.c							\
	session.h							\
	settings.c							\
	settings.h							\
	spinning_cursor.c						\
	spinning_cursor.h						\
	stacking.c							\
	stacking.h							\
	startup_notification.c						\
	startup_notification.h						\
	tabwin.c							\
	tabwin.h							\
	terminate.c							\
	terminate.h							\
	transients.c							\
	transients.h							\
	ui_style.c							\
	ui_style.h							\
	wireframe.c							\
	wireframe.h							\
	workspaces.c							\
	workspaces.h							\
	xsync.c								\
	xsync.h								\
	xpm-color-table.h

eswm1_CFLAGS =								\
	$(GLIB_CFLAGS) 							\
	$(GTK_CFLAGS) 							\
	$(COMPOSITOR_CFLAGS)						\
	$(EPOXY_CFLAGS)							\
	$(LIBSTARTUP_NOTIFICATION_CFLAGS)				\
	$(LIBX11_CFLAGS)						\
	$(LIBEXPIDUS1KBD_PRIVATE_CFLAGS)					\
	$(LIBEXPIDUS1UI_CFLAGS)						\
	$(LIBDEVIDENT_CFLAGS)							\
	$(LIBEXPIDUS1UTIL_CFLAGS)						\
	$(LIBESCONF_CFLAGS)						\
	$(PRESENT_EXTENSION_CFLAGS)					\
	$(RANDR_CFLAGS)							\
	$(RENDER_CFLAGS)						\
	$(XINERAMA_CFLAGS)						\
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\"				\
	-DDATADIR=\"$(datadir)\"					\
	-DHELPERDIR=\"$(HELPER_PATH_PREFIX)\"				\
	-DPACKAGE_DATADIR=\"$(pkgdatadir)\"				\
	-DG_LOG_DOMAIN=\"eswm1\"

eswm1_LDADD =								\
	$(top_builddir)/common/libeswm-common.la 			\
	$(GLIB_LIBS) 							\
	$(GTK_LIBS) 							\
	$(COMPOSITOR_LIBS)						\
	$(EPOXY_LIBS)							\
	$(LIBSTARTUP_NOTIFICATION_LIBS)					\
	$(LIBX11_LDFLAGS)						\
	$(LIBX11_LIBS)							\
	$(LIBEXPIDUS1KBD_PRIVATE_LIBS)					\
	$(LIBDEVIDENT_LIBS)										\
	$(LIBEXPIDUS1UI_LIBS)						\
	$(LIBEXPIDUS1UTIL_LIBS)						\
	$(LIBESCONF_LIBS)						\
	$(PRESENT_EXTENSION_LIBS)					\
	$(RANDR_LIBS) 							\
	$(RENDER_LIBS)							\
	$(XINERAMA_LIBS)						\
	$(MATH_LIBS)

AM_CPPFLAGS = 								\
	-I${top_srcdir} 						\
	$(PLATFORM_CPPFLAGS)

EXTRA_DIST = 								\
	gen-color-table.pl
