ACLOCAL_AMFLAGS = -I m4
SUBDIRS = lib cli . tests

FORMAT_DIRS = cli include lib tests
FORMAT_FIND = find $(FORMAT_DIRS) \( -name '*.c' -o -name '*.h' \)

.PHONY: format format-check

format:
	cd $(top_srcdir) && $(FORMAT_FIND) -exec $(CLANG_FORMAT) -i --verbose {} +

format-check:
	cd $(top_srcdir) && $(FORMAT_FIND) -exec $(CLANG_FORMAT) --dry-run -Werror {} +
