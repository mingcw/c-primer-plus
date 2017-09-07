#include <stdio.h>

#define SIZE 41

struct book											
{
	char title[SIZE];
	char author[SIZE];
	float value;
};

int main(void)
{
	/*结构的指定初始化项目：语法类似于数组指定成员的初始化（方括号和下标对指定元素初始化）：
		结构成员运算符(.)和成员名对指定元素初始化：.member
	*/

	//1.部分初始化
	struct book library1 = { .value = 10.99 };

	//2.按照任意顺序对指定项目初始化
	struct book library2 = {
		.value = 25.99f,
		.author = "Philionna Pestle",
		.title = "Rue for the Toad"
	};

	//3.像数组一样，跟在一个指定初始化项目之后的常规初始化项目为跟在指定成员后的成员提供了初始值
	struct book library3 = {
		.value = 18.90f,				//指定初始化项目，初始化value成员
		.author = "Philionna Pestle",	//指定初始化项目，初始化author成员
		0.25f							/*常规初始化项目，初始化author后的成员value(覆盖了旧的赋值18.90)
				  
										  这一点类似于数组：如果一个指定元素后有多个值，这些值将依次对后续元素初始化，并且只保留对某成员的最后一次初始化，覆盖旧值：
										  int num[10] = {1, 2 ,3 ,4 ,[5] = 4，2，3，0}；该语句对第6个元素初始化4，其后的元素依次被后续值初始化并且保留最后一次初始化。*/			
	};

	printf("Title: %s\n", library1.title);
	printf("Author: %s\nValue?：", library1.author);
	scanf_s("%f", &library1.value, 10);		
	printf("Value: $%.2f\n", library1.value);

	getchar();
	getchar();
	return 0;
}
