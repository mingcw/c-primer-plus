#include <stdio.h>
#include <stdlib.h>

//创建一个具有伸缩型数组成员的结构模板
struct flex
{
	int count;
	double average;
	double scores[];			//伸缩型数组成员（直接声明struct flex类型变量时，并不能用scores成员做任何事，因为没有为它分配内存空间）
	//伸缩型数组成员的类型长度为0,所以sizeof(struct flex)= 16 （结构的类型长度取类型最长的成员的大小作为每个成员的大小，即 8 + 8 == 16，伸缩型数组成员类型长度为0）
};

/*
	一、伸缩型数组成员的特殊属性：

	1.该数组成员并不存在，至少不立即存在。
	2.可以编写代码使用这个伸缩型数组成员。
	
	二、结构里声明一个伸缩型数组成员的规则：

	1.伸缩型数组成员必须是最后一个数组成员
	2.结构中必须至少有一个其他成员
	3.伸缩型数组就像普通数组一样被声明，除了它的方括号内是空的

	简言之：伸缩型数组成员必须放在多个常规成员最后
	
	三、C99的意图：

	1.C99提供具有伸缩型数组成员的结构flex并不是为了让用户声明这种结构变量，因为这并不为伸缩型数组成员分配内存空间
	2.C99提供该特殊结构是为了，声明一个指向具有伸缩型数组成员的结构flex的指针，然后用malloc()来分配足够的空间，
	  以存放struct flex结构的常规内容和伸缩型数组成员需要的任何额外空间。*/

void showFlex(const struct flex * p);

int main(void)
{
	struct flex * pf1, *pf2;
	int n = 5;
	double tot = 0;

	//为结构和数组分配存储空间

	system("color 5A");
	//1.伸缩型数组成员具有5个double元素
	pf1 = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(double));		//理解为：结构的定长类型成员的类型长度+要申请的伸缩型数组成员的类型长度
	pf1->count = n;
	for (int i = 0; i < n; i++)
	{
		pf1->scores[i] = 20.0f - i;
		tot += pf1->scores[i];
	}
	pf1->average = tot / n;
	showFlex(pf1);

	//2.伸缩型数组成员具有9个double元素
	n = 9;
	tot = 0;
	pf2 = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for (int i = 0; i < n; i++)
	{
		pf2->scores[i] = 20.0f - i / 2.0f;
		tot += pf2->scores[i];
	}
	pf2->average = tot / n;
	showFlex(pf2);
	free(pf1);
	free(pf2);

	system("pause");
	return 0;
}

void showFlex(const struct flex * p)
{
	printf("Score: ");
	for (int i = 0; i < p->count; i++)
	{
		printf("%g ", p->scores[i]);
	}
	printf("\nAverage: %g\n", p->average);
}