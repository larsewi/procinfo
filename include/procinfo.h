#ifndef __PROC_INFO_PROCINFO_H__
#define __PROC_INFO_PROCINFO_H__

#include <sys/types.h>

typedef struct procinfo procinfo_t;

const char *procinfo_version(char *err_msg);

#endif /* __PROCINFO_H__ */
