
/*
	调试途经：
			在命令行环境运行程序，并提供命令行参数进行函数测试

	知识点：
			1.命令行：在命令行环境下，用户输入的用于运行程序的行
			2.命令行参数：同一个命令行的附加项；当有多个命令行参数时，系统使用空格判一个字符串结束、另一个字符串开始
			3.标准main函数
*/

#include <stdio.h>

int main(int argc, char * argv[])
{
	/*
	  标准main函数包括2个参数:

	  第一个参数是包括命令名在内的命令行参数个数，
	  第二个参数是指向各个命令行参数的指针数组
	*/
	printf("The command line has %d arguements: \n", argc - 1);		//命令行参数包括命令名
	for (int i = 1; i < argc; i++)
	{
		printf("%d: %s\n", i, argv[i]);								//打印所有的命令行参数
	}
	
	getchar();
	return 0;
}