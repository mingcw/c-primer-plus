//C的通用工具库中有很多函数，譬如随机数函数rand(),srand()，排序搜索函数，数据转换函数和内存管理函数。
//本实例是关于C的快速排序搜索函数qsort()的应用。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 40

void fillarray(double ar[], int n);
void showarray(double ar[], int n);
int mycomp(const void * p1, const void * p2);

/*
	C实现快速排序算法的函数是qsort()：
	第一个参数是指向数组头部的指针（这个指针是void类型的通用指针），这个数组指针可以是任何数据类型的指针。
	第二个参数是参与排序的项目数。
	第三个参数：因为第一个参数是void类型的指针，所以在传入数组后丢失数组元素大小信息。因此第三个参数是数组元素的类型大小（size_t类型)
	第四个参数：指向函数的指针，用于确定排序顺序；指针类型：int (* compar)(const void * p1, const void * p2)

	该函数指针指向一个具体的比较函数，该比较函数的函数功能是：
	如果p1指向的值大于p2指向的值，则返回一个正数；否则如果相等，则返回0：如果前者指向的值小于后者指向的值，则返回一个负数。
*/
int main(void)
{
	double ar[NUM];

	system("color 5A");
	fillarray(ar, NUM);
	puts("Original array:");
	showarray(ar, NUM);
	qsort(ar, NUM, sizeof(double), mycomp);
	puts("\nSorted array:");
	showarray(ar, NUM);

	system("pause");
	return 0;
}

void fillarray(double ar[], int n)
{
	int i;

	srand((unsigned int)time(NULL));
	for (i = 0; i < NUM; i++)
	{
		ar[i] = (double)rand() / ((double)rand() + 0.1);
	}
}

void showarray(double ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%9.4Lf", ar[i]);
		if (i % 6 == 5)
		{
			putchar('\n');
		}
	}
	if (i % 6 != 0)
	{
		putchar('\n');
	}
}

//按照从小到大的顺序排序
int mycomp(const void * p1, const void * p2)
{
	//转换成合适的指针类型
	const double * a1 = (const double *)p1;
	const double * a2 = (const double *)p2;

	if (*a1 > *a2)
	{
		return 1;
	}
	else if (*a1 == *a2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}