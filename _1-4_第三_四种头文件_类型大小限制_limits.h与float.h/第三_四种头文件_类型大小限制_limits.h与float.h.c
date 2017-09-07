#include <stdio.h>
#include <limits.h>  //整数限制
#include <float.h>  //小数限制

int main(void)
{
	printf("★★整数和小数的大小限制★★\n\n");
	printf("整型数_最大值 == %d\n\n", INT_MAX);
	printf("无符号长整数_最小值 == %lld，长度 == %d字节\n\n", LLONG_MIN, sizeof(long));
	printf("1字节 == %d位\n\n", CHAR_BIT);
	printf("双精度小数_最大值 == %e\n\n", DBL_MAX);
	printf("浮点数_最小值 == %e\n\n", FLT_MIN);
	printf("浮点数_精度 == %d\n\n", FLT_DIG);
	printf("双精度浮点数_精度 == %d\n\n", DBL_DIG);
	printf("★★更多相关类型请查看头文件★★\n\n");

	getchar();
	return 0;

}
