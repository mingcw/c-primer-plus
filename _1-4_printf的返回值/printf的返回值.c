#include <stdio.h>

int main(void)
{
	//printf的返回值
	int bph2o = 100;
	int rv;

	rv = printf("%d °C is water's bolling point.\n",bph2o);//printf的返回值包括打印范围内的所有字符（即包括不可将字符）
	printf("This printf function printed %d characters.\n", rv);

	getchar();
	return 0;
}