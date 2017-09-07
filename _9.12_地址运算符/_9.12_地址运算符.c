
/*查看变量的存储地址*/
#include <stdio.h>				//声明

void mikado(int);

int main(void)
{
	int pooh = 2, bah = 5;		//局部变量

	printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In main(), bah = %d and &bah = %p\n", bah, &bah);
	mikado(pooh);

	getchar();
	return 0;
}

void mikado(int bah)			//定义
{
	int pooh = 10;				//局部变量

	printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);

}