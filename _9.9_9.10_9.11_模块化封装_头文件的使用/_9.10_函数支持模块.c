
//旅馆管理函数

#include <stdio.h>
#include <stdlib.h>
#include "_9.11_hotel.h"		//提供旅馆管理函数的常量定义和函数声明

int menu(void)		
{
	int code, status;

	system("color 4E");

	printf("\n%s%s\n", STARS, STARS);
	printf("Enter the number of the desired hotel: \n");
	printf("1).Fairfield Arms      2).Hotel Olympic\n");
	printf("3).Chertworthy Plaza   4).The Stockton\n");
	printf("5).quit\n");
	printf("%s%s\n", STARS, STARS);
	while (((status = scanf_s("%d", &code))!= 1) || (code < 1 || code > 5))		//扫描数字失败或者，数字超出1到5
	{
		if (status != 1)		//如果扫描数字失败
		{
			scanf_s("%*s");		//跳到下一个空白字符（从第一个非空字符开始，到下一个空白字符为止，所有字符全部读取并丢弃）
		}
		printf("Enter an integer from 1 to 5, please.\n");
	}
	
	return code;	//返回房间号
}

int getnights(void)
{
	int nights;

	printf("How many nights are needed: ");
	while (scanf_s("%d", &nights) != 1)
	{
		scanf_s("%*s");
		printf("Please enter an integer , such as 2.\n");
	}

	return nights;		//返回天数
}

void showprice(double rate, int nights)
{
	double total = 0.0;			//编译器视浮点常量为double类型
	double factor = 1.0;

	for (int n = 1; n <= nights; n++, factor *= DISCOUNT)
	{
		total += rate * factor;
	}
	printf("The total cost will be $%.2f\n", total);

}