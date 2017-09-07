#include <stdio.h>

#define BORDER 23
/*
	联合：在统一存储空间（但不同时）存储不同类型数据的数据类型*/
union hold					//联合模板，标记为hold
{
	int digit;
	double bigfl;
	char letter;
};

int main(void)
{
	union hold fit;			//hold类型的联合变量（编译器分配足够的空间以保存所描述可能性的最大需要。该情况下，最大可能性为double型数据）
	union hold save[10];	//10个联合变量的数组
	union hold * pu;		//指向hold类型联合的指针

	//联合的初始化：只能存储一个值，不同于结构
	//1.把一个联合初始化为同样类型的另一个联合
	union hold valA;
	valA.letter = 'R';			//把一个联合初始化为另一个联合

	union hold valB = valA;

	//2.初始化联合的第一个元素
	union hold valC = { 88 };	//初始化联合的digit成员

	//3.C99标准，指定初始化项目
	union hold valD = { .bigfl = 118.2f };

	//联合的通常用在：
	//1.一个成员将值保存在联合里，另一个成员来查看这些内容（该做法有时很有用，实例见_15.4）
	/*2.某些结构中使用联合，该结构存储的信息有赖于其中的一个成员。
		例如：假定有一个表示一辆汽车的结构。如果汽车属于使用者，就用一个结构成员来描述这个所有者。如果汽车被租赁，就用一个成员描述租赁它的公司：*/
	struct owner
	{
		char socsecurity;
		//...
	};

	struct leasecompany
	{
		char name[40];
		char headquarters[40];
		//...
	};

	union data
	{
		struct owner ownercar;
		struct leasecompany leasecar;
	};

	struct car_data
	{
		char name[40];
		int status;		//0==私有，1==租赁
		union data ownerinfo;
	};
	
	/*假定fits是一个car_data类型的结构变量。
	  如果：fits.status == 0，程序可以用fits.ownerinfo.ownercar.socsecurity;
	  如果：fits.status == 1，程序可以用fits.ownerinfo.leasecar.name;	*/
}