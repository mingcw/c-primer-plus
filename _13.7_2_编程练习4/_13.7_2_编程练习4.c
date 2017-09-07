/*使用命令行参数在屏幕上依次显示命令行中的全部文件，argc控制循环*/

#include <stdio.h>
#include <stdlib.h>
//include <conlose.h>

void show_file(char * filename);

int main(int argc, char * argv[])
{
	system("color 0A");
	//argc = ccommand(&argv);
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++)
	{
		show_file(argv[i]);
	}

	system("pause");
	return 0;
}

void show_file(char * filename)
{
	FILE * fp;
	int ch;

	if (fopen_s(&fp, filename, "r"))
	{
		fprintf(stderr, "\nCan't open %s\n", filename);
		return;
	}
	while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}
	if (ferror(fp) != 0)
	{
		fprintf(stderr, "\nError in reading %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	putchar('\n');
}