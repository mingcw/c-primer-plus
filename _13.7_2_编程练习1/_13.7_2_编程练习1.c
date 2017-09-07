#include <stdio.h>
#include <stdlib.h>

#define SIZE 81

int main(int argc, char * argv[])
{
	int ch;												//读取时存储每个字符的位置
	FILE * fp;											//文件指针
	long count = 0;
	errno_t err;
	char file[SIZE];

	system("color 5A");
	printf("Enter file name to read:\n");
	gets_s(file, SIZE);
	if ((err = fopen_s(&fp, file, "rb")))				//只读方式打开文件（获得错误码退出）
	{
		printf("Can't open file.\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);									//输出字符到标准输出流
		count++;
	}
	fclose(fp);
	printf("\nFile has %d characters.\n", count);

	getchar();
	return 0;
}