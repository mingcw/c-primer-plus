#include <stdio.h>
#define PI 3.141592657

int main(void)
{
	int num = 5;
	float expresso = 13.5;
	int cost = 3100;

	printf("The %d CEOs drank %f cups of expresso.\n", num, expresso);
	printf("The value of the PI is %f\n", PI);
	printf("Farewell!Thou art too dear for my possessing:\n");
	printf("%c%d\n", '$', cost * 2);

	getchar();
	return 0;
}