#include <stdio.h>
#define ROWS 10
#define CHAR 7

int main(void)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (char ch = 'A'; ch < ('A' + CHAR); ch++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}

	getchar();
	return 0;
}