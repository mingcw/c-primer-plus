#include <stdio.h>  //包含stdio头文件(standard input and output)标准输入输出头文件
void butler(void);  //声明自定义函数
int main(void)
{
	printf("I will summon the butler function.\n");
	butler();
	printf("Yes.Bring me some tea and writeable CD-ROMs.\n");
	getchar();
	return 0;

}

void butler(void)	//butler函数定义的开始(函数头)，"{}"内为函数体
{
	printf("You rang, sir?\n");
}