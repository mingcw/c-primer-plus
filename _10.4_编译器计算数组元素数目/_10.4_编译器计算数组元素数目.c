#include <stdio.h>

int main(void)
{
	/*有时为避免可能初始化数组成员数超出数组大小，可以不必设置数组大小，
	由编译器自动匹配数组中已初始化的成员数目*/

	const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //修饰为只读数组

	size_t size = sizeof days / sizeof days[0];		//数组成员数, 即数组大小除以单个成员大小
	for (int i = 0; i < size; i++)	
	{
		printf("Month %2d has %2d days.\n", i + 1, days[i]);
	}

	getchar();
	return 0;
}