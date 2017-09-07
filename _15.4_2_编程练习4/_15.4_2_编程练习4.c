/*
	编写一个函数，该函数接受2个int参数：1个值和1个位的位置，如果指定位上的值为1，则返回1，否则返回0
	在程序中测试该函数。*/

#include <stdio.h>
#include <stdlib.h>

int get_bit(int n, int bitindex);

int main(void)
{
	int num = 73, bitindex = 6, bit;

	system("color 5A");
	bit = get_bit(num, bitindex);
	printf("The %d's bit-%d: %d\n", num, bitindex, bit);

	getchar();
	return 0;
}

int get_bit(int n, int bitindex)
{
	n >>= bitindex;			//把指定位的值移到位0
	n &= 01;				//用01作掩码取出位0

	return n;
}