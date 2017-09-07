#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char name1[11], name2[11];
	int count;
	
	system("color 0A");
	printf("Please enter 2 names:\n");
	count = scanf_s("%s %s", name1, 6, name2, 11);		/*作为scanf()的安全版本，该函数在原有基础上缓冲区的大小限制，至少等于读入字节数+1*/
	printf("I have read %d names %s and %s\n", count, name1, name2);

	system("pause");
	return 0;
}