#include <stdio.h>
#include <stdlib.h>

void up_and_down(int);

int main(void)
{
	//递归：调用自己本身的过程

	system("COLOR F4");
	printf("★★★★★★★★★★★★★★★ 递 归 的 基 本 原 理 ★★★★★★★★★★★★★\n\n"
		"★   第一，每一级的函数都有自己的变量。回到第一级调用时原来的变量仍具初值。 ★\n\n"
		"★   第二，每一次函数调用都会有一次返回。递归过程逐级返回。                 ★\n\n"
		"★   第三，位于递归调用前的语句的执行顺序和各个被调函数的顺序相同。         ★\n\n"
		"★   第四，位于递归调用后的语句的执行顺序和各个被调函数的顺序相反。         ★\n\n"
		"★   第五，每一级递归的代码不会被复制。（只有需要的变量会被创建）           ★\n\n"
		"★   第六，递归函数内必须有终止递归调用的语句。                             ★\n\n"
		"★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n\n");

	up_and_down(1);/* 该函数是递归过程，
			 解释1：  
				   传递1调用up_and_down，#1输出Level 1，
				   1小于4，up_and_down（第一级）调用up_and_down（第二级），#1输出Level 2，
				   2小于4, up_and_down（第二级）调用up_and_down（第三级），#1输出Level 3，
				   3小于4，up_and_down（第三级）调用up_and_down（第四级），#1输出Level 4，
				   4小于4为假，#2输出LEVEL 4,
				   指令执行返回到调用up_and_down（第四级）的up_and_down（第三级）的下一条指令，
				   #2输出LEVEL 3，
				   指令执行返回到调用up_and_down（第三级）的up_and_down（第二级）的下一条指令，
				   #2输出LEVEL 2，
				   指令执行返回到调用up_and_down（第二级）的up_and_down（第一级）的下一条指令，
				   #2输出LEVEL 1，
				   注意： 每一级递归都使用自己的私有变量，可以通过查看地址的值来得出这个结论
			 解释2：
				   fun1()调用fun2()，
				   fun2()调用fun3()，
				   fun3()调用fun4()，
				   fun4()执行完后，fun3()继续执行，
				   fun3()执行完后，fun2()继续执行，
				   fun2()执行完后，fun1()继续执行，
				   */
				
	getchar();
	return 0;
}

void up_and_down(int n)
{
	printf("Level %d: n location %p\n", n, &n);	/* #1 */
	if (n < 4)
		up_and_down(n + 1);	//递归结束后，执行位置返回到下一条语句处
	printf("LEVEL %d: n location %p\n", n, &n);	/* #2 */  
}
