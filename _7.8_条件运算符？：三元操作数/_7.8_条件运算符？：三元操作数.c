#include <stdio.h>

#define COVETRAGE 200 /*每罐漆可喷的平方英尺数*/

int main(void)
{
	/*条件运算符操作的条件表达式 expression1 ? expression2 : expression3;
								如果expression1为真，整个条件表达式的值为expression2，否则为expression3*/
	//计算向给定的平方英尺的面积涂油漆，全部涂完需多少罐油漆.数学法则：用平方英尺数除每罐可涂的平方英尺数。当结果非整数时，应该进1(如1.2取2)

	int sq_feet;
	int cans;

	printf("Enter number of square feet to be painted(q to quit):\n");
	while (scanf_s("%d",&sq_feet) == 1)
	{
		cans = sq_feet / COVETRAGE;
		cans += (sq_feet % COVETRAGE == 0) ? 0 : 1;
		printf("You need %d %s of paint.\n", cans,
			(cans == 1) ? "can" : "cans");
		printf("Please enter next number of square feet to be painted(q to quit):\n");
	}
	
	return 0;
}