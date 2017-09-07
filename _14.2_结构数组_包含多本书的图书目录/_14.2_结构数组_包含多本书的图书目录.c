#include <stdio.h>
#include <stdlib.h>

#define MAXTITL 41
#define MAXAUTH 41
#define MAXBKS 100		/*最多可以容纳的图书册数（结构数组的大小）*/

struct book
{
	char title[MAXTITL];
	char author[MAXAUTH];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];		//声明book类型的结构数组

	int count = 0;
	
	system("color 5A");
	printf("Please enter the book title.\n");
	printf("Press [enter] at the begining of the line to stop:\n");
	while (count < MAXBKS &&
			gets_s(library[count].title != NULL, MAXTITL) &&
			library[count].title[0] != '\0')
	{
		printf("Now enter the author:\n");
		gets_s(library[count].author, MAXAUTH);
		printf("Now enter the value:\n");
		scanf_s("%f", &library[count].value, 20);		//遗漏了换行符在输入流中
		
		while (getchar() != '\n')						//清空剩余行
		{
			continue;
		}
		printf("Enter the next title:\n");
		++count;
	}
	if (count > 0)
	{
		printf("Here is the list of your book:\n");
		for (int i = 0; i < count; i++)
		{
			printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
		}
	}
	else
	{
		printf("No books? Too bad.\n");
	}

	system("pause");
	return 0;
}