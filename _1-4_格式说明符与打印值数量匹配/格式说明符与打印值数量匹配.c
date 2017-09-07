#include <stdio.h>
int main(void)
{
	int ten;
	int two;
	ten = 10;
	two = 2;

	printf("Doing it right:");
	printf("%d minus %d is %d.\n",ten,2,ten-two);
	printf("Doing it wrong:");
	printf("%d minus %d is %d.\n", ten);
	getchar();
	return 0;
	//格式说明符必须与要打印值的数量匹配，否则有格式说明符而没有提供打印值的位置会由编译器从内存中任意提取一个值填充
}