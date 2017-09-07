#include <stdio.h>

int main(void)
{
	/*打印长字符串
	1.使用多个printf()
	2.*/
	printf("Here's one way to print a ");//告诉编译器打印字符串（前半段）
	printf("long string.\n");//告诉编译器在当前光标处继续打印字符串（后半段）（“Here's another way to print a long string”）
	printf("Here's another way to print a \
					long string.\n");//\告诉编译器打印字符串时，忽略\后的整行空字符，从第二行最左边继续打印（“Here's another way to print a 		   long string”）
	printf("Here's another way to print a \
long string.\n");//\换行告诉编译器打印字符串时，忽略\后的整行空字符，从第二行最左边继续打印（“Here's another way to print a long string”）
	printf("Here's the newest way to print a "
		"long string.\n");//ANSI C风格，最新的一种打印长字符串的方法，""告诉编译器打印字符串时，将两串字符串连接起来（“Here's another way to print a long string”）
	
	getchar();
	return 0;
}