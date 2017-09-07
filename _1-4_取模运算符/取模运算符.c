#include <stdio.h>
#define SEC_PER_MIN 60	//每分钟60秒
int main(void)
{
	//取摸运算符也即求余
	printf("Convetion For seconds。。英语不太好，大概就这个意识。。\n");
	int sec, min, left;	//剩余的意思

	printf("Please enter a second-number:（<=0 to quit）\n");
	scanf_s("%d", &sec, 10);
	while (sec > 0)
	{
		min = sec / SEC_PER_MIN; //计算分钟数,整数运算只保留整数部分（似乎取整运算符在标准数学库头文件里，不要它也行）
		left = sec % SEC_PER_MIN; //取模计算不够1分钟的秒数
		printf("%d seconds is %d minutes and %d seconds\n", sec, min, left);
		printf("Please enter another second-number:(<=0 to quit)\n");
		scanf_s("%d", &sec, 10);
	}
	printf("Done!\n");
	getchar();
	getchar();
	return 0;
}