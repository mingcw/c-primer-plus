#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void)
{
	int choice;
	void count(void);		//打印菜单界面等待用户响应

	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
		case 'a':
			printf("Buy low, sell high.\n");
			break;
		case 'b':
			putchar('\a');
			break;
		case 'c':
			count();
			break;
		default:
			printf("Program error!\n");
			break;
		}
	}
	printf("Bye!\n");

	getchar();
	return 0;
}

//获取用户选择的菜单选项
char get_choice(void)
{
	int ch;

	printf("Enter the letter of your choice: \n");
	printf("a.advice               b.bell\n");
	printf("c.count                q.quit\n");
	ch = get_first();
	while ((ch < 'a' || ch > 'c') && ch != 'q')
	{
		printf("Please respond the a, b, c, or q.\n");		//输入a, b ,c ,q 以外的字符时，提示用户
		ch = get_first();
	}

	return ch;
}

//获取输入行的第一个非空白字符
char get_first(void)
{
	int ch; 

	ch = getchar();
	while (isspace(ch))
	{
		printf("Please respond the a, b, c, or q.\n");
		ch = getchar();
	}	
	while (getchar() != '\n')
		continue;		//剔除输入行的剩余部分

	return ch;
}

//循环写行
void count(void)
{
	int n;

	printf("Count how far? Enter an integer: \n");
	n = get_int();
	for (int i = 1; i <= n; i++)
		printf("%d\n", i);
}

//确认输入一个有效整数
int get_int(void)
{
	int input;
	char ch;

	
	while (scanf_s("%d", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);	//取出错误的输入
		printf(" is not an integer value.\nPlease enter an ");
		printf("integer value, such as 25, -225, or 3: ");
	}

	return input;
}