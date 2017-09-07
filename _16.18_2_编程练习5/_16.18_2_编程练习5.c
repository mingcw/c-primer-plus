/*
编写一个函数。该函数接受下列参数：一个int数组的名称，数组大小和一个代表选取次数的值。
然后函数从数组中随机选择指定树量的元素并打印它们。每个元素最多打印一次。编写一个简单的程序测试函数。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define SIZE 500

void fillarray(int ar[], int n);
void printsome(int ar[], int n, int nwant);

int main(void)
{
	int ar[SIZE], nwant, count = 0;

	fillarray(ar, SIZE);
	system("color 5A");
	puts("Please enter the number of printing (q to quit):");
	while (scanf_s("%d", &nwant) == 1)
	{
		assert(nwant > 0);
		count = nwant < SIZE ? nwant : SIZE;
		printf("Here is the list of %d integer (no more than %d):\n", count, SIZE);
		printsome(ar, SIZE, nwant);
		puts("Next number:");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

void fillarray(int ar[], int n)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		ar[i] = rand();
	}
}

void printsome(int ar[], int n, int count)
{
	int * par;
	int i, j;

	//分配内存
	par = (int *)malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		//随机获取一个ar数组的元素写到par数组内
		par[i] = ar[rand() % n];
		//确保par内的该元素不重复
		j = 0;
		while (j < i)
		{
			if (par[i] == par[j])
			{
				par[i] = ar[rand() % n];
			}
			else
			{
				j++;
			}
		}
	}
	//打印par数组元素
	for (i = 0; i < count; i++)
	{
		printf("%-6d ", par[i]);
		if (i % 10 == 9)
		{
			putchar('\n');
		}
	}
	if (i % 10)
	{
		putchar('\n');
	}
	//释放内存
	free(par);
}