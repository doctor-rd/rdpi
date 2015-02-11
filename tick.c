#include <stddef.h>

#include "tick.h"

suseconds_t nextHalfSec()
{
	suseconds_t result;
	struct timeval tv;

	gettimeofday( &tv, NULL );
	result = 1000000 - tv.tv_usec;

	if( result >= 500000 )
		result -= 500000;

	return result;
}

suseconds_t nextQuatSec()
{
	suseconds_t result = nextHalfSec();

	if( result >= 250000 )
		result -= 250000;

	return result;
}
