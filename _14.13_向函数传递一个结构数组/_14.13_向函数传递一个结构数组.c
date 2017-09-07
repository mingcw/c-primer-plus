#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50
#define N 2

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds money[], int n);

int main(void)
{
	struct funds jones[N] = { 
	{
		"Garlic-Melon Bank",
		3024.72f,
		"Lucky's Saving and Loan",
		9237.11
	},
	{
		"Honest Jack's Bank",
		3534.28,
		"Party Time Savings",
		3203.89
	}
	};

	system("color 5A");
	printf("The Joneses have a total of $%.2lf\n", 
		sum(jones, N));		//数组名是数组的地址，准确地，也是数组首元素、即结构jones[0]的地址，所以等价写法为：sum(&jones[0], N);

	/*要点总结：

	● 可以用数组名把数组中第一个结构的地址传递给函数
	● 然后可以用数组的方括号符号来访问数组中的后续结构。注意下面的函数调用和使用数组名有同样的效果：
		sum(&jones[0], n);
		因为二者都指向同一地址。使用数组名只是传递结构的地址的间接方法。
	● 因为函数sum()不用来改变原来的数据，所以使用ANSI C的类型限定词const。*/
	system("pause");
	return 0;
}

double sum(const struct funds money[], int n)
{
	double total = 0;
	
	for (int i = 0; i < n; i++)
	{
		total += money[i].bankfund + money[i].savefund;
	}

	return total;
}