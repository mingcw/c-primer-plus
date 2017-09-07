#include <stdio.h>

long Fibonacci(int dec);

int main(void)
{
	int dec;

	printf("Please enter an integer to get the Fibonacci value (q to quit): \n");
	while (scanf_s("%d", &dec, 10) == 1)
	{
		printf("The Fibonacci value is %ld\n", Fibonacci(dec));
		printf("Please enter an integer to get the Fibonacci vlaue (q to quit): \n");
	}
	printf("Done!\n");

	getchar();
	getchar();
	return 0;
}

long Fibonacci(int dec)
{
	if (dec > 2)
	{
		return Fibonacci(dec - 1) + Fibonacci(dec - 2);
	}
	else
	{
		return 1;
	}
}
