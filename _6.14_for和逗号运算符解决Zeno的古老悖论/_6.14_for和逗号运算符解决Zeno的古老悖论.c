#include <stdio.h>

int main(void)
{
	/*希腊哲学家Zeno辩论到一支箭永远不能到达它的目标
	 箭要到达目标，首先得到达目标距离的一半，然后又必须到达剩余距离的一半，这样就没有穷尽
	 利用for循环计算所需时间的前几项的和看看*/
	int t_ct;		//项计数
	double time, x;
	int limit;

	printf("Enter the nuber of terms you want:");
	scanf_s("%d", &limit);
	for (time = 0, x = 1, t_ct = 1; t_ct <= limit; t_ct++, x *= 2.0)
	{
		time += 1.0 / x;
		printf("time = %f when terms = %d\n", time, t_ct);
	}

	getchar();
	getchar();
	return 0;
}