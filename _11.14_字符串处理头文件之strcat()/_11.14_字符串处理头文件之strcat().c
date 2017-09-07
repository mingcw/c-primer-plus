#include <stdio.h>
#include <string.h>

#define SIZE 81

int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";

	puts("What is your favorite flower?");
	gets_s(flower, SIZE);
	strcat_s(flower, SIZE, addon);		/*字符串连接函数的安全版本，将源字符串拷贝到目标字符串的尾部，
										 拷贝的字节数至少等于两字符串的长度+1,
										 如果源字符串空间不够，多出来的字符会溢出到相邻的存储单元，引发一些问题*/
	puts(flower);
	puts(addon);

	getchar();
	return 0;
}