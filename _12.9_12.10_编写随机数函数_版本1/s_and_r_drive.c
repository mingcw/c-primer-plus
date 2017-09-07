/*测试函数rand1()和srand()*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		//为time()函数提供ANSCII原型

extern void srand1(unsigned int x);		//引用声明，外部函数
extern int rand1(void);					//同上
extern unsigned long int next;

int main(void)
{
	int count;
	unsigned seed;

	system("color 0A");
	
	//1.用户输入一个种子值
	/*printf("Please enter your choice for seed(q to quit): \n");
	while (scanf_s("%u", &seed, 10) == 1)
	{
		srand1(seed);
		for (count = 0; count < 5; count++)
		{
			printf("%hd \n", rand1());
		}
		printf("Please enter your choice for seed(q to quit): \n");
	}
	printf("Bye!\n");*/


	//2.使用系统时钟初始化种子值
	printf("%d", 7);
	seed =  (unsigned int)time(NULL);		//调用time()获取系统时钟，作为随机数种子(注意，time()的返回值是time_t类型，强制转换可能出现截断)
	srand1(seed);
	printf("Here are some random number: \n");
	for (count = 0; count < 5; count++)
	{
		printf("%hd \n", rand1());
	}

	getchar();
	getchar();
	getchar();
	return 0;
}