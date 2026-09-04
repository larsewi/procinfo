#include <config.h>

#include <assert.h>
#include <buffer.h>
#include <procinfo.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    buffer_t *buf = buffer_create("foo%s", "bar");
    assert(buf != NULL);

    const char *data = buffer_data(buf);
    assert(strcmp(data, "foobar") == 0);

    size_t length = buffer_length(buf);
    assert(length == 6);

    buffer_destroy(buf);

    return EXIT_SUCCESS;
}
