#include <stdio.h>	//包含stdio头文件,标准输入输出头文件（内部封装多个函数()和关键字），目的调用printf函数格式化打印

int main(void)		//标志main函数
{
	int num;		//声明语句，声明整型的num变量
	int a;
	num = 1;		//赋值语句，为num赋值
	
	//定义部分与动作部分分开
	a = printf("I'm a simple ");	//函数调用语句，调用printf函数，格式化打印第一行(该函数的返回值是打印出字符的长度)
	printf("computer.\n");			//同上
	printf("My favourite number is %d because it is first.\n", num);	//格式化打印第二行,%指出num的输出位置，d为把num按照十进制整数输出
	printf("%d", a);
	getchar();	//等待用户输入，防止屏幕一闪而过
	return 0;	//返回语句，返回0值
}