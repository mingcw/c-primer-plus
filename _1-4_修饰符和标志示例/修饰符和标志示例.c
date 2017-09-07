#include <stdio.h>

#define PAGES 931
#define FLT 9.12345

int main(void)
{
	printf("*%d*\n\n", PAGES);
	printf("*%2d*\n\n", PAGES);    	//打印长度最短为2
	printf("*%10d*\n\n", PAGES);   	//打印长度最短为10，最高位用空格填充
	printf("*%010d*\n\n", PAGES);  	//打印长度最短为10，最高位用0填充
	printf("*%-10d*\n\n", PAGES);  	//打印长度最短为10，数字左对齐
	printf("*%+10d*\n\n\n", PAGES);	//打印长度最短为10，带正负号
	printf("*%6.4f*\n\n", FLT);	//打印长度最短为 6，精确到小数点后4位
	
	getchar();
	return 0;
}