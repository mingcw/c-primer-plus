#include <stdio.h>

#define SIZE 4

int main(void)
{
	//未经初始化的数组
	int no_data[SIZE];

	printf("%2s%14s", "i", "no_data[i]\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%2d%14d\n", i, no_data[i]);	//数组未经初始化，内部成员是内存单元里已有的其他数值，打印出错误的结果
	}
	
	getchar();
	return 0;
}