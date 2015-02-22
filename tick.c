#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#include "tick.h"

static int wdfd = -1;
static unsigned int modmask = 0x7f;

void tickSetup( unsigned int frequency )
{
	char* wdenv = getenv( "WATCHDOG" );

	if( frequency < 2 || frequency > 255 )
		exit( 1 );

	if( wdenv != NULL && wdfd == -1 )
		if( *wdenv == '1' )
		{
			wdfd = open( "/dev/watchdog", O_RDWR );
			if( wdfd == -1 )
			{
				perror( "watchdog" );
				exit( 1 );
			}
		}

	modmask = 0x1ff;
	for( ; frequency > 0; frequency /= 2 )
		modmask /= 2;
}

void tickWait()
{
	struct timespec tp;
	unsigned int c;

	if( wdfd != -1 )
		write( wdfd, ".", 1 );

	clock_gettime( CLOCK_MONOTONIC, &tp );
	c = ( 1000000000 - (unsigned int) tp.tv_nsec ) / 3906250;
	c &= modmask;
	c++;
	const struct timespec sl = { 0, c * 3906250 };
	nanosleep( &sl, NULL );
}
