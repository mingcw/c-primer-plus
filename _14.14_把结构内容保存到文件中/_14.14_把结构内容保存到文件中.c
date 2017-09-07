#include <stdio.h>
#include <stdlib.h>

#define FILENAME "book.dat"
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10							//图书的最多本数

struct book									//定义结构模板，标记为book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];					//结构数组
	int count = 0;
	int filecount;									//文件内图书数目
	FILE * pbooks;
	size_t size = sizeof(struct book);

	system("color 0A");

	//获得二进制更新流
	if (fopen_s(&pbooks, FILENAME, "a+b") != 0)		//首次创建，可更新，文本尾追加，二进制模式
	{
		fprintf(stderr, "Can't open file %s\n", FILENAME);
		exit(EXIT_FAILURE);
	}
	rewind(pbooks);									//定位到文件首
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
		{
			fprintf(stdout, "Current contents of %s:\n", FILENAME);
		}
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);
		count++;
	}
	filecount = count;								
	if (count == MAXBKS)
	{
		fputs("The %s file is full.\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("Please add new book titles.");
	puts("Press [enter] key at the start of a line to stop:");
	while (count < MAXBKS
		&& gets_s(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		gets_s(library[count].author, MAXTITL);
		puts("Now enter the value:");
		scanf_s("%f", &library[count].value);		//遗漏换行符
		while (getchar() != '\n')
		{
			;			//清空输入行
		}
		count++;
		printf("Enter the next title:\n");
	}
	if (count > 0)
	{
		puts("Here is the list of your books:");
		for (int i = 0; i < count; i++)
		{
			printf("%s by %s: $%g\n", library[i].title,
				library[i].author, library[i].value);
		}
		fwrite(&library[filecount], size, count - filecount, pbooks);

	}
	else
	{
		puts("No books? Too bad.");
	}
	printf("Bye!\n");
	fclose(pbooks);

	system("pause");
	return 0;
}