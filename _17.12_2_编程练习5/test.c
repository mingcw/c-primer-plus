#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

int main(void)
{
	Stack str;
	Item temp[MAXSTACK];
	int i = 0;

	InitializeStack(&str);
	puts("Plesse input a string (empty to quit):");
	while (gets_s(temp, MAXSTACK) != NULL && temp[0] != '\0')
	{
		while (temp[i])
		{
			Push(&temp[i], &str);
			i++;
		}
		PopAll(temp, &str, MAXSTACK);
		printf("Here is the reversal string you entered:\n%s\n", temp);
		puts("Plesse input a string (empty to quit):");
	}
	puts("Bye!");

	system("pause");
	return 0;
}