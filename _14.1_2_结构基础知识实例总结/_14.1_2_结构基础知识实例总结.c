#include <stdio.h>

#define SIZE 41

struct book												/*1.声明结构定义，该结构模板声明在所有函数之外，
															所以，它的标记可以被本文件中该声明之后的所有函数使用
														  2.book是可选的标记，可用于快速访问这个结构，
															即该结构的快速标记
															尤其在需要声明多个该结构类型的变量时，就需要使用标记*/
{
	char title[SIZE];
	char author[SIZE];
	float value;
};

int main(void)
{
	struct book library = {								/*1.初始化一个book类型的结构变量（用一对花括号括起来的、逗号分隔的初始化项目列表初始化各个结构成员）
														  2.结构变量library属于自动存储类变量（现在的C允许是任意存储类，ANSI之前的C不允许是自动变量）
														  3.初始化项目列表的成员必须匹配结构成员的数据类型*/
		"Chicken of the Alps",
		"Bismo Lapoult",
		14.95f
	};

	printf("Title: %s\n", library.title);				//结构成员运算符点(.)可以访问结构的各个成员，library.title成员的使用与其他char []类型相同
	printf("Author: %s\nValue?：", library.author);		//结构成员运算符访问author成员，library.author成员的使用与其他char []类型相同
	scanf_s("%f", &library.value, 10);					/*1.结构成员运算符访问value成员，library.value成员的使用与其他float类型相同
														  2.结构成员运算符(.)的优先级高于地址运算符(&)，
															所以 &library.value表达式和
																 &(library.value)表达式一样*/
	printf("Value: $%.2f\n", library.value);

	getchar();
	getchar();
	return 0;
}