#include <stdio.h>
#include <string.h>  /*提供strlen函数原型
						strlen()函数计算字符串长度的方式与scanf_s()类似,从字符串的首字符到遇到的第一个空字符为止(不计入空字符)*/

#define PRAISE "What's a marvelous name!"

int main (void)
{
	char name[40];

	printf("What's your name?\n");
	scanf_s("%s", name, 40);
	printf("Hello,%s.%s\n", name, PRAISE);
	printf("Your name of %d letters occupies %d memory cells.\n",
		strlen(name),sizeof(name));
	printf("The phrase of praise has %d letters ",
		strlen(PRAISE));
	printf("and occupied %d memory cells\n", sizeof(PRAISE));

	getchar();
	getchar();
	return 0;
	
}