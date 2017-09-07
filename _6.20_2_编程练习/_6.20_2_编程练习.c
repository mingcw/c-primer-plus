#include <stdio.h>

int main(void)
{
	//打印梯形美元符
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("$");
		}
		printf("\n");
	}
	printf("\n");

	//打印梯形字母行
	for (int i = 0; i < 6; i++)
	{
		for (char ch = 'F'; ch >= 'F'- i; ch--)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	printf("\n");

	//打印字母金字塔

	char ch_top;
	int line;

	printf("Letters Pyramid\nPlease enter a letter of the spire: ");
	scanf_s("%c", &ch_top, 1);
	printf("Please enter the number of rows to print: ");
	scanf_s("%d", &line, 2);
	for (int i = 1; i <= line; i++)
	{
		for (int j = 1; j <= line - i; j++)
		{
			printf(" ");			//处理空格
		}
		for (char ch = ch_top; ch <= ch_top + i - 1; ch++)
		{
			printf("%c", ch);		//升序打印字母
		}
		for (char ch = ch_top + i - 2; ch >= ch_top; ch--)
		{
			printf("%c", ch);		//升序打印字母
		}		
		printf("\n");
	}
	
	
	getchar();
	getchar();
	return 0;
}