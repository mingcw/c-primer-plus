#include <stdio.h>
#include <string.h>  //目的：调用取字符串长度strlen()
#define NUM 56  //声明int常量
#define STR "Hello"
#define CH 'A'

int main(void)
{
	/*sizeof()是计算括号中变量的类型所占的储存空间(不考虑内容)
	*strlen()是计算变量值为起点的内存地址到第一个空字符'\0'的距离，以字节为单位，字符串尾部为'\0'
	*简单理解：
	*sizeof()是类型的长度，
	*strlen()是有效字符串的长度，不包括空字符*/

	int n = 56;
	printf("int n = 56的sizeof：%d\n\n", sizeof(n));

	/*char a[5] = {'a', 'b', 'c', 'd', 'e'};
	printf("char a[5] = \"Hello\"的sizeof：%d\n", sizeof(a));
	printf("char a[5] = \"Hello\"的strlen：%d\n\n", strlen(a));*/

	char m = 'A';
	printf("char m = \'A\'的sizeof：%d\n\n", sizeof(m));  //字符以int类型保存，所以sizeof(CH)=4

	int array1[50] = { 4, 4, 4, 4 };
	printf("int array1[50]的sizeof：%d\n\n", sizeof(array1)); //int数组以int类型保存，所以sizeof(array)=4*50=200

	long long array2[50] = { 4, 4, 4, 4 };
	printf("long long array2[50]的sizeof：%d\n\n", sizeof(array2));  //long long数组以int类型保存，所以sizeof(array)=8*50=400

	char array3[50] = { 4, 4, 4, 4 };
	printf("char array3[50] = { 4, 4, 4, 4 }的sizeof：%d\n\n", sizeof(array3));
	printf("char array3[50] = { 4, 4, 4, 4 }的strlen：%d\n\n", strlen(array3));

	char *s = "0123456789";
	printf("char *s = \"0123456789\"的sizeof：%d\n\n", sizeof(s));
	printf("char *s = \"0123456789\"的strlen：%d\n\n", strlen(s));

	char ss[] = "0123456789";
	printf("char ss[] = \"0123456789\" 的sizeof：%d\n\n", sizeof(ss));
	printf("char ss[] = \"0123456789\" 的strlen：%d\n\n", strlen(ss));

	getchar();
	return 0;

}