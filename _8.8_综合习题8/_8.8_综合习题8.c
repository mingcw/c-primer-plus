#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float num1, num2; 

char get_choice(void);
char get_first(void);
void get_opetate_num(char choice, float num1, float num2);
float get_num(void);
double get_result(char choice, float num1, float num2);

int main(void)
{
	char ch;

	system("color E9");
	printf("★The console version of the calculator★\n");
	while ((ch = get_choice()) != 'q')
	{
		switch (ch)
		{
		case 'a':
			get_opetate_num(ch, num1, num2);
			printf("%g + %g = %g\n", num1, num2, num1 + num2);
			break;
		case 's':
			get_opetate_num(ch, num1, num2);
			printf("%g - %g = %g\n", num1, num2, num1 - num2);
			break;
		case 'm':
			get_opetate_num(ch, num1, num2);
			printf("%g × %g = %g\n", num1, num2, num1 * num2);
			break;
		case 'd':
			get_opetate_num(ch, num1, num2);
			printf("%g ÷ %g = %g\n", num1, num2, num1 / num2);
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

//获取输入的菜单选项
char get_choice(void)
{
	char ch;

	printf("Enter the opration of your choice: \n"
		"***********************************\n"
		"***   a.add         s.substract ***\n"
		"***   m.multiply    d.divide    ***\n"
		"***   q.quit                    ***\n"
		"***********************************\n");
	ch = get_first();
	while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
	{
		printf("You must enter a, s, m, d, or q.\n");		//输入a, s, m, d, q 以外的字符时，提示用户
		ch = get_first();
	}

	return ch;
}

//获取第一个非空白字符
char get_first(void)
{
	char ch;
	
	ch = getchar();
	while (isspace(ch))
	{
		printf("You must enter a, s, m, d, or q.\n");
		ch = getchar();
	}	
	while (getchar() != '\n')
		continue;
	
	return ch;
}

/*获取两个操作数
choice 菜单选项; num1, num2为返回的2个操作数*/
void get_opetate_num(char choice)
{
	printf("Enter first number: ");
	num1 = get_num();
	printf("Enter second number: ");
	num2 = get_num();
	while ((choice == 'd') && num2 == 0)
	{
			printf("Enter a number other than 0: ");
			num2 = get_num();
	}
	while (getchar() != '\n')
		continue;		//剔除换行符
}

//确认输入一个有效的数
float get_num()
{
	float fl_num;
	char ch;

	while (scanf_s("%f", &fl_num) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a number.\n");
		printf("Please enter an number, such as 2.5, -2.71E8, or 3: ");
	}

	return fl_num;
}
