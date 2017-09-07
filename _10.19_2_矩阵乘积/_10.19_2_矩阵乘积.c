#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 2
#define ROWS_OR_COLS 3

int main(void)
{
	int i, j, k, m = 2, n = 3, p = 2;
	int a[ROWS][ROWS_OR_COLS] = {
		{ 6, 8, 7 },
		{ 3, 4, 5 }
	};
	int b[ROWS_OR_COLS][COLS] = {
		{ 1, 2 },
		{ 2, 1 },
		{ -1, 0 }
	};
	int c[ROWS][COLS] = { 0 };

	system("color 0A");
	printf("æÿ’ÛA:\n");
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < ROWS_OR_COLS; j++)
		{
			printf("%6d", a[i][j]);
		}
		putchar('\n');
	}


	printf("æÿ’ÛB:\n");
	for (i = 0; i < ROWS_OR_COLS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("%6d", b[i][j]);
		}
		putchar('\n');
	}

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			for (k = 0; k < ROWS_OR_COLS; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	printf("æÿ’ÛC:\n");
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("%6d", c[i][j]);
		}
		putchar('\n');
	}

	getchar();
	return 0;
}