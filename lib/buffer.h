#ifndef __PROCINFO_BUFFER_H__
#define __PROCINFO_BUFFER_H__

#include <stdbool.h>
#include <stddef.h>

typedef struct buffer buffer_t;

size_t buffer_length(const buffer_t *self);

buffer_t *buffer_create(const char *format, ...);

const char *buffer_data(const buffer_t *self);

buffer_t *buffer_concat(buffer_t *self, const buffer_t *other);

void buffer_destroy(void *ptr);

#endif /* __PROCINFO_BUFFER_H__ */
