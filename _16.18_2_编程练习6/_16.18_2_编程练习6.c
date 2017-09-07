/*
	修改程序清单16.15，使其使用由struct names组成的数组，而不是使用double数组。使用较少元素并显示初始化数组为由合适名字组成的数组。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
#define NAMESIZE 41

struct names
{
	char first[NAMESIZE];
	char last[NAMESIZE];
};

typedef struct names NAME;

void showarray(NAME [], int);
int comp(const void *, const void *);

int main(void)
{
	NAME  stuff[MAXSIZE] = {
		{ "KOBE", "BRYAN" },
		{ "Tracy", "McGrady" },
		{ "Cristiano", "Ronaldo" },
		{ "Barack", "Obama" },
		{ "Justin", "Eric" },
		{ "Andre", "Drummond" },
		{ "DeMarcus", "Cousins" },
		{ "Monty", "Williams" },
		{ "Nate", "McMillan" },
		{ "Kevin", "Durant" }
	};

	system("color 5A");
	puts("Original list:");
	showarray(stuff, MAXSIZE);
	qsort(stuff, MAXSIZE, sizeof(NAME), comp);
	puts("\nSorted list:");
	showarray(stuff, MAXSIZE);
	system("pause");
	return 0;
}

void showarray(NAME ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("               %s %s\n", ar[i].first, ar[i].last);
	}
}

//按照ASICII顺序表进行排序
int comp(const void * p1, const void * p2)
{
	const NAME * a1 = (const NAME *)p1;
	const NAME * a2 = (const NAME *)p2;
	int res;

	res = strcmp(a1->last, a2->last);			/*比较姓*/
	if (res)
	{
		return res;
	}
	else
	{
		return strcmp(a1->first, a2->first);	/*姓相同时，比较名*/
	}
}