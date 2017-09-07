#include <stdio.h>

void display(char ch, int lines, int cols);

int main(void)
{
	int ch;
	int lines, cols;

	printf("Enter an character and two integers: \n");
	while ((ch = getchar()) != '\n')
	{
		if (scanf_s("%d %d", &lines, &cols) != 2)
		{
			break;
		}
		display(ch, lines, cols);
		while (getchar() != '\n')
		{
			continue;
		}
		printf("Enter another character and two integers\n");
		printf("Enter a new line to quit: \n");
	}
	printf("Bye!\n");

	getchar();
	return 0;
}

void display(char ch, int lines, int cols)
{
	for (int i = 1; i <= lines; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			putchar(ch);
		}
		printf("\n");
	}
}