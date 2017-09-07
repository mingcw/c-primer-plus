#include <stdio.h>

int main(void)
{
	//整数除法与浮点数除法的不同点
	printf("integer division; 5/4 = %d\n", 5 / 4);//整数的运算结果只有整数，计算错误
	printf("float division; 5.0/4.0 = %f\n", 5.0 / 4.0);//浮点数的运算结果精确，计算正确
	
	printf("mixed division; 7./4 = %f\n", 7. / 4);/*混合类型,整数和浮点数运算时，结果为浮点数，计算正确.
												  实质上，计算机是不能计算整数除浮点数的，
												  编译器在编译的时候，会将两个操作数将转换为相同的类型
												  这里呢，是将整数转换为浮点数，所以最后运算正确*/
	getchar();
	return 0;
}