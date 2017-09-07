#include <stdio.h>
#include <iso646.h>		//提供了逻辑运算符和位运算符的字符拼写形式

int main(void)
{
	int num = 1;
	int xorValue;

	/*if (num != 2 && num != 3)
	{
		xorValue = num ^ num;			
		printf("%d xor %d = %d", num, num, xorValue);
	}
	*/

	//以上语句等价于：
	if (num != 2 and num != 3)
	{
		xorValue = num xor num;			//1和1异或为0
		printf("%d xor %d = %d", num, num, xorValue);
	}

	getchar();
	return 0;

}