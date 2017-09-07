//测试Queue类型ADT的驱动程序

#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main(void)
{
	Queue line;
	Item temp;
	char ch;

	system("color 5A");
	
	InitializeQueue(&line);
	puts("Testing the Queue interface. Type a to add a value");
	puts("Type d to delete a value, and type q to quit:");
	while ((ch = getchar()) != 'q')
	{
		if (ch != 'a' && ch != 'd')
		{
			continue;
		}
		if (ch == 'a')
		{
			printf("Integer to add: ");
			assert(scanf("%d", &temp) == 1);
			if (!QueueIsFull(&line))
			{
				printf("Putting %d into queue.\n", temp);
				EnQueue(temp, &line);
			}
			else
			{
				puts("Queue is full.");
			}
		}
		else
		{
			if (QueueIsEmpty(&line))
			{
				puts("Nothing to delete!");
			}
			else
			{
				DeQueue(&temp, &line);
				printf("Removing %d from queue.\n", temp);
			}
		}
		printf("%d items in queue.\n", QueueItemCount(&line));
		puts("Type a to add, d to delete, or q to quit:");
	}
	EmptyTheQueue(&line);
	puts("Bye!");

	system("pause");
	return 0;
}