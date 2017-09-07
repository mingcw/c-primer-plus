#include <stdio.h>

int main(void)
{
	//增量，前缀和后缀
	int ultra = 0, super = 0;

	while (super < 5)
	{
		super++;
		++ultra;
		printf("super = %d, ultra = %d\n", super, ultra);
	}
	getchar();
	return 0;
}
