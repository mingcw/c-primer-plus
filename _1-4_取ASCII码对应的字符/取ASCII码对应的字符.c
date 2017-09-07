#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;

	system("color E9");
	printf("Enter the ASCII£º");
	while (scanf_s("%d", &ch, sizeof(ch)) == 1)
	{
		printf("The character for %d is %c\n\n", ch, ch);
		printf("Enter next ANCII£º");
	};
	printf("Bye!\n");

	getchar();
	getchar();
	getchar();
	return 0;

}