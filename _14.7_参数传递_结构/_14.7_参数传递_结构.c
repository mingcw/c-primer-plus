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

double sum(struct funds moolah);		//参数是一个结构

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"Lucky's Savings and Loan",
		9237
	};

	system("color 0A");
	printf("Stan has a total of $%.2f\n", sum(stan));		//调用sum()时，会根据funds模板创建一个自动变量moolah，然后这个moolah结构的成员被初始化为stan结构的相应成员取值的副本

	getchar();
	return 0;

}

double sum(struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);

}