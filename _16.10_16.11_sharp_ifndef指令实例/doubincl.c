//doubinc.c -- 两次包含同一头文件
#include <stdio.h>
#include "names_st.h"
#include "names_st.h"			/*不小心两次包含同一头文件
								  但是因为，该头文件中有防止重复包含的代码。所以，虽然包含两次，但防止了重复定义（比如结构定义，只能有一次定义）
								  如果去掉该头文件中的ifndef指令保护，程序就不能通过编译*/

int main(void)
{
	names winner = { "Less", "Ismoor" };

	printf("The winner is %s %s.\n", winner.first, winner.last);

	return 0;
}