#include <stdio.h>
#include <stdlib.h>

#define MAX 81

int main(void)
{
	char name[MAX];
	char * ptr;

	system("color 0A");
	printf("Hi, what's your name?\n");
	ptr = gets_s(name, MAX);		/*gets_s()获取指定长度-1的字符串并追加空字符，将换行符读取丢弃
									读取到的字符串保存到第一个参数指向的地址，
									读取成功返回指向该字符串的char指针，失败返回空指针

									注意: gets_s()返回的指针和传递过来的是同一个指针，但意义不同：
									依据该函数功能，可知name作为字符串的地址常量，不可执行自增自减运算，否则会导致字符串的地址发生变化
									而返回的指向该字符串的指针ptr可以执行自增运算，使得指针指向下一个字符*/
	printf("%s? Ah! %s!\n", name, ptr);

	getchar();
	return 0;
}