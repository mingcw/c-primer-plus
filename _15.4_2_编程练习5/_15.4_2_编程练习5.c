/*
	编写一个函数，该函数将一个unsigned int中的所有位向左旋转指定数量的位。例如
	rotate_l(x,4)将x中的所有位向左移动4个位置，而且从左端丢失的位会重新出现在
	最右端。也就是说，把从高位移出的位放入低位。在程序中测试该函数。*/

#include <stdio.h>
#include <stdlib.h>

unsigned int rotate_l(unsigned int n, int bits);

int main(void)
{
	unsigned int num = 73, bits = 3,a;

	system("color 5A");
	printf("The %u after rotating is %u\n", num, a=rotate_l(num, bits));

	getchar();
	return 0;
}

unsigned int rotate_l(unsigned int n, int bits)
{
	unsigned int i = 0, end;

	while (i++ < bits)
	{
		end = (n & 01);			//取出位0
		n >>= 1;				//注意n是无符号数，所以右移时空出的位用0填充
		end <<= 8 * sizeof(int)-1;
		n |= end;				//写入位31（如果end里的位值是1，则打开对应的n的位，否则不变）
	}

	return n;
}