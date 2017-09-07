#include <stdio.h>
#include <stdlib.h>

//是否透明和是否可见
#define YES		1
#define NO		0

//边框线样式
#define SOLID	0
#define DOTTED	1
#define DASHED	2

//三原色
#define BLUE	4
#define GREEN	2
#define RED		1

//混合颜色
#define BLACK	0
#define YELLOW	(RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN	(GREEN | BLUE)
#define WHITE	(RED | GREEN | BLUE)

/*	位字段结构;
	对位进行操作的第二种方法是位字段。
	位字段是一个signed int或unsigned int中一组相邻的位（C99标准还允许_Bool类型位字段）。
	位字段由一个结构声明建立，该结构声明为每个字段提供标签，并决定字段的宽度*/

struct box_props							//声明位字段的结构模板（占用一个int的存储空间大小）
{
	unsigned int opaque			: 1;
	unsigned int fill_color		: 3;
	unsigned int				: 4;		//使用未命名的字段宽度填充未命名的洞（使用宽度为0的未命名字段将迫使下一字段与下一整数对齐）
	
	//未命名字段的填充使得与填充有关的信息存在一个字节中，与边框有关的信息存在下一字节中

	unsigned int show_border	: 1;
	unsigned int border_color	: 3;
	unsigned int border_style	: 2;
	unsigned int				: 2;
};

const char * colors[] = { "black", "red", "green", "yellow", 
						"blue", "magenta", "cyan", "white" };

void show_settings(const struct box_props * ps);

int main(void)
{
	/*创建和初始化box_props结构*/
	struct box_props box = { YES, YELLOW, YES, GREEN, DASHED };

	system("color 0A");
	printf("Original box settings:\n");
	show_settings(&box);

	box.opaque = NO;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	printf("\nModefied box setting:\n");
	show_settings(&box);

	getchar();
	return 0;
}

void show_settings(const struct box_props * ps)
{
	printf("Box is %s.\n", 
		ps->opaque == YES ? "opaque" : "transparent");
	printf("The fill color is %s.\n", colors[ps->fill_color]);
	printf("Border %s.\n",
		ps->show_border == YES ? "shown" : "not shown");
	printf("The border color is %s.\n", colors[ps->border_color]);
	printf("The border style is ");
	switch (ps->border_style)
	{
	case SOLID:
		printf("solid.\n"); 
		break;
	case DOTTED:
		printf("dotted.\n");
		break;
	case DASHED:
		printf("dashed.\n");
		break;
	default:
		printf("unknown type.\n");
		break;
	}
}