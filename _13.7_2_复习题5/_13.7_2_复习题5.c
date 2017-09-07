#include <stdio.h>
#include <stdlib.h>
//#include <console.h>					//针对Mac用户
#include <string.h>

#define SIZE 256

int has_ch(char ch, char * line);		//寻找字符串中的指定字符

int main(int argc, char * argv[])
{
	char ch;
	FILE * fp;
	char line[SIZE];

	/*程序功能：接受2个命令行参数，第一个是一个字符，第二个是文件名。程序打印文件中包含给定字符的行
	注意：对于Macintosh，使用console.h和ccomand()*/

	system("color 5A");
	//argc = ccommand(&argv);
	if (argc != 3)
	{
		printf("Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ch = argv[1][0];				//取命令行参数的第一个字符
	if (fopen_s(&fp, argv[2], "r") != 0)
	{
		printf("Can't open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, SIZE, fp) != NULL)
	{
		if (has_ch(ch, line))
		{
			fputs(line, stdout);
		}
	}
	if (ferror(fp) != 0)
	{
		printf("Reading \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	system("pause");
	return 0;
}

int has_ch(char ch, char * line)
{
	/*法1
	return strchr(line, ch) != NULL ? 1 : 0;*/		//可以用之前学的字符串系列函数嘛

	//法2
	while (*line)
	{
		if (ch == *line++)					//自增运算符的优先级高于间接运算符，怕我忘了，提醒一哈
		{
			return 1;
		}
	}

	return 0;
}