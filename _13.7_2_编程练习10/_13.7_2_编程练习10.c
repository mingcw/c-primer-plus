
/*交互获取文件名，在一个循环里获取文件流的读位置，打印该位置到行末的字符
用户键入非数字位置退出循环*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 81
#define LSIZE 256

int main(void)
{
	char file[SIZE];
	FILE * fp;
	int index;
	int last;
	long pos;
	char line[LSIZE];

	system("color 5A");
	puts("Enter a file name to access:");
	gets_s(file, SIZE);
	if (fopen_s(&fp, file, "rb") != 0)
	{
		fprintf(stderr, "Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	printf("Input index to read content of the file ( 0 - %d , q to quit):\n", last - 1);
	while (scanf_s("%d", &index) == 1)
	{
		if (index < 0 || index > last)
		{
			fprintf(stderr, "No valid index!\n");
			continue;
		}
		pos = index * sizeof(char);
		fseek(fp, pos, SEEK_SET);
		fgets(line, LSIZE, fp);
		fputs(line, stdout);	//虽然是二进制流，内含\r字符，但输出字串并无影响（行末的回车符只是将光标移到行首，其后的换行符再将光标移到下一行行首，提示信息从下一行输出，不影响输出的文件内容）
		printf("Next index( 0 - %d , q to quit):\n", last - 1);
	}
	puts("GOOD BYE!");
	system("pause");
	return 0;
}