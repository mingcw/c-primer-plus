#include <stdio.h>
#include "names.h"		//需要names结构模板
//记住链接names_st.c文件

int main(void)
{
	names candidate;

	get_names(&candidate);
	printf("Let's welcome ");
	show_names(&candidate);
	printf(" to this program!\n");

	getchar();
	return 0;
}