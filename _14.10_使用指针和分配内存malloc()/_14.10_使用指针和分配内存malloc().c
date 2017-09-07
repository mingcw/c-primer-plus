#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

/**************************************************************************************************************

	前言：

	在结构中建议使用字符数组，除非理解字符指针的含义并会活用
	1.使用字符数组，字符串直接存储在结构内部
	2.使用字符指针，存储了字符指针，指示了存储字符串的地址（即字符串存储在程序中其他地方，在编译器存储字符串常量的任何地方）
	  如果：printf("%s",person.fname);//程序正常运行，person.fname指示了存储在数据段的字符串常量的地址	
	  但是：scanf("%s",person.fname)；//编译没问题，但有一个潜在的风险。
									person.fname是字符指针，指示了scanf()将读入一个字符串到person.fname指示的地址处——
									而该指针变量未经初始化，所以地址可能是任何值，程序就可以把该字符串存在任何地方。
									如果幸运的话，程序至少有些时候可以正常运行。否则这个操作可以使程序彻底停止。
									实际上，如果程序运行，那是很不幸的，因为程序中含有用户未察觉到的危险的编程错误。
	因此，如果需要一个结构来存储字符串，应该使用字符数组成员。存储字符指针有它的用处，但也有被严重误用的可能。

	************************************************************************************************************
	本节：

	在结构中使用指针处理字符串有意义的一个例子——使用malloc()分配内存，并用指针来存放地址。

	这个方法的优点是：可以请求malloc()分配刚好满足字符串需求数量的空间。可以请求4字节来存储"Joe"，等等。

	（注意：使用malloc()分配的内存在程序执行期间一直存在，直到free()释放该占用内存。即malloc() 分配的内存存储时期是调用内存分配函数开始一直到第一次调用free()为止。
		这可是以前学过的，再提提印象。(^_^)）
	下面是实例：
*/

struct namect
{
	char * fname;						//使用字符指针
	char * lname;
	int letters;
};

void getinfo(struct namect *);			//分配内存
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);			//用完后及时释放内存

int main(void)
{
	struct namect person;

	system("color 0A");
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	system("pause");
	return 0;
}

void getinfo(struct namect * pst)
{
	char temp[SIZE];

	printf("Please enter your first name:\n");
	gets_s(temp, SIZE);
	pst->fname = (char *)malloc((strlen(temp) + 1) * sizeof(char));		//分配存放名字的内存
	strcpy_s(pst->fname, (strlen(temp) + 1), temp);						//把名字复制到已分配的内存中
	printf("Please enter your last name:\n");
	gets_s(temp, SIZE);
	pst->lname = (char *)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(pst->lname, (strlen(temp) + 1), temp);
}

void makeinfo(struct namect * pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{ 
	printf("%s %s, your name contains %d letters.\n", 
		pst->fname, pst->lname, pst->letters);		//间接成员运算符通过结构指针间接访问结构成员（结构成员运算符通过结构名直接访问结构成员）
}

void cleanup(struct namect * pst)
{
	free(pst->fname);
	free(pst->lname);
}