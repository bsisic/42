#include <stdio.h>
void yesorno(void)
{
	int rep;
	printf("'y' or 'n'\n");
	scanf("%c", &rep);
	if (rep == 'y' || rep == 'n')
		printf("rep -> %c\n", rep);
	else
		printf("ERROR : please retry\n");
}
int main(void)
{
	yesorno();
	return 0;
}
