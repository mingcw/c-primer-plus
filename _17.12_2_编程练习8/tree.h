/*tree.h -- 二叉搜索树的接口头文件*/

/*树中不允许有相同的项目*/
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>


/*您可以在这里把Item定义为适合的类型*/
#define MAXKINDS 20			//同名宠物的最大种类数量
typedef	struct item
{
	char petname[20];			//宠物名
	char petkind[MAXKINDS][20];	//同名宠物的种类数组
} Item;

#define MAXITEMS 10			//用该值测试当树已满时程序是否顺利运行。如果需要，可以设置更大

typedef struct node
{
	Item item;
	struct node * left;		/*指向左分支的指针*/
	struct node * right;	/*指向右分支的指针*/
} Node;


typedef struct tree
{
	Node * root;			/*指向树根的指针*/
	int size;				/*树中项目的个数*/
} Tree;


/*函数原型*/

/*操作：  把一个树初始化为一个空树*/
/*操作前：ptree指向一个树*/
/*操作后：该树已被初始化为空树*/
void InitializeTree(Tree * ptree);


/*操作：  确定树是否为空*/
/*操作前：ptree指向一个树*/
/*操作后：如果树为空则函数返回tree，
		  否则返回false*/
bool TreeIsEmpty(const Tree * ptree);


/*操作：  确定树是否已满*/
/*操作前：ptree指向一个树*/
/*操作后：如果树已满则函数返回tree，
		  否则返回false*/
bool TreeIsFull(const Tree * ptree);


/*操作：  确定树中项目的个数*/
/*操作前：ptree指向一个树*/
/*操作后：函数返回树中项目的个数*/
int TreeItemCount(const Tree * ptree);


/*操作：  向树中添加一个项目*/
/*操作前：pi是待添加项目的地址
		  ptree指向一个已初始化的树*/
/*操作后：如果可能，函数把项目添加到树中
		  并返回tree，否则返回false*/
bool AddItem(const Item * pi, Tree * ptree);


/*操作：  在树中查找一个项目*/
/*操作前：pi指向一个项目，
		  ptree指向一个已初始化的树*/
/*操作后：如果项目在树中，则将项目数据
		  复制到*pi, 函数返回tree，
		  否则返回false*/
bool InTree(Item * pi, const Tree * ptree);


/*操作：  从树中删除一个项目*/
/*操作前：pi是待删除项目的地址
		  ptree指向一个已初始化的树*/
/*操作后：如果可能，函数从树中删除该项目
		  并返回tree，否则返回false*/
bool DeleteItem(const Item * pi, Tree * ptree);


/*操作：  把一个函数作用于树中每一个项目*/
/*操作前：ptree指向一棵树，
		  pfun指向一个没有返回值的函数，
		  该函数接受一个Item作为参数*/
/*操作后：pfun指向的函数被作用于树中
		  每一个项目一次*/
void Traverse(const Tree * ptree, void(*pfun)(Item item));


/*操作：  从树中删除所有节点*/
/*操作前：ptree指向一个已初始化的树*/
/*操作后：该树为空树*/
void EmptyAll(Tree * ptree);


#endif // !_TREE_H_