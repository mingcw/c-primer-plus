#include <stdio.h>

int main(void)
{
	//数据类型的自动转换
	char ch;
	int i;
	float fl;

	fl = i = ch = 'C';
	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
	ch = ch + 1;
	i = fl + ch*2;
	fl = 2.0*ch + i;
	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
	ch = 5212205.17;
	printf("ch = %c\n", ch);
	getchar();
	return 0;
}