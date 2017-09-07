#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char * argv[])
{
	int ch, countchar, countword, countupper, countlower, countpunct, countnum;
	FILE *fp;							//文件指针
	errno_t err;
	char fname[50];
	bool inword = false;

	countchar = countword = countupper = countlower = countpunct = countnum = 0;

	system("color 0A");
	printf("Please enter the name of the file（e.g.\"test.txt\"）:\n");
	scanf_s("%s", fname, sizeof fname);
	err = fopen_s(&fp, fname, "r");		//以只读方式打开文件供读取,失败返回非0错误码
	if (err)							//打开失败
	{
		printf("Failed to open the file!\n");
		exit(1);						//退出程序
	}
	while ((ch = getc(fp)) != EOF)		//getc()从文件读一个字符
	{
		countchar++;					//字符计数器
		if (!isspace(ch) && !inword)
		{
			countword++;				//单词计数器
			inword = true;
		}
		if (isspace(ch) && inword)
		{
			inword = false;
		}
		if (isupper(ch))
		{
			countupper++;				//大写字母计数器
		}
		if (islower(ch))
		{
			countlower++;				//小写字母计数器
		}
		if (ispunct(ch))
		{
			countpunct++;				//标点符号计数器
		}
		if (isdigit(ch))
		{
			countnum++;					//数字字符计数器
		}
	}
	fclose(fp);

	printf("The count of characters is %d\n", countchar);
	printf("The count of words is %d\n", countword);
	printf("The count of upper words is %d\n", countupper);
	printf("The count of lower words is %d\n", countlower);
	printf("The count of punctuation characters is %d\n", countpunct);
	printf("The count of number characters is %d\n", countnum);

	getchar();
	getchar();
	getchar();
	return 0;
}