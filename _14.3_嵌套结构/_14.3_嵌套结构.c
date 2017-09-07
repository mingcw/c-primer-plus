#include <stdio.h>
#include <stdlib.h>

//注意;点运算符和成员名可以访问结构变量的指定成员

#define LEN 21

const char * msgs[5] = {
	"    Thank you for the wonderful evening, ",
	"You certainly prove that a ",
	"is a special kind of guy. We must get together",
	"over a dicilious ",
	" and hanve a few laughs"
};

struct names				//第一个结构
{
	char first[LEN];
	char last[LEN];
};
struct guy					//第二个结构
{
	struct names handle;	//嵌套结构
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	struct guy fellow = {	//初始化一个guy类型的结构变量
		{ "Ewen", "Villard" },
		"grilled salmon",
		"personality coach",
		58112.00f
	};

	system("color 5A");

	//打印信的开头
	printf("Dear %s, \n\n", fellow.handle.first);
	//打印信的内容
	printf("%s%s.\n", msgs[0], fellow.handle.first);
	printf("%s%s\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
	//打印句末标点
	if (fellow.income > 150000.0f)
	{
		puts("!!");
	}
	else if (fellow.income > 75000.0f)
	{
		puts("!");
	}
	else
	{
		puts(".");
	}
	//打印信尾
	printf("\n%40s%s\n", " ", "See you soon, ");
	printf("%40s%s\n", " ", "Shalsls");
	
	system("pause");
	return 0;
}