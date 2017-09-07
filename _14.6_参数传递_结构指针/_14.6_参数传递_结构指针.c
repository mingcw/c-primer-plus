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

double sum(const struct funds *);			//接受一个指向funds类型结构的指针

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"Lucky's Savings and Loan",
		9237.11
	};

	system("color 0A");
	printf("Stan has a total of $%.2lf\n", sum(&stan));

	getchar();
	return 0;
}

double sum(const struct funds * money)
{
	return (money->bankfund + money->savefund);		//间接成员运算符访问结构指针指向结构的成员

}