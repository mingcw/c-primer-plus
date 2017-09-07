#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loop(clock_t t);

int main(void)
{
	clock_t start, finish;
	long i = 400000000;

	start = clock();
	while (i--)
	{
		;
	}
	finish = clock();
	system("color 5A");
	loop(finish - start);
	printf("Elapsed time: %.2lfsec\n", (double)(finish - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}

void loop(clock_t t)
{
	while (t--)
	{
		;
	}
}