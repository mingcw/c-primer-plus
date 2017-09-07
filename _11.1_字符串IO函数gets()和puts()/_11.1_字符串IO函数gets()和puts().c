#include <stdio.h>
#include <stdlib.h>
		//字符串常量属于静态存储类，在程序运行的过程中，该字符串只存储一份
#define MSG "You must have many talents.Tell me some! "			//定义字符串，法1：字符串常量(位于一对双引号内的任何字符由编译器追加结尾标志空字符，作为字符串保存到内存空间)																

#define LIM 5
#define LINELEN 81												/*最大字符串长度 + 1*/

int main(void)
{
	char name[LINELEN];											//定义字符串，法2：char数组
	char talents[LINELEN];	

	//初始化一个大小确定的char数组, 比标准数组初始化相对简短:
	const char m1[40] = "Limit yourself to one line's worth.";		//初始化字符串时，必须保证字符数组的长度至少比字符串大1（用来容纳空字符'\0'）,字符数组内剩余的元素空间被空字符'\0'填充
	
	/*const char m1[40] = {		//标准数组初始化,注意：标准初始化字符串必须带有字符串的终止符'\0'，否则只是一个字符数组
	'L', 'i', 'm', 'i', 't', ' ',
	'y', 'o', 'u', 'r', 's', 'e', 'l', 'f', ' ',
	't', 'o', ' ',
	'o', 'n', 'e', ' ',
	'l', 'i', 'n', 'e', '\'', 's', ' ',
	'w', 'o', 'r', 't', 'h', '.','\0'
	};*/

	//让编译器计算数组大小
	const char m2[] = "If you can't think of anything, fake it. ";
	
	//初始化一个指针
	const char * m3 = "\nEnough about me - what's your name?";	//定义字符串，法3：char指针指向首字符，指针可以执行自增运算指向下一个字符，字符串位于PE文件的资源块里
	
	//初始化一个字符串指针的数组								
	const char * mytal[LIM] = {									//定义字符串，法4：字符串指针数组， 
		"Adding numbers swiftly",
		"Multiplying accurately", 
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language" 
	};

	system("color 0A");
	printf("Hi! I'm Clyde the Computer. "                      "I have many talents.\n");	//如果字符串文字中间没有间隔或间隔的是空格符，ANSI C会将它们串联起来

	printf("Let me tell you some of them.\n");
	puts("What were they? Ah, yes, here's a partial list.");	//字符串输出函数
	for (int i = 0; i < LIM; i++)
	{
		puts(mytal[i]);				/*打印计算机功能的列表*/
	}
	puts(m3);
	gets_s(name, LINELEN);										//字符串获取函数，从第一个字符到第一个换行符之间的所有字符全部读入到name，读取81个字节
	printf("Well, %s, %s\n", name, MSG);
	printf("%s\n%s\n", m1, m2);
	gets_s(talents, LINELEN);
	puts("Let's see if I've got that list: ");
	puts(talents);
	printf("Thanks for the information, %s\n", name);

	system("pause");
	return 0;
}