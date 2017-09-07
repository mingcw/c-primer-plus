#include <stdio.h>

int main(void)
{
	const int NUMBER = 22;
	
	for (int i = 1; i <= NUMBER; i++)	/*"int i = 1"初始化表达式，循环开始前执行一次
										"i <= NUMBER"判断条件；在每次循环之前都要进行求值；
										"i++"控制变量的更新，每次循环结束时进行计算*/
	{
		printf("Be my Valentine!\n");
	}

	getchar();
	return 0;
}