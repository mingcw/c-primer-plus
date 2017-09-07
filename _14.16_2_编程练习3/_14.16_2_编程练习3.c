/*
	修改程序清单14.2中的书目列表程序，使它首先按照输入的顺序输出图书的秒数
	然后按照标题的字母升序输出图书的描述，最后按照value值的升序输出图书的
	秒数*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZETITL 41
#define SIZEAUTL 21
#define SIZEBKS 10

struct book
{
	char title[SIZETITL];
	char author[SIZEAUTL];
	float value;
} ;
typedef struct book BOOK;

void show(const BOOK library[], int n);
void sort_title(BOOK library[], int n);
void sort_value(BOOK library[], int n);

int main(void)
{
	BOOK library[SIZEBKS];
	int count = 0;

	system("color 5A");
	//获取输入
	puts("Please input a title.");
	puts("Press [enter] at the start of a line to stop;");
	while (count < SIZEBKS
		&& gets_s(library[count].title, SIZETITL) != NULL
		&& library[count].title[0] != '\0')
	{
		puts("Enter the author:");
		gets_s(library[count].author, SIZEAUTL);
		puts("Enter the value:");
		scanf_s("%f", &library[count].value);
		while (getchar() != '\n')
		{
			;					//清空输入行
		}
		puts("Next title (empty line to quit)");
		count++;
	}

	if (count > 0)
	{
		//按照输入顺序输出图书描述
		puts("Here is the list of your books:");
		show(library, count);

		//按照标题的字母升序输出图书描述
		puts("Here is the list of your books according to the title:");
		sort_title(library, count);
		show(library, count);

		//按照value值升序输出图书描述
		puts("Here is the list of your books according to the value:");
		sort_value(library, count);
		show(library, count);
	}
	else
	{
		printf("No books? Good!\n");
	}
	
	system("pause");
	return 0;

}

void show(const BOOK library[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
	}
}

void sort_title(BOOK library[], int n)
{
	BOOK temp;

	//n个元素比较n-1次
	for (int i = 0; i < n - 1; i++)
	{
		//从前往后，依次取出两个进行比较
		for (int j = 0; j < n - i - 1; j++)			//跟剩余的n-i-1个元素比较
		{
			if (strcmp(library[j].title, library[j + 1].title) > 0)
			{
				temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
}

void sort_value(BOOK library[], int n)
{
	BOOK temp;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)				
		{
			if (library[j].value > library[j + 1].value)
			{
				temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
}