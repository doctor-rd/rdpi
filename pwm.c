#include <stddef.h>
#include <sys/time.h>
#include <wiringPi.h>

#include "pwm.h"

static float values[17];
static float oldpos[17];

void pwmSetup( const pwm_t* p )
{
	values[p->gpio] = 0;
	oldpos[p->gpio] = 0;

	pinMode( p->gpio, OUTPUT );
	digitalWrite( p->gpio, p->inverted );
}

void pwmSet( const pwm_t* p, float value )
{
	values[p->gpio] = value;
}

void pwmRefresh( const pwm_t* p )
{
	struct timeval tv;
	int len = p->length;
	gettimeofday( &tv, NULL );
	float curpos = ( (float) ( tv.tv_sec % len ) + ( (float) tv.tv_usec ) / 1000000 ) / len;

	int an = curpos < values[p->gpio];

	if( !an || curpos < oldpos[p->gpio] )
		if( p->inverted )
			digitalWrite( p->gpio, !an );
		else
			digitalWrite( p->gpio, an );

	oldpos[p->gpio] = curpos;
}
