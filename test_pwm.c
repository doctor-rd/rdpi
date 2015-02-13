#include <stdlib.h>
#include <wiringPi.h>

#include "pwm.h"

const pwm_t p = { 1, 5, 0 };

int main( int argc, char **argv )
{
	wiringPiSetup();
	pwmSetup( &p );
	pwmSet( &p, atof( argv[1] ) );
	while(1)
		pwmRefresh( &p );
}
