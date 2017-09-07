#include <stdio.h>

int main(void)
{
	//造前20个整数的平方表，造孽呀
	int number = 1;

	while (number <= 20)
	{
		printf("%4d %6d \n", number, number*number);
		number = number + 1;
	}
	getchar();
	return 0;
}