#include <stdio.h>

int main(void)
{
	//for的3个表达式的灵活性(initialize表达式、test表达式、update表达式)

	//1.计数减小
	for (int sec = 5; sec > 0; sec--)
	{
		printf("%d second!", sec);
		if (sec != 1)
		{
			printf("\bs!\n");
		}
	}
	printf("\n\n");
	
	//2.递增值自定义
	for (int i = 2; i < 60; i += 13)
	{
		printf("%d\n", i);
	}
	printf("\n");
	
	//3.以字符计数
	for (char ch = 'a'; ch <= 'z'; ch++)	//增（减）量运算符在for循环里，执行一次循环就增加（减小）1（前后缀效果相同）
	{
		printf("The ASCII for %c is %d\n", ch, ch);
	}
	printf("\n");

	//4.判断迭代次数之外的条件
	printf("    n n-cubed\n");
	for (int i = 1; i*i*i <= 216; i++)
	{
		printf("%5d %5d\n", i, i*i*i);
	}
	printf("\n");

	//5.几何增加取代算术增加
	for (double i = 100.0; i < 150.0; i*= 1.1)
	{
		printf("Your debt is now $%.2f\n", i);
	}
	printf("\n");
	
	//6.使用代数计算进行更新（不好的编程风格）
	int x;
	int y = 55;

	for (x = 1; y <= 75; y = (++x * 5) + 50)	//代数计算知道第二个表达式等价于x<=5
	{
		printf("%10d %10d\n", x, y);
	}
	printf("\n");

	//7.一个或多个表达式为空，但要有分号，只需确保在循环中包含了能使循环结束的语句（注意：第8个例子）
	int n, ans;

	ans = 2;
	for (n = 3; ans <= 25; )
	{
		ans *= n;
		printf("n = %d, ans = %d\n", n, ans);
	}
	printf("\n");

	//7.2.第二个表达式为空时，默认为真，循环会永远执行
	/*for (;;)
	{
		printf("I want some action.\n");
	}
	printf("\n");*/

	//8.第一个表达式不必初始化一个变量，可以是某种类型的printf（）语句。它只被执行一次
	int num = 0;

	for (printf("Keep entering numbers!(6 end the loop-for)\n"); num != 6;)
	{
		scanf_s("%d", &num);
	}
	printf("That's the one I want!\n\n");
	
	//9.循环中的动作可以改变循环表达式的参数
	int delta = 0;

	printf("Please enter the increment of the loop-for\n");
	printf("(When the num is 0, the loop-for will use the default 10):");

	scanf_s("%d", &delta);
	for (int i = 0; i < 100; i += delta)
	{
		if (delta == 0)
		{
			delta = 10;
		}
		printf("i = %d\n", i);
	}
	printf("\n");

	getchar();
	getchar();
	return 0;
}