#include <stdio.h>
#include <ctype.h>		//提供了。，\\ 原型

int main(void)
{
	//改善7.2的源代码，把用户输入的字母字符按照它的ANCII序列的后一个输出，非字母字符原样输出

	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))		//当输入字符时
		{
			putchar(ch + 1);	//则改变它
		}
		else					//否则
		{
			putchar(ch);		//原样打印它
		}
	}
	putchar(ch);				//打印换行字符

	getchar();
	getchar();
	return 0;
}