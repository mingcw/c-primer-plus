//names_st结构的头文件

//常量
#define SLEN 32

//结构声明
struct names_st
{
	char first[SLEN];
	char last[SLEN];
};

//类型定义
typedef struct names_st names;

//函数原型
void get_names(names *);
void show_names(const names *);

/*注意：头文件的内容不是可执行代码，而是编译器用于产生可执行代码的信息。*/