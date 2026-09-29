#include "utils.h"


#include <config.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <procinfo.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

#define PROC_PATH "/proc"

struct procinfo {
    pid_t pid;
    procinfo_t *next;
};

const char *procinfo_version(void) { return PACKAGE_STRING; }

static bool is_pid(const char *const name) {
    for (const char *ch = name; *ch != '\0'; ch++) {
        if (!isdigit(*ch)) {
            return false;
        }
    }
    return true;
}

static procinfo_t *parse_process(const DIR *const dir, const char *const name) {

}

procinfo_t *procinfo_get(char **err) {
    const char *const path = "/proc";
    DIR *const dir = opendir(path);
    if (dir == NULL) {
        *err = format("failed to open directory '%s': %s", path, strerror(errno));
        return NULL;
    }

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        /* PID names contain only digits */
        if (!is_pid(ent->d_name)) {
            continue;
        }

        int fd = openat(dirfd(dir), ent->d_name, O_RDONLY | O_DIRECTORY | O_CLOEXEC);
        if (fd == -1) {
            continue;
        }

        parse_process(dir, ent->d_name);
    }

    return NULL;
}
