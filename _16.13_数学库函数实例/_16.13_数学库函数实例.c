#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(_MSC_VER)
#if _MSC_VER == 1800
#pragma message("Compiler Version：vs2013")

#endif // _MSC_

#endif // defined(_MSC_VER)

#define PI (4.0 * atan(1))			//使用足够多的扩号保证正确的运算顺序和结合性
#define RAD_TO_DEG (180.0 / PI)

typedef struct polar_v
{
	double magnitude;
	double angle;
} POLAR_V;

typedef struct rect_v
{
	double x;
	double y;
} RECT_V;

//POLAR_V rect_to_polar(RECT_V);
__inline POLAR_V rect_to_polar(RECT_V rv)				//不支持inline(复习一下之前的内联函数,也可以写成一般的外部函数定义。（注意：存储类中说过，函数的存储类默认是extern的。）
{
	POLAR_V pv;

	pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);		/*如果编译器提示“sqrt”无法解析的外部符号，那么说明编译器的链接器没有找到数学库。
														UNIX系统要求使用-lm标记指示链接器搜索数学库：cc _16.13_数学库函数实例.c -lm
														Linux的gnu编译器也使用相同形式：gcc _16.13_数学库函数实例.c -lm
														*/
	if (pv.magnitude == 0)
	{
		pv.angle = 0;
	}
	else
	{
		pv.angle = atan2(rv.y, rv.x) * RAD_TO_DEG;
	}
	
	return pv;
}

int main(void)
{
	RECT_V input;
	POLAR_V result;

	system("color 0A");
	puts("Enter x, y coordinates: enter q to quit:");
	while (scanf_s("%lf %lf", &input.x, &input.y) == 2)
	{
		result = rect_to_polar(input);
		printf("magnitude = %.2lf, angle = %.2lf\n",
			result.magnitude, result.angle);
	}
	puts("Bye!");

	system("pause");
	return 0;
}