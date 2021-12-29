CC += gcc
CFLAGS += -Werror -Wall -Wextra

$(info "${CFLAGS}")

.PHONY: all clean

all: check

check: fsynctest
	./fsynctest

fsynctest: fsynctest.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f fsynctest
