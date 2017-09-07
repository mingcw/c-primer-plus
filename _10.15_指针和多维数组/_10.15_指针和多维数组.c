#include <stdio.h>
#include <stdlib.h>

#define COLOR system("Color 4F")

int main(void)
{
	COLOR;

	int zippo[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };

	printf("   zippo = %p,    zippo + 1 = %p\n", zippo, zippo + 1);		// zippo：数组首元素{2，4}的地址
																		// zippo+1：第1个元素{6，8}的地址	（zippo值增加1表示增加一个对象大小即增加8）
	
	printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);// zippo[0]：数组{2，4}首元素的地址，即2的地址 ……………………………………语句1
																		// zippo[0]+1：数组{2，4}中4的地址  （zippo[0]值增加1表示增加一个对象大小即增加4）
	
	printf("  *zippo = %p,   *zippo + 1 = %p\n", *zippo, *zippo + 1);	// *zippo：取值为数组{2，4}首元素2的地址  ……………………………………………语句2
																		// *zippo+1: 取值为数组{2，4}中4的地址
	//语句1和语句2打印的值是相同的

	printf("  zippo[0][0] = %d\n", zippo[0][0]);	//打印2
	printf("    *zippo[0] = %d\n", *zippo[0]);		//打印2
	printf("      **zippo = %d\n", **zippo);		//打印2

	printf("  zippo[2][1] = %d\n", zippo[2][1]);	//打印3

	printf("*(*(zippo+2)) = %d\n", *(*(zippo + 2)));//打印1

	getchar();
	return 0;
}