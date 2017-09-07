
//多个文件之间凌乱的变量混用，够坑（找个表情）。。。窝草，居然找不到合适的表情表达我的心情

//各种存储类
#include <stdio.h>
#include <stdlib.h>

void report_count(void);
void accumulate(int k);				//必需的函数原型（函数定义在另一个文件，之后调用该函数，必须提供函数原型，由编译器去定位函数定义并执行）

int count = 0;						//文件作用域，外部链接

int main(int argc, char * argv[])
{
	int value;						//自动变量
	register  int i;				//寄存器变量

	system("color 0A");

	printf("Enter a positive integer (0 to quit): ");
	while (scanf_s("%d", &value, 10) == 1 && value > 0)
	{
		++count;					//使用文件作用域变量
		for (i = value; i >= 0; i--)
		{
			accumulate(i);
		}
		printf("Enter a positive integer (0 to quit): ");
	}
	report_count();

	getchar();
	getchar();
	return 0;
}

void report_count(void)
{
	printf("Loop executed %d times\n", count);
}