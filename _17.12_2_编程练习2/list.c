//list.c -- 支持列表操作的函数

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*局部函数原型*/
static void CopyToNode(Item item, Node * pnode);

//接口函数

/*把列表设置为空列表*/
void InitializeList(List * plist)
{
	plist->head = plist->end = NULL;
}

/*如果列表为空则返回真，否则返回假*/
bool ListIsEmpty(const List * plist)
{
	if (plist->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*如果列表已满则返回真，否则返回假*/
bool ListIsFull(const List * plist)
{
	Node * pnode = (Node *)malloc(sizeof(Node));
	if (pnode == NULL)
	{
		return true;
	}
	else
	{
		free(pnode);
		return false;
	}
}

/*返回节点数*/
unsigned int ListItemCount(const List * plist)
{
	Node * pnode = plist->head;
	unsigned int count = 0;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

/*创建存放项目的节点，并把它添加到
plist指向的列表的尾部（较慢的方法）*/
bool AddItem(Item item, List * plist)
{
	Node * pnode = (Node *)malloc(sizeof(Node));
	//Node * scan = plist->head;

	if (pnode == NULL)
	{
		return false;
	}

	CopyToNode(item, pnode);
	pnode->next = NULL;
	if (plist->head == NULL)
	{
		plist->head= pnode;
	}
	else
	{
		plist->end->next = pnode;
	}
	plist->end = pnode;

	/*if (scan == NULL)
	{
		plist->head = pnode;
	}
	else
	{
		while (scan->next != NULL)
		{
			scan = scan->next;
		}
		scan->next = pnode;
	}*/

	return true;
}

/*访问每个节点并对它们分别执行pfun指向的函数*/
void Traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pnode = plist->head;

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}


/*释放由malloc()分配的内存
把列表指针设置为NULL*/
void EmptyTheList(List * plist)
{
	Node * tmp;

	while (plist->head != NULL)
	{
		tmp = plist->head->next;
		free(plist->head);
		plist->head = tmp;
	}
}


//局部函数定义

//把一个项目复制到一个节点中
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}