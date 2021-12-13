## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = interfaceadmin

interfaceadmin_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonction.c fonction.h \
	foyer.c foyer.h \
	tree.c tree.h \
	CRUD.c CRUD.h \
	capteur.c capteur.h \
	produit.c produit.h \
	fonctionmenu.c fonctionmenu.h

interfaceadmin_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

