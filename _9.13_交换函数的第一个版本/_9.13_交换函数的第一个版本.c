
//交换数值，错误源码（_9.14 正确源码）

#include <stdio.h>

void interchange(int u, int v);

int main(void)
{
	int x = 5, y = 10;

	printf("Originally x = %d, y = %d\n", x, y);
	interchange(x, y);	//交换数值时，传入两个参数，但被调函数内部实现机制为，给传入的2个参数划分内存空间临时保存，然而参与交换的变量的内存地址已发生变化，交换后的与交换前的是不同地址处的2对变量
	printf("Now x = %d, y = %d\n", x, y);

	getchar();
	return 0;
}

void interchange(int u, int v)	
{
	int temp;

	temp = u;
	u = v;
	v = temp;
}