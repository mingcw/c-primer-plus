#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//观察strcmp()的返回值总结返回值规律

	system("color 4E");

	printf("strcmp (\"A\", \"A\") is ");
	printf("%d\n\n", strcmp("A", "A"));					//0

	printf("strcmp (\"A\", \"B\") is ");
	printf("%d\n\n", strcmp("A", "B"));					//-1

	printf("strcmp (\"B\", \"A\") is ");
	printf("%d\n\n", strcmp("B", "A"));					//1

	printf("strcmp (\"C\", \"A\") is ");	
	printf("%d\n\n", strcmp("C", "A"));					//1

	printf("strcmp (\"Z\", \"a\") is ");
	printf("%d\n\n", strcmp("Z", "a"));					//-1

	printf("strcmp (\"mingcxx\", \"mingc\") is ");
	printf("%d\n\n", strcmp("mingcxx", "mingc"));		//1
	
	/*
	总结：strmp()依次查找两字符串对应的每一对字符的ANSCII值，
	前者大于后者返回1（该C环境下）,
	前者小于后者返回-1,
	两者相等则继续查找下一对字符直到找到一对ANSCII不相等字符返回非0值或任何一个字符串的结尾，
	如果每一对字符的ANSCII值相等，则返回0

	即：strcmp()依次比较两字符串的每一对字符的ANSCII差值，前者减去后者，小于0返回负值，大于0返回正值，等于0则继续查找下一对字符
	（说明;前一个字符换的该字符在前面）

	ANSI标准规定：如果第一个字符串在字母表中的顺序先于第二个字符串，返回负值（确定的数值依赖于不同的C实现）
	*/
	
	getchar();
	return 0;
}