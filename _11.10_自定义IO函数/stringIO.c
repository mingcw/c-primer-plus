
/*自定义字符串输出函数
  put1()
  函数功能：输出指定地址处的字符串，不追加换行符
*/

#include "stringIO.h"				/*自定义头文件用双引号加以区分C的头文件,提供函数声明和常量定义*/

void putl(const char * string)		/*打印一个字符串
									  不会修改字串内容
									  参数1为指向字符串的指针
									  使用const char * string 而不用const char string[]是因为：
									  虽然两者等价有效，但
									  方括号会提示程序员这个函数处理的是数组，
									  使用字符串形式，实际参数可以是数组名、引起来的字符串、或被声明为char * 类型的变量
									  使用const char * string可以提示：实际参数不一定是个数组*/
{
	while (*string)
	{
		putchar(*string++);
	}
}