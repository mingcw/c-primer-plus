#include <stdio.h>
#include <stdlib.h>

#define COLOR system("color 0A")
#define SIZE 10

int sum_arr_argc(int arr[], int n);
int sum_pointer_argc(int * ptr, int n);

int main(void)
{
	//对一个数组的所有元素求和

	int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer1, answer2;

	COLOR;
	answer1 = sum_arr_argc(marbles, SIZE);
	answer2 = sum_pointer_argc(marbles, SIZE);
	printf("The total number of marbles is %ld.\n", answer1);
	printf("The total number of marbles is %ld.\n", answer2);
	printf("The size of arr is %u bytes.\n", sizeof marbles);

	getchar();
	return 0;
}

//参数一，数组名，参数二，数组大小
int sum_arr_argc(int arr[], int n)			//用数组符号索引数组元素，对数组元素求和
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];
	printf("The size of array is %u bytes.\n", sizeof arr);

	return sum;
}

int sum_pointer_argc(int * ptr, int n)		//用指针符号索引数组元素，对数组元素求和
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += *(ptr + i);					//即sum += arr[i]

	return sum;
}