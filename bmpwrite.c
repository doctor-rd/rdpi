#include <unistd.h>
#include <wiringPi.h>

#include "bmpwrite.h"

// wiringPiSetup() muss vorher ausgeführt werden.
int bmpSetup( const bmpwrite_t* b )
{
	int i;

	for( i = 0; i < b->len; i++ )
		pinMode( b->gpios[i], OUTPUT );

	return 0;
}

int bmpWrite( const bmpwrite_t* b, int value )
{
	int i;

	for( i = 0; i < b->len; i++ )
		digitalWrite( b->gpios[i], ( value >> i ) & 1 );

	// etwas Zeit geben
	return usleep( 10 );
}
