#include <stdio.h>
#include <stdbool.h>		//使用bool关键字代替_Bool,也提供了true和false的标识符

int main(void)
{
	//目前综合应用：在一个循环里，读入一个整数，显示所有能被它整除的数，如果没有，报告它是一个素数。

	unsigned long num;		//用户输入的数
	unsigned long div;		//可能的约数
	bool isPrime;			//素数的标志（flag）

	printf("This is a program for adjusting prime.");
	printf("Please enter a integer to analysis\n");
	printf("q to quit\n");

	/*当用户输入一个无符号的long类型值时
	（或者可以包含字符函数分析头文件
	利用原型isdigit()传入参数进行判断用户是否的确输入一个数字）
	*/
	while (scanf_s("%lu", &num) == 1)		
	{
		for (div = 2, isPrime = true; (div * div) <= num; div++)	//判断从2到本次输入的要测试数的平方根之间的所有整数,并针对每个新输入的数初始化素数标志为true
		{
			if (num % div == 0)		//如果要测试数不是素数
			{
				if (div * div != num)
				{
					printf("The integer %lu is divisibled by %lu and %lu\n", num, div, num / div);	//打印出要测试数的两个约数，div 和 num/div	
				}
				else
				{
					printf("The integer %lu is divisibled by %lu\n", num, div);		//打印出该数作为要测试数的平方根	
				}
				isPrime = false;	//不是一个素数
			}
		}
		if (isPrime)
			printf("The integer %lu is a primer number\n", num);
		printf("Please enter another integer to analysis\n");
		printf("q to quit\n");
	}
	printf("Bye! Thanks for using!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}