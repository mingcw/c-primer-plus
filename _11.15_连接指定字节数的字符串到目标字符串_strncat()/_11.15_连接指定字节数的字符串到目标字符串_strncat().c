#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 31
#define BUGSIZE 13

int main(void)
{
	char flower[SIZE];
	char add_on[] = "s smell like old shoes.";
	char bug[BUGSIZE];
	int available;											

	system("color 1A");

	puts("What is your favourite flower?");
	gets_s(flower, SIZE);									//扫描输入字符串，缓冲区的最大长度是读入的字符数+1；C不检查数组越界，一旦元素超出数组边界，可能引发异常

	if (strlen(flower) + strlen(add_on) + 1 <= SIZE)		//flower的长度+addon的长度不超过flower的最大长度
	{
		strcat_s(flower, SIZE, add_on);						//将zddon字符串拷贝到flower后边
	}
	puts(flower);											//打印（接长后的）flower字符串

	puts("What is your favorite bug?");
	gets_s(bug, BUGSIZE);

	available = BUGSIZE - strlen(bug) - 1;					//bug字符串可以连接的最大字符数
	strncat_s(bug, BUGSIZE, add_on, available);				//最多添加available个字符到bug, bug最大容量为BUGSIZE
	puts(bug);

	getchar();
	return 0;
}