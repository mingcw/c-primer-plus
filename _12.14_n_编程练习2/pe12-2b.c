#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
	int mode;

	printf("Enter 0 for metric mode, 1 for US code: ");
	scanf_s("%d", &mode);
	while (mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode, 1 for US code ");
		printf("(-1 to quit): ");
		scanf_s("%d", &mode);
	}
	printf("Done!\n");

	getchar();
	getchar();
	getchar();
	return 0;
}