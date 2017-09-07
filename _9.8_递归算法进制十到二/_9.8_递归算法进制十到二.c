#include <stdio.h>

void to_binary(unsigned long dec);
void to_octonary(unsigned long dec);
void to_hexadecimal(unsigned long dec);

int main(void)
{
	unsigned long dec;

	printf("Enter an integer (q to quit): \n");
	while (scanf_s("%ul", &dec) == 1)
	{
		printf("Binary equivalent: ");
		to_binary(dec);
		printf("\nOctonary equivalent: ");
		to_octonary(dec);
		printf("\nEnter an integer (q to quit): \n");
	}
	printf("Done!\n");

	return 0;

}

void to_binary(unsigned long dec)
{
	unsigned long result = dec % 2;		//对2求余

	if (dec >= 2)
		to_binary(dec / 2);				//如果被除数大于2，继续调用，对2求余
	putchar(result ? '1' : '0');		//打印余数（因为在递归语句之后，所以在最后一级调用完毕才开始打印最后一个数字1或0，然后逐级返回，打印倒数第2个，倒数第3个，......，第1个，实现了除2取余，倒序写出的算法，得到2进制数）
}

void to_octonary(unsigned long dec)
{
	unsigned long result = dec % 8;

	if (dec >= 8)
		to_octonary(dec / 8);
	printf("%u", result);		
}