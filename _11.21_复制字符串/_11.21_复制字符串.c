#include <stdio.h>
#include <string.h>
#include <string.h>

#define SIZE 41
#define ROWS 5
int main(void)
{
	//strcpy_s()拷贝字符串函数拷贝以q开头的5个字符串到目标指针处

	char qwords[ROWS][SIZE];
	char temp[SIZE];
	int i = 0;

	system("color 0A");
	
	printf("Enter %d words begin with q: \n", ROWS);
	while (i < ROWS && gets_s(temp, SIZE))
	{
		if (temp[0] != 'q')		
		//或者用if(strncmp(temp, "q", 1) != 0)
		{
			printf("%s donesn't begin with q.\n", temp);
		}
		else
		{
			strcpy_s(qwords[i], SIZE, temp);	//拷贝字符串函数，将源字串拷贝到目标字串里，缓冲区最小为要拷贝的字符数+1
			i++;
		}
	}
	printf("Here are the words accepted: \n");
	for (i = 0; i < ROWS; i++)
	{
		puts(qwords[i]);
	}

	getchar();
	return 0;
}