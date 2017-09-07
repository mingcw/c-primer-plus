#include <stdio.h>

//方法1
#define PI 3.1415926  
#define BEEP '\a'//转义字符
#define TEE 'T'
#define ESC '\033'//转义字符
#define OOPS "Now you have done it!"

int main(void)
{
	float circum, area, radius;
	
	//方法2
	const int A = 99;  

	printf("What is the radius of your pizza?\n");

	scanf_s("%f",&radius,6);

	circum = 2 * PI * radius;
	area = PI * radius * radius ;

	printf("Your basic pizza parameters are as follows:\n");

	printf("circumference = %.2f,area = %.2f\n\n", circum, area);


	printf("......包括转义字符的常量打印输出:\n");

	printf("%f\n", PI);

	printf("%c\n", BEEP);

	printf("%c\n", TEE);

	printf("%c\n", ESC);

	printf("%s\n", OOPS);

	printf("%d\n", A);



	getchar();
	getchar();
	return 0;

}