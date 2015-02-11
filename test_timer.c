#include "timer.h"

int main()
{
	int t;
	t = startTimer( 1 );
	while( !checkTimer( t ) );
}
