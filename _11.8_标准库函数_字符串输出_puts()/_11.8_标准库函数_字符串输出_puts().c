#include <stdio.h>
#include <stdlib.h>

#define DEF "I am a #defined string."

int main(void)
{
	char str1[80] = "An array was initialized to me.";
	const char * str2 = "A pointer initialized to me.";

	//gets_s(str1, 80);			//gets_s()函数读取一行字符串，缓冲区大小为80B（换行符被读取丢弃）

	puts("I'm an argument to puts().");		//puts()函数输出一行非符号字符串常量（字符串常量本身是指向首字符的指针）
	puts(DEF);			//输出一行符号字符串常量（同上）
	puts(str1);			//输出一行字符串（在一个追加了空字符的字符数组中）
	puts(str2);			//输出一行str2指向的字符串
	puts(&str1[5]);		//输出一行str1的第6个元素所在地址处的字符串
	puts(&str2 + 4);	//输出一行str2偏移4指向的字符串

	getchar();
	return 0;
}