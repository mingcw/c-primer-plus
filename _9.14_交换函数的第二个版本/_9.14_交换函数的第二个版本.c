
/*交换函数的第二个版本，错误版本参看_9.13*/

#include <stdio.h>

void interchange(int u, int v);

int main(void)
{
	int x = 5, y = 10;

	printf("Originally x = %d and y = %d\n", x, y);
	interchange(x, y);
	printf("Now x = %d and y = %d\n", x, y);

	getchar();
	return 0;
}

void interchange(int u, int v)
{
	int temp;

	printf("Originally x = %d and y = %d\n", u, v);
	temp = u;
	u = v;
	v = temp;
	printf("Now x = %d and y = %d\n", u, v);

}