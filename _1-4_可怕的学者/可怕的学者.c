/*
一位强大统治者要奖励一位对他做出突出贡献的学者，学者指着棋盘
	说，第一格放1粒小麦，第二格放2粒，第......就是这样
*/

#include <stdio.h>

#define SQUARES 64	//棋盘的方格数
#define CROP 1e15	//以粒计的美国小麦产量

int main(void)
{
	double current, total;
	int count = 1;

	printf("square  grains added  total grains  fraction of\n");
	printf("				    US total\n");
	total = current = 1;	//开始时1粒
	printf("%-6d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);

	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0*current;//下个方格的粒数加倍
		total = total + current;
		printf("%-6d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	}
	printf("That's all.\n");
	getchar();
	return 0;
}