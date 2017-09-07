//names_st.h -- 带有多次包含保护的修订版本

#ifndef NAMES_H_
#define NAMES_H_

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

#endif // !NAMES_H_