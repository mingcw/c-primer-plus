
//再次熟悉、掌握文件IO：把多个文件的二进制数据追加到一个文件内,命令行参数实现

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZEFILE 81
#define SIZEBUF 1024

void append(FILE * src, FILE * dest);

int main(int argc,char * argv[])
{

	FILE * fa, * fs;				//fa指向追加的目的文件，fs指向源文件
	int count = 0;					//源文件计数器

	system("color 5A");
	if (argc < 3)
	{
		fprintf(stderr, "Have no destination filr or resource file.\n");
		exit(EXIT_FAILURE);
	}

	//打开要追加的目的文件,获得输出流（文本流）
	if (fopen_s(&fa, argv[1], "a") != 0)
	{
		fprintf(stderr, "Can't open file %s!\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	//关联输出流的缓冲区
	if (setvbuf(fa, NULL, _IOFBF, SIZEBUF) != 0)
	{
		fputs("Can't create output buffer!\n", stderr);
		exit(EXIT_FAILURE);
	}

	//循环获取源文件名并追加
	for (int i = 2; i < argc; i++)
	{
		//检测文件名重复,否继续，是输入下一个源文件名
		if (strcmp(argv[i], argv[1]) == 0)
		{
			fputs("Can't append file to itself.\n", stderr);
		}
		//打开源文件，获得输入流（文本流）,成功继续，失败输入下一个源文件名
		else if (fopen_s(&fs, argv[i], "r") != 0)
		{
			fprintf(stderr, "Can't open file %s!\n", fs);
		}
		else
		{
			//关联输入流的缓冲区
			if (setvbuf(fs, NULL, _IOFBF, SIZEBUF) != 0)
			{
				fputs("Can't create input buffer!\n", stderr);
				continue;
			}
			append(fs, fa);									//追加数剧
			//检测读写错误
			if (ferror(fa) != 0)
			{
				fprintf(stderr, "Error in writing file %s.\n", argv[1]);
			}
			if (ferror(fs) != 0)
			{
				fprintf(stderr, "Error in reading file %s.\n", argv[i]);
			}
			fclose(fs);										//关闭源文件(同时销毁缓冲区)
			++count;										//计数器+1
		}
	}
	fclose(fa);												//关闭追加文件(同时销毁缓冲区)
	fprintf(stdout, "Done. %d files appended.\n", count);

	system("pause");
	return 0;

}

void append(FILE * src, FILE * dest)
{
	size_t count;
	static char temp[SIZEBUF];								//分配一次

	while ((count = fread(temp, sizeof(char), SIZEBUF, src)) > 0)			
	{
		fwrite(temp, sizeof(char), count, dest);
	}
}