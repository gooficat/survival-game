#include "time.h"

double get_ms(void) {
	long ret;
	struct {
		long sec;
		long nsec;
	} spec;

	__asm__ volatile(
		"syscall"
		: "=a"(ret)
		: "a"(228) /*SYS_clock_gettime*/, "D"(1) /*CLOCK_MONOTONIC*/, "S"(&spec)
		: "rcx", "r11", "memory" /**/
	);

	if (!ret) {
		return ((double)spec.sec * 1000.0) + ((double)spec.nsec / 1000000.0);
	}

	return -1.0;
}
