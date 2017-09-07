/*
	编写一个程序，用指向函数的指针数组执行菜单。例如，在菜单中选择a会激活由数组第一个元素指向的函数。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FUNSIZE 4

typedef void(*pfun)(char *);

void showmenu(void);
char get_choice(void);
void eatline(void);
void funa(char *);
void funb(char *);
void func(char *);
void fund(char *);


int main(void)
{
	pfun funs[FUNSIZE] = { funa, funb, func, fund };
	char choice;

	system("color 0A");
	showmenu();
	choice = get_choice();
	while (choice != 'e')
	{
		switch (choice)
		{
		case 'a':
			funs[0]("★");
			break;
		case 'b':
			funs[1]("&");
			break;
		case 'c':
			funs[2]("*");
			break;
		case 'd':
			funs[3](" ");
			break;
		}
		showmenu();
		choice = get_choice();
	}
	puts("Bye!");

	system("pause");
	return 0;
}

void showmenu(void)
{
	puts("To choose a function, enter its letter label:");
	puts("a) print ★");
	puts("b) print &");
	puts("c) print *");
	puts("d) print nothing.");
	puts("e) quit");
}

void funa(char * str)
{
	int count;

	puts("Please enter the number of printing:");
	if (scanf_s("%d", &count, 10) == 1)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%s", str);
		}
		putchar('\n');
	}
	else
	{
		puts("No valid number.");
	}
	eatline();
}

void funb(char * str)
{
	int count;

	puts("Please enter the number of printing:");
	if (scanf_s("%d", &count, 10) == 1)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%s\n", str);
		}
	}
	else
	{
		puts("No valid number.");
	}
	eatline();
}

void func(char * str)
{
	int count;

	puts("Please enter the number of printing:");
	if (scanf_s("%d", &count, 10) == 1)
	{

		for (int i = 0; i < count; i++)
		{
			printf("%*s\n", i + 1, str);
		}
	}
	else
	{
		puts("No valid number.");
	}
	eatline();
}

void fund(char * str)
{
	;
}

char get_choice(void)
{
	char ch;

	ch = getchar();
	ch = tolower(ch);
	eatline();
	while (strchr("abcde", ch) == NULL)
	{
		puts("Please enter a, b, c, d or e:");
		ch = tolower(getchar());
		eatline();
	}

	return ch;
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		continue;
	}
}