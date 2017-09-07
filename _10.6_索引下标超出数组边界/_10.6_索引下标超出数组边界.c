#include <stdio.h>

#define SIZE 4

int main(void)
{
	int value1 = 44;
	int arr[SIZE];
	int value2 = 88;
	
	printf("value1 = %d, value2 = %d\n", value1, value2);
	
	for (int i = -1; i <= SIZE; i++)
	{
		arr[i] = 2 * i + 1;		//为数组赋值，显然，数组下标超出范围，超出部分的数值被初始化到其他内存单元，可能改变其他位置的变量数值
	}
	for (int i = -1; i < 7; i++)	//数组下标超出范围，超出部分的数值在其他内存单元，可能是其他位置的变量数值
	{
		printf("%2d %d\n", i, arr[i]);
	}
	printf("value1 = %d, value2 = %d\n", value1, value2);

	getchar();
	return 0;
}