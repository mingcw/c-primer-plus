#include <stdio.h>

int main(void)
{
	int n = 0, m = 0;

	while (++n <= 9)
	{
		while (++m <= n)
		{
			printf("%dx%d=%-2d ", m, n, m*n);
		}
		printf("\n");
		m = 0;//内层循环打印完一行之后，m==n+1，将m初始化，参与外层循环打印下一行（n控制行数，m控制列数）
	}

	
	//do循环输出乘法表
	/*do
	{
		do
		{
			printf("%dx%d=%-2d ", m, n, m*n);
			m++;
		} while (m <= n);
		printf("\n");
		m = 1;
		n++;
	} while (n <= 9);*/


	//for循环输出乘法表
	/*for (size_t i = 1; i <= 9; i++)
	{
		for (size_t j = 1; j <= i; j++)
		{
			printf("%dx%d=%-2d ", j, i, j*i);
		}
		printf("\n");
	}*/

	getchar();
	return 0;
}