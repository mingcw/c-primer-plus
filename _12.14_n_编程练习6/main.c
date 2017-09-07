
//产生1000个1-10的随机数，记录报告这10个种子值出现的次数（不必打印随机数）
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define COUNT 1000

int main(void)
{
	int randnum;							//随机数
	int rec[SIZE] = { 0 };					//记录1-10每个随机数出现的次数的记录数组

	system("color 5A");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < COUNT; i++)
	{
		randnum = rand() % SIZE + 1;
		rec[randnum - 1]++;					//该随机数对应的记录+1
	}
	printf("Here are random-number and there count:\n");
	puts("    x   t");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%5d%5d\n", i + 1, rec[i]);
	}

	getchar();
	return 0;
}