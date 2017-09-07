#include <stdio.h>
#define SPACE ' '		//字符“空格”

int main(void)
{
	//把用户输入的字符序列按照每个字符的下一个ANCII字符输出，空格字符保持不变

	int ch = getchar();		//读入一个字符
	while (ch != '\n')		//当在一行内时
	{
		if (ch == SPACE)
		{
			putchar(ch);		//输入空格时，原样输出
		}
		else
		{
			putchar(ch + 1);	//改变成输入字符的下一个ANCII字符，输出
		}
		ch = getchar();			//读入下一个字符
	}
	putchar(ch);

	getchar();
	return 0;
}