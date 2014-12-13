#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	size_t i;
	srand(3);
	for(i=0; i<10; i++) printf("%i\n", rand());
	return 0;
}
