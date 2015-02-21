#include <time.h>

#include "timer.h"

int startTimer( int timeout )
{
	struct timespec tp;
	clock_gettime( CLOCK_MONOTONIC, &tp );
	return ( (int) tp.tv_sec + timeout ) * 512 + (int) tp.tv_nsec / 2097152;
}

int checkTimer( int t )
{
	return t - startTimer( 0 ) <= 0;
}
