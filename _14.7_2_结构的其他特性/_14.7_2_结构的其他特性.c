#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

int main(void)
{
	struct funds stan = {
		"bank_A",
		4545.00,
		"save_B",
		3423.89
	};
	
	//结构其他特性：

	//1.现在的C允许把一个结构赋值给另一个结构，不能对数组这样做。
	struct funds o_data;

	o_data = stan;		//使得o_data的每个成员值都被赋成stan相应成员的值，即使有一个成员是数组也照样完成赋值

	//也可以把一个结构初始化为另一个同样类型的结构：
	struct funds right_filed = { "bank_A", 4545.00, "save_B", 3423.89 };
	struct funds caption = right_filed;		//把一个结构初始化为另一个结构

	//2.现在的C（包括ANSI C）中，结构不仅可以作为参数传递给地址，也可以作为函数返回值返回

	//把结构作为函数参数可以将函数信息传递给另一个函数，
	//使用函数返回结构可以将结构信息从被调函数传递给调用函数（主调函数）。

	//3.结构指针也允许双向通信（即可作为函数参数进行传递，也可以作为函数返回值返回）

}