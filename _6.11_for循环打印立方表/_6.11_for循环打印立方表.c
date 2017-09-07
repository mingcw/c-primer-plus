#include <stdio.h>

int main(void)
{
	//打印1-5的立方值
	printf("    n n-cubed\n");
	for (int i = 0; i <= 6; i++)
	{
		printf("%5d %5d\n", i, i*i*i);
	}

	getchar();
	return 0;
}