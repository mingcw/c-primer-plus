
//自定义字符串IO的声明

#define MSG "CHANGE THE WORLD BY PROGRAMING!"

/*打印一个字符串
参数1为指向字符串的指针
使用const char * string 而不用const char string[]是因为：
虽然两者等价有效，但
方括号会提示程序员这个函数处理的是数组，
使用字符串形式，实际参数可以是数组名、引起来的而字符串、或被声明为char * 类型的变量
使用const char * string可以提示：实际参数不一定是个数组*/
void putl(const char * string);		
