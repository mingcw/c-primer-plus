#include <stdio.h>
#include <string.h>

#define SIZE 40
#define MARGSIZE 7
#define LIM 5

int main(void)
{
	char qwords[LIM][MARGSIZE];
	char temp[SIZE];
	int i = 0;

	printf("Enter %d words bengining with q:\n", LIM);
	while (i < LIM && gets_s(temp, SIZE))
	{
		if (temp[0] != 'q')
			printf("%s doesn't begining with q.\n", temp);
		else
		{
			/*函数功能，把源字符串的前n个字符或者空字符之前的所有字符（包括空字符）复制到最大空间为SizeInByte的目标字符串里
			如果源字符串包括空字符没有超出要复制的字符数n，则赋值整个源字符串包括空字符
			如果源字符串包括空字符超出要复制的字符数n，则只复制前n个字符，最后的空字符落下
			此时，需要在目标字符串的尾部添加空字符，将赋值进去的前n个字符标志为字符串*/

			strncpy_s(qwords[i],MARGSIZE ,temp, MARGSIZE - 1);		

			/*如果输入超出指定长度（6），那么在拷贝完前N个字符之后，必须
			在字符数组的最后一个元素里植入空字符标志一个有效的字符串而不是字符数组*/

			qwords[i][MARGSIZE - 1] = '\0';			
			i++;
		}
	}

	printf("Here are the words accepted:\n");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);

	getchar();
	return 0;
}