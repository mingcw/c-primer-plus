#include <stdio.h>
#include <stdlib.h>

void why_me(void);

int main(void)
{																	
	system("color 0A");

//#pragma c9x on

#ifdef __STDC__
#if __STDC__ == 1												//__STDC__:			设置为1时，表示该实现遵循C标准。
	printf("STDC.\n");	
#else
	printf("not STDC.\n");
#endif // __STDC__
#else
#line 666 "program.c"											//#line:			重置由预定义宏__LINE__报告的行号（下一行）和__FILE__报告的文件名
//#error Not C99																	//#error指令向编译器发出一条错误消息，消息中包含指定的文本。可能的话，编译过程应该中断。并且无法该指令行内添加注释，所有文本都被视为错误消息。
	printf("__STDC__ is not exist.\n");
#endif // __STDC__

#ifdef __FILE__
	printf("This file is %s.\n", __FILE__);						//__FILE__:			当前源文件的文件名的字符串文字
#endif // !__FILE__

#ifdef __DATE__
	printf("This date is %s.\n", __DATE__);						//__DATE__:			进行预处理的日期（"Mmm dd yyyy"形式的字符串文字）
#endif // __DATE__

#ifdef __TIME__
	printf("This time is %s.\n", __TIME__);						//__TIME__：			源文件的编译时间（"hh: mm: ss"形式的字符串文字）
#endif // __TIME__

#if defined(__STDC_VERSION__)
#if __STDC_VERSION__ == 199901L 
	printf("C99: %d.\n", __STDC_VERSION__);						//__STDC_VERSION__:	为C99时设置为199901L
#else
	printf("Not C99: %d\n", __STDC_VERSION__);
#endif // __STDC_VERSION__ == 199901L 
#else
	printf("Not C99.\n");
#endif // defined(__STDC_VERSION__)

#ifdef __STDC_HOSTED__
#if __STDC_HOSTED__ == 1
	printf("Local environment.\n", __STDC_HOSTED__);			//__STDC_HOSTED__:	为本机环境设置为1，否则设0
#else
	printf("IS not local environment.\n");
#endif // __STDC_HOSTED__ == 1
#endif // __STDC_HOSTED__

#ifdef __LINE__
	printf("This is line %d.\n", __LINE__);						//__LINE__:			源文件中当前语句行的行号
#endif // __LINE__

#ifdef __func__
	printf("This function is %s.\n", __func__);					//__func__:			C99提供的一个预定义标识符。（展开为一个函数名的字符串）
																					//该标识符具有函数作用域，而宏本质上具有文件作用域。所以__func__是C语言的预定义标识符，而非预定义宏。*/
#endif // __func__		

#ifdef __FUNCTION__												//__FUNCTION__:		在GCC和MS的编译器中，__FUNCTION__是__func__的别名，前者属于语言实现（编译器）之下（可由编译开关disable之），后者则属于C语言标准。
	printf(":This function is %s().\n", __FUNCTION__);
#endif //__FUNCTION__
	why_me();
	 
	getchar();
	return 0;
}

void why_me(void)
{
#ifdef __func__
	printf(".This function is %s.\n", __func__);
#endif // __LINE__
#ifdef __FUNCTION__
	printf(":This function is %s().\n", __FUNCTION__);
#endif //__FUNCTION__

#ifdef __LINE__
	printf("This is line %d.\n", __LINE__);
#endif // __LINE__
}