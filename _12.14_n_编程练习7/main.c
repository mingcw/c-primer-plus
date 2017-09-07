
//_12.13_的新版本，掷n个骰子，总共掷m次，报告每次掷得的点数之和

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dicedie(int dice, int sides, int dieamount);

int main(int argc, char * argv[])
{
	int dice;											//掷的次数
	int sides;											//骰子面数
	int dieamount;										//骰子个数

	system("color 5A");
	srand((unsigned int)time(NULL));					//初始化种子
	puts("Enter the number of sets: q to stop");
	while (scanf_s("%d", &dice, 10))
	{
		puts("How many sides and how many dice?");
		scanf_s("%d %d", &sides, &dieamount, 10);
		dicedie(dice, sides, dieamount);
		puts("Enter the number of sets: q to stop");
	}
	puts("Done!");

	system("pause");
	return 0;
}

void dicedie(int dice, int sides, int dieamount)
{
	int roll = 0;										//每次掷的点数之和
	int i, j;

	printf("Here are %d sets of %d %d-sided throws.\n", dice, dieamount, sides);
	for (i = 0; i < dice; i++)							//掷dice次
	{
		for (j = 0, roll = 0; j < dieamount; j++)		//每次掷dieamount个
		{
			roll += rand() % sides + 1;
		}
		printf("%3d", roll);
		if (i % 15 == 14)
		{
			putchar('\n');
		}
	}
	if (i % 15 != 0)
	{
		putchar('\n');
	}
}