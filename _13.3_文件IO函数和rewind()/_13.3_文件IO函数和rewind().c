
/*程序首次运行时创建一个“words”文件，将用户输入的信息保存到文件内*/

#include <stdio.h>
#include <stdlib.h>					//提供了exit()的函数原型

#define SIZE 41

int main(void)
{
	FILE * fp;								//文件指针
	char words[SIZE];						//临时字符串

	system("color 5A");
	//打开文件（首次创建、以后追加）
	if (fopen_s(&fp, "words", "a+"))
	{
		fprintf(stderr, "Open file \"words\" failed");
		exit(EXIT_FAILURE);
	}

	//获取输入到文件
	fprintf(stdout, "Enter words add to the file \"words\"\n");
	fprintf(stdout, "(press the Enter key at the begining of a line to terminate): \n");
	while (gets_s(words, SIZE) != NULL && words[0] != '\0')
	{
		fprintf(fp, words);					//之前打开的fp指向的文件，是以追加的方式打开的，所以向文件写入格式化字符串时，只会在文件尾添加
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
