#include <stdio.h>
#include <stdlib.h>

#define MAXTITL 41
#define MAXAUTL 31

struct book				//结构模本，标记是book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};


/*
	C99新增的复合文字特性不仅适合数组，也使用于结构。
	可以使用复合文字创建一个被用来作为函数参数或被赋值给另一个结构的结构。
	语法：使用类型指派运算符把类型名写在圆括号中，后跟一个用花括号括起来的初始化项目列表。例如：
	(struct book){"C Primer Plus", "Stephen Prata", 60.00f};
*/
int main(void)
{
	struct book readfirst;
	int score;

	system("color 0A");
	printf("Enter test score:\n");
	scanf_s("%d", &score, 10);
	
	if (score >= 84)
	{
		readfirst = (struct book){				//将复合文字进行类型转化直接赋值
			"Crime and Punishment",
				"Fyodor Dostoyevsky",
				9.99f
		};
	}
	else
	{
		readfirst = (struct book){
			"Mr.Bouncy's Nice Hat",
				"Fred Winsome",
				5.99f
		};
	}
	printf("Your assigned reading:\n");
	printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);

	system("pause");
	return 0;
}