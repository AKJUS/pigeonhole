settingsdir = $(dovecot_moduledir)/settings

dovecot_pkglibexec_PROGRAMS = managesieve-login

AM_CPPFLAGS = \
	$(LIBDOVECOT_INCLUDE) \
	$(LIBDOVECOT_SERVICE_INCLUDE) \
	$(LIBDOVECOT_LOGIN_INCLUDE) \
	-I$(top_srcdir) \
	-I$(top_srcdir)/src/lib-sieve \
	-I$(top_srcdir)/src/lib-managesieve

libmanagesieve_login_settings_la_LDFLAGS = -module -avoid-version

settings_LTLIBRARIES = \
	libmanagesieve_login_settings.la

libmanagesieve_login_settings_la_SOURCES = \
	managesieve-login-settings.c \
	managesieve-login-settings-plugin.c

libmanagesieve_login_settings_la_CFLAGS = \
	$(AM_CFLAGS) $(LIBDOVECOT_CONFIG_INCLUDE) -DPKG_LIBEXECDIR=\""$(dovecot_pkglibexecdir)"\"
libmanagesieve_login_settings_la_LIBADD = \
	$(top_builddir)/src/lib-sieve/libdovecot-sieve.la

libs = \
	$(top_builddir)/src/lib-managesieve/libdovecot-managesieve.la

managesieve_login_CPPFLAGS = $(AM_CPPFLAGS) $(BINARY_CFLAGS)
managesieve_login_LDFLAGS = $(BINARY_LDFLAGS)
managesieve_login_LDADD = $(libs) $(LIBDOVECOT_LOGIN) $(LIBDOVECOT)
managesieve_login_DEPENDENCIES = $(libs) $(LIBDOVECOT_LOGIN_DEPS) $(LIBDOVECOT_DEPS)

managesieve_login_SOURCES = \
	client.c \
	client-authenticate.c \
	managesieve-login-settings.c \
	managesieve-proxy.c

noinst_HEADERS = \
	client.h \
	client-authenticate.h \
	managesieve-login-settings.h \
	managesieve-login-settings-plugin.h \
	managesieve-proxy.h
