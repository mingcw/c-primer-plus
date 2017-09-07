#include <stdio.h>
int main(void)
{
	int i = 2147483647;		//int变量的取值范围(-2147483648,2147483647)
	unsigned int j = 4294967295;		//unsigned int变量的取值范围(0, 4294967295)

	printf("%d %d %d\n", i, i + 1, i + 2);		//i+1溢出到最小值-2147483638
	printf("%u %u %u\n", j, j + 1, j + 2);		//j+1溢出到最小值0

	printf("\n温馨提示：\n本计算机以%d字节存放int整数",sizeof(int));
	printf("，1字节占8位");
	printf("，所以unsigned int类型的32无符号整数的最大值是1111 1111 1111 1111 1111 1111 1111 1111，即十进制的4294967295");
	getchar();
	return 0;

}