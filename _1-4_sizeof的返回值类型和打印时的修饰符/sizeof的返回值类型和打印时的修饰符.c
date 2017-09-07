#include <stdio.h>

int main(void)
{
	/*sizeof运算符返回size_t类型值（无符号（长）整数），
	计算数据对象或类型的大小，当操作数是类型的时候，必须括号括起来，
	在printf()语句中的格式说明符是%zd，z修饰说明是sizeof的返回值类型，
	如果%zd不能用，可以用%u或%lu,这也说明sizeof的返回值类型size_t是无符号整数类型，更长为无符号长整数类型
	*/
	int n = 10;
	size_t intsize = sizeof (int);
	
	printf("%d has %u bytes,and all ints has %u bytes.\n", n, sizeof n, intsize);

	getchar();
	return 0;
}