#include <stdio.h>
#include <stdlib.h>			//提供了malloc()和calloc()和free()的函数原型

int main(void)
{
	int * p1;
	int * p2;

	p1 = (int *)malloc(10 * sizeof (int));			//malloc()分配10个int空间，不初始化内存块
	p2 = (int *)calloc(10, sizeof (int));			//calloc()功能同上，但初始化内存块为0（不保证浮点数0和数字0或空字符完全相同）

	for (int i = 0; i < 10; i++)
	{
		printf("%3d", p1[i]);						//由malloc()创建的数组，在访问数组元素前最好先初始化，编译器不会检查是否初始化这一问题
	}
	putchar('\n');
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", p2[i]);						//由calloc()创建的数组，数组元素都被置0
	}
	putchar('\n');

	getchar();
	return 0;
}
