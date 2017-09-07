#include <stdio.h>

int main(void)
{
	//C默认非0值为真，0值为假
	int n = 3;

	while (n)
		printf("循环体1：n = %d\n", n--);
	printf("\n结束循环1：n = %d\n\n", n);

	n = -3;
	while (n)
		printf("循环体2：n = %d\n", n++);
	printf("\n结束循环2：n = %d\n\n", n);

	int goast = 7;
	while (goast)		//等价于while(goast!= 0),程序员常用写法
	{
		;//写入代码
	}
	return 0;
}