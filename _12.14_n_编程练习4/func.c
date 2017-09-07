
//func.c
#include <stdio.h>

int func(void)
{
	static int called_count = 0;

	printf("T'm a simple computer\n");

	return  ++called_count;
}