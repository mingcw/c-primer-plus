#include <stdio.h>

int main(void)
{
	int num = 1;

	while (num < 21)
	{
		printf("%10d %10d\n", num, num*num++);/*参数的从右向左入栈导致，num先运算本身的平方，之后加1，
											   参数num变为加一后的值,出现num+1平方==num*num*/
	}
	getchar();
	return 0;
}