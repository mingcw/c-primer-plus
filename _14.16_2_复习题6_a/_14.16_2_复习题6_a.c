
//给定以下的typedef，声明一个10个元素的指定结构的数组。
//然后通过各个成员赋值（或等价字符串），使第3个元素描述一个焦距长度为500mm、孔径为f/2.0的Remarkatar镜头

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct lens			//镜头描述
{
	float foclen;			//焦距长度，以mm为单位
	float fstop;			//孔径
	char brand[30];			//品牌名称
} LENS;

int main(void)
{
	LENS bigeye[SIZE];

	bigeye[2].foclen = 500.0f;
	bigeye[2].fstop = 2.0f;
	//bigeye[2].brand = "Remarkatar";
	strcpy_s(bigeye[2].brand, 30, "Remarkatar");

	printf("Foclen: %.2f\n", bigeye[2].foclen);
	printf("Fstop: %.2f\n", bigeye[2].fstop);
	printf("Brand: %s\n", bigeye[2].brand);

	getchar();
	return 0;
}