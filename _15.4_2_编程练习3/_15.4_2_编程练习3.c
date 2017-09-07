/*
	编写一个函数，该函数接受一个int参数，并返回这个参数中打开位的数量。在程序中测试这个函数*/
#include <stdio.h>
#include <stdlib.h>

int count_onbit(int n);

int main(void)
{
	int n = 73;
	
	system("color 5A");
	printf("The %d has %d bits on.\n", n, count_onbit(n));

	system("pause");
	return 0;
}

int count_onbit(int n)
{
	int size = 8 * sizeof(int);
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if ((n & 01) == 1)
		{
			count++;
		}
		n >>= 1;
	}

	return count;
}