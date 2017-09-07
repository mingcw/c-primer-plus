#include <stdio.h>
#include <stdlib.h>

//有以下模板
struct gas
{
	float distance;
	float gals;
	float mpg;
};

//a.设计一个函数，它接受一个struct gas 参数。假定传递进来的结构包括distance和gals信息。
//函数为mpg成员正确计算出值并返回这个现在完整的结构。

struct gas makeinfoA(struct gas);

//b.设计一个函数，它接受struct gas的地址。假定传递进来的结构包括distance和gas信息。
//函数为mpg成员正确计算出值并把它赋给恰当的成员。

void makeinfoB(struct gas * pst);


int main(void)
{
	//驱动测试
	struct gas gasA = { .distance = 300.0f, .gals = 20 };

	gasA = makeinfoA(gasA); 
	system("color 5A");
	printf("%.2f %.2f %.2f\n", gasA.distance, gasA.gals, gasA.mpg);

	struct gas gasB = gasA;
	struct gas * pst = &gasB;
	makeinfoB(pst);
	printf("%.2f %.2f %.2f\n", gasB.distance, gasB.gals, gasB.mpg);

	getchar();
	return 0;
}

struct gas makeinfoA(struct gas info)
{
	//我猜是这么算的。。
	info.mpg = info.distance / info.gals;		//单位：英里每加仑

	return info;
}

void makeinfoB(struct gas * pst)
{
	pst->mpg = pst->distance / pst->gals;
}
