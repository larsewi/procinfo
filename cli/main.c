#include <config.h>
#include <getopt.h>
#include <procinfo.h>
#include <stdio.h>
#include <stdlib.h>

const struct {
    struct option long_opts;
    const char *description;
} OPTIONS[] = {
    {
        {"version", no_argument, NULL, 'v'},
        "Print version number",
    },
    {{NULL, 0, NULL, 0}, NULL},
};

int main(int argc, char *argv[]) {
    int c;
    while ((c = getopt_long(argc, argv, "v", (const struct option *)OPTIONS,
                            NULL)) != -1) {
        switch (c) {
        case 'v':
            printf("%s\n", procinfo_version());
            return EXIT_SUCCESS;
        case '?':
            return EXIT_FAILURE;
        default:
            printf("Unhandled option '%c'", c);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
