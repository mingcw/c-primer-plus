#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
#define FILENAME "book.dat"
#define BOOKS 10		//图书最大记录数

struct book				//结构模板，标记为book
{
	char title[SIZE];
	char author[SIZE];
	float value;
};

/*
	建立一个文件，由用户向文件内添加图书记录，添加完后反馈文件内的所有图书记录。
	如果文件内已有图书记录，先反馈用户。最多允许10条记录*/
int main(void)
{
	struct book library[BOOKS];
	FILE * fp;
	int count = 0;
	int filecount;
	size_t size = sizeof(struct book);

	system("color 0A");
	if (fopen_s(&fp, FILENAME, "a+b") != 0)
	{
		fprintf(stderr, "Can't open file.\n");
		exit(EXIT_FAILURE);
	}

	while (count < BOOKS && fread(&library[count], size, 1, fp) == 1)
	{
		if (count == 0)
		{
			printf("Current contents of the file is:\n");
		}
		printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;

	if (count == BOOKS)
	{
		fprintf(stderr, "The file is full.\n");
		exit(EXIT_FAILURE);
	}
	puts("Now you can add new title to the file:");
	puts("Press [enter] at the start of a line to stop:");
	while (count < BOOKS && gets_s(library[count].title, SIZE) != NULL && library[count].title[0] != '\0')
	{
		puts("Enter the author:");
		gets_s(library[count].author, SIZE);
		puts("Enter the value");
		scanf_s("%f", &library[count].value);
		while (getchar() != '\n')
		{
			;					//清空剩余行
		}
		count++;
		puts("Please enter next title([enter] to quit):");
	}
	
	if (count > 0)
	{
		puts("Here is the list of your book:");
		for (int i = 0; i < count; i++)
		{
			printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
		}
		if (fwrite(&library[filecount], size, count - filecount, fp) != count - filecount)
		{
			fprintf(stderr, "Error in writing file.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "No books? OK, very good.\n");
	}

	putchar('\n');
	system("pause");
	return 0;
}
