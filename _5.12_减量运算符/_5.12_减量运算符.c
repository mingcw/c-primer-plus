#include <stdio.h>
#define MAX 10

int main(void)
{
	//熟练的抒情诗人-计算机
	int count = MAX + 1;

	while (--count > 0)
	{
		printf("%d bottles of spring water on the wall,"
			"%d bottles of spring water!\n", count, count);
		printf("Take one down and pass it around.\n");
		printf("%d bottles of spring water!\n\n", count - 1);
	}
	getchar();
	return 0;
}