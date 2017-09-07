//以多种方式初始化一个字符A
#include <stdio.h>

int main(void)
{
	char ch_1 = 'A';		
	char ch_2 = 65;		 //A的十进制ASCII码
	char ch_3 = '\101';  //A的八进制ASCII码
	char ch_4 = '\x41';  //A的十六进制ASCII码
	char ch_5 = '\X41';  //c(10): warning C4129: “pX”: 不可识别的字符转义序列;c(10): warning C4305: “初始化”: 从“int”到“char”截断
	char ch_6 = '女';	 //c(11): warning C4305: “初始化”: 从“int”到“char”截断

	printf("%c\n", ch_1);  //A
	printf("%c\n", ch_2);  //A
	printf("%c\n", ch_3);  //A
	printf("%c\n", ch_4);  //A
	printf("%c\n", ch_5);  //1
	printf("%c\n", ch_6);  //?
	
	getchar();
	return 0;

}