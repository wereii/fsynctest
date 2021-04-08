#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

static const struct timespec zero;

int main(){
	syscall(__NR_futex, NULL, 31, 0, &zero, 0, 0);
	return errno == ENOSYS;
}
