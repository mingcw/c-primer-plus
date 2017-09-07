#include <stdio.h>
#include <stdlib.h>

/*请在命令行环境添加命令行参数（整数）调试程序*/

int main(int argc, char * argv[])
{
	int times;

	if (argc < 2 || (times = atoi(argv[1])) < 1)			//如果用户么有输入命令行参数或输入的数不是正整数
	{
		printf("Usage: %s positive-number\n", argv[0]);		//反馈用户
	}
	else
	for (int i = 0; i < times; i++)
		puts("Hello, good looking!");

	getchar();
	return 0;
}