/*
	C有5种存储类，决定了使用哪种存储类之后，就自动决定了作用域和存储时期。
	该变量将服从预先定制的内存管理机制。而另一个灵活选择：
	
	使用标准库函数来分配和管理内存
	
	变量在声明时，程序运行时必须为变量留有足够的内存来存储它们的数据，一些内存分配是自动完成的：
	float x;								//系统将分配足够float变量的内存存储数据,同时也给出了这个内存的标识符（可以用place来标识数据）
	char place[] = "Dancing Oxen Creak";	//系统分配足够的内存空间保存字符串
	int place[100];							//系统将留出100个int的内存位置，同时也给出了这个内存的标识符（可以用place来标识数据）
	
	而在C程序运行时，也可以分配更多的内存，工具函数是标准库函数malloc()
	
	malloc()接受一个参数：所需内存的字节数
			返回指向该匿名内存（分配了内存，但没有为他起名字）的通用指针（C99以前返回char指针），分配失败时返回空指针
		    所以在调用函数时，应该将返回的指针类型指派为适当的类型
													  （优点：1.程序更加清晰，2.移植到C++时更容易 < C中可选，C++中必须 > ）
	所以，创建一个数组：

	1.常量表达式声明普通数组，						 数组名访问数组元素
	2.变量表达式声明VLA，							 数组名访问数组元素
	3.声明一个指针，调用malloc()分配内存，			 用指针访问数组元素
	
	方法2和3的好处在于，可以创建一个动态数组（dynamic array），在程序运行时，根据需要改变数组大小，例如：
	C99之前，不允许VLA：						int x[n];									//n是一个变量
	但是，动态分配内存，却是可行的：			int * pt = (int *)malloc(n * sizeof(int))	//n是一个变量，这比VLA更灵活，可以使程序适应不同的情形
	
	一般地，对应每个malloc()调用，应该调用一次free()
	mallod()分配的内存块使得内存数量增加（不同于自动变量），通过调用free()释放mallod()分配的内存，
	尤其在一个复杂的程序里，这是很必要的，可以使2者管理的内存池被多次使用，也可以防止内存泄露*/

/*
	第二个内存分配函数calloc()和特性
	语法：void * calloc(_In_ _CRT_GUARDOVERFLOW size_t _Count, _In_ _CRT_GUARDOVERFLOW size_t _Size)
	参数一指定所需的内存单元数，参数二指定内存单元的大小
	返回指向内存块的通用指针
	特性：calloc()分配的内存块，会将块内的全部位都置0（但在某些硬件系统上，浮点数0并不是全部0位表示的）
	释放：也可以调用free()释放被calloc()分配的内存*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	double * ptd;												//指向动态数组首元素的指针
	int max;													//用户输入的动态数组的大小
	int number;													//用户输入的数组元素数目
	int i = 0;

	system("color 5A");
	puts("What is the maximum of type double entries?");
	scanf_s("%d", &max, 10);
	ptd = (double *)malloc(max * sizeof(double));				//为动态数组分配内存
	if (ptd == NULL)
	{
		puts("Memory allocated failed!");
		exit(EXIT_FAILURE);
	}
	//ptd指向有max个double值的数组首元素
	puts("Enter the double values (q to quit):");
	while (i < max && scanf_s("%lf", &ptd[i]) == 1)
	{
		++i;
	}
	printf("Here are your entered values:\n", number = i);
	for (i = 0; i < number; i++)
	{
		printf("%7.2f", ptd[i]);
		if (i % 7 == 6)
		{
			putchar('\n');
		}
	}
	if (i % 7 != 0)
	{
		putchar('\n');
	}
	puts("Done!");
	free(ptd);													//释放内存，管理内存池
	
	system("pause");
	return 0;
}