#include <stdio.h>
#include <stdlib.h>


typedef double(*fp)(double, double);		//定义函数指针新标记

double fun1(double, double);
double fun2(double, double);
double fun3(double, double);
double fun4(double, double);

int main(void)
{
	fp pfun[4] = { fun1, fun2, fun3, fun4 };
	double(*fp[4])(double, double) = { fun1, fun2, fun3, fun4 };

	system("color 5A");
	for (int i = 0; i < 4; i++)
	{
		pfun[i](i + 1, i + 1);					//语法1
		(*pfun[i])(i + 1, i + 1);				//语法2
		fp[i](i + 1, i + 1);
		(*fp[i])(i + 1, i + 1);
		putchar('\n');

	}
	getchar();
	return 0;
}

double fun1(double n, double m)
{
	printf("%*sfun1: %.2lf, %.2lf\n", 30, " ", n, m);
	return 1.0;
}

double fun2(double n, double m)
{
	printf("%*sfun2: %.2lf, %.2lf\n", 30, " ", n, m);
	return 1.0;
}

double fun3(double n, double m)
{
	printf("%*sfun3: %.2lf, %.2lf\n", 30, " ", n, m);
	return 1.0;
}

double fun4(double n, double m)
{
	printf("%*sfun4: %.2lf, %.2lf\n", 30, " ",n, m);
	return 1.0;
}