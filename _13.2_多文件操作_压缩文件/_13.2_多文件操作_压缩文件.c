
//命令行环境键入命令行参数提供输入文件名，将文件内容压缩到.red的同名文件内

#include <stdio.h>
#include <stdlib.h>				//调用exit()
#include <string.h>				//提供strchr(), strncpy(), strcat()的原型

#define SIZE 81

int main(int argc, char * argv[])
{
	FILE * in, *out;			//文件指针
	int ch;
	char name[SIZE];			//存放输入文件名
	int count = 0;				
	errno_t err;
	char * pos;
	int cpylen;

	system("color 0A");
	//检查命令行参数
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//实现输入
	if (err = fopen_s(&in, argv[1], "r"))
	{
		fprintf(stderr, "Open file \"%s\" failed.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	//实现输出
	if (pos = strchr(argv[1], '.'))
	{
		cpylen = pos - argv[1];
	}
	else
	{
		cpylen = strlen(argv[1]);
	}
	strncpy_s(name, SIZE, argv[1], cpylen);				//拷贝文件名到数组中（test.txt的前半部分test被拷贝）
	strcat_s(name, SIZE, ".red");						//添加后缀名.red
	if (err = fopen_s(&out, name, "w"))
	{
		fprintf(stderr, "Open file \"%s\" failed.\n", name);
		exit(EXIT_FAILURE);
	}

	//复制数据
	while (((ch = getc(in)) != EOF))
	{
		if (count++ % 3 == 0)
		{
			putc(ch, out);								//向.red文件打印每3个字符的第一个
		}
	}

	//收尾工作
	if (fclose(in) || fclose(out))
	{
		fprintf(stderr, "Errors in closing files.\n");
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}