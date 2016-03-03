#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int alea;
	srand (time (NULL));
	alea = rand () % 1000;
	printf("alea => %d", alea);
	return 0;
}
