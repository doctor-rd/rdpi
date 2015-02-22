#include <stdio.h>
#include <stdlib.h>

int main( int argc,char **argv )
{
	int f=atoi( argv[1] );
	int i;

	tickSetup( f );
	for( i=0 ; i < 10 * f ; i++ )
	{
		printf( "tick: %d\n", i );
		tickWait();
	}
	return 0;
}
