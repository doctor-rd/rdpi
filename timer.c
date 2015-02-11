#include <stddef.h>
#include <sys/time.h>

#include "timer.h"

int startTimer( int timeout )
{
	struct timeval tv;
	gettimeofday( &tv, NULL );
	return ( (int) tv.tv_sec + timeout ) * 256 + (int) tv.tv_usec / 4096;
}

int checkTimer( int t )
{
	struct timeval tv;
	gettimeofday( &tv, NULL );
	return t - ( (int) tv.tv_sec * 256 + (int) tv.tv_usec / 4096 ) <= 0;
}

// clock_gettime( CLOCK_MONOTONIC wäre vielleicht besser
