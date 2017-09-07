
#include <stdio.h>
#include "stringIO.h"

int main(void)
{
	/*结合多文件的编译调试：

	在单独的源文件里自定义字符串IO函数，

	在自定义头文件里提供函数声明和一些已定义的常量
	
	在主源代码文件里编写驱动程序测试函数实现
	*/

	putl(MSG);

	getchar();
	return 0;
}