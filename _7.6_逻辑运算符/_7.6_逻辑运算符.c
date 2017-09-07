#include <stdio.h>

#define PERIOD '.'		//句号字符

int main(void)
{
	char ch;
	int charCount = 0;		//除了

	while ((ch = getchar()) != PERIOD)	//当输入字符不是句号，即输入字符串未结束时
	{
		if (ch != '"' & ch != '\'')
		{
			charCount++;
		}
	}
	printf("There are %d non-quote characters.\n", charCount);
	
	getchar();
	getchar();
	return 0;

}