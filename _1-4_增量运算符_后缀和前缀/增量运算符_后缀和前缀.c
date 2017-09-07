#include <stdio.h>

int main(void)
{
	int a = 1, b = 1;
	int aplus, plusb;

	aplus = a++; /*后缀,aplus保存了a改变之前的值*/
	plusb = ++b; /*前缀,plusb保存了b改变之后的值*/
	printf("a aplus b plusb \n");
	printf("%1d %3d %3d %3d\n", a, aplus, b, plusb);
	getchar();
	return 0;
}