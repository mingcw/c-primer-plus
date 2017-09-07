#include <stdio.h>
#include <stdlib.h>
#include "starfolk.h"		//提供了BEM的结构模板

void show(BEM * pst);

int main(void)
{
	BEM * pst;
	BEM deb = {
		6,
		{ "Berbnaze", "Gwolkapwolk" },
		"Arcturan"
	};

	pst = &deb;

	//a.下列语句的打印结果
	printf("%d\n", deb.limbs);
	printf("%s\n", deb.type);
	printf("%s\n", deb.type + 2);

	//b.表示“Arcturan”
	deb.title.last;
	pst->title.last;
	(*pst).title.last;
	
	//c.驱动测试
	show(pst);
	
	getchar();
	return 0;

}

//c.编写一个函数，以一个bem结构的地址为参数，并以下列的形式打印结果内容。结构模板定义在starfolk.h文件
//Berbnaze Gwolkapwolk is a 6-limited Arcturan.

void show(BEM * pst)
{
	printf("%s %s is a %d-limited %s.\n", pst->title.first, pst->title.last, pst->limbs, pst->type);
}