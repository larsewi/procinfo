#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.72])
AC_INIT([procinfo], [0.1.0], [https://github.com/larsewi/procinfo/issues], [procinfo], [https://github.com/larsewi/procinfo])
AC_CONFIG_SRCDIR([lib/procinfo.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

# Checks for programs.
AC_PROG_CXX
AM_PROG_AR
AC_PROG_AR
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_CHECK_PROGS([CLANG_FORMAT], [clang-format], [clang-format])

LT_INIT

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

AC_CONFIG_TESTDIR([tests], [cli])
AC_CONFIG_FILES([Makefile
                 cli/Makefile
                 lib/Makefile
                 tests/Makefile])

AC_OUTPUT
