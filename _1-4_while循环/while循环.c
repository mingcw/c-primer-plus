#include <stdio.h>
#define ADJUST 7.64
#define SCALE 0.325

int main(void)
{
	//while循环输出尺码对应的英寸表
	double shoe, foot;
	
	printf("Shoe size(men's)	foot length\n");
	shoe = 3.0;
	while (++shoe < 18.5)
	{
		foot = SCALE*shoe + ADJUST;
		printf("%12.1f %15.2f inches\n", shoe, foot);
		//shoe++;
	}
	getchar();
	return 0;
}