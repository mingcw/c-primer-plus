//栈的接口实现函数

#include <stdbool.h>
#include <string.h>
#include "stack.h"


//接口函数定义

void InitializeStack(Stack * ps)
{
	memset(ps->items, 0, MAXSTACK * sizeof(Item));
	ps->top = 0;
}


bool StackIsEmpty(Stack * ps)
{
	return ps->top == 0 ? true : false;
}



bool StackIsFull(Stack * ps)
{
	return ps->top == MAXSTACK - 1 ? true : false;
}


bool Push(const Item * pi, Stack * ps)
{
	if (StackIsFull(ps))
	{
		return false;
	}

	ps->items[ps->top] = *pi;
	ps->top++;
	return true;
}


bool Pop(Item * pi, Stack * ps)
{
	if (StackIsEmpty(ps))
	{
		return false;
	}

	*pi = ps->items[ps->top - 1];
	memset(&ps->items[ps->top - 1], 0, sizeof(Item));
	ps->top--;
	if (ps->top == 0)
	{
		InitializeStack(ps);
	}
	return true;
}



void PopAll(Item pi[], Stack * ps, int MaxItems)
{
	int i = 0;

	while (i < MaxItems && !StackIsEmpty(ps))
	{
		Pop(&pi[i], ps);
		i++;
	}
}