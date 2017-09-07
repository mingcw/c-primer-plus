/*使用命令行或用户输入，打开2个文件。
打印第一个文件的第一行、第二个文件的第一行
	第一个文件的第二行、第二个文件的第二行，
依次类推，直到打印完行数较多的文件的最后一行。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 81
#define LSIZE 256

void adjust(FILE ** fa, FILE ** fb);
int getlines(FILE * fp);

int main(int argc, char * argv[])
{
	FILE * fa;
	FILE * fb;
	char file_a[SIZE];
	char file_b[SIZE];
	char line_a[LSIZE];
	char line_b[LSIZE];

	system("color 0A");
	//获取文件名
	if (argc == 3)
	{
		strcpy_s(file_a, SIZE, argv[1]);
		strcpy_s(file_b, SIZE, argv[2]);
	}
	else
	{
		puts("Enter first file name:");
		gets_s(file_a, SIZE);
		puts("Second file name:");
		gets_s(file_b, SIZE);
	}

	//打开文本输入流
	if (fopen_s(&fa, file_a, "r"))					//只读，文本流
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fb, file_b, "r"))					//只读，文本流
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	//调整文件指针
	adjust(&fa, &fb);

	//打印信息
	while (fgets(line_a, LSIZE, fa) != NULL)
	{
		fputs(line_a, stdout);
		if (fgets(line_b, LSIZE, fb) != NULL)
		{
			fputs(line_b, stdout);
		}
	}

	//检查读写错误
	if (ferror(fa) != 0)
	{
		fprintf(stderr, "Error in reading %s\n", file_a);
		exit(EXIT_FAILURE);
	}
	if (ferror(fb) != 0)
	{
		fprintf(stderr, "Error in reading %s\n", file_b);
		exit(EXIT_FAILURE);
	}

	//关闭文件（流）
	if (_fcloseall() == 0)
	{
		fprintf(stderr, "Failed in closing files!");
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;
}

//调整文件指针。前者将指向行较数多的文件流。
void adjust(FILE ** fa, FILE ** fb)
{
	int ct_a = 0;
	int ct_b = 0;
	FILE * temp;

	ct_a = getlines(*fa);
	ct_b = getlines(*fb);
	if (ct_a < ct_b)
	{
		temp = *fa;
		*fa = *fb;
		*fb = temp;
	}
}

//获取文件流行数
int getlines(FILE * fp)
{
	int ch;
	int pre;
	int ct = 0;

	while ((ch = getc(fp)) != EOF)
	{
		if (ch == '\n')
		{
			++ct;						//行计数器计数
			pre = ch;
		}
	}
	if (pre != '\n')
	{
		++ct;							//统计不完全行
	}
	rewind(fp);							//文件位置指示器定位到文件头

	return ct;
}