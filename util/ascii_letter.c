#include <stdio.h>
typedef struct data_s
{
	int count;
	char lett;
}				data_t;
void ascii_min()
{
	data_t asc;

	asc.count = 1;
	asc.lett = 'a';
	while (asc.count < 26)
	{
		printf("%c -> %d\n", asc.lett, asc.lett);
		asc.count++;
		asc.lett++;
	}
}
void ascii_maj(void)
{
	data_t asc;

	asc.count = 1;
	asc.lett = 'A';
	while (asc.count < 26)
	{
		printf("%c -> %d\n", asc.lett, asc.lett);
		asc.count++;
		asc.lett++;
	}
}
int main(void)
{
	ascii_min();
	printf("\n");
	puts("Press Enter for MAJ ->");
	getchar();
	ascii_maj();
	return (0);
}
