#include <stdio.h>

#define MONTHS 12

int main(void)
{
	//用[]和下标对指定元素初始化（其他未初始化的元素被默认设置为0）
	int days[MONTHS] = { 31, 28, [4] = 44, 30, 31, [1] = 11 };		/*1.如果在指定项目后跟有不只一个值，则这些值将用来对后续元素初始化
																	  2.对一个元素多次初始化时，最后一次初始化生效（覆盖之前的初始化）*/

	for (int i = 0; i < MONTHS; i++)
	{
		printf("%2d %d\n", i + 1, days[i]);
	}

	getchar();
	return 0;
}