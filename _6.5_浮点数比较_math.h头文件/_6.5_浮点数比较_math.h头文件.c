#include <stdio.h>
#include <math.h>

int main(void)
{
	const double ANSWER = 3.14159;
	double responce;

	printf("What is the value of pi?\n");
	scanf_s("%lf", &responce, 6);
	while (fabs(responce - ANSWER) > 0.0001)//即当用户输入值的误差在0.0001内时视为正确
	{
		printf("Try again!\n");
		scanf_s("%lf", &responce, 6);
	}
	printf("Close enough!\n");
	getchar();
	getchar();
	getchar();
	return 0;
}