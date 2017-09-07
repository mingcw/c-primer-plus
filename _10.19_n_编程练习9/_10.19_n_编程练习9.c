#include <stdio.h>
#include <stdlib.h>

#define COLOR system ("color 0A")
#define SIZE 5

void get_arr(float arr[], int size);
void add(float arr1[], float arr2[], float arr_added[], int size);
void show_arr(float arr[], int size);

int main(void)
{
	float arr1[SIZE], arr2[SIZE], arr_added[SIZE];

	COLOR;
	printf("array 1, enter %d numbers; \n", SIZE);
	get_arr(arr1,SIZE);
	printf("array 2, enter 5 numbers; \n", SIZE);
	get_arr(arr2, SIZE);

	add(arr1, arr2, arr_added, SIZE);

	printf("array1: \n");
	show_arr(arr1, SIZE);
	printf("\narray2: \n");
	show_arr(arr2, SIZE);
	printf("\nArray1 and array2 is: \n");
	show_arr(arr_added, SIZE);
	putchar('\n');

	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}

void get_arr(float arr[SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf_s("%f", &arr[i]);
	}
}

void add(float arr1[], float arr2[], float arr_added[], int size)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr_added[i] = arr1[i] + arr2[i];
	}
}

void show_arr(float arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%.1f ", arr[i]);
	}
}