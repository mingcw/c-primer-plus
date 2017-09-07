#include <stdio.h>
#include <stdlib.h>

#define COLOR system("color 0A")
#define ROWS 3
#define COLS 5

void show_array(const int arr[][COLS], int rows);
void double_array(int arr[][COLS], int rows);

int main(void)
{
	int arr[ROWS][COLS] = {
		{11,12,13,14,15},
		{21,22,23,24,25},
		{31,32,33,34,35}
	};

	COLOR;
	printf("Original array: \n");
	show_array(arr, ROWS);
	double_array(arr, ROWS);
	printf("Doubled array: \n");
	show_array(arr, ROWS);

	getchar();
	return 0;

}

void show_array(const int arr[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%3d", arr[i][j]);
		}
		putchar('\n');
	}
}

void double_array(int arr[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] *= 2;
		}
	}
}