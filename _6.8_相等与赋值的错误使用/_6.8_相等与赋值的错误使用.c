#include <stdio.h>

int main(void)
{
	//计算用户输入的数字的和
	long num, sum = 0L;		//初始化long值为0，保存和
	int status;				//初始化scanf()的返回值，即成功扫描输入的项目数

	printf("Please enter an integer to be sumed");
	printf("（‘q’to quit）:");
	status = scanf_s("%ld", &num,10);
	while (status = 1)		//status被不断置为1.导致无限循环
	{
		sum = sum + num;
		printf("Please enter next number to sum: ");
		status = scanf_s("%ld", &num);/*当scanf未能读取long值，会继续将它留在用户输入里；
									    在下次读取时，从读取失败的地方继续读取之前的内容
										在该失败的循环体内，导致scanf一旦读取失败，将无限读取失败
										也就是说，改程序代码不仅产生了失败的无限循环，也造就了失败的无限读取*/
	}
	printf("Those integers sum to %ld.\n", sum);

	getchar();
	getchar();
	getchar();
	return 0;
}