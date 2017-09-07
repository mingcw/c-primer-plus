
/*题目太长，大致是：创建一个有20行，每行30个整数的文本文件。整数在0-9之间，用空格分开。
该文件是一个图片的数字表示，从0到9代表灰度的增加。程序将文件内容读入到20*30的int数组。
一种将这种数字表示转化为图片的粗略方法就是让程序使用数组中的数值来初始化一个20*31的字符陈列。
0对应空格字符，1对应句号字符，依次类推，较大的值对应占用空间较多的字符。
比如，可以使用#代表9。每行的最后一个字符（第31个）为空字符，这样数组将包含20个字符串。
然后程序显示结构图片（即打印这些字符串），并将结果存入一个文本文件中。

我的做法：写600个int数到文本里，手会不高兴。所以，直接用程序创建20*30的数组并写到文件，也省去了再读出来的麻烦。
		至于哪个数字对应转换为哪个字符，题目无明确要求，可以自定义。欧克
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FNAME "number.txt"
#define FDEST "graph.txt"
#define ROW 20
#define COL 30

char tochar(int num);

int main(void)
{
	FILE * fp;
	int num[ROW][COL];
	char chlist[ROW][COL + 1];							//字符阵列，产生多行的字符串
		
	system("color 0A");
	if (fopen_s(&fp, FNAME, "w") != 0)
	{
		fprintf(stderr, "Error in opening file %s.\n", FNAME);
		exit(EXIT_FAILURE);
	}

	//写入20x30的int数据
	srand((unsigned int)time(NULL));
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			num[i][j] = rand() % 10;
			fprintf(fp, "%d", num[i][j]);
			if (j != COL - 1)
			{
				putc(' ', fp);
			}
		}
		putc('\n', fp);
	}
	fclose(fp);

	//转换出字符阵列
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			chlist[i][j] = tochar(num[i][j]);
		}
		chlist[i][COL] = '\0';						//每行是字符串
	}
	
	//打印字符阵列
	for (int i = 0; i < ROW; i++)
	{
		printf("%s", chlist[i]);
		putchar('\n');
	}

	//写入字符阵列到文件
	if (fopen_s(&fp, FDEST, "w") != 0)
	{
		fprintf(stderr, "Error in opening file %s.\n", FDEST);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < ROW; i++)
	{
		fprintf(fp, "%s", chlist[i]);
		putc('\n', fp);
	}
	fclose(fp);

	system("pause");
	return 0;
}

char tochar(int num)
{
	char ch;

	switch (num)
	{
	case 0:
		ch = ' ';
		break;
	case 1:
		ch = '.';
		break;
	case 2:
		ch = '*';
		break;
	case 3:
		ch = '/';
		break;
	case 4:
		ch = '?';
		break;
	case 5:
		ch = '&';
		break;
	case 6:
		ch = '%';
		break;
	case 7:
		ch = '$';
		break;
	case 8:
		ch = '@';
		break;
	case 9:
		ch = '#';
		break;
	}

	return ch;
}