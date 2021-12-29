#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>

#include "errname.h"

static const struct timespec zero;

#ifndef __NR_futex_waitv
#define __NR_futex_waitv 449
#endif

static int fsync_enabled = 0;

int main() {
  // Detect old futex_wait_multiple patches
  // https://github.com/ValveSoftware/wine/blob/3da025c3b623c415f61e3200c4ec77554e1ab7d7/server/fsync.c#L63
  syscall(__NR_futex, NULL, 31, 0, &zero, 0, 0);
  if (errno != 0) {
    if (errno != ENOSYS) {
      fprintf(stderr,
              "futex_wait_multiple check failed with unexpected error: ");
      goto failfast;
    }
    errno = 0;
  } else {
    fprintf(stderr, "Detected older FUTEX_WAIT_MULTIPLE patch. "
                    "Newer tools (Proton) might not enable fsync\n");
    fsync_enabled = 1;
  }

  // Detect newer fsync, returns EINVAL on success, ENOSYS on failure
  syscall(__NR_futex_waitv, 0, 0, 0, 0, 0);
  if (errno == EINVAL) {
    fprintf(stderr,
            "Detected newer (latest) fsync patch. "
            "Some older versions of Proton might not yet detect it and won't "
            "enable fsync.\n");
    fsync_enabled = 1;
  } else if (errno != ENOSYS) {
    fprintf(stderr, "futex_waitv check failed with unexpected error: ");
    goto failfast;
  }

  return 0 == fsync_enabled;

failfast:
  fprintf(stderr, "%s ", errnoname(errno));
  perror("");
  return 130;
}
