
//命令行环境下，提供命令行参数打开指定文件读内容

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int ch;												//读取时存储每个字符的位置
	FILE * fp;											//文件指针
	long count = 0;
	errno_t err;

	system("color 5A");
	if (argc != 2)										//没有命令行参数时,异常退出
	{
		printf("Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((err = fopen_s(&fp, argv[1], "rb")))				//只读方式打开文件（获得错误码退出）
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