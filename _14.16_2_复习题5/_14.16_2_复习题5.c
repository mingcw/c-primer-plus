/*
	设计一个结构模板，保存一个月份名、一个3个字母的该月份的缩写、该月份的天数，以及月份号
	创建结构数组，初始化一个年份（非闰年）
	编写一个函数，用户输入一个月份号，程序返回一年中到该月为止（包括该月）总共的天数。结构数组设置为外部变量
*/
#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 10
#define REDUCESIZE 4
#define MONTHSIZE 12

struct month
{
	char name[NAMESIZE];				//月份明
	char abbrev[REDUCESIZE];			//月份缩写
	int days;							//天数
	int monnumb;						//月份号
};
typedef struct month MONTH;

MONTH year[MONTHSIZE] = {				//结构数组，静态、外链接
	{ "January", "Jan", 31, 1 },
	{ "February", "Feb", 28, 2 },
	{ "March", "Mar", 31, 3 },
	{ "April", "Apr", 30, 4 },
	{ "May", "May", 31, 5 },
	{ "June", "Jun", 30, 6 },
	{ "July", "Jul", 31, 7 },
	{ "August", "Aug", 31, 8 },
	{ "September", "Sep", 30, 9 },
	{ "October", "Oct", 31, 10 },
	{ "November", "Nov", 30, 11 },
	{ "December", "Dec", 31, 12 }
};

int days(int month);

int main(void)
{
	int mon;
	int total;

	system("COLOR 5A");
	puts("Enter a month-number (q to quit):");
	while (scanf_s("%d", &mon, 10) == 1)
	{
		total = days(mon);
		if (total > 0)
		{
			printf("The total days is %d from the start of a year to the %d month.\n", total, mon);
		}
		else
		{
			printf("Please enter a month-number from 1 to 12.\n");
		}
	}
	printf("Bye!\n");

	system("pause");
	return 0;
}

int days(int month)
{
	int total = 0;

	if (month < 1 && month > 12)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < month; i++)
		{
			total += year[i].days;
		}
		return total;
	}
}