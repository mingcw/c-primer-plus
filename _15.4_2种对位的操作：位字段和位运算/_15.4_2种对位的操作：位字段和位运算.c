/*
	位字段是在一个unsigned int大小的结构里访问操作位值；
	位运算则对一个unsigned int值进行位操作访问位值。
	
	本示例中使用这两种方法访问位值，是为了解释其中的不同，
	而并不是按时同时使用这两种方法是一个好主意
	
	似乎写了FH，就当练打字了。只需知道：位操作可以用位运算，设置一个位组合的信息可以用位字段(单字段写入int单元里的顺序依赖于实现）
	*/

//#include <stdio.h>
#include <stdlib.h>

//位字段常量
//是否透明和是否可见
#define YES		1
#define NO		0

//边框线的样式
#define SOLID	0
#define DOTTED	1
#define DASHED	2

//三原色
#define BLUE	4
#define GREEN	2
#define RED		1

//混合颜色
#define BLACK	0
#define YELLOW	(GREEN | RED)
#define MAGENTA (BLUE | RED)
#define CYAN	(BLUE | GREEN)
#define WHITE	(BLUE | GREEN | RED)

//位运算中使用的常量
#define OPAQUE			0x00000001
#define FILL_BLUE		0x00000008
#define FILL_GREEN		0x00000004
#define FILL_RED		0x00000002
#define FILL_MASK		0x0000000E
#define BORDER			0x00000100
#define BORDER_BLUE		0x00000800
#define BORDER_GREEN	0x00000400
#define BORDER_RED		0x00000200
#define BORDER_MASK		0x00000E00
#define B_SOLID			0
#define B_DOTTED		0x00001000
#define B_DASHED		0x00002000
#define STYLE_MASK		0x00003000

const char * colors[8] = { "black", "red", "green", "yellow",
							"bule", "magenta", "cya", "white" };

struct box_props						/*根据实践，我的电脑是从右向左填充字段的。也就是第一个字段填在位0（最低位），最后一个字段填在位31（最高位，我的系统下int是4字节32位的）
										  不过这个位字段结构只用了一个int的后2个字节（低16位），果然用位字段设置信息最方便了(^_^)*/
{
	unsigned int opaque			: 1;
	unsigned int fill_color		: 3;
	unsigned int				: 4;
	unsigned int show_border	: 1;
	unsigned int border_color	: 3;
	unsigned int border_style	: 2;
	unsigned int				: 2;
};

union Views										//把数据视作位字段结构或unsigned int变量
{
	struct box_props st_view;
	unsigned int ui_view;
};

void show_settings(const struct box_props * ps);
void show_settings1(unsigned int);
char * itobs(int n, char * ps);							//把int值的二进制补码打印出来
void show_bstr(char * str);

int main(void)
{
	/*创建联合对象，初始化第一个成员*/
	union Views box = { YES, YELLOW, YES, GREEN, DASHED };
	char bin_str[8 * sizeof(int)+1];

	system("color 0A");
	printf("Original box settings:\n");
	show_settings(&box.st_view);						//把联合视作结构体(int大小）

	printf("Box settings using unsigned int view:\n");
	show_settings1(box.ui_view);						//把联合视作int值

	printf("Bits are ");
	itobs(box.ui_view, bin_str);
	show_bstr(bin_str);

	box.ui_view &= ~FILL_MASK;							//把代表填充色位全部清零
	box.ui_view |= (FILL_GREEN | FILL_BLUE);			//重置填充色
	box.ui_view ^= OPAQUE;								//转置指示是否透明的位
	box.ui_view |= BORDER_RED;							//错误的方法
	box.ui_view &= ~STYLE_MASK;							//清除样式位
	box.ui_view |= B_DOTTED;							//把样式设置为点

	printf("\nModified box settings:\n");
	show_settings(&box.st_view);

	printf("Box settings using unsigned int view:\n");
	show_settings1(box.ui_view);

	printf("Bits are ");
	itobs(box.ui_view, bin_str);
	show_bstr(bin_str);

	getchar();
	return 0;
}

void show_settings(const struct box_props * ps)
{
	printf("Box is %s.\n",
		ps->opaque == YES ? "opaque" : "transparent");
	printf("The fill color is %s.\n",
		colors[ps->fill_color]);
	printf("Border is %s\n",
		ps->show_border == YES ? "shown" : "not shown");
	printf("Border color is %s.\n", 
		colors[ps->border_color]);
	printf("Border style is ");
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

void show_settings1(unsigned int n)
{
	printf("Box is %s.\n",
		(n & OPAQUE) == OPAQUE ? "opaque" : "transparent");		//位运算符优先级低于==号，注意加括号
	printf("The fill color is %s.\n",
		colors[(n & FILL_MASK) >> 1]);					/*1.fill_color属性在位1到位3之间，所以为了取出这三位表示的属性值，先右移一位，再用掩码取出低3位的颜色值，从而对应了数组0-7的颜色索引和颜色字符串
														  2.注意位运算符优先级低于&，所以在复杂运算里出现位运算时，最好加括号括起来*/
	printf("Border is %s.\n",
		(n & BORDER) == BORDER ? "shown" : "not shown");
	printf("（1）Border color is %s.\n",
		colors[(n & BORDER_MASK) >> 9]);				//用0xE00做掩码取出对应的位9到位11之间的颜色值（和右边低位的所有位），然后再右移9位让这3位颜色值落到低3位，从而对应了数组0-7的颜色索引和颜色字符串
	printf("（2）Border color is %s.\n",
		colors[(n >> 9) & 07]);							//把n右移9位，再与07相与取出低3位
	printf("（3）Border color is %s.\n",
		colors[(n >> 9) & (0xE >> 1)]);					//把n右移9位，把0xE右移1位，再与n相与，取出低3位
	//总结：用位运算取出特定位并转换成单个的数值时，只需2部：
	//1.移位（如果要取出中间的某n位，那么先把这n位右边的所有位移出去，让这n为落到最低位）
	//2.取值（用一个最后n位全为1的掩码跟那个数作用取出那个数的最后n位）

	//注：移位和取值并没有次序，先取值再把后边的无关位移出也可以(本函数内的第二个printf()语句里就是这样的）。所以，移位的方法也就多种多样了，但原理和步骤应该就是这样了。

	printf("Border style is  ");
	switch (n & STYLE_MASK)								//因为这个不需要取出值，所以只需要对位15和位14判断，其他位全部屏蔽（所以还是用掩码）
	{
	case B_SOLID:
		printf("solid.\n");
		break;
	case B_DOTTED:
		printf("dotted.\n");
		break;
	case B_DASHED:
		printf("dashed.\n");
		break;
	default:
		printf("unknown type.\n");
		break;
	}
}

char * itobs(int n, char * ps)
{
	int size = 8 * sizeof(int)+1;

	for (int i = size - 2; i >= 0; i--, n >>= 1)
	{
		ps[i] = (n & 01) + '0';							//n不断右移，用01做掩码取出位0的位值，加上0字符的ASCII码转换为字符，依次从后向前写入到字符数组
	}
	ps[size - 1] = '\0';								//最后一个位置植入空字符

	return ps;
}

void show_bstr(char * str)
{
	int i = 0;

	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i] != '\0')
		{
			putchar(' ');
		}
	}
	putchar('\n');
}