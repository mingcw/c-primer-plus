//驱动程序、测试随机数函数rand0()

#include <stdio.h>
#include <stdlib.h>

extern int rand0(void);			//extern表明该函数是一个外部函数（类似于对变量的引用声明，函数定义在其他文件内）

int main(void)
{
	int count;

	system("COLOR 0A");
	for (count = 0; count < 5; count++)
	{
		printf("%hd\n", rand0());		//rand0()的返回值是0到32767
	}
	
	getchar();
	return 0;
}