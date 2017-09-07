#include <stdio.h>

void interchange(int * u, int * v);

int main(void)
{
	int x = 5, y = 10;

	printf("Originally x = %d and y = %d\n", x, y);
	interchange(&x, &y);	//函数传递x和y的地址 -> 函数声明和定义中的形参u,v将使用地址作为它们的值，因此，它们被声明为指针，通过该指针访问该变量
	printf("Now x = %d and y = %d\n", x, y);

	getchar();
	return 0;
}

void interchange(int * u, int * v)	//访问指针指向的变量，然后进行数据的交换
{
	int temp;	//提供临时变量

	temp = *u;		//temp得到u指向的值，temp = x
	*u = *v;		//v指向的值赋给u指向的值,x = y
	*v = temp;		//u指向的值赋给v指向的值,y = temp
	/*注意：间接运算符通过内存地址，间接得到数值
	 间接运算符间接操作数值实现数值的交换，漏掉会导致内存地址参与交换*/
}