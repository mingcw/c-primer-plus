//定义names_st函数

#include <stdio.h>
#include <stdlib.h>
#include "names.h"		//包含头文件

//函数定义
void get_names(names * pn)
{
	int i;

	system("color 0A");

	printf("Please enter your first name: ");
	fgets(pn->first, SLEN, stdin);
	i = 0;
	while (pn->first[i] != '\n' && pn->first[i] != '\0')
	{
		i++;
	}
	if (pn->first[i] == '\n')		//如果被保存的字符串中存在换行符，就用空字符代替该换行符
	{
		pn->first[i] = '\0';
	}
	else							//否则，表示fgets()在达到行尾之间已经停止读取，为了不影响后续IO操作，代码去掉用户输入的剩余行。
	{
		while (getchar() != '\n')
		{
			continue;
		}
	}

	printf("Please enter your last name: ");
	fgets(pn->last, SLEN, stdin);
	i = 0;
	while (pn->last[i] != '\n' && pn->last[i] != '\0')
	{
		i++;
	}
	if (pn->last[i] == '\n')
	{
		pn->last[i] = '\0';
	}
	else
	{
		while (getchar() != '\n')
		{
			continue;
		}
	}
}

void show_names(const names * pn)
{
	printf("%s %s", pn->first, pn->last);
}