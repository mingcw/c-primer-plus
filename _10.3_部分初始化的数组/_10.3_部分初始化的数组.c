#include <stdio.h>

#define SIZE 4

int main(void)
{
	//部分初始化的数组
	int some_data[SIZE] = { 1492, 1066 };	//其他成员被设置为0

	printf("%2s%17s", "i", "some_data[i]\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%2d%14d\n", i, some_data[i]);		//（编写者）已初始化的数组成员原样打印，（编写者）未初始化的其他成员被（编译器）初始化为0，然后打印
	}

	//综合“_10.2_未经初始化的数组”源代码，总结：未经初始化的数组元素存放垃圾值，但是部分初始化的数组中，未初始化的成员被设置为0

	getchar();
	return 0;
}