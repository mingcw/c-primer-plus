#include <stdio.h>

int main(void)
{
	int num;
	//scanf()中使用*跳过指定的输入项目
	printf("Please enter three integers: \n");
	scanf_s("%*d %*d %d", &num,10);
	printf("The last integer is %d\n", num);

	getchar();
	getchar();
	return 0;

}