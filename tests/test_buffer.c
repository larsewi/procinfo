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

    {
        buffer_t *tmp1 = buffer_create("baz");
        assert(tmp1 != NULL);

        const buffer_t *tmp2 = buffer_concat(buf, tmp1);
        assert(buf == tmp2);

        buffer_destroy(tmp1);
    }

    data = buffer_data(buf);
    assert(strcmp(data, "foobarbaz") == 0);

    size_t length = buffer_length(buf);
    assert(length == 9);

    buffer_destroy(buf);

    return EXIT_SUCCESS;
}
