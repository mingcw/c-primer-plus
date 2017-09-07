#include <stdio.h>

int main(void)
{
	//输入一些高尔夫分数，报告平均分

	const float MIN = 0.0f;
	const float MAX = 100.0f;

	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;

	printf("Please enter the first score (q to quit):\n");
	while (scanf_s("%f",&score) == 1)
	{
		if (score < MIN || score > MAX)
		{
			printf("%.1f is an invalid value.\n", score);
			continue;
		}
		printf("Accepting the value!\n");
		min = (score < min) ? score : min;
		max = (score > max) ? score : max;
		total += score;
		n++;
		printf("Please enter next score (q to quit):\n");
	}
	if (n > 0)
	{
		printf("Average of %d scores is %0.1f\n", n, total / n);
		printf("Low = %0.1f, high = %0.1f\n", min, max);
	}
	else
	{
		printf("No valid scores were entered!\n");
	}
	
	getchar();
	getchar();
	getchar();
	return 0;
}