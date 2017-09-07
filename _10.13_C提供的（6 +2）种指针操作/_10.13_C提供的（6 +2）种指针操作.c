#include <stdio.h>
#include <stdlib.h>

#define COLOR system("color 4E")

int main(void)
{
	COLOR;

	int urn[5] = { 100, 200, 300, 400, 500 };
	int * ptr1, *ptr2, *ptr3;

	ptr1 = urn;			//把一个地址赋给指针
	ptr2 = &urn[2];		//同上
	//取得指针指向的值
	//并且得到指针的地址
	printf("pointer value, dereferenced pointer, pointer address:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
		ptr1, *ptr1, &ptr1);

	ptr3 = ptr1 + 4;	/*指针加法
						1.指针加指针等同于一般的加法
						2.指针加整数时，这个整数会和指针所指类型的字节数相乘，然后所得的结果会加到初始地址上
						当指针指向的数组元素超出数组范围时，结果是不确定的，除非超出数组最后一个元素的地址能够保证是有效的，
						即有效的“越界”指针只能是数组最后一个元素的下一个“元素”地址）*/
	printf("\nadding an int to a pointer: \n");
	printf("ptr1 + 4 = %p, *(ptr1 + 3) = %d\n",
		ptr1 + 4, *(ptr1 + 3));

	ptr1++;				//递增指针
	printf("\nvalues after ptr1++\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
		ptr1, *ptr1, &ptr1);

	ptr2--;				//递减指针
	printf("\nvalues after --ptr2\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
		ptr2, *ptr2, &ptr2);

	--ptr1;				//恢复为初始值
	++ptr2;				//恢复为初始值
	printf("\nPointers reset to original values:\n");
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

	//一个指针减去另一个指针（得到的差的单位是所指向类型的字节大小，通常用于求一个数组内2个元素之间距离多少的类型大小）
	printf("\nsubstracting one pointer from another:\n");
	printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n",		//ptr2 - ptr1求得两个元素之间的距离为(ptr2 - ptr1)个int数值大小
		ptr2, ptr1, ptr2 - ptr1);

	//一个指针减去一个整数(等价于指针减去指针类型大小的整数倍)
	printf("\nsubstracting an int from a pointer;\n");
	printf("ptr3 = %p, ptr3 - 2 = %p\n",
		ptr3, ptr3 - 2);

	getchar();
	return 0;

}