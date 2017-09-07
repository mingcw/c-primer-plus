#include <stdio.h>
#include <stdlib.h>

#define MAX 81
int main(void)
{
	/*gets()函数读取字符串：
	读取换行符之前的所有字符，并在尾部追加一个空字符返回给调用方
	同时，读取换行符并将其丢弃


	注意： gets()容易泄露内存，
	该编译器下用gets_s()限制读取字符串的长度*/

	char name[MAX];			//分配空间

	system("color 0A");
	printf("Hi, what's your name?\n");
	gets_s(name, MAX);		//读取字符串到name数组
	printf("Nice name, %s!\n", name);

	getchar();
	return 0;
}