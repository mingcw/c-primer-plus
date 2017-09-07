/*
	编写一个与练习6所描述功能相同的程序。使用一个unsigned long来保存字体信息。
	使用位运算符而不是位成员来管理这些信息*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//ID（右起第一字节）
#define ID_MASK			0xFF

//字体大小（第二字节低7位）
#define SIZE_MASK		0x7F00

//对齐(第三字节低2位）
#define LEFT 0								//左对齐
#define CENTER			0x10000				//中间对齐
#define RIGHT			0x20000				//右对齐
#define ALIGNMENT_MASK	0x30000

//B、I、U（第4字节低3位）
#define BOLID			0x1000000			//加粗
#define ITALIC			0x2000000			//倾斜
#define UNDERLINE		0x4000000			//下划线

enum choice
{
	f = 'f',
	s = 's',
	a = 'a',
	b = 'b',
	i = 'i',
	u = 'u',
	q = 'q'
};
typedef enum choice CHOICE;

typedef unsigned long UL;

void show_info(UL n);
void show_bstr(UL n);
void show_menu(void);
CHOICE get_choice(void);
void eatline(void);
UL change_font(UL n);
UL change_size(UL n);
UL change_alignment(UL n);
UL toggle_bold(UL n);
UL toggle_italic(UL n);
UL toggle_underline(UL n);

int main(void)
{
	UL font, size = 12;
	CHOICE ch;

	//设置字体信息（从低位向高位）
	font &= 0;								//所有位清0
	font |= (1 & ID_MASK);					//ID设置为1
	font |= (12 << 8);						//size设置为12
	font |= LEFT;							//左对齐

	system("color 5A");
	show_info(font);
	show_menu();
	while ((ch = get_choice()) != q)
	{
		switch (ch)
		{
		case f:
			font = change_font(font);
			break;
		case s:
			font = change_size(font);
			break;
		case a:
			font = change_alignment(font);
			break;
		case b:
			font = toggle_bold(font);
			break;
		case i:
			font = toggle_italic(font);
			break;
		case u:
			font = toggle_underline(font);
			break;
		}
		show_info(font);
		show_menu();
	}
	puts("Bye!");

	system("pause");
	return 0;
}

UL toggle_underline(UL n)
{
	n ^= UNDERLINE;

	return n;
}

UL toggle_italic(UL n)
{
	n ^= ITALIC;

	return n;
}

UL toggle_bold(UL n)
{
	n ^= BOLID;

	return n;
}

UL change_alignment(UL n)
{
	char ch;

	puts("Select alignment:");
	puts("l)left c)center r)right");
	ch = getchar();
	eatline();
	while (strchr("lcr", ch) == NULL)
	{
		puts("Please enter l, c, or r.");
		ch = getchar();
		eatline();
	}
	n &= ~ALIGNMENT_MASK;					//对齐的位清零
	if (ch == 'l')
	{
		n |= LEFT;
	}
	else if (ch == 'c')
	{
		n |= CENTER;
	}
	else
	{
		n |= RIGHT;
	}

	return n;
}

UL change_size(UL n)
{
	UL size;

	printf("Enter font size (0-127): ");
	while (scanf_s("%u", &size, 10) != 1)
	{
		eatline();
		puts("Please enter an integer in 0-127.");
	}
	eatline();
	size &= (SIZE_MASK >> 8);				//取低7位
	n &= ~SIZE_MASK;						//size清零
	n |= (size << 8);						//设置size

	return n;
}

UL change_font(UL n)
{
	UL ID;

	printf("Enter font ID (0-255): ");
	while (scanf_s("%u", &ID, 10) != 1)
	{
		eatline();
		puts("Please enter an integer in 0-255.");
	}
	eatline();
	ID &= ID_MASK;							//取低8位
	n &= ~ID_MASK;							//ID清零
	n |= ID;								//设置ID

	return n;
}

CHOICE get_choice(void)
{
	CHOICE ch;

	ch = getchar();
	ch = tolower(ch);
	eatline();
	while (strchr("fsabiuq", ch) == NULL)
	{
		puts("Please enter f, s, a, b, i, u, or q.");
		ch = getchar();
		ch = tolower(ch);
		eatline();
	}

	return ch;
}

void eatline(void)
{
	while (getchar() != '\n')
	{
		;
	}
}

void show_menu(void)
{
	puts("f)change font s)change size   a)change alignment");
	puts("b)toggle bold i)toggle italic u)toggle underline");
	puts("q)quit");
}

void show_info(UL n)
{
	puts("ID SIZE ALIGNMENT B I U");
	printf("%u %u ", n&ID_MASK, (n&SIZE_MASK) >> 8);
	switch (n&ALIGNMENT_MASK)
	{
	case LEFT:
		printf("left ");
		break;
	case CENTER:
		printf("center ");
		break;
	case RIGHT:
		printf("right ");
		break;
	default:
		printf("Unknown ");
		break;
	}
	printf("%s ", (n&BOLID) == BOLID ? "on" : "off");
	printf("%s ", (n&ITALIC) == ITALIC ? "on" : "off");
	printf("%s\n", (n&UNDERLINE) == UNDERLINE ? "on" : "off");

	show_bstr(n);
}

void show_bstr(UL n)
{
	int i, size = 8 * sizeof(unsigned long)+1;
	char bstr[8 * sizeof(unsigned long)+1];				//不支持VLA，所以写成常量表达式（C中sizeof的返回值是常量）

	for (i = size - 2; i >= 0; i--, n >>= 1)
	{
		bstr[i] = (n & 01) + '0';
	}
	bstr[size - 1] = '\0';
	i = 0;
	while (bstr[i])
	{
		putchar(bstr[i]);
		if (++i % 4 == 0 && bstr[i] != '\0')
		{
			putchar(' ');
		}			
	}
	putchar('\n');
}