
/*命令行参数提供：第一个：字符串，第二个：文件名。打印文件中包含字符串的所有行*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char * argv[])
{
	FILE * fp;
	char line[SIZE];

	system("color 0A");
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fp, argv[2], "r") != 0)
	{
		fprintf(stderr, "Can't open file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	//依次读入一行字串，如果该字串有命令行键入的子字串，则输出该行
	while (fgets(line, SIZE, fp) != NULL)
	{
		if (strstr(line, argv[1]) != NULL)
		{
			fputs(line, stdout);
		}
	}
	//检测读写错误
	if (ferror(fp) != 0)
	{
		fprintf(stderr, "Error in reading file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	//收尾工作
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error in closing file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}