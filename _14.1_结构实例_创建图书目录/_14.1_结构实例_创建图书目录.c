#include <stdio.h>
#include <stdlib.h>

#define MAXTITL 41				//书名的最大长度+1
#define MAXAUTL 31				//作者名的最大长度+1

//定义结构设计
struct book						//结构模板，标记为book(标记名可选。提供了对该结构的快速访问。是一个该结构的快速标记)
{
	char title[MAXTITL];		//member1/field1
	char author[MAXAUTL];		//member2/field2
	float value;				//member3/field3
};								//结构模板结束

int main(void)
{
	//声明一个结构变量
	struct book library;		/*1.把library声明为一个book类型的变量
								  2.把library声明为一个使用book结构设计的结构变量*/

	system("color 5A");
	printf("Please enter the book title:\n");
	gets_s(library.title, MAXTITL);
	printf("Now enter the author:\n");
	gets_s(library.author, MAXAUTL);
	printf("Now enter the value:\n");
	scanf_s("%f", &library.value, 20);
	printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);

	system("pause");
	return 0;
}