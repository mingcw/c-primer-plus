#include <stdio.h>

#define MSG "CHANGE THE WORLD BY PROGRAMING!"

int put2(const char * string);

int main(void)
{
	int count;

	count = put2(MSG);

	printf("count = %d\n", count);

	getchar();
	return 0;
}

//打印一个字串，并统计其中的字符数

int put2(const char * string)
{
	int count = 0;

	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');		//换行符不统计在内

	return count;
}