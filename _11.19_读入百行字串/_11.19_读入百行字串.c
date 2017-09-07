#include <stdio.h>
#include <string.h>

#define SIZE 81
#define LINES 100
#define STOP "quit"

int main(void)
{
	char input[LINES][SIZE];
	int ct = 0;

	printf("Enter up to %d lines (enter \"quit\" to quit): \n", LINES);
	while (ct < LINES && 
		gets_s(input[ct], SIZE) != NULL && 
		strcmp(input[ct], STOP) != 0)		//循环读入LINES行字符串，遇到EOF或输入“quit”均会退出循环
	{
		ct++;
	}
	printf("%d strings entered.\n", ct);

	getchar();
	return 0;
}