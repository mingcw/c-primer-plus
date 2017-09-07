#include <stdio.h>
#include <string.h>		/*提供字符串相关的函数原型*/
#include <stdlib.h>

void ChangeStrlen(char * string, unsigned int size);

int main(void)
{
	char msg[] = "Hold on to your hats, hackers.";

	system("color 0A");
	puts(msg);		//打印字符串，追加换行符
	ChangeStrlen(msg, 7);
	puts(msg);
	puts("Let's look at some more of the string.");
	puts(msg + 8);		//打印msg偏移8处的字符串

	getchar();
	return 0;
}


//如果源字符串的长度大于size，则缩短为size大小
void ChangeStrlen(char * string, unsigned int size)
{
	if (strlen(string) > size)
	{
		*(string + size) = '\0';		//在字串size长度后，第size+1个成员赋值为空字符
	}
}