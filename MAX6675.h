// https://github.com/mttrb/MAX6675Pi

#ifndef MAX6675_H
#define MAX6675_H

int MAX6675Setup( int SPIChannel );
// Der MAX6675 braucht bis zu 0.22 Sekunden.
float MAX6675GetTempC( int SPIChannel );
float MAX6675GetTempF( int SPIChannel );

#endif
