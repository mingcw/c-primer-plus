
/*程序首次运行时创建一个“words”文件，将用户输入的信息保存到文件内.
为录入的单词编号，下次录入时，编号从之前的一个继续开始。*/

#include <stdio.h>
#include <stdlib.h>					//提供了exit()的函数原型
#include <ctype.h>
#include <string.h>

#define SIZE 41
#define CTRL_Z '\32'

void createID(char * str, int size, int ID);
int IDlen(int ID);

int main(void)
{
	FILE * fp;								//文件指针
	char words[SIZE];						//临时字符串
	int ch;
	int ID = 0;
	long pos = 0L;
	int prenum = 0;
	int index = 0;

	system("color 5A");
	//打开文件（首次创建、以后追加）
	if (fopen_s(&fp, "words", "a+"))
	{
		fprintf(stderr, "Open file \"words\" failed");
		exit(EXIT_FAILURE);
	}
	//获取已有单词的最后一个编号
	while ((ch = getc(fp)) != EOF)
	{
		if (isdigit(ch))
		{
			ungetc(ch, fp);										//放回数字字符到文本流中
			fscanf_s(fp, "%d", &ID, SIZE);						//保存最大的单词编号，即最后一个单词编号,同时移动流的指针到下一个非数字字符
		}
	}

	//获取输入到文件
	fprintf(stdout, "Enter words add to the file \"words\"\n");
	fprintf(stdout, "(press the CTRL+Z at the begining of a line to terminate): \n");

mark1:
	while (scanf_s("%s", words, SIZE) == 1 && words[0] != CTRL_Z)
	{
		while (words[index] != '\0')
		{
			if (isdigit(words[index++]))
			{
				fprintf(stderr, "Words must be consisted of letters.\n");
				goto mark1;
			}
		}
		createID(words, SIZE, ++ID);
		fprintf(fp, words);					//之前打开的fp指向的文件，是以追加的方式打开的，所以向文件写入格式化字符串时，只会在文件尾添加
		putc('\n', fp);						//每个单词分行写入
	}

	//反馈文件内容
	puts("File contents:");
	rewind(fp);								//将文件内部的指针重新指向一个流的开头
	while (fscanf_s(fp, "%s", words, SIZE) == 1)
	{
		puts(words);
	}

	//关闭文件
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error closing file.\n");
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}

void createID(char * str, int size, int ID)
{
	int end;
	int idlen;
	char temp[SIZE];

	end = strlen(str);
	idlen = IDlen(ID);

	//确保加入编号后，字符串没有超出字符数组的长度,不能相等，最后一个位置留给空字符
	if (end + idlen + 1 < size)		//字符串长度+编号长度+一个“.”长度
	{
		//所有字符向后移动idlen+1个字节
		for (int i = end; i >= 0; i--)
		{
			str[i + idlen + 1] = str[i];
		}
		//空出来的前idlen个字节位置写入编号
		sprintf_s(temp, SIZE, "%d", ID);
		for (unsigned int i = 0; i < strlen(temp); i++)
		{
			str[i] = temp[i];
		}
		str[strlen(temp)] = '.';
	}
}

int IDlen(int ID)
{
	char dest1[SIZE];

	sprintf_s(dest1, SIZE, "%d", ID);

	return strlen(dest1);
}