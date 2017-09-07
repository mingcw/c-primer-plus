//-可变参数的函数
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
	头文件stdarg.h提供了可变参数函数的支持，下面是使用步骤：
	1.在函数原型中使用省略号
	2.在函数定义中创建一个va_list类型的变量
	3.用宏将该变量初始化为一个参数列表
	4.用宏访问这个参数列表
	5.用宏完成清理工作
	*/

double sum(int lim, ...);

int main(void)
{
	double s, t;

	s = sum(3, 1.1, 2.5, 13.3);
	t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
	system("color 5A");
	printf("return value for "
		"sum(3,1.1.2.5,13.3):             %g\n", s);
	printf("return value for "
		"sum(6,1.1,2.1,13.1,4.1,5.1,6.1): %g\n", t);

	system("pause");
	return 0;
}

double sum(int lim, ...)			//参数列表中至少有一个后跟省略号的参量（ASCI标准使用parmN表示省略号前最右侧的参量lim，它指定了省略号部分中的参数个数）
{
	va_list ap;						//声明存放参数列表的变量
	double tot = 0;

	va_start(ap, lim);				//把ap初始化为参数列表
	
	for (int i = 0; i < lim; i++)
	{
		tot += va_arg(ap, double);	//依次访问第一个、第二个...参数，并且va_arg()不提供后退回先前参数的方法，所以有时可以用宏va_copy(dest, src)保存va_list变量的副本以备再次使用
	}
	va_end(ap);						//释放分配的用于存放参数的内存
	
	return tot;
}