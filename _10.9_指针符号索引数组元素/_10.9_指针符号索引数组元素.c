#include <stdio.h>
#include <stdlib.h>
#define PAUSE system("pause")
#define COLOR system("color 0A")
#define MONTHS 12

int main(void)
{
	int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	COLOR;
	for (int i = 0; i < MONTHS; i++)
	{
		printf("Month %2d has %d days.\n", i + 1,
			*(days + i));  //*(days + i) = days[i] （理解不了看看源文件名，想想你的处境，2年的尝试，影响以后）
	}
	PAUSE;
	return 0;
}
/*现在开始，使用指针符号索引数组，直到完全熟悉，后，灵活“混用”*/