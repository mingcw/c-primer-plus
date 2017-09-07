/*重写13.2，不用命令行，提示用户键入*/

#include <stdio.h>
#include <stdlib.h>				//调用exit()
#include <string.h>				//提供strchr(), strncpy(), strcat()的原型

#define SIZE 81

int main(int argc, char * argv[])
{
	FILE * in, *out;			//文件指针
	int ch;
	char file_in[SIZE];			//存放输入文件名
	char file_out[SIZE];
	char temp[SIZE];
	int count = 0;
	errno_t err;
	char * pos;
	int cpylen;

	system("color 0A");
	puts("Enter file for inputing:");
	gets_s(file_in, SIZE);

	//实现输入
	if (err = fopen_s(&in, file_in, "r"))
	{
		fprintf(stderr, "Open file \"%s\" failed.\n", file_in);
		exit(EXIT_FAILURE);
	}

	//实现输出
	puts("Enter file for outputing:");
	gets_s(temp, SIZE);
	if (pos = strchr(temp, '.'))
	{
		cpylen = pos - temp;
	}
	else
	{
		cpylen = strlen(temp);
	}
	strncpy_s(file_out, SIZE, temp, cpylen);				//拷贝文件名到数组中（test.txt的前半部分test被拷贝）
	strcat_s(file_out, SIZE, ".red");						//添加后缀名.red
	if (err = fopen_s(&out, file_out, "w"))
	{
		fprintf(stderr, "Open file \"%s\" failed.\n", file_out);
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