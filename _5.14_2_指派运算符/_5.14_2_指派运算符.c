#include <stdio.h>

int main(void)
{
	//使用（type）可以直接转换数据类型（指派运算符）
	float fl_1 = 1.6, fl_2 = 1.7;
	int a;
	
	a = fl_1 + fl_2;
	printf("a=%d\n", a);
	a = (int)fl_1 + (int)fl_2;
	printf("a=%d\n", a);
	getchar();
	return 0;
}