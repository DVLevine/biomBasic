
/**
 * Based on librobotcontrol
 */


#ifndef BIOM_TIME_H
#define BIOM_TIME_H

#include <stdint.h>
#include <time.h>
#include <sys/time.h>

typedef struct timespec	timespec;
typedef struct timeval timeval;

/**
 * @brief      Sleep in nanoseconds
 *
 * A wrapper for the normal UNIX nanosleep function which takes a number of
 * nanoseconds instead of a timeval struct. This also handles restarting
 * nanosleep with the remaining time in the event that nanosleep is interrupted
 * by a signal. There is no upper limit on the time requested.
 *
 * @param[in]  ns    nanoseconds to sleep
 */
void rc_nanosleep(uint64_t ns);


/**
 * @brief      Sleep in microseconds
 *
 * The traditional usleep function, however common, is deprecated in linux as it
 * uses SIGALARM which interferes with alarm and timer functions. This uses the
 * new POSIX standard nanosleep to accomplish the same thing which further
 * supports sleeping for lengths longer than 1 second. This also handles
 * restarting nanosleep with the remaining time in the event that nanosleep is
 * interrupted by a signal. There is no upper limit on the time requested.
 *
 * @param[in]  us    microseconds to sleep
 */
void rc_usleep(unsigned int us);


#endif