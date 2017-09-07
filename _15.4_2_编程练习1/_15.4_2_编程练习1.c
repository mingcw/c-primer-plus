/*
	编写一个将二进制字符串转化为数字值的函数。也就是说，如果有以下语句：
	char * pbin = "01001001";
	那么可以将pbin作为参数传递给一个函数，使该函数返回一个int值25*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tonumber(char * pbin);

int main(void)
{
	char * pbin = "01001001";
	int n;

	n = tonumber(pbin);	
	system("color 5A");
	printf("The \"%s\"'s value is %u.\n", pbin, n);

	getchar();
	return 0;
}

int tonumber(char * pbin)
{
	unsigned int bin = 0, size = strlen(pbin);

	for (unsigned int i = 0; i < size; i++)
	{
		bin &= ~01;					//位0清零
		bin |= *(pbin + i) - '0';	//写入位0
		bin <<= 1;					//左移1位
	}
	bin >>= 1;						//写完最后一位之后向左多移了1位，所以向右移动一位，字符串转换为二进制位

	bin >>= 3;
	bin |= 0x10;					//打开位4

	return bin;
}