
/*编程练习12_的改版题目，原题太长，大致是：创建一个有20行，每行30个整数的文本文件。整数在0-9之间，用空格分开。
该文件是一个图片的数字表示，从0到9代表灰度的增加。程序将文件内容读入到20*30的int数组。
一种将这种数字表示转化为图片的粗略方法就是让程序使用数组中的数值来初始化一个20*31的字符陈列。
0对应空格字符，1对应句号字符，依次类推，较大的值对应占用空间较多的字符。
比如，可以使用#代表9。每行的最后一个字符（第31个）为空字符，这样数组将包含20个字符串。
然后程序显示结构图片（即打印这些字符串），并将结果存入一个文本文件中。

改版要求：数字图像，尤其是宇宙飞船发回的数字图像可能包含尖峰脉冲。为第12道编程练习题（就是上面这道）添加消除尖峰脉冲的函数。
			该函数应该对每一个值和它上下左右的相邻值比较，如果该值与它周围每个值的差都大于1，就使用所有相邻值的平均值（取
			与其最接近的整数）取代这个值。注意到边界上的点的相邻点都少于4个，所以它们需要特殊处理。

我的初步做法还是它：写600个int数到文本里，手会不高兴。所以，直接用程序创建20*30的数组并写到文件，也省去了再读出来的麻烦。
至于哪个数字对应转换为哪个字符，题目无明确要求，可以自定义。欧克
	接下来就是编写消除所谓尖峰脉冲的函数了。

	注意：下面说的边点指二维数组四周的点(不包括角点)，角点指四个角上的点。灰常重要，不至懵逼。*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FNAME "number.txt"
#define FDEST "graph.txt"
#define ROW 20
#define COL 30

char toChar(int num);
void alterNum(int num[][COL], int rows);										//修改二维数组，消除尖峰脉冲

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

	//消除尖峰脉冲
	alterNum(num, ROW);

	//转换出字符阵列
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			chlist[i][j] = toChar(num[i][j]);
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

char toChar(int num)
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

//修改二维数组，消除尖峰脉冲
void alterNum(int num[][COL], int rows)
{
	//处理四个角

	if (num[0][0] - num[0][1] > 1 && num[0][0] - num[1][0] > 1)																//左上角
	{
		num[0][0] = (num[0][1] + num[1][0]) / 2;
	}
	if (num[0][COL - 1] - num[0][COL - 2]>1 && num[0][COL - 1] - num[1][COL - 1] > 2)										//右上角
	{
		num[0][COL - 1] = (num[0][COL - 2] + num[1][COL - 1]) / 2;
	}
	if (num[rows - 1][0] - num[rows - 2][0] > 1 && num[rows - 1][0] - num[rows - 1][1] > 2)									//左下角
	{
		num[rows - 1][0] = (num[rows - 2][0] + num[rows - 1][1]) / 2;
	}
	if (num[rows - 1][COL - 1] - num[rows - 2][COL - 1] > 1 && num[rows - 1][COL - 1] - num[rows - 2][COL - 1 ] > 2)		//右下角
	{
		num[rows - 1][COL - 1] = (num[rows - 2][COL - 1] + num[rows - 2][COL - 1]) / 2;
	}

	//处理四边
	for (int i = 1; i < COL - 1; i++)																						//第一行
	{
		if (num[0][i] - num[0][i - 1]>1 && num[0][i] - num[0][i + 1] > 1 && num[0][i] - num[1][i] > 1)
		{
			num[0][i] = (num[0][i - 1] + num[0][i + 1] + num[1][i]) / 3;
		}
	}
	for (int i = 1; i < COL - 1; i++)																						//最后一行
	{
		if (num[rows - 1][i] - num[rows - 1][i - 1] > 1 && num[rows - 1][i] - num[rows - 1][i + 1] > 1 && num[rows - 1][i] - num[rows - 2][i] > 1)
		{
			num[rows - 1][i] = (num[rows - 1][i - 1] + num[rows - 1][i + 1] + num[rows - 2][i]) / 3;
		}
	}
	for (int i = 1; i < rows - 1; i++)																						//第一列
	{
		if (num[i][0] - num[i - 1][0] > 1 && num[i][0] - num[i + 1][0] > 1 && num[i][0] - num[i][1] > 1)
		{
			num[i][0] = (num[i - 1][0] + num[i + 1][0] + num[i][1]) / 3;
		}
	}
	for (int i = 1; i < rows - 1; i++)																						//最后一列
	{
		if (num[i][COL - 1] - num[i - 1][COL - 1] > 0 && num[i][COL - 1] - num[i + 1][COL - 1] > 1 && num[i][COL - 1] - num[i][COL - 2] > 1)
		{
			num[i][COL - 1] = (num[i - 1][COL - 1] + num[i + 1][COL - 1] + num[i][COL - 2]) / 3;
		}
	}
	
	//处理中间的点
	for (int i = 1; i < rows - 1; i++)
	{
		for (int j = 1; j < COL - 1; j++)
		{
			if (num[i][j] - num[i - 1][j] > 1 && num[i][j] - num[i + 1][j] > 1 && num[i][j] - num[i][j - 1] > 1 && num[i][j] - num[i][j + 1] > 1)
			{
				num[i][j] = (num[i - 1][j] + num[i + 1][j] + num[i][j - 1] + num[i][j + 1]) / 4;
			}
		}
	}

}