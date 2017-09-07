#include <stdio.h>
#include <stdlib.h>

#define MAX 81

int main(void)
{
	char name[MAX];
	char * ptr;

	system("color 0A");
	printf("Hi, what's your name?\n");
	ptr = fgets(name, MAX, stdin);		/*从标准输入流读取字符串到name数组，返回指向字符串的指针值
										注意： 这是从文件读取字符串的函数，所以：
										1.一般接受文件指针（这里接受键盘输入，文件指针改为标准输入流）
										2.因为读取文件内容，所以换行符同样读取
										（不同于从标准输入流获取字串的gets_s()(读取换行符之前的所有字串，将换行符读取丢弃)）*/
	printf("%s? Ah, %s!\n", name, ptr);

	system("pause");
	return 0;
}