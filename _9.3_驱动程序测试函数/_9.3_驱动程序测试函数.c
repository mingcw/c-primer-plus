#include <stdio.h>
#include <stdlib.h>

int imin(int, int);		//在函数声明中，对形式参量的声明，可以省略变量名

int main(void)
{
	int evil1, evil2;

	system("color 0A");

	printf("Enter a pair of integer (q to quit) : \n");
	while (scanf_s("%d %d", &evil1, &evil2) == 2)
	{
		printf("The lesser of %d and %d is %d.\n",
			evil1, evil2, imin(evil1, evil2));
		printf("Enter a pair of integer (q to quit) : \n");
	}
	printf("Bye!\n");

	getchar();
	getchar();
	return 0;
}

int imin(int n, int m)
{
	return (n < m) ? n : m;		//返回该数值，类型由声明确定（注意二选一型的判断分支用条件表达式更为简洁和精炼，运行速度也快）
}

/*int imin(int n, int m)
{
	double min = (n < m) ? n : m;

	return min;			//返回值类型与声明类型不一致，实际的返回值类型由声明确定，所以截断为int类型
}*/

/*int imin(int n, int m)
{
	int min = (n < m) ? n : m;
	return min;
}*/

/*int imin(int n, int m)
{
	int min;

	if (n < m)
	{
		min = n;
	}
	else
	{
		min = m;
	}
	return min;
}*/
