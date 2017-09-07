#include <stdio.h>
#include <string.h>

struct fullname
{
	char fname[20];
	char lname[20];
};

struct bard
{
	struct fullname name;
	int born;
	int died;
};
struct bard willie;					//静态、外链接的结构变量
struct bard * pt = &willie;			//结构指针

int main(void)
{
	//a.
	willie.born;
	//b.
	pt->born;
	//c.
	scanf_s("%d", &willie.born, 10);
	//d.
	scanf_s("%d", &pt->born, 10);
	//e.
	scanf_s("%s", willie.name.lname, 20);
	//f.
	scanf_s("%s", pt->name.lname, 20);
	//g.
	willie.name.fname[2];
	//h.
	size_t len = strlen(willie.name.fname) + strlen(willie.name.lname);

}