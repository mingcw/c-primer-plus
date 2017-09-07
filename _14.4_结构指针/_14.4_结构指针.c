#include <stdio.h>
#include <stdlib.h>

#define LEN 20

struct names
{
	char first[LEN];
	char last[LEN];
};

struct guy
{
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	//声明一个结构数组
	struct guy fellow[2] = {
		{
			{ "Ewen", "Villard" },
			"grilled salmon",
			"personality coach",
			58112.00f
		},
		{
			{"Rodney", "Swillbelly"},
			"tripe",
			"tabloid editor",
			232400.00f
		}
	};
	
	//声明一个结构指针
	struct guy * him;	/*这是一个指向guy结构的指针，与普通指针的声明类似
						（即该声明并不创建一个新的结构，而是意味着指针him可以指向任何现有的guy类型的结构
						  例如：barney是一个guy类型的结构。可以这样做：him = &barney;）*/

	system("color 5A");
	printf("address #1: %p, #2: %p\n", &fellow[0], &fellow[1]);						/*地址运算符取出第0个guy类型的结构fellow[0]和第1个fellow[1]*/
	him = &fellow[0];	/*告诉该指针它要指向的地址*/								/*注意区别：
																					  结构和数组的一个不同之处：
																								一个数组的名字就是该数组的地址
																								但是，
																								一个结构的名字不是该结构的地址，
																					  所以当使用
																					  结构指针指向某个结构时，要使用地址运算符&*/
	printf("pointer #1: %p, #2: %p\n", him, him + 1);								/* him 指向结构fellow[0]，
																					   him + 1 指向下一个结构fellow[1],
																					   并且(him+1)-him等于84
																					  （因为每个guy型结构占84字节<不信自己数一数哦o(︶︿︶)o>，
																						
																						顺带提一下，有些系统中，为了保持内存的对齐，系统对数据的存储会导致缝隙。
																						所以，结构的大小有可能大于它内部各成员大小之和。）*/
	printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);/*		 him->income：对结构指针使用间接成员运算符->取出结构指针指向的结构的成员
																									*him).income：对结构名字使用结构成员运算符. 取出结构的成员

																						所以：后跟->的结构指针和后跟. 的结构名是一样的。（假设该结构指针指向该结构）
																						*/
	him++;				/*指向下一个结构*/
	printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last);
	
	system("pause");
	return 0;
}