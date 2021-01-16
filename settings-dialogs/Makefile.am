bin_PROGRAMS = \
	eswm1-settings  \
	eswm1-tweaks-settings  \
	eswm1-workspace-settings

eswm1_workspace_settings_SOURCES = \
	workspace-settings.c \
	eswm1-workspace-dialog_ui.h \
	workspace-resource.c \
	workspace-resource.h

eswm1_workspace_settings_CFLAGS = \
	$(GTK_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(DBUS_GLIB_CFLAGS) \
	$(LIBEXPIDUS1UTIL_CFLAGS) \
	$(LIBEXPIDUS1UI_CFLAGS) \
	$(LIBESCONF_CFLAGS) \
	$(LIBWNCK_CFLAGS) \
	-DDATADIR=\"$(datadir)\" \
	-DSRCDIR=\"$(top_srcdir)\" \
	-DLOCALEDIR=\"$(localedir)\" \
	-DWNCK_I_KNOW_THIS_IS_UNSTABLE

eswm1_workspace_settings_LDADD = \
	$(top_builddir)/common/libeswm-common.la \
	$(GTK_LIBS) \
	$(GLIB_LIBS) \
	$(DBUS_GLIB_LIBS) \
	$(LIBEXPIDUS1UTIL_LIBS) \
	$(LIBEXPIDUS1UI_LIBS) \
	$(LIBESCONF_LIBS) \
	$(LIBWNCK_LIBS)

eswm1_settings_SOURCES = \
	eswm1-settings.c \
	eswm1-settings.h \
	eswm1-dialog_ui.h \
	range-debouncer.c \
	range-debouncer.h

eswm1_settings_CFLAGS = \
	$(GTK_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(DBUS_GLIB_CFLAGS) \
	$(LIBEXPIDUS1UI_CFLAGS) \
	$(LIBEXPIDUS1KBD_PRIVATE_CFLAGS) \
	$(LIBESCONF_CFLAGS) \
	-DDATADIR=\"$(datadir)\" \
	-DSRCDIR=\"$(top_srcdir)\" \
	-DLOCALEDIR=\"$(localedir)\"

eswm1_settings_LDADD = \
	$(top_builddir)/common/libeswm-common.la \
	$(GTK_LIBS) \
	$(GLIB_LIBS) \
	$(DBUS_GLIB_LIBS) \
	$(LIBEXPIDUS1UI_LIBS) \
	$(LIBEXPIDUS1KBD_PRIVATE_LIBS) \
	$(LIBESCONF_LIBS)

eswm1_tweaks_settings_SOURCES = \
	tweaks-settings.c \
	eswm1-tweaks-dialog_ui.h \
	range-debouncer.c \
	range-debouncer.h

eswm1_tweaks_settings_CFLAGS = \
	$(GTK_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(DBUS_GLIB_CFLAGS) \
	$(LIBEXPIDUS1UI_CFLAGS) \
	$(LIBESCONF_CFLAGS) \
	-DDATADIR=\"$(datadir)\" \
	-DSRCDIR=\"$(top_srcdir)\" \
	-DLOCALEDIR=\"$(localedir)\"

eswm1_tweaks_settings_LDADD = \
	$(top_builddir)/common/libeswm-common.la \
	$(GTK_LIBS) \
	$(GLIB_LIBS) \
	$(DBUS_GLIB_LIBS) \
	$(LIBEXPIDUS1UI_LIBS) \
	$(LIBESCONF_LIBS)

AM_CPPFLAGS = \
	-I${top_srcdir} \
	$(PLATFORM_CPPFLAGS)

if MAINTAINER_MODE

BUILT_SOURCES = \
	eswm1-dialog_ui.h \
	eswm1-tweaks-dialog_ui.h \
	eswm1-workspace-dialog_ui.h \
	workspace-resource.h \
	workspace-resource.c

eswm1-workspace-dialog_ui.h: eswm1-workspace-dialog.glade
	$(AM_V_GEN) $(XDT_CSOURCE) --static --strip-comments --strip-content --name=workspace_dialog_ui $< >$@

eswm1-dialog_ui.h: eswm1-dialog.glade
	$(AM_V_GEN) $(XDT_CSOURCE) --static --strip-comments --strip-content --name=eswm1_dialog_ui $< >$@

eswm1-tweaks-dialog_ui.h: eswm1-tweaks-dialog.glade
	$(AM_V_GEN) $(XDT_CSOURCE) --static --strip-comments --strip-content --name=tweaks_dialog_ui $< >$@

workspace-resource.h:
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) $(srcdir)/workspace.gresource.xml --target=$@ --generate-header

workspace-resource.c:
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) $(srcdir)/workspace.gresource.xml --target=$@ --generate-source

endif

desktopdir = $(datadir)/applications
desktop_in_files = \
	expidus-wm-settings.desktop.in \
	expidus-wmtweaks-settings.desktop.in \
	expidus-workspaces-settings.desktop.in
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)

@INTLTOOL_DESKTOP_RULE@

EXTRA_DIST = \
	$(desktop_in_files)  \
	eswm1-workspace-dialog.glade  \
	eswm1-tweaks-dialog.glade  \
	eswm1-dialog.glade \
	workspace.gresource.xml \
	monitor-icon.svg

DISTCLEANFILES = \
	$(desktop_DATA)
