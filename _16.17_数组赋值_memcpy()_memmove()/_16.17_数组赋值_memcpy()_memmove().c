#include <stdio.h>
#include <stdlib.h>
#include <string.h>			//提供了内存拷贝函数的函数原型
//#include <memory.h>

#define SIZE 10

void show_array(const int ar[], int n);

/*
	内存拷贝函数：memcpy()和memmove()
	函数原型：void * memcpy(void * restrict s1, const void * resterct s2, size_t n);
			 void * memmove(void * s1, const * s2, size_t n);
	函数功能：均将s1指向的位置复制n字节到s2指向的位置
			 两种间的差别由关键字restrict造成，即memcpy()可以假定两指针指向的位置没有重叠。memmove()没有这个假定，它的复制过程类似于将源位置所有字节复制到临时缓冲区，再复制到目标位置。
			 如果两区域存在重叠，使用memcpy()的行为是不可预知的，即可能正常工作，也可能失败。在不应该使用memcpy()时，编译器不会禁止使用memcpy()。所以使用时必须确保没有重叠区域。
	简单说：使用memcpy()需要不重叠区域。如果有内存重叠，行为不可预知。(restrict关键字记住即可）
		   使用memmove()类似于通过临时缓冲区复制内存的方式可以有效处理内存重叠问题。
		   
	所以,安全起见，不清楚内存重叠的话，使用memmove()为好。*/
int main(void)
{
	int values[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int target[SIZE];
	double curious[SIZE / 2] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

	system("color 5A");
	puts("memcpy() used:");
	puts("values (Original data");
	
	show_array(values, SIZE);
	memcpy(target, values, SIZE * sizeof(int));
	puts("targer (copy of values):");
	show_array(target, SIZE);

	puts("\nUsing memmove() with overlapping ranges:");
	memmove(values + 2, values, 5 * sizeof(int));					//两区域有内存重叠，使用memmove()为好
	puts("values -- elememts 0-4 copied to 2-6:");
	show_array(values, SIZE);

	puts("\nUsing memcpy()to copy double to int:");
	memcpy(target, curious, (SIZE / 2) * sizeof(double));			//memcpy()只拷贝内存，不关心数据类型
	puts("target -- 5 double into 10 int positions:");
	show_array(target, SIZE);

	system("pause");
	return 0;
}

void show_array(const int ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
	}
	putchar('\n');
}