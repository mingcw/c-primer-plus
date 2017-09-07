/*程序要求：
将一个字符、0个或多个文件名作为命令行参数。如果字符后没有参数跟随，程序读取标准输入文件。
否则，程序一次打开每个文件，然后报告每个文件中该字符的出现次数。文件名和字符本身随同计数值
一起报告。程序中包括错误检查，以确定参数数目是否正确和是否能打开文件。如果不能打开文件，程
序要报告这一情况然后继续处理下一文件。
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 81

int count(int ch, FILE ** fp);

int main(int argc, char * argv[])
{
	char file[SIZE];
	FILE * fp;
	int i = 2;

	system("color 0A");
	if (argc < 2 )
	{
		fprintf(stderr, "The number of order-paramater is not enough.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		//从标准输入流获取一个文件名，打开得到文本流，反馈信息
		puts("Enter the file name:");
		gets_s(file, SIZE);
		if (fopen_s(&fp, file, "r") != 0)
		{
			fprintf(stderr, "Can't open file %s.\n", file);
			exit(EXIT_FAILURE);
		}
		printf("The \'%c\' has %d in the file %s.\n", argv[1][0], count(argv[1][0], &fp), file);
		if (ferror(fp) != 0)
		{
			fprintf(stderr, "Error in reading %s\n", file);
			exit(EXIT_FAILURE);
		}
		fclose(fp);
	}
	else
	{
		//从命令行参数获取多个文件名，打开得到文本流，反馈信息
		while (i < argc)
		{
			if (fopen_s(&fp, argv[i], "r") != 0)
			{
				fprintf(stderr, "Can't open file %s.\n", file);
				continue;
			}
			printf("The \'%c\' has %d in the file %s.\n", argv[1][0], count(argv[1][0], &fp), argv[i]);
			if (ferror(fp) != 0)
			{
				fprintf(stderr, "Error in reading %s\n", argv[i]);
				continue;
			}
			fclose(fp);
			i++;
		}
	}

	system("pause");
	return 0;
}


int count(int ch, FILE ** fp)
{
	int temp;
	int ct = 0;

	while ((temp = getc(*fp)) != EOF)
	{
		if (ch == temp)
		{
			ct++;
		}
	}

	return ct;
}