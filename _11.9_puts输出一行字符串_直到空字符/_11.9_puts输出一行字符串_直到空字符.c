#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	/*调用字符串IO函数时，必须保证要打印的字符串是一个有效的C字符串（空字符结尾的标识）
	而不是一个字符数组，否则输出的字符串内容无法保证*/

	char side_a[] = "SIDE A";					//字符串
	char dont[] = { 'W', 'O', 'W', '!' };		//字符数组 -> 当作为字符串输出时，编译器会输出该字符数组的所有元素，在遇到第一个空字符时停止输出
	char side_b[] = "SIDE B";

	puts(dont);		//dont不是一个字符串

	getchar();
	return 0;
}