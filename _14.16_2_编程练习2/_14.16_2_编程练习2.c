#include <stdio.h>
#include <stdlib.h>

#define SIZE_N 10
#define SIZE_A 4
#define SIZE_M 3
#define SIZE 12

typedef struct _month
{
	char name[SIZE_N];
	char abbrev[SIZE_A];
	int days;
	int monnumb[SIZE_M];
} MONTH;

MONTH months[SIZE] = {
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

int isleapyear(int year);
int get_days(int year, int month, int day);

int main(void)
{
	 
	 int year, month, day, total;

	 system("color 5A");
	 puts("Please enter a date(e.g. 2016 4 24):");
	 while (scanf_s("%d %d %d", &year, &month, &day, 10) == 3)
	 {
		 total = get_days(year, month, day);
		 if (total)
		 {
			 printf("This day is the %d day of %d-year.\n", total, year);
		 }
		 else
		 {
			 printf("Invalid data.\n");
		 }
		 puts("Next data ( e.g. 2016 4 24):");
	 }
	 puts("Bye!");

	 system("pause");
	 return 0;

}

int isleapyear(int year)
{
	if (year % 400 == 0)
	{
		return 1;
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int get_days(int year, int month, int day)
{
	int total = 0;

	if (year <= 0 || month < 1 || month > 12 || day > 31)
	{
		return -1;
	}

	if (isleapyear(year))
	{
		months[1].days = 29;
	}
	for (int i = 0; i < month - 1; i++)
	{
		total += months[i].days;
		if (month == i + 1)
		{
			break;
		}
	}
	total += day;

	return total;
}