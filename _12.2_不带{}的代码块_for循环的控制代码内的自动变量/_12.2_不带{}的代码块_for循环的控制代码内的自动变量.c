#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	
	/*自动变量除非显式初始化，否则不会自动初始化（即可能是任意值）
	 1.显式初始化自动变量为常量值（）或常量表达式
		 int repid;							//自动变量没有显式初始化，所以repid值为先前分配给个的占用空间的任意值
		 int number = 1;					//自动变量显式初始化
	  
	 2.显式初始化自动变量为非常量表达式，但必须非常量表达式中包含的变量是已定义过的
		 int a = 110;
		 int b = 2 * a + 5;					//使用先前定义过的变量
	*/

	system("color 5A");

	auto int n = 10;						//初始n（显式初始化自动变量）
	
	printf("Initially, n = %d\n", n);
	for (int n = 1; n < 3; n++)				//索引n（覆盖初始n，作用域是for循环）
		printf("Loop 1: n = %d\n", n);
	printf("After loop 1, n = %d\n", n);	//初始n（for循环中的索引n销毁，初始n恢复作用）
	for (int n = 1; n < 3; n++)				//索引n（覆盖初始n，作用域是for循环）
	{
		printf("Loop 2 index n = %d\n", n);
		int n = 30;							//新建n（覆盖索引n，每次循环结束时销毁）
		printf("Loop 2: n = %d\n", n);
		n++;
	}										//新建n在每次循环结束时销毁
	printf("After loop 2, n = %d\n", n);	//初始n（for循环中的新建n、索引n销毁，初始n恢复作用）

	getchar();
	return 0;

	/*后记：

	  1.自动变量必须显式初始化为一个确定的值
	
	  2.寄存器变量：存储可以存储在CPU寄存器中，或，存在速度最快的可用内存中，可以给比普通玻璃更快地被访问或操作
					注意：无论“请求”寄存器变量成功与否，都无法获得寄存器变量的地址、不能使用地址运算符

					与自动变量具有相同的代码块作用域、空链接、自动存储时期

					使用register关键字“请求”寄存器变量。编译器必须在您的请求与可用的寄存器个数或者可用的高速内存之间做权衡。
														  所以，请求寄存器变量可能失败，降为自动变量；
					*/

	auto int number = 1;		//显式初始化一个普通的自动变量
	register int a;				//请求一个寄存器变量，可能失败将为普通自动变量,不能使用地址运算符
	

}