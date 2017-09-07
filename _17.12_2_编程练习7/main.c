/*
	编写程序，能打开、读入一个文本文件并统计文件中每个单词出现的次数。
	用改进的二叉搜索树存储单词及其出现的次数。程序读入文件后，会提供
	一个有三个选项的菜单。
	第一个选项为列出所有的单词连同其出现的次数。
	第二个选项为让您输入一个单词，程序报告该单词在文件中出现的次数。
	第三个选项为退出。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void show(Item item);
void find(Tree * pt);

int main(void)
{
	Tree wTree;
	FILE * fp;
	Item input;
	char choice;
	
	system("color 0A");

	InitializeTree(&wTree);
	//打开文件
	if (fopen_s(&fp, "test.txt", "r"))
	{
		fprintf(stderr, "Failed open file.");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_SET);		//定位到文件首
	while (fscanf_s(fp, "%s", input.word, MAXWORDLENGTH) == 1)
	{
		AddItem(&input, &wTree);
	}
	fclose(fp);

	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 's':
			Traverse(&wTree, show);
			break;
		case 'f':
			find(&wTree);
			break;
		default:
			fprintf(stderr, "Error in switching.\n");
			break;
		}
	}
	puts("Bye!");
	EmptyAll(&wTree);

	system("pause");
	return 0;
}


char menu(void)
{
	char ch;

	puts("Please select a option:");
	puts("s) show the list of words       f) find a word");
	puts("q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
		{
			;
		}
		if (strchr("sfq", ch) == NULL)
		{
			printf("Please enter s, f, or q\n");
		}
		else
		{
			break;
		}
	}
	if (ch == EOF)
	{
		ch = 'q';
	}
	return ch;
}

void show(Item item)
{
	printf("%*s has %d\n", MAXWORDLENGTH, item.word, item.count);
}

void find(Tree * pt)
{
	int count;
	Item temp = {"", 0};

	puts("Please enter the word you want to find:");
	if (scanf_s("%s", temp.word, MAXWORDLENGTH) == 1)
	{
		count = GetItems(&temp, pt);
		printf("%s has %d\n", temp.word, count);
	}
	else
	{
		printf("Error in entering.\n");
	}
}
