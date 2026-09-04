#ifndef __PROCINFO_UTILS_H__
#define __PROCINFO_UTILS_H__

#include <stdio.h>

#define UNUSED __attribute__((unused))

#ifdef NDEBUG
#define NDEBUG_UNUSED __attribute__((unused))
#else
#define NDEBUG_UNUSED
#endif

char *v_format(const char *fmt, va_list ap);

char *format(const char *fmt, ...);

#endif /* __PROCINFO_UTILS_H__ */
