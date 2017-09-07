#include <stdio.h>

int main(void)
{
	int i_a = 1;
	int i_b = 2;
	float f_c = 1.4f;

	printf("%d %d\n", i_a);		//参数太少
	printf("%d\n", i_b, i_b);		//参数太多
	printf("%f %d\n", i_b, f_c);		//格式说明符不匹配，用%d显示float值不会转换为近似的int值，显示垃圾值;(%f显示int值同样),结果错误

	getchar();
	return 0;
}
