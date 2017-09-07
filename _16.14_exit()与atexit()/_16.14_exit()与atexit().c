#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

/*
	exit()函数已经用过，另外，main()中返回时会自动调用exit()函数。
	atexit()：注册终止函数。在调用exit()时执行的函数列表中进行注册，以便exit()退出时按照先进后出的顺序执行特定函数。最多可注册32个。
	exit()执行了atexit()注册的函数后，
	会刷新输出流、关闭所有打开的流、和关闭通过调用标准IO函数tmpfile()创建的临时文件；
	最后，exit()将控制权返回给主机环境。可能的话，还会向主机环境报告终止状态（比如是否正常退出等等）
	*/

void sign_off(void);
void too_bad(void);

int main(void)
{
	int n;

	atexit(sign_off);			//注册sign_off()函数
	puts("Enter an interger : ");
	if (scanf("%d", &n) != 1)
	{
		puts("That's no integer!");
		atexit(too_bad);
		exit(EXIT_FAILURE);
	}
	printf("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");

	return 0;					//返回时调用exit()函数
}

void sign_off(void)
{
	puts("Thus terminates another magnificent program from");
	puts("SeeSaw Software!");
}

void too_bad(void)
{
	puts("SeeSaw Software extends its heartfelt condolences");
	puts("to you upon the failure of your program.");
}