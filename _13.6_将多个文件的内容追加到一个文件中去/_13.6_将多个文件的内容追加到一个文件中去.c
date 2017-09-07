#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define LSIZE 81

void append(FILE * src, FILE * dest);

int main(void)
{
	FILE * fa, * fs;					//fa指向追加的目标文件，fs指向源文件
	int files = 0;						//源文件计数器
	char fname_a[LSIZE];
	char fname_s[LSIZE];

	system("color 0A");
	puts("请输入要为其追加内容的目标文件名:");
	gets_s(fname_a, LSIZE);

	//打开目标文件
	if (fopen_s(&fa, fname_a, "w") != 0)		//追加方式打开文本流(输出流)
	{
		fprintf(stderr, "文件\"%s\"打开失败！\n", fname_a);
		exit(EXIT_FAILURE);
	}
	
	//在对输出流进行操作之前，关联缓冲区
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("输出缓冲区创建失败！\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("请输入源文件名（键入空行结束）");
	while (gets_s(fname_s, LSIZE) != NULL && fname_s[0] != '\0')
	{
		if (strcmp(fname_a, fname_s) == 0)
		{
			fputs("警告！无法向文件本身追加内容！\n", stderr);
		}
		else if (fopen_s(&fs, fname_s, "r") != 0)	//只读方式打开文本流(输入流)
		{
			fprintf(stderr, "文件\"%s\"打开失败！\n", fname_s);
			exit(EXIT_FAILURE);
		}
		else
		{
			//在对输入流进行操作之前，关联缓冲区
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("输入缓冲区创建失败！\n", stderr);
				continue;
			}

			//开始追加
			append(fs, fa);

			//检测读写错误
			if (ferror(fs) != 0)
			{
				fprintf(stderr, "读取文件\"%s\"出错！\n", fname_s);
			}
			if (ferror(fa) != 0)
			{
				fprintf(stderr, "改写文件\"%s\"出错！\n", fname_a);
			}
			fclose(fs);
			files++;
			printf("第%d次向文件\"%s\"追加数据完毕！\n", files, fname_a);
			puts("请输入下一个目标文件名:");
		}
	}
	fclose(fa);
	printf("向文件\"%s\"追加数据结束！\n", fname_a);

	system("pause");
	return 0;
}

void append(FILE * src, FILE * dest)
{
	size_t bytes;
	static char temp[BUFSIZE];				//分配一次，静态存储

	//二进制I/O
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, src)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, dest);
	}
}