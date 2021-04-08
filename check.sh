#!/usr/bin/env sh

# fsync_syscall returns non-error status 
# if fsync with wait_multiple is available
# (or, the syscalll does not error with ENOSYS)

set -e

echo -n "FSYNC: "
./fsync_syscall && echo OK || echo FAIL
