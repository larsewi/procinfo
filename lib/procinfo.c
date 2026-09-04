#include <config.h>
#include <procinfo.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

struct procinfo {
    pid_t pid;
    procinfo_t *next;
};

const char *procinfo_version(void) { return PACKAGE_STRING; }

struct procinfo_t *procinfo_get(char *err_msg) {
    DIR* dir = opendir("/proc");
    if (dir == NULL) {

        return NULL;
    }
    return NULL;
}
