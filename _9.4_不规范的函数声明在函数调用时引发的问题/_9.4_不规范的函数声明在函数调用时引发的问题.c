#include <stdio.h>
#include <stdlib.h>

//不规范的函数声明
int imax();		/*可以省略参数名，但最好不要省略参数数量和类型，
				如果未声明参数个数和类型，编译器无法检查函数调用时参数的传递数量和类型，
				生成的编译版本可能引发不可预知的错误*/

int main(void)
{
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3));		/*根据函数定义，函数调用时，
							push 3
							call &imax
							imax()从栈中取出2个整数，
							第1个整数是推入栈的3，第二个是栈中的其他数据，
							*/
	printf("The maximum of %d and %d is %d.\n",
		3, 5, imax(3.0, 5.0));/*两个double值（共16字节128位）推入栈中，
							  imax()从栈中取出2个int值（共8字节64位），将前64位ASCII值解释为2个int值，
							  调试知道，较大值解释为1074266112*/

	getchar();
	return 0;
}

int imax(n, m)
int n, m;		//声明参数类型（最好在定义头声明完全）
{
	int max;

	if (n > m)
		max = n;
	else
		max = m;

	return max;
}