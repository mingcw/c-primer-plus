#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 21

struct namect
{
	char fname[SIZE];
	char lname[SIZE];
	int letters;
};

//使用结构指针传递结构信息

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);

int main(void)
{
	struct namect person;

	system("color 0A");
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);

	system("pause");
	return 0;
}

void getinfo(struct namect * pst)
{
	printf("Please enter your first name:\n");
	gets_s(pst->fname, SIZE);
	printf("Please enter your last name:\n");
	gets_s(pst->lname, SIZE);
}

void makeinfo(struct namect * pst)
{
	pst->letters = strlen(pst->fname) + 
				   strlen(pst->lname);

}

void showinfo(const struct namect * pst)
{
	printf("%s %s, your name contains %d letters.\n",
		pst->fname, pst->lname, pst->letters);
}