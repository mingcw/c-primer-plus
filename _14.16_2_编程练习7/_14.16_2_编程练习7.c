/*
	修改程序清单14.14，在从文件中读出每个记录并且显示它时，允许用户选择删除该记录或修改该记录的内容。
	把修改后的记录信息写入文件。。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define FILENAME "book.dat"
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book									//定义结构模板，标记为book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char showmenu(void);
void eatline(void);
bool operate(struct book library[], int * n);				//可能涉及记录增减，所以传递指针
bool Delete(struct book library[], int * n);
void Alter(struct book library[], int n);

int main(void)
{
	struct book library[MAXBKS];					//结构数组
	int count = 0;
	FILE * pbooks;
	size_t size = sizeof(struct book);
	bool changed;

	system("color 0A");

	if (fopen_s(&pbooks, FILENAME, "r+b") != 0)
	{
		fprintf(stderr, "Can't open file %s\n", FILENAME);
		exit(EXIT_FAILURE);
	}
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
		{
			fprintf(stdout, "Current contents of %s:\n", FILENAME);
		}
		printf("%d. %s by %s: $%.2f\n", count, library[count].title,
			library[count].author, library[count].value);
		count++;
	}

	changed = operate(library, &count);
	if (count > 0)
	{
		if (changed == 1)
		{
			puts("Here is the list of your books now:");
			for (int i = 0; i < count; i++)
			{
				printf("%d. %s by %s: $%g\n", i, library[i].title,
					library[i].author, library[i].value);
			}
			rewind(pbooks);
			fwrite(library, size, count, pbooks);
		}
	}
	else
	{
		puts("No books? Too bad.");
	}
	printf("Bye!\n");
	fclose(pbooks);

	system("pause");
	return 0;
}

bool operate(struct book library[], int * n)
{
	char ch;
	bool changed = false;

	while ((ch = showmenu()) != 'q')
	{
		switch (ch)
		{
		case 'd':
			changed = Delete(library, n);
			break;
		case 'a':
			Alter(library, *n);
			changed = true;
			break;
		}
	}

	return changed;
}

char showmenu(void)
{
	char ch;

	puts("Enter d, a or q:");
	puts("d).delete       a).alter");
	puts("q).quit");
	ch = tolower(getchar());
	eatline();
	while (strchr("daq", ch) == NULL)
	{
		puts("Please enter d, a or q:");
		ch = tolower(getchar());
		eatline();
	}

	return ch;
}

bool Delete(struct book library[], int * n)
{
	int index;
	bool changed = false;

	printf("Input number to delete (0-%d):\n", *n - 1);

	if ((scanf_s("%d", &index)) && index >= 0 && index < *n)
	{
		for (int i = index + 1; i < *n; i++)
		{
			library[i - 1] = library[i];
		}
		puts("Delete success.");
		(*n)--;
		changed = true;
	}
	else
	{
		puts("Delete failure.");
	}
	eatline();

	return changed;
}

void Alter(struct book library[], int n)
{
	int index;

	printf("Input number to alter (0-%d):\n", n - 1);
	if ((scanf_s("%d", &index)) && index >= 0 && index < n)
	{
		eatline();
		printf("No.%d: new title:\n", index);
		gets_s(library[index].title, MAXTITL);
		printf("No.%d: new author:\n", index);
		gets_s(library[index].author, MAXAUTL);
		printf("No.%d: new value:\n", index);
		scanf_s("%f", &library[index].value);
		puts("Alter success.");
	}
	else
	{
		puts("Alter failure.");
	}
	eatline();
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		;
	}
}