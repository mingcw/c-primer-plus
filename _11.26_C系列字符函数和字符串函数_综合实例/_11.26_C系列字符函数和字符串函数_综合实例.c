#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 81

void ToUpper(char * str);
int CountPunct(const char * str);

int main(void)
{
	char line[SIZE];
	
	system("color 0A");
	puts("Enter a line:");
	gets_s(line, SIZE);
	ToUpper(line);
	puts(line);
	printf("That line has %d punctuation characters.\n",
		CountPunct(line));

	getchar();
	return 0;
}

//字符串转换到大写形式
void ToUpper(char * str)
{
	while (*str)					//如果指针指向非空字符
	{
		*str = toupper(*str);		//将指向的char字符转换为大写
		str++;
	}
}

//统计字符串的标点符号数
int CountPunct(const char * str)
{
	int count = 0;

	while (*str)
	{
		if (ispunct(*str))
			count++;
		str++;
	}

	return count;
}