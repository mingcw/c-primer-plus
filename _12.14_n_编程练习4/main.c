
//main.c
#include <stdio.h>
#include <stdlib.h>

int func(void);

int main(void)
{
	int x;
	int i;
	int count;

	system("color 5A");
	puts("Enter a integer (q to quit):");
	while (scanf_s("%d", &x, 10) == 1)
	{
		for (i = 0; i < x; i++)
		{
			count = func();
		}
		puts("Enter a integer (q to quit):");
	}
	printf("The func() called %d times\n", count);
	puts("Bye!");

	system("pause");

	return 0;
}