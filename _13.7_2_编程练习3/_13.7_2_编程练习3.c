/*用户输入源文件名和输出文件名，复制文件数据成大写形式。使用标准I/O和文本制模式*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 81

int main(void)
{
	char file_dest[SIZE];
	char file_src[SIZE];
	FILE * fsrc;
	FILE * fdest;
	int ch;

	puts("Enter name of destination file:");
	gets_s(file_dest, SIZE);
	if (fopen_s(&fdest, file_dest, "w") != 0)			//打开文本流作输出流
	{
		printf("Can't open %s\n", file_dest);
		exit(EXIT_FAILURE);
	}
	puts("Enter name of resource file:");
	gets_s(file_src, SIZE);
	if (fopen_s(&fsrc, file_src, "r") != 0)				//打开文本流作输入流
	{
		printf("Can't open %s\n", file_src);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fsrc))!= EOF)
	{
		ch = toupper(ch);
		putc(ch, fdest);
	}
	if (ferror(fdest))
	{
		printf("Error in writing %s\n", file_dest);
		exit(EXIT_FAILURE);
	}
	if (ferror(fsrc))
	{
		printf("Error reading %s\n", file_src);
		exit(EXIT_FAILURE);
	}
	_fcloseall();
	printf("Copy success!\n");

	system("pause");
	return 0;
}