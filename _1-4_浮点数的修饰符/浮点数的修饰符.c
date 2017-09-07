#include <stdio.h>

int main(void)
{
	const double RENT = 3852.99;

	printf("*%f*\n\n", RENT);
	printf("*%e*\n\n", RENT);	//按照e-计数法打印浮点数
	printf("*%4.2f*\n\n", RENT);//打印4字节长，精确2位小数，如果要打印数字宽度超出，会自动扩充到数字宽度，即最短为4字节长，精确2位小数
	printf("*%3.1f*\n\n", RENT);//打印长度最短为3字节，精确1位小数
	printf("*%10.3f*\n\n", RENT);//打印长度最短为10字节，精确3位小数，最高位用空格填充
	printf("*%010.3f*\n\n", RENT);//打印长度最短为10字节，精确3位小数，最高位用0填充
	printf("*%-10.3f*\n\n", RENT);//数字左对齐
	printf("*%+10.3f*\n\n", RENT);//显示正负号

	getchar();
	return 0;
}