/*用户输入源文件名和输出文件名，复制文件数据。使用标准I/O和二进制模式*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 81

int main(void)
{
	char file_dest[SIZE];
	char file_src[SIZE];
	FILE * fsrc;
	FILE * fdest;
	char temp[SIZE];
	size_t bytes;

	puts("Enter name of destination file:");
	gets_s(file_dest, SIZE);
	if (fopen_s(&fdest, file_dest, "wb") != 0)
	{
		printf("Can't open %s\n", file_dest);
		exit(EXIT_FAILURE);
	}
	puts("Enter name of resource file:");
	gets_s(file_src, SIZE);
	if (fopen_s(&fsrc, file_src, "rb") != 0)
	{
		printf("Can't open %s\n", file_src);
		exit(EXIT_FAILURE);
	}
	while ((bytes = fread(temp, sizeof(char), SIZE, fsrc)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, fdest);
	}
	if (ferror(fdest) != 0)
	{
		printf("Error in writing %s\n", file_dest);
		exit(EXIT_FAILURE);
	}
	if (ferror(fsrc) != 0)
	{
		printf("Error in reading %s\n", file_dest);
		exit(EXIT_FAILURE);
	}
	_fcloseall();

	printf("Copy successfully!\n");
	system("pause");
	return 0;
}