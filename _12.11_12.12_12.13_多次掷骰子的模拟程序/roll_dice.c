//掷骰子的相关函数文件

#include <stdlib.h>							//提供了rand()的函数原型
#include <time.h>							//提供了time()的函数原型

int roll_count = 0;							//外部链接、文件作用域

static int dice_once(int sides)				//静态函数，文件私有
{
	unsigned int roll;						//掷骰子的点数

	srand((unsigned int)time(NULL));		//用系统时间初始化一个种子值
	roll = rand() % sides + 1;				//1-骰子最大点数的随机数
	++roll_count;							//掷骰子次数

	return roll;
}

 int dice_more(int dices, int sides)			//外部函数()
{
	 int total = 0;

	 if (sides < 2)
	 {
		 printf("Need at least 2 sides.\n");	//至少2面（2面时模仿掷硬币）
		 return -2;
	 }
	 if (dices < 1)
	 {
		 printf("Need at least 1 die.\n");		//至少1个骰子
		 return -2;
	 }
	 for (int i = 0; i < dices; i++)			//依次掷dices个骰子，并累加求和
	 {
		 total += dice_once(sides);
	 }

	 return total;
}