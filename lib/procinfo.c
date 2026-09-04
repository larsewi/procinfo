#include <config.h>
#include <dirent.h>
#include <procinfo.h>
#include <stdbool.h>
#include <sys/types.h>

#define PROC_PATH "/proc"

const char *procinfo_version(void) { return PACKAGE_STRING; }
