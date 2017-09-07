/*
	与#运算符一样，##运算符可以用于类函数宏的替换部分。（##还可以用于类对象宏的替换部分）
	##运算符把2个语言符号组合成单个的语言符号。*/

/*说人话就是：
			   #运算符可以把宏参数转化成字符串
			  ##运算符可以粘合出一个新的标识符
			  
			  一个#可以创建字符串，两个#可以创建标识符*/

#include <stdio.h>
#include <stdlib.h>

#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n)

int main(void)
{
	int XNAME(1) = 14;		//变为 int x1 = 14;
	int XNAME(2) = 20;		//变为 int x2 = 20;

	system("color 5A");

	PRINT_XN(1);			//变为 printf("x1 = %d\n", x1);
	PRINT_XN(2);			//变为 printf("x2 = %d\n", x2);

	getchar();
	return 0;
}