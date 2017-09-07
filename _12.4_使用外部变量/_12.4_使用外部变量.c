#include <stdio.h>

int units = 0;					//声明外部变量（不初始化时，默认为0）, 对后面函数可用；外部变量只能在定义时，进行初始化
	//第一次声明：定义声明（留出存储空间）

void critic(void);

int main(void)
{
	extern int units;			//提高程序的可读性，可选的二次声明（存储类说明符extern告诉编译器在该函数中用到的units都是指同一个在函数外（甚至是文件外）定义的 变量）
	//第二次声明：引用声明（关键字extern表明该声明不是定义，因为它指示编译器参考其他地方）extern引用一个已经存在的外部定义

	printf("How many pounds to a firkin of butter?\n");
	scanf_s("%d", &units, 10);
	while (units != 56)
	{
		critic();
	}
	printf("You must have looked up!\n");

	getchar();
	getchar();
	return 0;
}

void critic(void)
{
								//这里忽略了可选的二次声明
	printf("No luck, chumy.Try again!\n");
	scanf_s("%d", &units, 10);	//外部变量
}