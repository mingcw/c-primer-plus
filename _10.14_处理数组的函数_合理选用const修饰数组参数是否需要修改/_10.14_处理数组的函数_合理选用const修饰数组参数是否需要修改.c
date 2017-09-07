#include <stdio.h>
#include <stdlib.h>

#define COLOR system("COLOR 4F")
#define SIZE 5

void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);

int main(void)
{
	COLOR;

	double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
	printf("The original dip array: \n");
	show_array(dip, SIZE);
	mult_array(dip, SIZE, 2.5);
	printf("The dip array after calling mult_array(): \n");
	show_array(dip, SIZE);

	getchar();
	return 0;
}

//显示数组内容
void show_array(const double ar[], int n)  /*不需要修改数组，最好用const修饰为常量（只读数组），
										   调试时一旦有指令试图修改数组内容，编译器就会生成一条错误信息，通知用户正在试图修改常量*/
{
	for (int i = 0; i < n; i++)
	{
		printf("%8.3f ", ar[i]);
	}
	putchar('\n');
}

/*用同一乘数去乘每个数组元素*/
void mult_array(double ar[], int n, double mult)	//需要修改数组内容，不可加const修饰
{
	for (int i = 0; i < n; i++)
	{
		ar[i] *= mult;
	}
}