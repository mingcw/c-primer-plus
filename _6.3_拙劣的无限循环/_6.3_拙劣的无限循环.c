#include <stdio.h>

int main(void)
{
	/*注意：循环体内是复合语句时加花括号
	本代码造成无限循环*/

	int a = 3;

	while (a < 5)
		printf("n is %d\n", a);
	a++;
	printf("This is all this program does.\n");
	getchar();
	return 0;
}