CC?=gcc
CFLAGS+=-Werror -Wall -Wextra

# $(info Cflags are: ${CFLAGS})

.PHONY: all check clean

all: fsynctest

check: fsynctest
	./fsynctest

fsynctest: fsynctest.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f fsynctest
