#include <config.h>

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"
#include "utils.h"

struct buffer {
    size_t length;
    size_t capacity;
    char *buffer;
};

static buffer_t *buffer_init(size_t capacity) {
    buffer_t *buffer = (buffer_t *)malloc(sizeof(buffer_t));
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        abort();
    }

    buffer->capacity = capacity + 1;
    buffer->length = 0;
    buffer->buffer = (char *)malloc(buffer->capacity);
    if (buffer->buffer == NULL) {
        perror("Failed to allocate memory");
        abort();
    }
    buffer->buffer[0] = '\0';

    return buffer;
}

size_t buffer_length(const buffer_t *const self) {
    assert(self != NULL);
    return self->length;
}

buffer_t *buffer_create(const char *const format, ...) {
    if (format == NULL) {
        return buffer_init(0);
    }

    va_list ap, ap_copy;
    va_start(ap, format);
    va_copy(ap_copy, ap);

    const int length = vsnprintf(NULL, 0, format, ap);
    if (length < 0) {
        va_end(ap_copy);
        return false; /* encoding error */
    }

    buffer_t *self = buffer_init((size_t)length);

    NDEBUG_UNUSED const int ret =
        vsnprintf(self->buffer + self->length, self->capacity - self->length,
                  format, ap_copy);
    va_end(ap_copy);

    assert(ret == length);
    assert((size_t)ret < self->capacity - self->length);

    self->length += (size_t)length;
    return self;
}

const char *buffer_data(const buffer_t *const buffer) {
    assert(buffer != NULL);
    assert(buffer->buffer != NULL);

    return buffer->buffer;
}

void buffer_destroy(void *const ptr) {
    buffer_t *const self = (buffer_t *)ptr;

    if (self != NULL) {
        assert(self->buffer != NULL);
        free(self->buffer);
        free(self);
    }
}
