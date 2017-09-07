#include <stdio.h>
#include <math.h>

//使用可变参数的宏：实现思想是用省略号代替参数列表中的最后一个参数

/*
该实例中显示了可变宏的应用：...和__VA_ARGS__
以及#预处理运算符和字符串的连接功能。（##预处理连接符的用处别忘了）*/

#define PR(x, ...) printf("Message " #x ": "__VA_ARGS__)

int main(void)
{
	double x = 48.0;
	double y;

	y = sqrt(x);

	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f, y = %.4f\n", x, y);

	getchar();
	return 0;
}

//省略号只能代替最后的宏参数，下面的定义是错误的：
#define WRONG(x, ..., y) #x #__VA_ARGS__ #y
