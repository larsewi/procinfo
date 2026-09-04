
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

char *v_format(const char *fmt, va_list ap) {
    assert(fmt != NULL);

    va_list ap_copy;
    va_copy(ap_copy, ap);

    const int len = vsnprintf(NULL, 0, fmt, ap);
    if (len < 0) {
        va_end(ap_copy);
        return NULL; /* encoding error */
    }

    char *const str = (char *)malloc((size_t)len + 1);
    if (str == NULL) {
        perror("Failed to allocate memory");
        va_end(ap_copy);
        abort();
    }

    NDEBUG_UNUSED const int ret = vsnprintf(str, (size_t)len + 1, fmt, ap_copy);
    assert(ret == len);

    va_end(ap_copy);
    return str;
}

char *format(const char *fmt, ...) {
    assert(fmt != NULL);

    va_list ap;
    va_start(ap, fmt);

    char *const str = v_format(fmt, ap);
    va_end(ap);

    return str;
}
