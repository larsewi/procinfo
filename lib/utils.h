#ifndef __PROCINFO_UTILS_H__
#define __PROCINFO_UTILS_H__

#define LCH_UNUSED __attribute__((unused))
#ifdef NDEBUG
#define LCH_NDEBUG_UNUSED __attribute__((unused))
#else
#define LCH_NDEBUG_UNUSED
#endif

char *string_format(const char *fmt, ...);

char *add_context(char *msg, const char *ctx);

#endif /* __PROCINFO_UTILS_H__ */
