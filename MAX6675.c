// https://github.com/mttrb/MAX6675Pi

#include <wiringPiSPI.h>
#include <inttypes.h>

#include "MAX6675.h"

#define MAX6675_CLOCK_SPEED 32000

int MAX6675Setup( int SPIChannel ) {
	if ( wiringPiSPISetup( SPIChannel, MAX6675_CLOCK_SPEED ) == -1 )
		return -1;

	return 0;
}

// Der MAX6675 braucht bis zu 0.22 Sekunden. Bei schnelleren Abfragen erhält man keine neuen Werte.
float MAX6675GetTempC( int SPIChannel ) {
	char buffer[2] = { 0, 0 };

	int ret = wiringPiSPIDataRW( SPIChannel, buffer, 2 );

	if ( ret != 2 )
		return -1.0;

	uint16_t reading = ( buffer[0] << 8 ) + buffer[1];

	if( reading & 4 != 0 ) // thermocouple open?
		return -1.0;

	reading >>= 3;

	return reading * 0.25;
}

float MAX6675GetTempF( int SPIChannel ) {
	float C = MAX6675GetTempC( SPIChannel );

	if( C < 0.0 )
		return C;

	return ( C * 1.8 ) + 32.0;
}
