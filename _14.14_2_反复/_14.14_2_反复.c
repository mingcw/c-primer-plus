#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
#define AMOUNT 10
#define FNAME "book.dat"


struct book
{
	char title[SIZE];
	char author[SIZE];
	float value;
};

int main(void)
{
	struct book library[AMOUNT];
	FILE * fp;
	int count = 0;
	int filecount;
	size_t size = sizeof(struct book);

	system("color 0A");
	//打开文件流
	if (fopen_s(&fp, FNAME, "a+b") != 0)
	{
		fputs("打开文件失败！", stderr);
		exit(EXIT_FAILURE);
	}

	//反馈文件内图书记录，并写入结构数组
	rewind(fp);															//确保文件位置指示器在文件首
	while (count < AMOUNT && fread(&library[count], size, 1, fp) == 1)
	{
		if (count == 0)
		{
			printf("这是文件内的图书记录:\n", FNAME);
		}
		printf("《%s》 作者：%s 价格：%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;													//文件内的记录数

	//检查是否达到最大图书数量
	if (count == AMOUNT)
	{
		fputs("The file is full.", stderr);
		exit(EXIT_FAILURE);
	}

	//继续录入
	puts("现在您可以添加图书记录。");
	puts("请输入新的书名，");
	puts("在一行的开头按下回车键停止录入:");
	while (count < AMOUNT && gets_s(library[count].title, SIZE) != NULL && library[count].title[0] != '\0')
	{
		puts("请输入作者名:");
		gets_s(library[count].author, SIZE);
		puts("请输入价格：");
		scanf_s("%f", &library[count].value);
		while (getchar() != '\n')
		{
			;
		}
		count++;
		puts("请输入下一部书名（直接键入空行结束）：");
	}

	//反馈总记录
	if (count > 0)
	{
		puts("这是现在的书目清单：");
		for (int i = 0; i < count; i++)
		{
			printf("《%s》 作者：%s 价格：%.2f\n", library[i].title, library[i].author, library[i].value);
		}
		//将新的图书记录添加到文件

		if (fwrite(&library[filecount], size, count - filecount, fp) != count - filecount)
		{
			fputs("写入文件信息失败！", stderr);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		puts("没书么？那就好！");
	}

	system("pause");
	return 0;
}