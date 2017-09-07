
//间接运算符*（取值运算符）：由地址运算符获取指向数据对象的指针，由间接运算符获取该指针指向的数据对象

#include <stdio.h>

int main(void)
{
	int * ptr;		//声明一个名为ptr的指针，类型为"指向int的指针"类型，即ptr是一个指向整数变量的指针
	int A, B;
	B = 10;

	ptr = &B;	//给ptr指针赋值为B的地址，称“令ptr指向B”
	A = *ptr;	//给A赋值为被指针ptr指向的值B，这两句代码等价于A = B;

	printf("A = %d", A);

	getchar();
	return 0;
}