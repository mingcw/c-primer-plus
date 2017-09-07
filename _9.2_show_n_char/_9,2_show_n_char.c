#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAME "GIGETHINK, INC. "
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megbapolis. CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char(char ch, int num);

int main(void)
{
	//改进9.1的程序，居中打印字符流

	int spaces;

	system("color 0A");

	show_n_char('*', WIDTH);
	putchar('\n');
	show_n_char(SPACE, 12);
	printf("%s\n", NAME);
	spaces = (WIDTH - strlen(ADDRESS)) / 2;
	
	show_n_char(SPACE, spaces);
	printf("%s\n", ADDRESS);
	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
	
	printf("%s\n", PLACE);
	show_n_char('*', WIDTH);
	putchar('\n');

	getchar();
	return 0;
}

void show_n_char(char ch, int num)
{
	for (int i = 1; i <= num; i++)
		putchar(ch);
}