#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//声明一个枚举类型，使用choices为标记，将枚举常量no、yes、maybe分别设置为0、1、2.

enum choices		//枚举类型模板，使用默认值，标记为choices
{
	no,
	yes,
	maybe
};

int main(void)
{
	enum choices choice;

	system("color 5A");
	srand((unsigned int)time(NULL));
	choice = rand() % 10;
	switch (choice)
	{
	case no:	printf("%d\n", choice);
		break;
	case yes:	printf("%d\n", choice);
		break;
	case maybe:	printf("%d\n", choice);
		break;
	default:	printf("No.\n");
		break;
	}

	getchar();
	return 0;
	
}