#include <stdio.h>
#include <stdlib.h>		//标准库头文件

int main(void)
{
	/*自动存储类的变量, 具有自动存储时期 <进入定义x的main代码块时，为变量x分配内存，离开时释放x占用的内存>、
						代码块作用域 <x的定义处到包含x定义的代码块的末尾变量x均可见>、和
						空链接 <变量x为代码块私有变量，不允许其他文件或函数访问，对其他文件或函数不可见>
	
	默认情况下，在代码块或函数头定义的变量都属于自动存储类，

	可在前面加存储类说明符关键字atuo加以清晰化该类自动变量
	
	同时，自动变量如果不显示声明，那么它的值是任意的*/

	system("color 5E");

	auto int x = 30;								//初始化自动存储类变量x
	printf("x in outer block: %d\n", x);
	{
		auto int x = 70;							//新的x，覆盖第一个
		printf("x in inner block: %d\n", x);
	}												//该代码块内的x释放内存
	printf("x in outer block: %d\n", x);			//第一个x恢复作用

	while (x++ < 33)								//第一个x
	{
		auto int x = 100;							//新的x，覆盖第一个（随着循环的每一次迭代，该自动变量均要创建和销毁一次）
		x++;
		printf("x in while loop: %d\n", x);	
	}												//该代码块内的x释放内存
	printf("x in outer block: %d\n", x);

	getchar();
	return 0;
}

