#include <stdio.h>		//调用该标准输入输出头文件中的printf函数
int main(void)
{
	int num = 100;

	printf("dec = %d, octal = %o, hex = %x, hex = %X\n", num, num, num, num);
	printf("dec = %d, octal = %#o, hex = %#x, hex = %#X\n", num, num, num, num);

	getchar();
	return 0;
}