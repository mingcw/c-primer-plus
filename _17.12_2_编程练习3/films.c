//films.c -- 使用ADT风格的链表

#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void showmovies(Item item);

int main(void)
{
	List movies;
	Item tmp;
	int itemcount;

	system("color 5A");

	//初始化
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memory avaliale!Bye!\n");
		exit(EXIT_FAILURE);
	}

	//收集信息
	puts("Enter first movie title:");
	while (gets(tmp.title) != NULL && tmp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");	
		assert((scanf("%d", &tmp.rating)) == 1);

		while (getchar() != '\n')
			continue;
		tmp.rating = tmp.rating > 10 ? 10 : tmp.rating;
		if (AddItem(tmp, &movies) == false)
		{
			fprintf(stderr, "Problem allocating memory.\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title (empty to stop):");
	}

	//显示
	if (ListIsEmpty(&movies))
	{
		puts("No data entered.");
	}
	else
	{
		puts("Here is the list of movies:");
		Traverse(&movies, showmovies);
	}
	itemcount = ListItemCount(&movies);
	printf("You entered %d %s.\n", itemcount, 
		itemcount == 1 ? "movie" : "movies");

	//清除
	EmptyTheList(&movies);
	puts("Bye!");

	system("pause");
	return 0;
}

void showmovies(Item item)
{
	printf("Movie: %s Rating: %d.\n", 
		item.title, item.rating);
}