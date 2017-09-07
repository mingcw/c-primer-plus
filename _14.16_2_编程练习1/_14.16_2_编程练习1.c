/*
	改写复习题3，用月份名的拼写代替月份号*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NAMESIZE 10
#define ABBRESIZE 4
#define MONTHS 12
#define LEN 40

typedef struct month
{
	char name[NAMESIZE];				//月份明
	char abbrev[ABBRESIZE];				//缩写
	int days;							//天数
	int monnumb;						//月份号
} MONTH;

MONTH months[MONTHS] = {
	{ "january", "jan", 31, 1 },
	{ "february", "feb", 28, 2 },
	{ "march", "mar", 31, 3 },
	{ "april", "apr", 30, 4 },
	{ "may", "may", 31, 5 },
	{ "june", "jun", 30, 6 },
	{ "july", "jul", 31, 7 },
	{ "august", "aug", 31, 8 },
	{ "september", "sep", 30, 9 },
	{ "october", "oct", 31, 10 },
	{ "november", "nov", 30, 11 },
	{ "december", "dec", 31, 12 }
};

int get_days(char * str);

int main(void)
{
	
	char input[LEN];
	int days;

	system("color 5A");
	puts("Please input a month-name (empty to quit):");
	while (gets_s(input, LEN) != NULL && input[0] != '\0')
	{
		days = get_days(input);
		if (days > 0)
		{
			printf("The toatal days are %d from the start of a year to %s.\n", days, input);
		}
		else
		{
			printf("No valid data.\n");
		}
		puts("Enter next month-name:");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

int get_days(char * str)
{
	int i = 0, days = 0;

	while (str[i])
	{
		str[i] = tolower(str[i]);
		i++;
	}

	for (i = 0; i < MONTHS; i++)
	{
		days += months[i].days;
		if (strcmp(str, months[i].name) == 0
			|| strcmp(str, months[i].abbrev) == 0)
		{
			return days;
		}
	}

	return -1;
}
