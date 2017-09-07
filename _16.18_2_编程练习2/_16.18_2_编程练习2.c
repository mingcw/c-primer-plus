#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

#define HARMONIC_AVGE(X,Y) (1.0 / ((1.0 / (X) + 1.0 / (Y))/ 2.0))

void _error(void);

int main(void)
{
	double x, y, res, ass;

	system("color 5A");
	puts("Please input two numbers to calculate it (0 to quit):");
	ass = scanf("%lf %lf", &x, &y);
	if (ass != 2 || !x || !y)
	{
		atexit(_error);
		exit(EXIT_FAILURE);
	}
	res = HARMONIC_AVGE(x, y);
	printf("Harmonic average of %g and %g: %g\n", x, y, res);

	system("pause");
	return 0;
}

void _error(void)
{
	puts("Must inputt two no-zero-numbers.");
}
