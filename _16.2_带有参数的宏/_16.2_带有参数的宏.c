#include <stdio.h>
#include <stdlib.h>

/*带有参数的类函数宏的使用注意：

	第一，对宏的主题使用必须的足够多的圆括号来保证以正确的顺序进行运算和结合。
	第二, 避免在宏的参数中使用增量减量运算符。（宏调用时看似只有一次的增量减量运算，但在实际的主体里也许有多次的增减运算）*/

#define SQUARE(X) X * X
	//系统把宏的主题当做语言符号类型的字符串，而不是字符型的字符串。C预处理器中的语言符号是宏定义主体中的单独的“词”。用空白字符把这些词分开。
	//所以上述的#define指令有3个语言符号：X、*和X。
#define SIX 2*3
	//该定义中有1个语言符号：即序列2*3。

/*重定义常量:

	ANSI标准只允许新定义与旧定义完全相同
	相同意味着主体拥有相同顺序的语言符号，因此，下面两个定义完全相同:*/
#define SIX 2 * 3
#define SIX 2	*	3
	//2者都有3个相同的语言符号，而且额外的空格不是主体的一部分。下面的定义被认为是不同的：
#define SIX 2*3
	//上式只有1个（而非3个）语言符号，因此与前两个定义不相同

#define PR(X) printf("The result is %d.\n", X)

int main(void)
{
	int x = 4;
	int z;

	system("color 5A");

	printf("Evaluating SQUARE(x): ");
	z = SQUARE(x);					//宏展开为z = x*x;
	PR(z);							//宏展开为printf("The result is %d.\n", z);

	printf("Evaluation SQUARE(2): ");
	z = SQUARE(2);					//宏展开为z = 2*2;
	PR(z);							//宏展开为printf("The result is %d.\n", z);

	printf("Evaluating 100 / SQUARE(2): ");
	PR(100 / SQUARE(2));			/*宏展开为printf("The result is %d.\n",100 / SQUARE(2));
									-> printf("The result is %d.\n",100 / 2*2);*/
	
	printf("Evaluating SQUARE(++x): ");
	PR(SQUARE(++x));				/*宏展开为printf("The result is %d.\n", SQUARE(++x));
									-> printf("The result is %d.\n", ++x*++x);
									从代码上看，x增加了一次*/
	getchar();
	printf("Evaluating incrementing, x is %x.\n", x);
									/*x起始值为4，终止值为6，增加了两次*/
	getchar();
	return 0;
}