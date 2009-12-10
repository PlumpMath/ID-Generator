#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT(Taiwan ID Generator, 0.1, coldnew.tw@gmail.com)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C_O

# Checks for libraries.
AM_PATH_GTK_2_0(2.12.0,,AC_MSG_ERROR([You need Gtk+ >= 2.12.0 to build $PACKAGE]))
AM_PATH_GLIB_2_0(2.14.0,,AC_MSG_ERROR([You need Glib >= 2.14.0 to build $PACKAGE])) 

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([
				 Makefile
				 src/Makefile
				 ]) 
AC_OUTPUT
