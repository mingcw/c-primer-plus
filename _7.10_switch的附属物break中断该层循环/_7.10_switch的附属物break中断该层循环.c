#include <stdio.h>

int main(void)
{
	//读入长方形的长和宽，输入非数字时，退出循环
	float length, width;

	printf("Please enter the length of the rectangle:\n");
	while (scanf_s("%f", &length) == 1)
	{
		printf("Length = %.2f\n", length);
		printf("Please enter the width:\n");
		if (scanf_s("%f", &width) != 1)
		{
			break;
		}
		printf("Width = %.2f\n",width);
		printf("Area = %.2f\n", length * width);
		printf("Please enter the next lenth of the rectangle:\n");
	}
	printf("Done!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}