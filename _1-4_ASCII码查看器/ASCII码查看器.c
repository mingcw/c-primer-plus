#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ch;

	system("color 2E");
	printf("Please enter a character\nCtrl+Z to quit: ");
	while ((ch = getchar()) != EOF) 
	{
		printf("The ASCII for %c is %d <%#x, %#o>.\n\n", ch, ch, ch, ch);
		printf("Please enter next character\nCtrl+Z to quit: ");
		if (ch != '\n')
		while (getchar() != '\n')
			continue;
	}	
	printf("Bye!\n");

	getchar();
	return 0;
}