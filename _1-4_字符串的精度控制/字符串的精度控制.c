#include <stdio.h>
#include <string.h>
#define BLURB "Authentic imitation!"

int main(void)
{
	printf("/%2s/\n\n", BLURB);//打印字符串，最短长度为2
	printf("/%24s/(长%d)\n\n", BLURB, strlen(BLURB));//打印字符串，最短长度为24，最高位用空格填充
	printf("/%24.5s/\n\n", BLURB);//打印字符串，最短长度为24，打印字符串的后5个字符，最高位用空格填充
	printf("/%-24.5s/\n\n", BLURB);//打印字符串，最短长度为24，打印字符串的后5个字符，最高位用空格填充，左对齐打印出字符（空格居右）
	//printf("/%+24.5s/\n\n", BLURB);//显示符号，哦，字符串无符号

	getchar();
	return 0;

}