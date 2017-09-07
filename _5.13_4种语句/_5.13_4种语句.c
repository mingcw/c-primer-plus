#include <stdio.h>

int main(void)
{
	//计算前20个整数的和
	int count, sum;				//声明语句

	count = 0;					//赋值语句
	sum = 0;
	while (count++ < 20)		//while
		sum = sum + count;		//语句
	printf("sum = %d\n", sum);	//函数语句
	getchar();
	return 0;
}