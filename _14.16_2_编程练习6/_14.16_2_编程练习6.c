/*
	一个文本文件中存放着一个棒球队的信息。每一行的数据都是这样排列的：
	4 Jessie Joybat 5 2 1 1
	第一项是球员号码，为了方便，范围是0到18。第二项是球员的名，第三项是姓。姓和名都是单个的单词。
	下一项是官方统计的球员上场次数，紧跟着是击中数、走垒数、和跑点数（RBI）。文件可能包括超过
	一场比赛的数据，因此同一个球员可能会有多余一行的数据，而且在不同的行之间有可能有别的球员的数据。
	写一个程序，把这些数据存储到一个结构数组中。结构中必须含有姓、名、上场次数、击中数、走垒数和跑
	点数，以及击球平均成功率（稍后计算）。可以使用球员号码作为数组索引。程序应该读到文件末尾，并且
	应该保存每个球员的累计总和。

	这个棒球运动中的统计方法时相关的。例如，一次走垒和触垒中的失误并不会计作上场次数，但是这可能产
	生一个RBI。可是，该程序所要做的只是处理数据文件，而不必关心数据的实际含义。

	要实现这些功能，最简单的方法是把结构的内容初始化为0值，将文件数据读入临时变量中，然后把它们加到
	相应结构的内容中。程序读完文件后，应该计算每个球员的击球平均成功率，并把它保存到相应的结构成员里。
	计算击球平均成功率是对球员的累计击中数除以上场累计次数：这是个浮点数运算。然后程序要显示每个球员
	的累计数据，并且对整个时期显示一行综合统计数据。
	
	*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define NAMESIZE	21
#define MAXSIZE	100
#define FILENAME "info.txt"
#define TEMPSIZE 41

struct _name
{
	char fname[NAMESIZE];
	char lname[NAMESIZE];
};

struct member
{
	int number;				//球员号
	struct _name name;		//球员
	int participate;		//上场次数
	int success;			//击中数
	int leakout;			//走垒数
	int RBI;				//跑点数
	float percent;			//击球成功率
};

int getinfo(struct member members[], int n, FILE * fp);									//获取数据
void makeinfo(struct member members[], int n);											//计算击球平局率
void showinfo(const struct member members[], int n);									//打印信息
bool is_num_repeat(const struct member members[], int n,const struct member temp);		//检查重复编号
void update(struct member members[], int n, const struct member temp);					//合并编号重复的记录
void saveinfo(const struct member members[], int n, FILE * fp);							//保存数据

int main(void)
{
	struct member members[MAXSIZE] = { 0 };
	FILE * fp;
	int count;

	system("color 5A");

	if (fopen_s(&fp, FILENAME, "r") != 0)
	{
		fprintf(stderr, "Can't open file.\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp);

	//读数据
	count = getinfo(members, MAXSIZE, fp);
	if (count > 0)
	{
		makeinfo(members, count);
		showinfo(members, count);

		//重写数据（合并重复记录）
		fclose(fp);
		if (fopen_s(&fp, FILENAME, "w") != 0)
		{
			fprintf(stderr, "Can't open file.\n");
			exit(EXIT_FAILURE);
		}
		rewind(fp);
		saveinfo(members, count, fp);
	}
	else
	{
		printf("No record? Too bad.\n");
	}
	fclose(fp);

	system("pause");
	return 0;
}

int getinfo(struct member members[], int n, FILE * fp)
{
	
	int count = 0, result;
	struct member temp;

	//读第一条记录
	result = fscanf_s(fp, "%d %s %s %d %d %d %d", &temp.number, temp.name.fname, NAMESIZE, temp.name.lname, NAMESIZE,
		&temp.participate, &temp.success, &temp.leakout, &temp.RBI);

	while (result == 7 && count < n)
	{
		if (is_num_repeat(members, count, temp))
		{
			update(members, count, temp);
		}
		else
		{
			members[count] = temp;
			count++;
		}

		//读下一条
		result = fscanf_s(fp, "%d %s %s %d %d %d %d", &temp.number, temp.name.fname, NAMESIZE, temp.name.lname, NAMESIZE,
			&temp.participate, &temp.success, &temp.leakout, &temp.RBI);
	}

	return count;
}

bool is_num_repeat(const struct member members[], int n, const struct member temp)
{
	for (int i = 0; i < n; i++)
	{
		if (members[i].number == temp.number)
		{
			return true;
		}
	}

	return false;
}

void update(struct member members[], int n,const struct member temp)
{
	for (int i = 0; i < n; i++)
	{
		if (members[i].number == temp.number)
		{
			members[i].participate += temp.participate;
			members[i].success += temp.success;
			members[i].leakout += temp.leakout;
			members[i].RBI += temp.RBI;
		}
	}
}

void makeinfo(struct member members[], int n)
{
	for (int i = 0; i < n; i++)
	{
		members[i].percent = (float)members[i].success / (float)members[i].participate;
	}
}

void showinfo(const struct member members[], int n)
{
	int participate_avge = 0, success_avge = 0, leakout_avge = 0, RBI_avge = 0;
	float percent_avge = 0;

	//puts("Here is the list of every member's accumulative data:");
	printf("%5s%12s%20s%10s%10s%10s%10s\n", 
		"Number", "Name", "Participate", "Success", "Leakout", "RBI", "Percent"); 

	for (int i = 0; i < n; i++)
	{
		printf("%5d%10s %-15s%7d%8d%9d%12d%11.1f\n", members[i].number, members[i].name.fname, members[i].name.lname,
			members[i].participate, members[i].success, members[i].leakout, members[i].RBI, members[i].percent);
		//统计和
		participate_avge += members[i].participate;
		success_avge += members[i].success;
		leakout_avge += members[i].leakout;
		RBI_avge += members[i].RBI;
		percent_avge += members[i].percent;
	}
	//显示综合数据
	printf("%-30s %7d%8d%9d%12d%11.1f\n", "Average data of above: ",
		participate_avge / n, success_avge / n, leakout_avge / n, RBI_avge / n, percent_avge / n);
}

void saveinfo(const struct member members[], int n, FILE * fp)
{
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d %s %s %d %d %d %d\n", members[i].number, members[i].name.fname, members[i].name.lname,
			members[i].participate, members[i].success, members[i].leakout, members[i].RBI);
	}
}