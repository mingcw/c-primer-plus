#include <stdio.h>

int main(void)
{
	const int ROWS = 7;
	const int CHAR = 7;

	for (int row = 0; row < ROWS; row++)
	{
		for (char ch = ('A' + row); ch < ('A' + CHAR); ch++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	
	getchar();
	return 0;
}