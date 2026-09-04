
#include <stdarg.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

char *string_format(const char *fmt, ...) {
    assert(fmt != NULL);

    va_list ap;
    va_start(ap, fmt);
    const int len = vsnprintf(NULL, 0, fmt, ap);
    assert(len >= 0);
    va_end(ap);

    char *const str = (char *)malloc((size_t)len + 1);
    if (str == NULL) {
        perror("Failed to allocate memory");
        abort();
    }

    va_start(ap, fmt);
    LCH_NDEBUG_UNUSED const int ret =
        vsnprintf(str, (size_t)len + 1, fmt, ap);
    assert(ret == len);
    va_end(ap);

    return str;
}

char *add_context(char *msg, const char *fmt, ...) {


    char *new = string_format("%s: %s", ctx, msg);
    free(msg);
    return new;
}
