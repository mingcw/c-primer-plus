#include <stdio.h>

#define TEST "消息文本"

/*
在所有的预处理指令中，#pragma 指令可能是最复杂的了，它的作用是设定编译器的状态或者是指示编译器完成一些特定的动作。
它的常用参数：*/

//1.message参数 -- 在编译信息的输出窗口输出相应的信息
#if defined(TEST)
#pragma message(TEST)				//message的消息文本可以是展开为C字符串的宏常量

#endif

//2.#pragma once(比较常用）-- 对头文件只包含一次
#pragma once

//3.屏蔽编译警告
#pragma warning(disable: 4996)		//忽略编号为4996的警告信息
//_Pragma("warning(disable: 4996)")
//或者：在包含stdio.h文件之前添加定义#define _CRT_SECURE_NO_WARNINGS

//其他的暂时不说了，理解不了

/*
补充：预处理器运算符：
1.字符串化运算符#
2.语言符号连接符##
3.是否定义运算符defined
4.编译指令化运算符_Pragma -- 该运算符完成字符析构工作，也就是说，它会把字符串中的转义序列转换成它所代表的字符。
*/

//_Pragma("nonstandrdtreatmenttypeB on")
//等价于
//#pragma nonstandrdtreatmenttypeB on

//因为该运算符没有使用#符号，所以可以作为宏展开的一部分：
//#define PRAGMA(X) _Pragma(#X)
//#define LIMRG(X) PRAGMA(STDC CX_LIMITED_RANGE X)

//接着可以使用
//LIMRG(ON)
#define PRINT(X) printf(#X "\n")

int main(void)
{
	PRINT(ming);

	scanf("123");
	return 0;
}