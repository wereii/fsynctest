CC=gcc
CCFLAGS=-Wall -Wextra

.PHONY: all check

all: check

check: fsync_syscall
	chmod +x check.sh
	./check.sh

fsync_syscall: fsync_syscall.c
	$(CC) $(CCFLAGS) -o $@ $^
