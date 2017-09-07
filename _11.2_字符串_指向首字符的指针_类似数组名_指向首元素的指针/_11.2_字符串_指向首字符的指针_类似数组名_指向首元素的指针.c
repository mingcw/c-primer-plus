
/*综合PE结构解析字符串：
编译后的源文件里，字符串作为PE文件的资源保存在数据段部分，准确的说是保存在资源块，
当程序由PE装载器加载到内存时，由源代码知道要初始化一个字符串，这时资源块的字符串资源被拷贝到字符数组（分配给数组内存空间）中，
拷贝到的字符串作为静态存储类在整个运行过程中只存储一份*/

#include <stdio.h>

int main(void)
{
	printf("%s\n", "String!");
	printf("%p\n", "Pointer");		//字符串指针首字符P，或者说，字符数组名指向首字符P
	printf("%c\n", *"Character");	//打印字符数组名指向的首字符

	getchar();
	return 0;

	//const char *m3 = "\nEnough about me - what's your name? ";		//指针符号建立字符串, 指向字符数组首元素
	//const char m31[] = "\nEnough about me - what's your name? ";	//使用数组符号建立字符串，字符数组名指向数组字符首元素

}

