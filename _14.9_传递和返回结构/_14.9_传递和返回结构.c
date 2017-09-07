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

//使用结构作为参数和返回值传递结构信息

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);

int main(void)
{
	struct namect person;

	system("color 0A");
	person = getinfo();
	person = makeinfo(person);
	showinfo(person);

	system("pause");
	return 0;
}

struct namect getinfo(void)
{
	struct namect info;

	printf("Please enter your first name:\n");
	gets_s(info.fname, SIZE);
	printf("Please enter your last name:\n");
	gets_s(info.lname, SIZE);

	return info;
}

struct namect makeinfo(struct namect info)
{
	info.letters = strlen(info.fname) + 
				   strlen(info.lname);
	return info;
}

void showinfo(struct namect info)
{
	printf("%s %s, your name contains %d letters.\n",
		info.fname, info.lname, info.letters);
}