#include <config.h>

#include <assert.h>
#include <getopt.h>
#include <procinfo.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const struct option OPTIONS[] = {
    {"version", no_argument, NULL, 'v'},
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0},
};

/* Keep in sync with OPTIONS above. */
static const char *const DESCRIPTIONS[] = {
    "print version number and exit",
    "print this help message and exit",
    NULL,
};

void usage(void) {
    printf(PACKAGE_STRING "\n\n");
    printf("Usage: " PACKAGE_NAME " [OPTIONS]\n\n");

    size_t longest = 0;
    for (int i = 0; OPTIONS[i].name != NULL; i++) {
        size_t len = strlen(OPTIONS[i].name);
        longest = (longest >= len) ? longest : len;
    }

    char fmt[64];
    int ret = snprintf(fmt, sizeof(fmt), "  -%%c,--%%-%zus    %%s\n", longest);
    assert(ret >= 0 && (size_t)ret < sizeof(fmt));

    printf("OPTIONS:\n");
    for (int i = 0; OPTIONS[i].name != NULL; i++) {
        printf(fmt, OPTIONS[i].val, OPTIONS[i].name, DESCRIPTIONS[i]);
    }

    printf("\nReport bugs to: <" PACKAGE_BUGREPORT ">\n");
}

int main(int argc, char *argv[]) {
    int c;
    while ((c = getopt_long(argc, argv, "vh", OPTIONS, NULL)) != -1) {
        switch (c) {
        case 'v':
            printf("%s\n", procinfo_version());
            return EXIT_SUCCESS;
        case 'h':
            usage();
            return EXIT_SUCCESS;
        case '?':
            printf("Try '" PACKAGE_NAME " --help' for more information.\n");
            return EXIT_FAILURE;
        default:
            printf("Error: Unhandled option '%c'\n", c);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
