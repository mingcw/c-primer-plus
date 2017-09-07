#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS ROWS

int main(void)
{
	int ar[ROWS][COLS] = {
		{ 11, 12, 13 },
		{ 21, 22, 23 },
		{ 31, 32, 33 }
	};
	int(*p)[4];

	system("color 0A");
	printf("Original array: \n");
	for (int i = 0; i < ROWS; i++)				//´òÓ¡¾ØÕó
	{
		for (int j = 0; j < COLS; j++)
			printf("%d\t", ar[i][j]);
		putchar('\n');
	}

	for (int i = 0; i < ROWS; i++)				//×ªÖÃ¾ØÕó
	{
		for (int j = 0, temp; j < i; j++)
		{
			temp = ar[i][j];
			ar[i][j] = ar[j][i];
			ar[j][i] = temp;
		}
	}

	printf("Transpose : \n");
	for (int i = 0; i < ROWS; i++)				//´òÓ¡×ªÖÃ¾ØÕó
	{
		for (int j = 0; j < COLS; j++)
			printf("%d\t", ar[i][j]);
		putchar('\n');
	}

	getchar();
	return 0;

}