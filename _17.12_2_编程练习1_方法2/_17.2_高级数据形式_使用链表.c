//递归实现逆序遍历显示

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45	/*存放片名的数组大小*/

struct film
{
	char title[TSIZE];
	int rating;
	struct film * next;
};

void reverseTraversal(struct film * head);

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
		}
		else
		{
			prev->next = current;
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
		//逆序遍历
		puts("Here is the list of movies:");
		reverseTraversal(head);

		//正向遍历
		/*current = head;
		while (current != NULL)
		{
			printf("Movie: %s Rating: %d.\n", current->title, current->rating);
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

//递归实现逆序遍历
void reverseTraversal(struct film * head)
{
	if (head != NULL)
	{
		reverseTraversal(head->next);
		printf("Movie: %s Rating: %d.\n", head->title, head->rating);
	}
}