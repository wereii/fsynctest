#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>

static const struct timespec zero;

int main() {
    // https://github.com/ValveSoftware/wine/blob/3da025c3b623c415f61e3200c4ec77554e1ab7d7/server/fsync.c#L63
    syscall(__NR_futex, NULL, 31, 0, &zero, 0, 0);
    return errno == ENOSYS;
}
