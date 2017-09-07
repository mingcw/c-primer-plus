#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NDEBUG
#include <assert.h>		/*头文件assert.h是设计用来辅助调试程序的小型库。*/

#pragma warning(disable: 4996)


int main(void)
{
	double x, y, z;

	system("color 5A");
	puts("Please enter a pair of numbers ( 0 0 to quit):");
	while (scanf("%lf %lf", &x, &y) == 2
		&& (x != 0 || y != 0))
	{
		z = x*x - y*y;	/*should be +*/
		assert(z >= 0);					/*assert()是定义在诊断库的断言宏，它接受整数表达式为参数（通常是关系或逻辑表达式）
										如果表达式的值为假，它向标准错误流写入一条错误信息并调用abort()函数终止程序。
										这条错误信息包含错误的判断（传入的参数表达式）、发生错误的文件名和行号。*/

		/*断言优点：1.反馈信息精准：能自动识别文件和发生错误的行号
				   2.无需改变代码，可开启或禁用宏assert()的机制：在包含assert.h头文件之前添加宏定义： #define NDEBUG 来禁用断言宏assert()*/
		printf("answer is %lf\n", sqrt(z));
		puts("Nwxt pair of numbers:");
	}
	puts("Done!");

	system("pause");
	return 0;
}