#include <stdio.h>
#include <stdlib.h>

#define COLOR system("color 0A")

int main(void)
{
	char * mesg = "Don't be a fool! ";
	char * copy;

	COLOR;
	
	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s, &mesg = %p, value = %p\n",	//打印指针指向的字符串、打印指针的地址、打印指针的值（字符串首元素的地址）
		mesg, &mesg, mesg);			
	printf("copy = %s, &copy = %p, value = %p\n",	//打印指针指向的字符串、打印指针的地址、打印指针的值（字符串首元素的地址）
		copy, &copy, copy);			
	
	getchar();
	return 0;
}