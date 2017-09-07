#include <stdio.h>

int main(void)
{
	int n = 0;

	while (n++ < 3)
	{
		;		//该循环体的语句为一个即空语句
	}
	printf("n is %d \n", n);
	printf("That's all thid program does.\n");
	getchar();
	return 0;
}

