/*
	下面是使用了可变函数的程序片段：
	#include <stdio.h>
	#include <stdlib.h>
	#include <strarg.h>
	void show_qrray(const double arp[, int n);
	double * new_d_array(int n, ...);
	int main(void)
	{
		double * p1;
		double * p2;

		p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
		p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
		show_array(p1, 5);
		show_array(p2, 4);
		free(p1);
		free(p2);

		return 0;
	}
	new_d_array()函数接受一个int参数和数量可变的double参数。该函数返回一个指向malloc()分配的内存块的指针。
	int参数指定动态数组中的元素个数;double值用于初始化元素（第一个值赋予第一个元素，以此类推）。
	提供show_arrary()和new_d_arrar()的代码，使程序完整。
	*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double * new_d_array(int lim, ...);
void show_array(double ar[], int n);

int main(void)
{
	double * p1;
	double * p2;

	p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
	system("color 5A");
	puts("Array1:");
	show_array(p1, 5);
	puts("\nArray2:");
	show_array(p2, 4);
	free(p1);										//释放malloc()分配的内存
	free(p2);

	system("pause");
	return 0;
}

double * new_d_array(int lim, ...)
{
	va_list ap;										//声明用于存放变惨的va_list变量
	double  * par;

	va_start(ap, lim)								//初始化参数列表
	par = (double *)malloc(lim * sizeof(double));	//为动态数组分配内存块
	for (int i = 0; i < lim; i++)
	{
		par[i] = va_arg(ap, double);				//取出参数并写到分配的内存块
	}
	va_end(ap);										//将ap复位，释放分配的内存

	return par;
}

void show_array(double ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%g ", ar[i]);
	}
	putchar('\n');
}
