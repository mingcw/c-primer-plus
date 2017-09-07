/*
	编写一个transform()函数，它接受4个参数：包含double类型的源数组名，double类型的目标数组名，
	表示数组元素个数的int变量以及一个函数名（或者，等价的指向函数的指针）。transform()函数把
	指定的函数作用于源数组的每个元素，并将返回值放到目标数组中。例如：
	transform(source, target, 100, sin)
	这个函数调用把sin(source[0])赋给target[0]，等等，共有100个元素。在一个程序中测试该函数，
	调用4次transform()，分别使用math.h函数库中的两个函数以及自己设计的两个合适的函数作为参数。*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define FUNSIZE 4
#define DBLESIZE 5

typedef double(*pfun)(double);

void showmenu(double src[], int n);
char get_choice(void);
void eatline(void);

double Square(double);
double Opposite(double);
void transform(double src[], double dest[], int n, pfun _pfun);
void cpyarr(double src[], double dest[], int n);

int main(void)
{
	pfun pfuns[FUNSIZE] = { sin, cos, Square, Opposite };
	double src[DBLESIZE] = { 1.0, 1.5, 2.0, 2.5, 3.0 };
	double dest[DBLESIZE];
	double copy[DBLESIZE];
	char choice;

	system("color 0A");

	showmenu(src, DBLESIZE);
	choice = get_choice();
	while (choice != 'e')
	{
		cpyarr(src, copy, DBLESIZE);
		switch (choice)
		{
		case 'a':
			transform(copy, dest, DBLESIZE, pfuns[0]);
			break;
		case 'b':
			transform(copy, dest, DBLESIZE, pfuns[1]);
			break;
		case 'c':
			transform(copy, dest, DBLESIZE, pfuns[2]);
			break;
		case 'd':
			transform(copy, dest, DBLESIZE, pfuns[3]);
			break;
		}
		showmenu(src, DBLESIZE);
		choice = get_choice();
	}
	puts("Bye!");

	system("pause");
	return 0;
}

void showmenu(double src[], int n)
{
	puts("To change below array, enter a funtion's letter label:");
	puts("a) sin");
	puts("b) cos");
	puts("c) Square");
	puts("d) Opposite");
	puts("e) quit");
	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", src[i]);
	}
	putchar('\n');
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

void transform(double src[], double dest[], int n, pfun _pfun)
{
	for (int i = 0; i < n; i++)
	{
		dest[i] = (*_pfun)(src[i]);		//语法1
		//dest[i] = *_pfun(src[i]);		  语法2
	}

	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", dest[i]);
	}
	putchar('\n');
}

double Square(double _double)
{
	return (_double * _double);
}

double Opposite(double _double)
{
	return (_double * (-1.0));
}

void cpyarr(double src[], double dest[], int n)
{
	for (int i = 0; i < DBLESIZE; i++)
	{
		dest[i] = src[i];
	}
}