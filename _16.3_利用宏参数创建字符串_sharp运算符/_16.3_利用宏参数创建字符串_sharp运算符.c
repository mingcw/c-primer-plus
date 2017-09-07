#include <stdio.h>
#include <stdlib.h>

#define PSQR(X) printf("The square of " #X " is %d.\n", ((X)*(X)))

//在宏函数中，如果X是一个宏参数，那么#X就可以把宏参数转化为相应的字符串，这个过程称为字符串化（stringgizing）。
int main(void)
{
	int y = 5;

	system("color 0A");

	PSQR(y);		//第一次调用宏时，用“y”代替#X
	PSQR(2 + 4);	//第二次调用宏时，用“2 + 4”代替#X
					//然后ANSI C的字符串连接功能将这些字符串连接为printf（）语句的格式字符串
	getchar();
	return 0;
}