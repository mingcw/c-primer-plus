/*
	编写一个程序，按要求创建结构模板：
	a.第一个成员是社会保障号；第二个成员是一个含3个成员的结构。
	  它的第一个成员是名，第二个成员是名和姓之间的字，最后一个
	  成员是姓。创建并初始化一个含有5个此类结构的数组，程序以
	  下列形式输出数据：
	  Dribble, Flossie M. - 302039823
	  名和姓之间的字只输出了它的第一个字母，后面加了一个句点。
	  如果姓名中间的名字为空，那么他的第一个字母和句点都不会输出。
	  写一个函数实现输出，把结构数组传递给这个函数。
	  */

#include <stdio.h>
#include <stdlib.h>

#define SIZENAME 20
#define SIZE 5

struct _name
{
	char fname[SIZENAME];			//名
	char mname[SIZENAME];			//字
	char lname[SIZENAME];			//姓
};

struct person
{
	int indemnumb;					//社会保障号
	struct _name name;
};

void showinfo(struct person persons[], int n);

int main(void)
{
	struct person persons[SIZE] = {
		{ 302039823, { "Dribble", "Mond", "Flossie" } }, 
		{ 302134234, { "Mkdjie", "", "Ldsinw" } },
		{ 323424121, { "Lijei", "Lin", "Ijdsoiafsdj" } },
		{ 356745023, { "Jone", "", "Edsjfoisdj" } },
		{ 359900212, { "Long", "Adfs", "Ddjsoafisd" } }
	};

	system("color 5A");
	showinfo(persons, SIZE);
	getchar();
	return 0;

}

void showinfo(struct person persons[], int n)
{

	for (int i = 0; i < n; i++)
	{
		printf("%s, %s ", persons[i].name.fname, persons[i].name.lname);
		if (persons[i].name.mname[0] != '\0')
		{
			printf("%c. ", persons[i].name.mname[0]);
		}
		printf("- %d\n", persons[i].indemnumb);
	}
}