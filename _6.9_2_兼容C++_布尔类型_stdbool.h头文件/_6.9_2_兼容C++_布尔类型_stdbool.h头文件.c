#include <stdio.h>
#include <stdbool.h>		//标准布尔类型头文件，提供了兼容C++的bool类型关键字

int main(void)
{
	//计算用户输入的数字的和
	long num;				//提供变量，保存用户输入
	long sum = 0L;			//初始化long值为0，保存和
	bool input_is_good;		//等价于_Bool input_is_good;

	printf("Please enter an integer to be sumed");
	printf("（‘q’to quit）:");
	input_is_good = (scanf_s("%ld", &num, 10) == 1);
	while (input_is_good)
	{
		sum += num;
		printf("Please enter next number to sum: ");
		input_is_good = (1 == scanf_s("%ld", &num));/*提示用户继续输入（非数字表示停止）*/
	}
	printf("Those integers sum to %ld.\n", sum);

	getchar();
	getchar();
	getchar();
	return 0;
}