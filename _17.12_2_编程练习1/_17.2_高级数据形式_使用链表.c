
/*
	修改程序达到双向遍历*/

//方法1：修改链表结构定义，加入一个成员：previous指针指向前一个film结构
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45	/*存放片名的数组大小*/

struct film
{
	struct film * previous;		//指向前一个film的指针
	char title[TSIZE];
	int rating;
	struct film * next;
};

void reverseTraversal(struct film * rear);

int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];

	//收集并存储信息
	system("color 0A");
	puts("Enter first movie title:");
	while (gets(input) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (head == NULL)
		{
			head = current;
			current->previous = NULL;
		}
		else
		{
			prev->next = current;
			current->previous = prev;
		}
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
		{
			;
		}
		current->rating &= 0xF;
		puts("Enter nwxt movie title (empty to stop):");
		prev = current;
	}

	//给出电影列表
	if (head == NULL)
	{
		printf("No data entered.");
	}
	else
	{		
		//逆向遍历
		puts("Here is the list of movies:");
		reverseTraversal(prev);

		//正向遍历
		/*current = head;
		while (current != NULL)
		{
			printf("Movie: %s Rating: %d\n", current->title, current->rating);
			current = current->next;
		}*/
	}
	
	//任务已完成，因此释放所分配的内存
	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
	puts("Bye!");

	system("pause");
	return 0;
}

void reverseTraversal(struct film * rear)
{
	struct film * current;

	current = rear;
	while (current != NULL)
	{
		printf("Movies: %s Rating: %d\n", current->title, current->rating);
		current = current->previous;
	}
}