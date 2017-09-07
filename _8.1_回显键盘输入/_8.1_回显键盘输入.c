#include <stdio.h>

int main(void)
{
	/*简单的小程序“单字符I/O”开始第八章
	该程序对用户输入的数据进行延迟回显
	即 将以行缓冲为输入模式的键盘键入的字符块保存到缓冲区，键入换行符刷新缓冲区，回显字符块
	ANSI C采用缓冲输入，键盘是标准的行缓冲，所以键入换行符时才回显数据*/

	char ch;

	while ((ch = getchar()) != '#')
	{
		putchar(ch);
	}
	printf("Bye!");

	getchar();
	getchar();
	return 0;

}