#include <stdio.h>

#define RATE1 0.12589	//第一个360千瓦时的费率
#define RATE2 0.17901	//下一个320千瓦时的费率
#define RATE3 0.20971	//超过680千瓦时的费率
#define BREAK1 360.0	//费率的第一个分界点
#define BREAK2 680.0	//费率的第二个分界点
#define BASE1 (BREAK1 * RATE1)	//用电360千瓦时的总费用
#define BASE2 (BASE1 + (BREAK2 - BREAK1) * RATE2)	//用电680千瓦时的总费用

int main(void)
{
	//else if 结构扩充if else计算用电费用（不同时间段有不同的费率）
	double kwh;
	double bill;

	printf("Please enter the kwh used: ");
	scanf_s("%lf", &kwh);
	if (kwh < BREAK1)
	{
		bill = kwh * RATE1;		//输入值小于费率的第一个分界点时的费用
	}
	else if (kwh < BREAK2)
	{
		bill = BASE1 + (kwh - BREAK1) * RATE2;		//输入值在费率的第一、二个分界点之间时的费用
	}
	else
	{
		bill = BASE2 + (kwh - BREAK2)* RATE3;		//输入值在费率的第三个分界点时的费用
	}
	printf("The charge for %.1f kwh is $%1.2f\n", kwh, bill);

	getchar();
	getchar();
	return 0;
}