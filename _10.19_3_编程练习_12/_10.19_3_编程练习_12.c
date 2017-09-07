#include<stdio.h>
#include<stdlib.h>

#define COLOR system("COLOR 0A")
#define ROWS 3
#define COLS 5
#define AMOUNT ROWS*COLS

void get_arr2d(double arr[][COLS], int rows);					//获取二维数组
void show_per_row_average(double arr[][COLS], int rows);		//打印二维数组的每一行的平均值
double get_row_average(double arr[], int cols);					//计算二维数组的一行的平均值
double get_all_row_average(double arr[][COLS], int rows);		//计算二维数组所有元素的平均值

int main(void)
{
	double arr[ROWS][COLS], average;
	
	COLOR;
	get_arr2d(arr, ROWS);
	show_per_row_average(arr, ROWS);
	average = get_all_row_average(arr, ROWS);
	printf("Average of the %d numbers: %.1lf\n", AMOUNT, average);

	getchar();
	getchar();
	getchar();
	return 0;
}

//获取二维数组
void get_arr2d(double arr[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		printf("Enter line %d with %d number: ", i + 1, COLS);
		for (int j = 0; j < COLS; j++)
		{
			scanf_s("%lf", &arr[i][j]);
		}
	}
}

//打印二维数组的每一行的平均值
void show_per_row_average(double arr[][COLS], int rows)
{
	double row_average;

	for (int i = 0; i < rows; i++)
	{
		row_average = get_row_average(arr[i], COLS);
		printf("Average of line %d: %.1lf\n", i + 1, row_average);
	}
}

//计算二维数组的一行的平均值
double get_row_average(double arr[], int cols)
{
	double retn = 0;

	for (int i = 0; i < cols; i++)
	{
		retn += arr[i];
	}
	retn /= cols;

	return retn;
}

//计算二维数组所有元素的平均值
double get_all_row_average(double arr[][COLS], int rows)
{
	double total = 0.0, average;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			total += arr[i][j];
		}
	}
	average = total / AMOUNT;

	return average;
}