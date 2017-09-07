
/*P242*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define MIN 1
#define QUIT 4

void show_menu(void);
int get_choice(int min, int max);

int main(void)
{
	int choice;

	show_menu();
	choice = get_choice(MIN, MAX);
	while (choice != QUIT)
	{
		switch (choice)
		{
		case 1:printf("You select 1\n");
			break;
		case 2:printf("You select 2\n");
			break;
		case 3:printf("You select 3\n");
			break;
		default:printf("Program error!\n");
			break;
		}
		show_menu();
		choice = get_choice(MIN, MAX);
	}
	printf("Bye!\n");

	getchar();
	getchar();
	return 0;

}

//显示菜单列表
void show_menu(void)
{
	int choice;

	printf("Please choose one of the following:\n"
		"1).copy files       2).move files\n"
		"3).remove files     4).quit\n"
		"Enter the number of yur choice: \n");
}

//读取用户输入
int get_choice(int min, int max)
{
	int choice;
	 
	while (scanf_s("%d",&choice)!= 1 || (choice < min || choice > max))
	{
		show_menu();
	while (getchar() != '\n')
		continue;
	}

	return choice;
}

