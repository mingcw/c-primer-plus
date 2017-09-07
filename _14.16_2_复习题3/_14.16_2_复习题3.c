
/*
设计一个结构模板，保存一个月份名、一个3个字母的该月份的缩写、该月份的天数，以及月份号*/
#include <stdio.h>

#define NAMESIZE 10
#define REDUCESIZE 4
#define MONTHS 12

struct month
{
	char name[NAMESIZE];				//月份名
	char abbrev[REDUCESIZE];			//月份缩写
	int days;							//天数
	int monnumb;						//月份号
};

typedef struct month MONTH;

int main(void)
{
	MONTH year[MONTHS] = { [5] = { .name = "June", .abbrev = "Jun", .days = 30, .monnumb = 6 } };

	printf("%s has a total of %d days.\n", year[5].name, year[5].days);
	printf("%s is the %dth month of a year.\n", year[5].abbrev, year[5].monnumb);

	getchar();
	return 0;
}