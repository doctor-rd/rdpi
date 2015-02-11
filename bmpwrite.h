#ifndef BMPWRITE_H
#define BMPWRITE_H

typedef struct {
	int* gpios;
	int len;
} bmpwrite_t;

// wiringPiSetup() muss vorher ausgeführt werden.
int bmpSetup( const bmpwrite_t* b );
int bmpWrite( const bmpwrite_t* b, int value );

#endif
