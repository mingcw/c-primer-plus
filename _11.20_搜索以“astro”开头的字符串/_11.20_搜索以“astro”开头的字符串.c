#include <stdio.h>
#include <string.h>

#define LISTSIZE 5

int main(void)
{

	/*搜索含有某个前缀的字符串时，
	可以用strncmp()比较字符串的前几个字符是否相同达到目标*/

	char * list[LISTSIZE] = {
		"astronomy",
		"astounding",
		"astrohpysics",
		"ostracize",
		"asterism"
	};
	int count = 0;

	for (int i = 0; i < LISTSIZE; i++)
	{
		if (strncmp(list[i], "astro", 5) == 0)		//如果2个字符串的每一对字符的ANSCII值都相等，即找到了astro_前缀的单词时打印计数
		{
			printf("Found: %s\n", list[i]);
			count++;
		}
	}
	printf("The list contained %d words beginning"
		" with astro.\n", count);

	getchar();
	return 0;
}