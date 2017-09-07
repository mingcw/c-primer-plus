#include <stdio.h>

#define MONTHS 12  //另开变量保存数组大小，有利于以后程序的维护和修改

int main(void)
{
	//初始化数组，格式如下
	const int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	//声明12个int成员的数组，const修饰为常量，使得该数组可读而不可写
	
	for (int i = 0; i < MONTHS; i++)
	{
		printf("Month %-2d has %2d days.\n", i + 1, days[i]);
	}

	getchar();
	return 0;
}