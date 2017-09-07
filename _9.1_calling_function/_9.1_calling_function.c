#include <stdio.h>
#include <stdlib.h>

#define NAME "GIGETHINK, INC. "
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megbapolis. CA 94904"
#define WIDTH 40

void starbar(void);

int main(void)
{
	system("color 0A");
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	printf("%d\n", WIDTH);
	starbar();

	getchar();
	return 0;
}

void starbar(void)
{
	for (int i = 1; i <= WIDTH; i++)
	{
		putchar('#');
	}
	putchar('\n');
}