#include <stdio.h>

#define PRAISE "What's a super mavelous name!"

int main(void)
{
	char name[40];

	printf("What's your name?\n");
	scanf_s("%s", name, 40);
	printf("OK,%s.%s", name, PRAISE);

	getchar();
	getchar();
	return 0;
}