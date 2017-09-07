#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

int main(int argc, char * argv[])
{

	/*前言: 
				题目写多了，请忽略“（命令行参数）”部分
	  函数介绍：
				 strtol(const char * Str, char ** EndPtr, int Radix)
	  函数功能：
				将字符指针指向的字符串转换为long型值，
				并反馈指向从字符串开始到遇到的第一个非数字字符的指针值，将其保存在一个二级指针里，
				同时，提供了对不同进制数字串的转换，即数字的基数，最多可以有36进制，使用一直到“z”的字母作为数字	 
	  相关函数：
				strtod(const char * Str, char ** EndPtr) 
				函数功能：转换字符串中的数字为十进制double型值，并反馈遇到的第一个非double字符

			    strtoul(const char * Str, char ** EndPtr, int Radix)
				函数功能：转换字符串中的数字为无符号long型值，并反馈遇到的第一个非long型字符，允许转换多种进制格式
				
				。。。等等。。。
		附录：
				很多C实现都用itoa()和ftoa()把整数和浮点数转换为字符串，
				但在兼容性上，应使用sprintf()函数替代以上*/

	char num_str[SIZE];
	char * end;
	long num_val;

	system("color 4A");
	puts("Enter a number (empty to quit) :");
	while (gets_s(num_str, SIZE) && num_str[0] != '\0')
	{
		num_val = strtol(num_str, &end, 10);		//把字符指针指向的字符串数据转换为long型值，并传入一个二级指针（指向一个指向字符的指针）
		printf("value: %ld, stopped at %s (%d)\n", num_val, end, *end);
		num_val = strtol(num_str, &end, 16);		/*基于16*/
		printf("value: %ld, stopped at %s (%d)\n", num_val, end, *end);
		puts("Next number:");
	}
	puts("Bye!");

	getchar();
	return 0;
}