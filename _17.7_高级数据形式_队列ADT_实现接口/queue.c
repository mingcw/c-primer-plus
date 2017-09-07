//queue.c -- 队列类型的实现文件

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/*局部函数*/
static void CopyToNode(Item item, Node * pnode);
static void CopyToItem(Node * pnode, Item * pitem);

void InitializeQueue(Queue * pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsEmpty(const Queue * pq)
{
	return pq->items == 0;
}

bool QueueIsFull(const Queue * pq)
{
	return pq->items == MAXQUEUE;
}

int QueueItemCount(const Queue * pq)
{
	return pq->items;
}

bool EnQueue(Item item, Queue * pq)
{
	Node * pnew;

	if (QueueIsFull(pq))
	{
		return false;
	}

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (QueueIsEmpty(pq))
	{
		pq->front = pnew;			//项目位于队列首端
	}
	else
	{
		pq->rear->next = pnew;		//项目链接到队列尾端
	}
	pq->rear = pnew;				//尾指针指向尾节点
	pq->items++;					//项目数 + 1

	return true;
}

bool DeQueue(Item * pitem, Queue * pq)
{
	Node * pt;

	if (QueueIsEmpty(pq))
	{
		return false;
	}

	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (pq->items == 0)
	{
		pq->rear = NULL;
	}
	
	return true;
}

void EmptyTheQueue(Queue * pq)
{
	Item item;

	while (!QueueIsEmpty(pq))
	{
		DeQueue(&item, pq);
	}
}

//局部函数定义
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}

static void CopyToItem(Node * pnode, Item * pitem)
{
	*pitem = pnode->item;
}