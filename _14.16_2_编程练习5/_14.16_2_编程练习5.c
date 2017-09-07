/*
	要求：
	a.外部定义一个name结构模板，它含有2个成员：一个字符串用于存放名字，另一个字符串用户存放姓氏。
	b.外部定义一个student结构模板，它含有3个成员：一个name结构，一个存放3个浮点数分数的grade数组，
	  以及一个存放着3个分数的平均分的变量。
	c.使main()函数声明一个具有CSIZE（CSIZE=4）个student结构的数组，并随意初始化这些结构的名字部分。
	  使用函数来执行d、e、f、g所描述的任务。
	d.请求用户输入学生姓名和分数，以交互地获取每个学生的成绩。将分数放到相应结构的grade数组成员中。
	  您可以自主选择在main()或一个函数中实现这个循环。
	e.为每个结构计算平均分，并把这个值赋给适合的成员。
	f.输出每个结构的信息。
	g.输出结构的每个数值成员的班级平均分。
	*/

#include <stdio.h>
#include <stdlib.h>

#define SIZENAME 21
#define SIZEGRAD 3
#define CSIZE 4

struct name
{
	char fname[SIZENAME];
	char lname[SIZENAME];
};

struct student
{
	struct name sname;
	float grade[SIZEGRAD];
	float average;
};

int getinfo(struct student students[], int n);
void eatline(void);
void makeinfo(struct student students[], int n);
void showinfo(const struct student students[], int n);

int main(void)
{
	struct student students[CSIZE] = {
		{ { "Bird", "Cing" } },
		{ { "Fish", "Down" } },
		{ { "Turtle", "Elfeo" } },
		{ { "Sea", "Flow" } },
	};
	int count;									//记录数

	system("color 5A");

	count = getinfo(students, CSIZE);
	if (count > 0)
	{
		makeinfo(students, count);
		showinfo(students, count);
	}
	else
	{
		printf("No students? Good!");
	}

	system("pause");
	return 0;
}

int getinfo(struct student students[], int n)
{
	int count = 0;

	printf("Input  a name of the first student %s\n", students[count].sname.fname);
	printf("Press [enter] at the start of a line to quit:\n");

	while (count < n
		&& gets_s(students[count].sname.fname, SIZENAME) != NULL
		&& students[count].sname.fname[0] != '\0')
	{
		printf("Enter the Chinese-grade of %s:\n", students[count].sname.fname);
		if (scanf_s("%f", &students[count].grade[0]) != 1)
		{
			exit(EXIT_FAILURE);
		}
		printf("Math-grade:\n");
		if (scanf_s("%f", &students[count].grade[1]) != 1)
		{
			exit(EXIT_FAILURE);
		}
		printf("English-grade:\n");
		if (scanf_s("%f", &students[count].grade[2]) != 1)
		{
			exit(EXIT_FAILURE);
		}
		eatline();										//清空输入行（尤其换行符）
		puts("Next name of student (empty line to quit):");
		count++;
	}

	return count;
}

void makeinfo(struct student students[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < SIZEGRAD; j++)
		{
			students[i].average += students[i].grade[j];
		}
		students[i].average /= SIZEGRAD;
	}
}

void showinfo(const struct student students[], int n)
{
	float totaverage = 0;

	printf("Here is the list grade:\n");
	printf("%10s%10s%10s%10s%10s\n", "Student", "Chinese", "Math", "English", "Average");
	for (int i = 0; i < n; i++)
	{
		printf("%10s%10.1f%10.1f%10.1f%10.1f\n", students[i].sname.fname,
			students[i].grade[0], students[i].grade[1], students[i].grade[2], students[i].average);
		totaverage += students[i].average;
	}
	printf("Class average: %.1f\n", totaverage / n);
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		;
	}
}