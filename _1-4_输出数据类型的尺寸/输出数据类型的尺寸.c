#include <stdio.h>

int main(void)
{
	//本编译器支持的数据类型尺寸的格式说明符为%u(也可以用%d打印数据类型尺寸)
	printf("Type int has a size of %u bytes.\n", sizeof(int));
	printf("Type short has a size of %u bytes.\n", sizeof(short));
	printf("Type long has a size of %u bytes.\n", sizeof(long));
	printf("Type char has a size of %u bytes.\n", sizeof(char));
	printf("Type float has a size of %u bytes.\n", sizeof(float));
	printf("Type double has a size of %u bytes.\n", sizeof(double));
	printf("Type long double has a size of %d bytes.\n", sizeof(long double));

	getchar();
	return 0;

}
