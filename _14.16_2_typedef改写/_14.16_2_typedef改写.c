#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 81

typedef void(*V_FP_CHARP)(char *);				//定义函数指针类型名

int showmenu(void);
void eatline(void);								//剔除剩余行
void show(V_FP_CHARP fp, char *);
void ToUpper(char *);							//把字符串转换为大写
void ToLower(char *);							//把字符串转换为小写
void Transpose(char *);							//大小写转置
void Dummy(char *);								//不改变字符串

int main(void)
{
	char line[SIZE];
	char copy[SIZE];
	int choice;
	V_FP_CHARP pfun[4] = { ToUpper, ToLower, Transpose, Dummy };		//函数指针构成的指针数组

	system("color 0A");
	puts("Enter a string (empty to quit):");
	while (gets_s(line, SIZE) && line[0] != '\0')
	{
		choice = showmenu();
		while (choice >= 0 && choice <= 3)
		{
			strcpy_s(copy, SIZE, line);			//为show制作一份拷贝以供修改（源字串不能修改，要留着下次做新的拷贝，拿拷贝的去修改处理，这样就实现了对一个字串的多次不同处理）		
			show(pfun[choice], copy);			//执行用户选择的不同函数
			choice = showmenu();
		}
		puts("Enter a string (empty to quit):");
	}
	puts("Bye!");

	system("pause");
	return 0;
}

int showmenu(void)
{
	char ans;
	int result;

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
	switch (ans)						//switch语句
	{
	case 'u':result = 0; break;
	case 'l':result = 1; break;
	case 't':result = 2; break;
	case 'o':result = 3; break;
	case 'n':result = -1; break;
	}

	return result;
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