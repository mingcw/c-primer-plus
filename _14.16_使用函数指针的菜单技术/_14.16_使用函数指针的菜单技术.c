#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 81
typedef void(*V_FP_CHARP)(char *);				//void(*)(char *)类型typedef为V_FP_CHARP
 
char showmenu(void);
void eatline(void);								//剔除剩余行

void show(V_FP_CHARP fp, char *);
//void show(void(*fp)(char *), char * str);		//接受函数指针和字符指针作为参量

void ToUpper(char *);							//把字符串转换为大写
void ToLower(char *);							//把字符串转换为小写
void Transpose(char *);							//大小写转置
void Dummy(char *);								//不改变字符串

int main(void)
{
	char line[SIZE];
	char copy[SIZE];
	char choice;
	V_FP_CHARP pfun;							/*函数指针pfun(等价于void(*pfun)(char *);)
												(指向的函数接受一个char *参数，
												并且没有返回值)*/
		
	system("color 0A");
	puts("Enter a string (empty to quit):");
	while (gets_s(line, SIZE) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)						//switch语句来设置函数指针
			{
			case 'u':pfun = ToUpper; break;
			case 'l':pfun = ToLower; break;
			case 't':pfun = Transpose; break;
			case 'o':pfun = Dummy; break;
			}
			strcpy_s(copy, SIZE, line);			//为show制作一份拷贝以供修改（源字串不能修改，要留着下次做新的拷贝，拿拷贝的去修改处理，这样就实现了对一个字串的多次不同处理）		
			show(pfun, copy);					//执行用户选择的不同函数
		}
		puts("Enter a string (empty to quit):");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

char showmenu(void)
{
	char ans;

	puts("Enter menu choice:");
	puts("u) uppercase l) lowercase");
	puts("t) transpose o) original case");
	puts("n) next string");
	ans = getchar();
	ans = tolower(ans);
	eatline();
	while (strchr("ulton", ans) == NULL)
	{
		puts("please enter a u, l, t, o, or n:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		continue;
	}
}

void ToUpper(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char * str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char * str)
{
	while (*str)
	{
		if (islower(*str))
		{
			*str = toupper(*str);
		}
		else if (isupper(*str))
		{
			*str = tolower(*str);
		}
		str++;
	}
}

void Dummy(char * str)
{
	//不改变字串
}

void show(V_FP_CHARP fp, char * str)
{
	(*fp)(str);
	puts(str);
}