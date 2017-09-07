#include <stdio.h>

int main(void)
{
	//在printf()中%*d，*指示字段宽度，可由用户指定要求的字段宽度，需要在格式化字符串后，像d一样提供一个参数指定字段宽度
	//在scanf()中%*d,*指示跳过后面的输入项目，此处跳过后面的一个有符号数
	unsigned  width, precision;//宽度，精度
	int number = 256;
	double weight = 242.5;

	printf("What filed weight?\n");
	scanf_s("%d", &width,6);
	printf("The number is: %*d: \n", width, number);
	printf("Now enter a width and a precision: \n");
	scanf_s("%d %d", &width, &precision,20);
	printf("Weight = %*.*f\n", width, precision, weight);

	getchar();
	getchar();
	return 0;
}