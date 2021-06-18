#include "biomechTime.h"

/**
 * @file time.h
 * @brief      Handy sleep and timing functions.
 *
 *             All functions are POSIX compliant and should work on any linux
 *             system.
 *
 * @author     James Strawson
 * @date       1/31/2018
 */

#include <time.h>
#include <sys/time.h> // for timeval
#include <errno.h>
#include <unistd.h> // for sysconf
#include <stdint.h> // for uint64_t


void rc_nanosleep(uint64_t ns){
	struct timespec req,rem;
	req.tv_sec = ns/1000000000;
	req.tv_nsec = ns%1000000000;
	// loop untill nanosleep sets an error or finishes successfully
	errno=0; // reset errno to avoid false detection
	while(nanosleep(&req, &rem) && errno==EINTR){
		req.tv_sec = rem.tv_sec;
		req.tv_nsec = rem.tv_nsec;
	}
	return;
}


void rc_usleep(unsigned int us){
	rc_nanosleep(us*1000);
	return;
}
