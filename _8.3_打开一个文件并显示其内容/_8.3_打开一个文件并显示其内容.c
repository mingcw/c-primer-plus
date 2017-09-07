#include <stdio.h>
#include <stdlib.h>						//提供了exit()的函数原型

int main(void)
{
	//利用文件读取函数打开一个文件并读取所有内容到控制台,以解决方案目录下的“test.txt”为测试文件

	int ch;
	FILE *fp;							//文件指针
	errno_t err;		
	char fname[50];

	system("color 0A");
	printf("Please enter the name of the file（e.g.\"test.txt\"）:\n");
	scanf_s("%s", fname, sizeof fname);
	err = fopen_s(&fp, fname, "r");		//以只读方式打开文件供读取,失败返回非0错误码
	if (err != 0)						//打开失败（异常退出）时
	{
		printf("Failed to open the file!\n");
		exit(1);						//退出程序
	}
	while ((ch = getc(fp)) != EOF)		//getc()从文件读一个字符
	{
		putchar(ch);
	}
	fclose(fp);							//关闭文件

	getchar();		
	getchar();		
	getchar();		
	return 0;
}