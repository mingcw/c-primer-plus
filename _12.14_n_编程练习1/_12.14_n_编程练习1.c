#include <stdio.h>
//声明外部变量（不初始化时，默认为0）, 对后面函数可用；外部变量只能在定义时，进行初始化
//第一次声明：定义声明（留出存储空间）

void critic(int * ptr);

int main(void)
{
	int units;

	printf("How many pounds to a firkin of butter?\n");
	scanf_s("%d", &units, 10);
	while (units != 56)
	{
		critic(&units);
	}
	printf("You must have looked up!\n");

	getchar();
	getchar();
	return 0;
}

void critic(int * ptr)
{
	//这里忽略了可选的二次声明
	printf("No luck, chumy.Try again!\n");
	scanf_s("%d", ptr, 10);
}