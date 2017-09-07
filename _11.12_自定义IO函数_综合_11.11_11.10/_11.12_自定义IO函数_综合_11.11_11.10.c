#include <stdio.h>

void put1(const char * string);
int put2(const char * string);

int main(void)
{
	/*综合_11.11和11.10_实现自定义IO函数的应用*/

	put1("If I'd as much money");
	put1("as I could spend, \n");
	printf("I count %d characters.\n",
		put2("I never would cry old chairs to mend."));		//该语句的理解可以依据参数压栈,先将参数压如栈中，然后调用函数实现过程

	getchar();
	return 0;
}

//打印字符串
void put1(const char * string)
{
	while (*string) /*应该熟悉这种C程序员的习惯写法，精炼且效率
					  等价于*string != '\n'*/
	{
		putchar(*string++);
	}
}

//打印字符串并返回成功打印的字符数
int put2(const char * string)
{
	int count = 0;

	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');

	return count;
}