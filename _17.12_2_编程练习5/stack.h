//stack.h -- 栈类型的接口文件

/*
	类型名称								栈
	
	类型属性						存放规则的项目序列
	
	类型操作						初始化栈为空栈
								栈是否为空
								栈是否已满
								向栈顶压入一项
								从栈顶弹出一项*/

#include <stdbool.h>

//在这里可以更改Item为适合的类型
typedef char Item;

#define MAXSTACK 256		//栈空间大小，可根据实际调试设置更大
typedef struct stack
{
	Item items[MAXSTACK];		//存放栈成员信息
	int top;					//第一个空位的索引
} Stack;

//函数原型

//操作：  初始化栈
//操作前：ps指向一个栈
//操作后：该栈被初始化为空
void InitializeStack(Stack * ps);


//操作：  检查栈是否为空
//操作前：ps指向一个已被初始化的栈
//操作后：如果该栈为空，则返回true;
//		 否则返回false
bool StackIsEmpty(Stack * ps);


//操作：  检查栈是否已满
//操作前：ps指向一个已被初始化的栈
//操作后：如果该栈已满，则返回true;
///		 否则返回false
bool StackIsFull(Stack * ps);


//操作：  向栈顶压入一项
//操作前：ps指向一个已被初始化的栈，
//		 pi指向要压入的项目
//操作后：如果栈不为空，将*pi添加
//		 栈顶，函数返回true,否则
//		 不改变栈，函数返回false
bool Push(const Item * pi, Stack * ps);


//操作：  从栈顶弹出（删除）一项
//操作前：ps指向一个已被初始化的栈，
//		 pi指向要被删除的项目
//操作后：如果栈不为空，将从栈顶删
//		 除一项，被删除的项目复制
//		 到*pi返回true；如果这一
//		 操作清空了栈，栈将被重置
//		 为空，如果栈本身就为空，
//		 不改变栈, 函数返回false
bool Pop(Item * pi, Stack * ps);


//操作：弹出所有项目，清空栈
//将栈顶的项目依次复制到pi[]数组
void PopAll(Item pi[], Stack * ps, int MaxItems);