//list.c -- 支持列表操作的函数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*局部函数原型*/
static void CopyToList(Item item, List * plist);


//接口函数

/*把列表设置为空列表*/
void InitializeList(List * plist)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		plist->entries[i] = (Item){ "", 0 };
	}
	plist->items = 0;
}

/*如果列表为空则返回真，否则返回假*/
bool ListIsEmpty(const List * plist)
{
	return plist->items == 0 ? true : false;
}

/*如果列表已满则返回真，否则返回假*/
bool ListIsFull(const List * plist)
{
	return plist->items == MAXSIZE ? true : false;
}

/*返回节点数*/
unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

/*创建存放项目的节点，并把它添加到
plist指向的列表的尾部*/
bool AddItem(Item item, List * plist)
{
	if (plist->items == MAXSIZE)
	{
		return false;
	}

	CopyToList(item, plist);
	plist->items++;
	return true;
}

/*访问每个节点并对它们分别执行pfun指向的函数*/
void Traverse(const List * plist, void(*pfun)(Item item))
{
	for (int i = 0; i < plist->items; i++)
	{
		(*pfun)(plist->entries[i]);
	}
}


/*释放由malloc()分配的内存
把列表指针设置为NULL*/
void EmptyTheList(List * plist)
{
	InitializeList(plist);
}


//局部函数定义

//把一个项目复制到列表中
static void CopyToList(Item item, List * plist)
{
	plist->entries[plist->items] = item;
}