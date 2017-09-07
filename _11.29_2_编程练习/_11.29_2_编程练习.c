#include <stdio.h>		//标准I/O头文件
#include <string.h>		//字符串处理函数
#include <stdlib.h>		//标准库头文件（atoi, atol, atof, strtol, strtoul, strtod, ...）
#include <ctype.h>		//C系列字符处理
#include <stdbool.h>	//兼容C++，标准布尔头文件

#define ANSWER "GRANT"
#define MAX 81
#define LIM 10

char * pr(char * str);
int readintput(char * str);
void readword(char * str);
int _strlen(const char * str);
char * _strchr(char * str, char ch);
char getfirst(void);
char * _strncpy(char * dest, rsize_t sizeinbyte, char * src, rsize_t MaxCount);
rsize_t get_min(rsize_t a, rsize_t b, rsize_t c);

int main(void)
{
	system("color 4A");

	//1.从第一行起，打印最后1个字符，下一行打印最后2个字符，再下一行打印最后3个字符，以此类推，直到打印完整个字符串为止
	/*char str[]= "Fummy";
	char *p = str + strlen(str);

	while (--p >= str)
	{
	puts(p);
	}*/

	//2.字符串，下标是3倍数的字符原样输出，否则输出该字符的前一个ANSCII字符
	/*char x[] = "Mingcxxsdfadsf";
	int i = 0;

	while (i < sizeof(x))
	{
	if (x[i] % 3 == 0)
	putchar(x[i]);
	else
	putchar(--x[i]);
	i++;
	}*/

	//3.改进_11.17,判断输入，忽略大小写
	/*char try_[MAX];
	int i = 0;

	puts("Who is bureied in Grant's tomb?");
	gets_s(try_, MAX);
	while (try_[i])
	{
	try_[i] = toupper(try_[i]);
	i++;
	}
	while (strcmp(try_, ANSWER) != 0)
	{
	puts("No, that's wrong. Try again.");
	gets_s(try_, MAX);
	}
	puts("That's right.");*/


	//4.读取N个字符到数组
	/*char str[MAX];
	int count;

	puts("Enter some characters:");
	readintput(str);
	printf("Here's read string:\n%s\n", str);*/


	//5.读入一行的首个单词
	/*char str[MAX];
	int count;

	puts("Enter a line sentence:");
	readword(str);
	printf("This is the first word:\n%s\n", str);*/

	//6.编写strchr()
	/*char str[MAX] = "FishC.com", ch;
	char * ptr;

	puts("Enter a character to seek for its position");
	printf("from \"%s\" ( press | to quit): \n", str);
	while ((ch = getfirst()) != '|')
	{
	ptr = _strchr(str, ch);
	if (ptr)
	{
	printf("The index position of \"%c\" <%p> from \"%s\" <%p> is %d\n", ch, ptr, str, str, ptr - str);		//指针值不直观，再转化为相对偏移
	}
	else
	{
	puts("Don't find it!");
	}
	puts("Enter next ( | to quit):");
	}
	puts("Bye!");*/


	//7.编写strchr()
	/*char str[MAX] = "FishC.com", ch;
	char * ptr;

	puts("Enter a character to seek for its position");
	printf("from \"%s\" ( press | to quit): \n", str);
	while ((ch = getfirst()) != '|')
	{
	ptr = _strchr(str, ch);
	if (ptr)
	{
	puts("Find it!");
	}
	else
	{
	puts("Don't find it!");
	}
	puts("Enter next ( | to quit):");
	}
	puts("Bye!");*/


	//8.编写strncpy_s()
	char dest[MAX], src[MAX / 2];
	char * ptr;

	printf("Enter a line (empty to quit and length must be not more than %d):\n", MAX);
	while (gets_s(src, MAX) && src[0] != '\0')
	{
		ptr = _strncpy(dest, MAX, src, 4);
		puts(ptr);
		puts("Enter next (empty to quit):");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

//将字符串关于末字符（不包括空字符）对称打印
char * pr(char * str)
{
	char * ptr = str;

	while (*ptr)
	{
		putchar(*ptr++);
	}
	do
	{
		putchar(*--ptr);
	} while (ptr - str);

	return ptr;
}

//自定义strlen()（不包括空字符）
int _strlen(const char * str)

{
	const char * ptr = str;
	int c = 0;

	while (*ptr)
	{
		c++;
		ptr++;
	}

	return c;
}

//读入LIM个字符或第一个空白符时终止读取，将字符保存到数组
int readintput(char * str)
{
	char ch;
	int count = 0;

	while (count < LIM && !isblank(ch = getchar()))
	{
		str[count] = ch;
		count++;
	}
	str[count] = '\0';		//标识字符串

	return count;
}

//读取输入的第一个单词
void readword(char * str)
{
	char ch;
	int count = 0;

	//提示用户输入非空的行
	while (!isalpha(ch = getchar()))
	{
		puts("Please enter the first no-space character......");
	}
	//写入第一个字母字符
	str[0] = ch;
	count++;
	//继续读取字母字符
	while (isalpha(ch = getchar()))
	{
		str[count] = ch;
		count++;
	}
	str[count] = '\0';		//标识字符串
}

//自定义strchr()
char * _strchr(char * str, char ch)
{
	char *ptr = str;
	while (*ptr && *ptr != ch)
	{
		ptr++;
	}

	return (*ptr == ch ? ptr : NULL);		//找到就返回指向该字符的指针，么找到返回空指针
}

//获取首字符
char getfirst(void)
{
	char ch = getchar();
	while (getchar() != '\n')
	{
		;
	}

	return ch;
}

//还是自定义strchr()。。。
bool is_within(const char ch, char * str)
{
	//法1：调用检查strchr()返回值
	return (strchr(str, ch) ? true : false);

	//法2：指针操作，遍历字符串
	/*char * ptr = str;

	while (*ptr && *ptr != ch)
	{
	ptr++;
	}

	return (*ptr == ch ? true : false);*/

	//法3:这个办法也很棒，调用检查strrchr()返回值(^_^)
	//return (strrchr(str, ch) ? true : false);

	//法4:指针换数组，法2变一变，你懂得...
}

//自定义strncpy()
char * _strncpy(char * dest, rsize_t sizeinbyte, char * src, rsize_t MaxCount)
{
	rsize_t count;

	count = get_min(MaxCount, strlen(src), sizeinbyte);		//取最大拷贝长度、源字符串长度、和目标字符串长度的最小值为实际拷贝长度
	for (rsize_t i = 0; i < count; i++)
		dest[i] = src[i];

	for (rsize_t i = count; i < sizeinbyte; i++)
	{
		dest[i] = '\0';									//填充空字符（或者去掉该循环用dest[count] = '\0'标识有效字符串）
	}

	return dest;
}

//
rsize_t get_min(rsize_t a, rsize_t b, rsize_t c)
{
	rsize_t min;

	if (a > b)
	{
		min = b;
	}
	else
	{
		min = a;
	}
	if (min > c)
	{
		min = c;
	}

	return min;
}