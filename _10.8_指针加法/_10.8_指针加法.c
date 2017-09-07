#include <stdio.h>

#define SIZE 4

int main(void)
{
	short dates[SIZE];
	short * pti;
	double bills[SIZE];
	double * ptf;

	pti = dates;		//把数组地址赋给指针
	ptf = bills;		//同上
	printf("%23s %10s\n", "short", "double");
	for (short i = 0; i < SIZE; i++)
	{
		printf("pointers + %d: %10p %10p\n", i, pti + i, ptf + i);		//指针加n等价于指针值增加n个所指向对象的类型的字节大小
	}

	getchar();
	return 0;
}