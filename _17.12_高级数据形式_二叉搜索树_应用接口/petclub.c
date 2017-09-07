//petclub.c -- 主文件，使用二叉搜索树的应用程序

/*
	程序描述：该程序是维护Nerfville宠物俱乐部的花名册。每一个项目由宠物的名字和种类组成。
	程序功能：该程序使用菜单来选择向俱乐部成员花名册添加宠物、显示成员列表、报告成员数、检查成员及退出。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include "tree.h"


//函数原型
char menu(void);
void addpet(Tree * ptree);
void showpets(const Tree * ptree);
void findpet(const Tree * ptree);
void droppet(Tree * ptree);
void printitem(Item item);
void uppercase(char * str);


int main(void)
{
	Tree pets;
	char choice;

	system("color 5A");
	InitializeTree(&pets);					//初始化
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 'a':
			addpet(&pets);
			break;
		case 'l':
			showpets(&pets);
			break;
		case 'f':
			findpet(&pets);
			break;
		case 'n':
			printf("%d pets in club.\n", TreeItemCount(&pets));
			break;
		case 'd':
			droppet(&pets);
			break;
		default:
			puts("Switching error.");
			break;
		}
	}
	EmptyAll(&pets);
	puts("Bye!");

	system("pause");
	return 0;
}


char menu(void)
{
	char ch;

	puts("NerFville Pet Club Membership Program");
	puts("Enter the letter corresponding to your choice: ");
	puts("a) add a pet            l) show list of pets");
	puts("n) number of pets       f) find pets");
	puts("d) delete a pet         q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
		{
			continue;
		}
		ch = tolower(ch);
		if (strchr("alnfdq", ch) == NULL)
		{
			puts("Please enter an a, l, f, n, d, or q:");
		}
		else
		{
			break;
		}
	}
	if (ch == EOF)
	{
		ch = 'q';				//令EOF导致程序退出
	}
	return ch;
}


void addpet(Tree * ptree)
{
	Item temp;

	if (TreeIsFull(ptree))
	{
		puts("No room in the club!");
	}
	else
	{
		puts("Please enter name of pet:");
		gets_s(temp.petname, 20);
		puts("Please enter pet kind:");
		gets_s(temp.petkind, 20);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddItem(&temp, ptree);
	}
}


void showpets(const Tree *ptree)
{
	if (TreeIsEmpty(ptree))
	{
		puts("No entries!");
	}
	else
	{
		Traverse(ptree, printitem);
	}
}


void findpet(const Tree * ptree)
{
	Item temp;

	if (TreeIsEmpty(ptree))
	{
		puts("No entries!");
		return;
	}
	
	puts("Please enter name of you wish to find:");
	gets_s(temp.petname, 20);
	puts("Please enter pet kind:");
	gets_s(temp.petkind, 20);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ", temp.petname, temp.petkind);
	if (InTree(&temp, ptree))
	{
		printf("is a member.\n");
	}
	else
	{
		printf("is not a member.\n");
	}
}


void droppet(Tree * ptree)
{
	Item temp;

	if (TreeIsEmpty(ptree))
	{
		puts("No entries.");
		return;
	}

	puts("Please enter name of pet you wish to delete:");
	gets_s(temp.petname, 20);
	puts("Please enter pet kind:");
	gets_s(temp.petkind, 20);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ", temp.petname, temp.petkind);
	if (DeleteItem(&temp, ptree))
	{
		printf("is dropped from the club.\n");
	}
	else
	{
		printf("is not a member.\n");
	}
}


void printitem(Item item)
{
	printf("Pet: %-19s Kind: %19s\n", item.petname, item.petkind);
}


void uppercase(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
