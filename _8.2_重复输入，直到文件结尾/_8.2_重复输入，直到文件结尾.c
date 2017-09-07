#include <stdio.h>

int main(void)
{
	/*ANSI C规定对输入进行缓冲，键盘以行缓冲进行字符块的传递到缓冲区，遇到换行符将缓冲区刷新（清空）显示*/

	int ch;		/*为具有通用性，最好将接受输入字符的变量ch声明为int类型，与getchar()返回值类型保持一致*/

	while ((ch = getchar()) != EOF)		/*C程序模仿对文件的读入方式读取屏幕输入，到达文件尾时，返回EOF（引入的头文件已经定义）
										但是，除非键入EOF的字符值，否则，该程序将无法停止
										所以，要定义一个标志EOF的字符值，PC机上，键入Ctrl+Z会将该位置识别为文件尾信号*/
	{
		putchar(ch);	//回显
	}
	//单步调试发现getchar()的执行机理：等待键盘输入字符，字符序列映射为stdin数据流，stdin流保存到缓冲区，getchar()从缓冲区获取字符
	printf("Bye!\n");

	getchar();
	return 0;

}