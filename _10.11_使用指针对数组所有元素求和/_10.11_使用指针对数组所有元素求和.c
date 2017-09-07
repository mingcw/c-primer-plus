
//C保证在为数组分配空间的时候，指向数组之后的第一个位置也是合法的（可用作一种特殊的“越界”指针标志数组的结尾）

#include <stdio.h>

#define SIZE 10

int sum_ptr(int * start, int * end);

int main(void)
{
	int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;

	answer = sum_ptr(marbles, marbles + SIZE);		/*由于索引由0开始，所以marbles+SIZE指向数组结尾之后的下一个“元素”（C保证了这种“越界”指针的合法性）
													注意: 虽然C保证了指针marbles + SIZE的合法性，但对marbles[SIZE]不做任何保证*/
	printf("The total number of marbles is %ld.\n", answer);

	getchar();
	return 0;
}

//start指向数组首元素，end指向数组最后一个元素之后
int sum_ptr(int * start, int * end)
{
	int total = 0;

	while (start < end)
	{
		total += *start++;	/*即 *（start++），引用指针加加  （*和++优先级相等，但结合性从右向左）
							后缀形式表示把指针指向的数据加到total上，然后指针自增1*/
	}

	return total;
}