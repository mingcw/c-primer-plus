/*#include <stdio.h>

int main(void)
{
	略述goto语句的常见情形，然后展开一个C习惯的方式

	1.处理需要多条语句的if情形
	if (size > 12)
		goto a;
	goto b;
	a:
		cost *= 1.95;
		flag = 2;
	b:
		bill = cost * flag;

	在旧风格的BASIC和FORTRAN中，只有直接跟在if后的单条语句隶属该if，没有代码块或符合语句的规定。可转换为以下使用代码块或复合语句的标准C方法更易于使用
	if (size > 12)
	{
		cost *= 1.95;
		flag = 2;
	}
	bill = cost * flag;

	2.二选一
	if (ibex > 14)
		goto a;
	sheds = 2;
	goto b;
	a: 
		sheds = 3;
	b:
		help = 2 * sheds;

	用C的if else进行替换
	if (ibex > 14)
	{
		sheds = 3;
	}
	else
	{
		sheds = 2;
	}
	help = 2 * sheds;

	3.建立不确定循环
	readin: scanf_s("%d", &score);
	if (score < 0)
	{
		goto stage2;
	}
	losts of statements;
	goto readin;
	stage2: 
		more stuff;

	用while循环代替：
	scanf_s("%d", &score);
	while (score <= 0)
	{
		losts of statement;
		scanf_s("%d", &score);
	}
	more stuff;

	4.调到循环末尾，并开始下一轮循环：用continue代替

	5.跳出循环：用break代替。
	实际上，break和continue是goto的特殊形式。
	使用它们的好处在于，它们的名字表明他们更以为这什么，并且，因为它们不使用标签，所以不存在标签放错位置的潜在危险。

	6.绝对禁止胡乱地调到程序的不同部分
	但允许使用goto跳出多层循环（单条break只能跳出最里层的循环）
}*/