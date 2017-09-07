#include <stdio.h>

int main(void)
{
	int guess = 1;
	char responce;

	printf("Pick an integer from 1 to 100 .I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with\n");
	printf("a n if it is wrong: \n");
	printf("Uh... Is it %d ?\n", guess);

	while ((responce = getchar()) != 'y')
	{
		if (responce == 'n')
			printf("Well, then. Is it %d?\n", ++guess);
		else
			printf("Sorry, I only understand y or n.\n");
		while ((getchar()) == '\n')
			continue;		//跳过输入行的剩余部分
	}
	printf("Ok, I know I could do it.\n");

	getchar();
	getchar();
	return 0;
}