//猜数小游戏的主文件

#include <stdio.h>
#include <stdlib.h>								//为srand()提供原型
#include <time.h>								//为time()提供函数原型
#include "randum.h"
#include <stdbool.h>
#include <Windows.h>

void evaluate(void);
void changefontcolor(void);
int printf1(const char * str, ...);

static int guess_count = 0;						//静态计数器,内部链接

int main (void)
{
	float guess;
	int secret;
	bool right = false;

	srand((unsigned int)time(NULL));			//取系统时间为随机数种子
	changefontcolor();
	printf( "********************************\n"
			"***   猜数小游戏 - C控制台   ***\n"
			"********************************\n"
			"\n系统已初始化一个0～%d的随机数，请输入您猜的数（q退出游戏）：\n", MAX);
	while (!right)
	{
		secret = randnum(MAX);					//产生随机数
		while (!right && scanf_s("%f", &guess, 10))
		{
			if (guess < secret)
			{
				printf("第%d次：您输入的数偏小！\n", ++guess_count);
				right = false;
			}
			else if (guess > secret)
			{
				printf("第%d次：您输入的数偏大！\n", ++guess_count);
				right = false;
			}
			else
			{
				printf("第%d次：哦了，您猜对了(^_^)\n", ++guess_count);
				right = true;
			}
		}
		if (right)								//如果猜对
		{
			putchar('\n');
			evaluate();
			changefontcolor();
			printf("\n新一轮开始, 请输入您猜的数（q退出游戏）：\n");
			guess_count = 0;					//猜的次数清零
			right = false;						//猜对置假
		}
		else
			goto mark1;							//用户输入非数字数据
	}
mark1:
	printf("游戏结束！\n");

	system("pause");
	return 0;
}

//评价函数
void evaluate(void)
{
	if (guess_count <= 5)
	{
		printf_evaluate("本次游戏，您的等级评价是 %c\n", 'A');
	}
	else if (guess_count >5 && guess_count <= 10)
	{
		printf_evaluate("本次游戏，您的等级评价是 %c\n", 'B');
	}
	else if (guess_count >10 && guess_count <= 20)
	{
		printf_evaluate("本次游戏，您的等级评价是 %c\n", 'C');
	}
	else
	{
		printf_evaluate("本次游戏，您的等级评价是 %c\n", 'D');
	}
}

//更改控制台文本色
void changefontcolor(void)
{
	HANDLE hConsoleOutput;
	static WORD color = 0x09;						//空链接、代码块作用域、静态类

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//color = (WORD)time(NULL) % 0x10;				//取随机的前景色0-F
	color += 0x1;
	color %= 0x1A;									//color是0～F的变色前景,背景色为0(黑色)
	SetConsoleTextAttribute(hConsoleOutput, color);
}

//打印颜色字体
int printf_evaluate(const char * str, char ch)
{
	HANDLE hConsoleOutput;
	int retn;

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput, 0x4E);
	retn = printf(str, ch);

	return retn;

	//以下是下一节的知识点：分配内存malloc()和free()
	char * ptd;
	ptd = (char *)malloc(sizeof (char)* 10);		/*注意，ANSCI C标准中，内存分配函数使用一个指向请求内存块的通用指针作为返回值，
													所以在分配内存时，为了程序清晰，应该对指针进行类型指派
													(但，将void指针赋值给其他类型指针，并不造成类型冲突，这一点有别于平常的指针赋值兼容性和要求)*/
}