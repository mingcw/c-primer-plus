//程序的剩余部分
#include <stdio.h>

extern int count;			//引用声明，外部链接(告诉编译器，该文件要用到外部的一个变量)
static int total = 0;		//静态定义，内部链接

void accumulate(int k);		//可选的函数声明（因为该文件内并不调用该函数，可以不必声明）

void accumulate(int k)		//k具有代码块作用域、空链接
{
	static int subtotal = 0;	//静态、空链接

	if (k <= 0)
	{
		printf("loop cycle: %d\n", count);
		printf("subtotal: %d, total: %d\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}

}