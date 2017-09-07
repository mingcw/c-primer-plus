#include <stdio.h>

int main(void)
{
	const int NUMBER = 22;
	int count = 1;

	while (count <= NUMBER)
	{
		printf("Be my Valentine!\n");
		count++;
	}

	getchar();
	return 0;
}