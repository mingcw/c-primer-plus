#include <stdio.h>

#define MAX 20

int main(void)
{

	/*sprintf_s()写入格式化数据到字符串，必须保证目标字符串和源字符串没有位置重叠、目标字符串的空间足够容纳元字符串
	  该函数可以将混合数据类型的字符流格式化写入到一个字符串，便于混合数据类型的收集存储*/

	char first[MAX];
	char last[MAX];
	char formal[2 * MAX + 10];
	double prize;

	puts("Enter your first name:");
	gets_s(first, MAX);
	puts("Enter your last name:");
	gets_s(last, MAX);
	puts("Enter your prize money:");
	scanf_s("%lf", &prize, 10);

	sprintf_s(formal, 2 * MAX + 10 , "%s, %-19s: $%6.2f", last, first, prize);		//格式化打印数据到字符串、写入格式化数据到字符串
	puts(formal);

	getchar();		//把scanf_s()落下的\n读入
	getchar();
	return 0;
}