/*
	编写一个程序，该程序用两个命令行参数读取两个二进制字符串,并打印对每个字符串使用~运算符的结果，
	以及对这两个数使用& | ^ 运算符的结果，使用二进制字符串的形式显示结果*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void show_bstr(int n);
bool is_bstr(char * p[], int n);
int tonumber(char * bstr);

int main(int argc, char * argv[])
{
	int para1, para2;

	system("color 5A");
	if (argc < 3)
	{
		printf("The command line's paramater is not right.\n");				//没有键入两个2进制字符串时退出
		exit(EXIT_FAILURE);
	}
	if (!is_bstr(argv, argc))
	{
		printf("These aren't binary characters.\n");
		exit(EXIT_FAILURE);
	}

	para1 = tonumber(argv[1]);
	para2 = tonumber(argv[2]);

	printf("~%d = %d: ", para1, ~para1);
	show_bstr(~para1);

	printf("~%d = %d: ", para2, ~para2);
	show_bstr(~para2);

	printf("%d & %d = %d: ", para1, para2, para1&para2);
	show_bstr(para1&para2);

	printf("%d | %d = %d: ", para1, para2, para1|para2);
	show_bstr(para1|para2);

	printf("%d ^ %d = %d: ", para1, para2, para1^para2);
	show_bstr(para1^para2);

	getchar();
	return 0;
}

void show_bstr(int n)
{
	int i, size = 8 * sizeof(int)+1;
	char bstr[8 * sizeof(int)+1];

	for (i = size - 2; i >= 0; i--, n >>= 1)
	{
		bstr[i] = (n & 01) + '0';
	}
	bstr[size - 1] = '\0';
	//printf("%s\n", bstr);
	i = 0;
	while (bstr[i])
	{
		putchar(bstr[i]);
		if (++i % 4 == 0 && bstr[i] != '\0')
			putchar(' ');
	}
	putchar('\n');
}

bool is_bstr(char * p[], int n)
{
	char * pstr;

	//首指针元素是程序名的指针，所以从p[1]开始查找
	for (int i = 1; i < n; i++)
	{
		pstr = p[i];
		while (*pstr)
		{
			if (*pstr++ > '1')
				return false;
		}
	}

	return true;
}

int tonumber(char * pbin)
{
	unsigned int bin = 0, size = strlen(pbin);

	for (unsigned int i = 0; i < size; i++)
	{
		bin &= ~01;					//位0清零
		bin |= *(pbin + i) - '0';	//写入位0
		bin <<= 1;					//左移1位
	}
	bin >>= 1;						//写完最后一位之后向左多移了1位，所以向右移动一位，字符串转换为二进制位

	return bin;
}