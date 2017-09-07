
//针对若干年的降水量数据，计算年降水总量、年降水均量，以及月降水均量

#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
#define YEARS 5

int main(void)
{
	system("color 0A");

	//用二维数组初始化2000-2004年的降水量数据

	const float rain[YEARS][MONTHS] = {
		{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },		//第0个成员
		{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },		//第1个成员
		{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },		//第2个成员
		{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },		//第3个成员
		{ 7.6, 5.5, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.0, 5.2 }		//第4个成员，所以，该数组是包含5个由12个浮点数组成数组的数组（或，5个成员的，每个成员是12个浮点数的数组；或，5行12列的二维数组）
	};
	int year, month;
	float subtot, total;

	printf(" YEAR   RAINFALL (inches)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{		 		//对于每一年，各月的总降水量subtot
		for (month = 0, subtot =0 ; month < MONTHS; month++)
		{		
			subtot += rain[year][month];
		}
		printf("%5d%15.1f\n", 2000 + year, subtot);		//2000 - 2004 年
		total += subtot;		//所有年度的总降水量
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("MONTHLY AVERAGES: \n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

	for (month = 0; month < MONTHS; month++)
	{				//对于每个月，各年该月份的总降水量subtot
		for (year = 0, subtot = 0; year < YEARS; year++)
		{
			subtot += rain[year][month];
		}
		printf("%4.1f", subtot / YEARS);
	}
	printf("\n");

	getchar();
	return 0;
}