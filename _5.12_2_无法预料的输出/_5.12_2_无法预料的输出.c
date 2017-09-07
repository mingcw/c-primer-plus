#include <stdio.h>

int main(void)
{
	/*加加减减的语句请单行写出
	并且，在同一行里，不要出现多个加加减减的语句
	结果是无法预料的*/
	int i = 1;

	printf("%d %d %d \n", i++, i++, i++);//打印结果为3 2 1，这是因为参数的从右向左入栈造成的
	printf("%d \n", i);
	getchar();
	return 0;
}