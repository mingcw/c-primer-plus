#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(double, double);

int main(void)
{
	struct funds stan = {
		"Garlic-Meln Bank",
		3024.72,
		"Lucky's Savings and Loan",
		9237.11
	};

	system("color 4A");
	printf("Stan has a total of $%.2lf.\n",
		sum(stan.bankfund, stan.savefund));		/*结构成员作为参数传递
												  
												  当然，如果希望被调函数影响结构成员的值，可以传递成员地址：modify(&stan.bankfund);*/

	getchar();
	return 0;
}

double sum(double x, double y)
{
	return (x + y);
}