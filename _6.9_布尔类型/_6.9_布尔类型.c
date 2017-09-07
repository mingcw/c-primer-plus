#include <stdio.h>

int main(void)
{
	//计算用户输入的数字的和
	long num, sum = 0L;		//初始化long值为0，保存和
	_Bool input_is_good;

	printf("Please enter an integer to be sumed");
	printf("（‘q’to quit）:");
	input_is_good = scanf_s("%ld", &num, 10);
	while (input_is_good)
	{
		sum = sum + num;
		printf("Please enter next number to sum: ");
		input_is_good = (1 == scanf_s("%ld", &num));/*提示用户继续输入（非数字表示停止）*/
	}
	printf("Those integers sum to %ld.\n", sum);

	getchar();
	getchar();
	getchar();
	return 0;
}