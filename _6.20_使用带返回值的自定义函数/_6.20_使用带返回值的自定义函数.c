#include <stdio.h>

double power(double n, int p);		//ANSI原型，声明函数原型

int main(void)
{
	double x, xpow;
	int exp;

	printf("\nPlease enter a number and the positive integer power ");
	printf("to which\nthe the number will be raised.Enter q ");
	printf("to quit.\n");

	while (scanf_s("%lf %d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoy the power trip -- bye!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}

/*计算任意数的整数次幂
 n 底数；p 指数*/
double power(double n, int p)		
{
	double power = 1.0;

	for (int i = 1; i <= p; i++)
	{
		power *= n;
	}
	return power;
}