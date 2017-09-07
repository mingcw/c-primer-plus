#include <stdio.h>
#include <stdlib.h>

void trystat();

int main(void)
{
	/*实例_5大存储类之具有空链接的静态存储类
	（有些地方也称该存储类为内部静态存储类，内部指函数内部，不是内部链接）*/

	/*静态变量：
				1.只在编译时初始化一次（静态变量和外部变量在程序加载到内存时已经就位，并非执行时的语句）
				2.静态变量具有代码块作用域时，只对包含该代码块的函数可见
				3.静态变量只声明而不赋值时，将被编译器初始化为0（区别于普通的自动变量必须初始化一个确定值）
				4.不允许对函数参量使用static（静态参量），例如：
																void trystat(static int x);	`		//警告：warning C4042: “x”: 有坏的存储类*/

	int count;

	system("color 5A");
	for (count = 1; count <= 3; count++)
	{
		printf("Here comes interation %d : \n", count);
		trystat();
	}

	getchar();
	return 0;
}

void trystat(void)
{
	int fade = 1;
	/*单步调试：
				发现：该语句属于该函数的一部分；
					  每次调用函数trystat（）时，都被执行
				所以：fade变量会被多次初始化
	*/

	static int stay;	//静态变量默认为0
	/*具有代码块作用域的静态变量，只在编译时被初始化一次。注意：如果不显式地对静态变量初始化，它将被初始化为0（区别于自动变量）
	 单步调试：
				发现：该语句不是函数trystat（）的一部分；
					  每次调用函数trystat（）时，都被跳过
				所以：stay变量在编译时已经初始化，后期不再初始化；放在该函数内，表明它只对该函数可见（具有空链接的静态存储类变量）
	*/

	printf("fade = %d and stay = %d\n", fade, stay++);	//静态变量可以不初始化，默认值为0
}

//下面占用资源，继续说说外部变量的初始化：
//int silent;						//可以，默认为0
//int x = 10;						//可以
//int y = 4 + 12;					//可以
//size_t t = sizeof (int);			//可以（只要类型不是VLA，sizeof表达式就认为是一个常量表达式）
//int z = 3 * x;					//不可以，必须是常量表达式
/*总结： 外部变量可以不初始化，默认为0；或者 只能初始化为常量表达式，不能含有其他变量*/