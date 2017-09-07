#include <stdio.h>

int main(void)
{
	//计算用户输入的数字的和
	long num, sum = 0L;		//初始化long值为0，保存和
	int status;				//初始化scanf()的返回值，即成功扫描输入的项目数

	printf("Please enter an integer to be sumed");
	printf("（‘q’to quit）:");
	status = scanf_s("%ld", &num,10);
	while (status == 1)		//确实输入一个数时，进入循环
	{
		sum = sum + num;
		printf("Please enter next number to sum: ");
		status = scanf_s("%ld", &num);
	}
	printf("Those integers sum to %ld.\n", sum);
	getchar();
	getchar();
	getchar();
	return 0;
}