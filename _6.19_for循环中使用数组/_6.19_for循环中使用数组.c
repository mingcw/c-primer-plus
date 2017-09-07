#include <stdio.h>
#define SIZE 10		//10个分数
#define PAR 72		//标准分

int main(void)
{
	//读入10个高尔夫分数，计算出和，平均分，差值（平均分与标准值的差）
	int score[SIZE];
	int sum = 0;
	float average;

	printf("Please enter %d golf scores: \n", SIZE);
	for (int i = 0; i < SIZE; i++)
		scanf_s("%d", &score[i]);		//读取10个分数
	printf("The scores read in are as follows: \n");
	for (int i = 0; i < SIZE; i++)
		printf("%d,", score[i]);		//验证输入
	printf("\b \n");
	for (int i = 0; i < SIZE; i++)
		sum += score[i];				//求和
	average = (float)sum / SIZE;
	printf("The sum of scores: %d, average = %.2f\n", sum, average);
	printf("That's a handicap of %.2f", average - PAR);

	getchar();
	getchar();
	return 0;

}