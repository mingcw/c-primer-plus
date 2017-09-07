#include <stdio.h>

int main(void)
{
	/*for(initilize;test;update)每个表达式语句可以由逗号隔开的多个表达式组成
	 for(expression1, espression2, ...; varible < length; expression1, espression2, ...)*/

	const int FIRST_OZ = 37;
	const int NEXT_OZ = 23;
	int ounces, cost;

	printf("ounces cost\n");
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
	{
		printf("%5d %4.2f\n", ounces, (float)cost / 100.0);
	}
	getchar();
	return 0;
}