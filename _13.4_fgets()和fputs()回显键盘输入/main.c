/*
	fgets():从文件指针指向的流获取一行字符串，返回指向字符串的指针
	细解：
		读取到第一个换行符的后面（换行符也读取），
		或者，读取比字符串的最大长度少1个的字符
		或者，读取到文件结尾
	返回指向字符串的指针，失败或到文件尾返回NULL，feof()/ferror()检查是否由于错误终止读取
	
	注意：fgets()可以读取换行符，fputs()不会追加换行符*/



#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 5

int main(void)
{
	char line[MAXLINE];

	system("color 0A");
	while (fgets(line, MAXLINE, stdin) != NULL && line[0] != '\n')		/*运行发现，当输入等于或超过MAXLINE-1个字符时，程序正常进行
																		  因为fgets()至多读取最大长度-1个字符（也可以读取换行符），
																		  比如，当输入“mingc”时，回车确定。
																		  第一次，fgets()读取5 -1 = 4个字符“ming”保存到line（最后一个位置由函数添加空字符标志字符串），fputs()输出4个字符,显示“ming”（没有换行符）
																		  回到循环首，继续读取第二次，fgets()在上一次读取的位置继续读取2个字符“c\n” 保存到line（最后一个位置由函数添加空字符标志字符串），fputs()在同一行继续输出2个字符，显示“mingc\n”（有换行符），光标移到下一行
																		  回到循环首，再次读取，直到扫描输入的字符串第0个为换行符，退出循环
																		  */
	{
		fputs(line, stdout);
	}

	system("pause");
	return 0;
}