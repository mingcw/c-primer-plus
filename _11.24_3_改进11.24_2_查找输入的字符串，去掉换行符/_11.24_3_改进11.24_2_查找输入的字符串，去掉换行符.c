#include <stdio.h>
#include <stdlib.h>
#include <string.h>		//提供了strchr()的原型

#define MAX 81

int main(void)
{
	char name[MAX];
	char * ptr;

	system("color 0A");
	printf("Hi, what's your name?\n");
	fgets(name, MAX, stdin);	
	ptr = strchr(name, '\n');		//查找换行符
	if (ptr)						//如果指针值不为NULL
		*ptr = '\0';				//植入空字符
	printf("%s? Ah, %s!\n", name, name);

	system("pause");
	return 0;
}