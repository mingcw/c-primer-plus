#include <stdio.h>

void pound(int n);	//ANSI风格的函数原型

int main(void)
{
	//调用自定义有参函数，如果参数类型与参量不匹配，会自动转换，也可以用指派运算符强制转换
	
	int times = 5;
	char ch = '!';	//ANCII值为33
	float fl = 6.0;
	
	pound(times);
	pound(ch);
	pound((int)fl);
	getchar();
	return 0;
}

//打印一定数量的“#”和一个换行符
void pound(int n)	
{
	while (n-- > 0)
	{
		printf("#");
	}
	printf("\n");
}