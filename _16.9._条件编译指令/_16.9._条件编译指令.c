//ifdef.c--使用条件编译指令(#indef、#else、#endif、#elif）

/*
	已定义与未定义：

	C预处理器在预处理指令中遇到的标识符，要么把该标识符当做已定义的，要么当做未定义的。

	这里的已定义表示由预处理器定义。如果该标识符是文件前面的#define创建的宏名，并且没有被#undef取消定义，那么该标识符就是已定义的。
	如果标识符不是宏，而是（例如）一个具有文件作用域的C变量，那么预处理器把该标识符当作未定义的。*/

#include <stdio.h>
#include <stdlib.h>

#define JUST_CHECKING					//空宏
#define LIMIT 4

int main(void)
{
	int total = 0;

	system("color 0A");

	for (int i = 1; i < LIMIT; i++)
	{
		total += 2 * i*i + 1;
#ifdef JUST_CHECKING												/*如果JUST_CHECKING是已定义的，则执行#ifdef和endif之间的代码
																	  #ifdef #else 类似于C中的if else。主要差异是预处理器不能识别标记代码块的花括号{}，因此使用#else（如果需要）和#endif（必须存在）来标记指令块或者C的语句块*/
		printf("i = %d, running total = %d.\n", i, total);
#endif // JUST_CHECKING
	}
/*
	如果略去JUST_CHECKING的定义（或把它置于C注释中，或用#undef指令取消它的定义）并重新编译程序，那么将会只显示最后一行。
    可以使用这种方法辅助调试程序。
	定义JUST_CHECKING并合理使用#ifdef，使编译器包含哪些用于打印辅助调试的中间值的程序代码。程序正常工作后，可以伤处定义并重新编译。
	如果以后还需要使用这些信息，可以重新插入定义，从而避免再次输入额外的打印语句。
	另外一种应用是，使用#ifdef指令选择使用与不同C实现的大块代码。*/

	printf("Grand total = %d\n", total);

	getchar();
	return 0;
}