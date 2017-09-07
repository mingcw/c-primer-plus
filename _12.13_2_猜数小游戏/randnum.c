//randnum.c

#include <stdlib.h>			//为rand()提供原型

int randnum(int max)
{
	unsigned num;
	 
	num = rand() % max;

	return num;
}